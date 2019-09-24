#include <iostream>
#include <vector>
#include <chrono>

#include "util_input.h"
#include "util_draw.h"

#include "InspectionDemoMobilenet_gen.h"

using namespace std;
using namespace dmp;
using namespace util;

#define IMAGE_W (224)
#define IMAGE_H (224)

#define RESULT_IMG_W (150)
#define RESULT_IMG_H (98)
#define RESULT_OK_IMG_PATH "../../img/ok.jpg"
#define RESULT_NG_IMG_PATH "../../img/ng.jpg"

#define BG_COLOR (0x4169e1)
#define FONT_PATH "font/NotoSerif-Black.ttf"

#define SPEED_LIST_COUNT (6)

#define FILENAME_WEIGHTS "../weights/InspectionDemoMobilenet_weights.bin"

#define ARCHNAME "MobileNet"

void add_text(COverlayRGB &bg_overlay, char *text, int text_size, int x, int y, int color){
    unsigned int w = 0;
    unsigned int h = 0;
    COverlayRGB::calculate_boundary_text(text, text_size, w, h);
    COverlayRGB tmp_overlay(get_screen_width(), get_screen_height());
    tmp_overlay.alloc_mem_overlay(w, h);
    tmp_overlay.copy_overlay(bg_overlay, x, y);
    tmp_overlay.set_text(0, 0, text, text_size, color);
    tmp_overlay.print_to_display(x, y);
}

int main()
{
    // Define CNN network model object
    CInspectionDemoMobilenet network;

    // Buffer for decoded image data
    uint32_t imgView[IMAGE_W * IMAGE_H];

    // Buffer for pre-processed image data
    __fp16 imgProc[IMAGE_W * IMAGE_H * 3];

    // image resource
    uint32_t imgOK[RESULT_IMG_W * RESULT_IMG_H];
    uint32_t imgNG[RESULT_IMG_W * RESULT_IMG_H];

    chrono::system_clock::time_point start, end;
    double elapsed_time;
    chrono::system_clock::time_point wait_start, wait_now;
    double wait_elapsed_time;

    int speed_index = 2;
    int speed_list[SPEED_LIST_COUNT] = { 50, 100, 500, 1000, 2000, 5000 };  // [ms]

    vector<string> img_path_list;

    if (!init_fb()) {
        cout << "init_fb() failed." << endl;
        return 1;
    }
        
    // Initialize network object
    network.Verbose(0);
    if (!network.Initialize()) {
        return -1;
    }
    if (!network.LoadWeights(FILENAME_WEIGHTS)) {
        return -1;
    }
    if (!network.Commit()) {
        return -1;
    }
   
    // Create background and image overlay
    COverlayRGB bg_overlay(get_screen_width(), get_screen_height());
    bg_overlay.alloc_mem_overlay(get_screen_width(), get_screen_height());
    COverlayRGB overlay_input(get_screen_width(), get_screen_height());
    overlay_input.alloc_mem_overlay(IMAGE_W, IMAGE_H);
  
    // image resource
    decode_jpg_file(RESULT_OK_IMG_PATH, imgOK, RESULT_IMG_W, RESULT_IMG_H);
    decode_jpg_file(RESULT_NG_IMG_PATH, imgNG, RESULT_IMG_W, RESULT_IMG_H);
    COverlayRGB overlay_result(get_screen_width(), get_screen_height());
    overlay_result.alloc_mem_overlay(RESULT_IMG_W, RESULT_IMG_H);

    // draw backgraound
    for(int i=0; i<2; i++) {
        bg_overlay.set_background_to_color(BG_COLOR);        
        bg_overlay.set_text_with_font(FONT_PATH, "Visual Inspection Demo", 220, 48, 32, 0xffffff); 

        bg_overlay.set_text(340, 550, "[ESC]: Quit  [SPACE]: Pause", 18, 0xffffff);

        bg_overlay.print_to_display(0, 0);
	    swap_buffer();
    }

    bool is_exit = false;
    bool is_pause = false;
    bool is_wait = false;
    std::vector<float> network_output;

    // image file path
    ifstream ifs("../../../data/image.txt");
    ofstream ofs("log.txt");
    if(ifs.fail()) {
        std::cerr << "Failed to open image.txt" << std::endl;
        exit(-1);
    }
    string img_path;
    while(getline(ifs, img_path)){
        if(img_path != ""){
            img_path_list.push_back(img_path);
        }
    }

    unsigned int img_index = 0;
    bool aaa = false;

    wait_start = chrono::system_clock::now();
    while(is_exit == false) {
        wait_now = chrono::system_clock::now();
        wait_elapsed_time = chrono::duration_cast<chrono::microseconds>(wait_now - wait_start).count() / 1000.0;
        if(wait_elapsed_time > (double)speed_list[speed_index]) {
            is_wait = false;
        }

	    if(is_pause == false && is_wait == false) {
            is_wait = true;
            wait_start = chrono::system_clock::now();
            // Read Image
            decode_jpg_file(img_path_list[img_index], imgView, IMAGE_W, IMAGE_H);
            overlay_input.convert_to_overlay_pixel_format(imgView, IMAGE_W * IMAGE_H);
	        preproc_image(imgView, imgProc, IMAGE_W, IMAGE_H, 0, 0, 0, 1.0/255.0, true, false);

            // Run network in HW
            start = chrono::system_clock::now();
            memcpy(network.get_network_input_addr_cpu(), imgProc, IMAGE_W * IMAGE_H * 6);

            // Handle output from HW
            network.RunNetwork();
            end = chrono::system_clock::now();
            elapsed_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

            network.get_final_output(network_output);

            if(aaa == false){
                ofs << img_path_list[img_index] << "," << network_output[0] << "," << network_output[1] << endl;
            }

            img_index++;
            if(img_index >= img_path_list.size()) { img_index = 0; aaa = true;}
        }
	        
        overlay_input.print_to_display(340, 185);
     
    	if (network_output[0] > network_output[1]){
            overlay_result.convert_to_overlay_pixel_format(imgOK, RESULT_IMG_W * RESULT_IMG_H);
	    }
	    else {
            overlay_result.convert_to_overlay_pixel_format(imgNG, RESULT_IMG_W * RESULT_IMG_H);
	    }
	    overlay_result.print_to_display(640, 185);

        char buf[256];
        sprintf(buf, "[OK] %f", network_output[0]);
        add_text(bg_overlay, buf, 20, 640, 340, 0xffffff); 
	    
        sprintf(buf, "[NG] %f", network_output[1]);
        add_text(bg_overlay, buf, 20, 640, 380, 0xffffff); 
	    
        sprintf(buf, "%lf [ms]", elapsed_time);
        add_text(bg_overlay, buf, 20, 640, 420, 0xffffff); 
	    
        sprintf(buf, ARCHNAME);
        add_text(bg_overlay, buf, 18, 640, 460, 0xffffff); 

        sprintf(buf, "[c]: Change display update time (%4d[ms])", speed_list[speed_index]);
        add_text(bg_overlay, buf, 18, 340, 580, 0xffffff);

        swap_buffer();

        int key = getchar();

        switch(key)
        {
            case 27:
                is_exit = true;
                break;

            case 32:
                is_pause = !is_pause;
                break;

            case 'c':
                speed_index++;
                if(speed_index >= SPEED_LIST_COUNT) {
                    speed_index = 0;
                }
                break;
        
            default:
                break;
        }
    }

    shutdown();

    return 0;
}
