#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "deepeye_image_classifier_gpu.h"
#include "deepeye_util.h"
#include "cm_image.h"

#define TITLE "Visual Inspection DEMO"
#define SPEED_LIST_COUNT (6)

using namespace deepeye;

void show_result(float *pred_prob, int n_classes, int pred)
{
    std::cout << std::fixed;
    std::cout << "[0] OK ... " << std::setprecision(5) << pred_prob[0] << std::endl;
    std::cout << "[1] NG ... " << std::setprecision(5) <<pred_prob[1] << std::endl;
    std::cout << "pred: [" << pred << ": ";
    if(pred == 0){
        std::cout << "OK]";
    }
    else if(pred==1){
        std::cout << "NG]";
    }

    std::cout << endl;
}

void classification()
{
    static const int n_classes = 2;
    static const int channel = 3;
    static const int batch_size = 1;

    vector<string> img_path_list;

    chrono::system_clock::time_point start, end;
    double time;
    int speed_index = 2;
    int speed_list[SPEED_LIST_COUNT] = { 50, 100, 500, 1000, 2000, 5000 };  // [ms]
    unsigned int arch_index = 0;
    vector<string> acrh_names {"GoogLeNet", "ResNet50", "MobileNet"};

    vector<ImageClassifier*> arch_list;
    arch_list.push_back(new ImageClassifier(n_classes, channel, batch_size, ImageClassifier::Arch::GoogLeNet));
    arch_list.push_back(new ImageClassifier(n_classes, channel, batch_size, ImageClassifier::Arch::ResNet50));
    arch_list.push_back(new ImageClassifier(n_classes, channel, batch_size, ImageClassifier::Arch::MobileNet));

    try
    {        
        arch_list[0]->load_weights("../weights/weights_googlenet.deep0");
        arch_list[1]->load_weights("../weights/weights_resnet50.deep0");
        arch_list[2]->load_weights("../weights/weights_mobilenet.deep0");        
    }
    catch(...)
    {
        cout << "failed to load weight file." << endl;
        exit(1);
    }

    float pred_prob[n_classes];
    int pred;

    cv::namedWindow(TITLE, CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
   
    int is_exit = false;
    int is_pause = false;
    cv::Mat roi;
    Image *x = nullptr;

    std::vector<cv::Mat> ret_img { cv::imread("../img/ok.png"), cv::imread("../img/ng.png") };
    cv::Mat cm_logo = cv::imread("../img/cm_logo.png");

    // image file path
    std::ifstream ifs("../../../data/image.txt");

    if (ifs.fail())
    {
        std::cerr << "Failed to open image.txt" << std::endl;
        exit(-1);
    }

    string img_path;
    while (getline(ifs, img_path))
    {
        if(img_path != ""){
            img_path_list.push_back(img_path);
        }
    }

    unsigned int img_index = 0;

    // main loop
    while(is_exit == false){
        if (is_pause == false){
            try{
                x = Image::load(img_path_list[img_index], arch_list[arch_index]->get_input_size());
            }
            catch(...){
                std::cerr << "Failed to open " << img_path_list[img_index] << std::endl;
                exit(-1);
            }

            if(x == nullptr){
                cout << "failed to open image file. [" << img_path_list[img_index] << "]" << endl;
                img_index++;
                if(img_index >= img_path_list.size()) {
                    img_index = 0;
                }
                continue;
            }

            //----- predict
            std::cout << "---- [" << img_index << "]" << img_path_list[img_index] << " ----" << std::endl;
            start = chrono::system_clock::now();
            arch_list[arch_index]->predict_prob(x->get_data(), pred_prob);
            end = chrono::system_clock::now();
            time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
            pred = arch_list[arch_index]->predict(x->get_data());
            show_result(pred_prob, n_classes, pred);
            std::cout << std::endl;

            // draw
            cv::Mat bg = cv::Mat::zeros(440, 500, CV_8UC3);
            cv::rectangle(bg, cv::Point(0,0), cv::Point(500, 440), cv::Scalar(0xe1,0x69,0x41), -1, CV_AA);

            #define RESULT_X (270)
            #define RESULT_Y (24)
            #define RESULT_Y2 (150)                
            roi = bg(cv::Rect(RESULT_X, RESULT_Y, ret_img[pred].cols, ret_img[pred].rows));
            ret_img[pred].copyTo(roi);

            char buf[256];
            sprintf(buf, "[OK] %f", pred_prob[0]);
            cv::putText(bg, buf, cv::Point(RESULT_X, RESULT_Y2), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255,255,255), 1, CV_AA);
            sprintf(buf, "[NG] %f", pred_prob[1]);                
            cv::putText(bg, buf, cv::Point(RESULT_X, RESULT_Y2+30), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255,255,255), 1, CV_AA);
            sprintf(buf, "%lf [ms]", time);
            cv::putText(bg, buf, cv::Point(RESULT_X, RESULT_Y2+60), cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255,255,255), 1, CV_AA);
            cv::putText(bg, acrh_names[arch_index], cv::Point(RESULT_X, RESULT_Y2+100), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,255,255), 1, CV_AA);


            #define CAPTION_X (24)
            #define CAPTION_Y (300)
            cv::putText(bg, "[ESC]:Quit  [SPACE]:Pause", cv::Point(CAPTION_X, CAPTION_Y), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,255,255), 1, CV_AA);
            sprintf(buf, "[c]:Change display update time (%d[ms])", speed_list[speed_index]);
            cv::putText(bg, buf, cv::Point(CAPTION_X, CAPTION_Y+30), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,255,255), 1, CV_AA);
            cv::putText(bg, "[m]:Change architecture", cv::Point(CAPTION_X, CAPTION_Y+60), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,255,255), 1, CV_AA);

            #define IMG_X (24)
            #define IMG_Y (24)
            roi = bg(cv::Rect(IMG_X, IMG_Y, x->getMat().cols, x->getMat().rows));
            x->getMat().copyTo(roi);

            cv::rectangle(bg, cv::Point(0,390), cv::Point(500, 440), cv::Scalar(255,255,255), -1, CV_AA);
            roi = bg(cv::Rect(210, 390, cm_logo.cols, cm_logo.rows));
            cm_logo.copyTo(roi);
            
            cv::imshow(TITLE, bg);

            img_index++;
            if(img_index >= img_path_list.size()) {
                img_index = 0;
            }
        }

        char key = cv::waitKey(speed_list[speed_index]);

        switch(key){
            case 27:    // ESC
                is_exit = true;
                break;

            case ' ':   // SPACE
                is_pause = !is_pause;
                break;
            
            case 'c':
            case 'C':
                speed_index++;
                if(speed_index >= SPEED_LIST_COUNT) {
                    speed_index = 0;
                }
                break;

            case 'm':
            case 'M':
                arch_index++;
                if(arch_index >= arch_list.size()) {
                    arch_index = 0;
                }

            default:
                break;
        }

        if (x != nullptr) {
            delete x;
            x = nullptr;
        }
    }

    for(auto net : arch_list) { delete net; }
}

int main()
{
    classification();

    return 0;
}
