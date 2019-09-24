# VisualInspectionDemo
Visual Inspection Demo

## DeepEye GPU Demo

* Ubuntu 18.04
* CUDA 9.0 / 9.1 / 10
* cuDNN
* cmake

### Build

#### cmake
https://cmake.org/

#### OpenCV
```
$ sudo apt-get install -y libopencv-dev
```

```
$ cd deepeye_gpu
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Start
```
$ cd deepeye_gpu
$ cd bin
$ ./visualInspectionDemoGpu
```

## ZIA-C3 Demo

### Build
```
$ cd googlenet or mobilenet or resnet50
$ make
```

### Start
```
$ cd googlenet/bin or mobilenet/bin or resnet50/bin
$ ./visualInspectionDemo
```

## Download data

https://g5-compmind.s-portcloud.com/f7bda7fd65395460ea730056cce4d50e1f95ab3ab

pass: dvmlJ3_D

### data.zip
unzip.

* VisualInspectionDemo/data/OK
* VisualInspectionDemo/data/NG

### DeepEye Weights
* VisualInspectionDemo/deepeye_gpu/demo/weights/weights_googlenet.deep0
* VisualInspectionDemo/deepeye_gpu/demo/weights/weights_mobilenet.deep0
* VisualInspectionDemo/deepeye_gpu/demo/weights/weights_resnet50.deep0

### ZIA-C3 Weights
* VisualInspectionDemo/zia_c3/googlenet/weights/InspectionDemoGoogLeNet_weights.bin
* VisualInspectionDemo/zia_c3/mobilenet/weights/InspectionDemoMobilenet_weights.bin
* VisualInspectionDemo/zia_c3/resnet50/weights/InspectionDemoResnet_weights.bin


