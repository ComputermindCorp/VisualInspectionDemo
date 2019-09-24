cmake_minimum_required(VERSION 2.8)

set(TARGET visualInspectionDemoGpu)

project(${TARGET})

set(PREDICTOR_LIB_NAME deepeye_predictor_gpu_demo)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if(WIN32)
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" )
    set(CMAKE_SUPPRESS_REGENERATION true)
endif(WIN32)

##### cuda
find_package(CUDA REQUIRED)

if(UNIX)
    set(CUDA_INCLUDE_DIRS "/usr/local/cuda/include")
    set(CUDA_LIBRARIE_DIRS "/usr/local/cuda/lib64")
    set(CUDA_LIBRARIES "-lcudart -lcublas -lcudnn")
endif(UNIX)


##### OPENCV
# OpenCV
if(UNIX)
    set(OpenCV_INCLUDE_DIRS "/usr/local/include/opencv/")
    set(OpenCV_LIBRARY_DIRS "/usr/local/lib/")
    set(OpenCV_LIBRARIES "-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs")
endif(UNIX)

##### INCLUDE
set(INCLUDE_DIRS
    ${CUDA_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/include" 
)
include_directories("${INCLUDE_DIRS}")

##### LIBRARY
if(UNIX)
    set(LIBRARY_DIRS
        ${CUDA_LIBRARIE_DIRS}
        ${OpenCV_LIBRARY_DIRS}
        "${CMAKE_CURRENT_SOURCE_DIR}/lib/linux"
    )
endif(UNIX)

link_directories("${LIBRARY_DIRS}")

if(UNIX)
    set(LIBS
        ${CUDA_LIBRARIES}
        ${OpenCV_LIBRARIES}
        -ldl
        -lz
    )
endif(UNIX)

##### FLAG
set(CMAKE_CXX_FLAGS "-std=c++11")
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif(UNIX)
set(CMAKE_CXX_FLAGS_DEBUG, "-g")
set(CMAKE_CXX_FLAGS_RELEASE, "-O2 -march=native")

#
add_executable(${TARGET} classifier_sample.cpp cm_image.cpp )

target_link_libraries(${TARGET} ${PREDICTOR_LIB_NAME} ${LIBS})