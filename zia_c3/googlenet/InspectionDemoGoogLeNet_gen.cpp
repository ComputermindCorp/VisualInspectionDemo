/*
 *  Copyright 2018 Digital Media Professionals Inc.

 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at

 *      http://www.apache.org/licenses/LICENSE-2.0

 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.

 *  This source code was generated using DMP-DV700 tools.
 */

#include "InspectionDemoGoogLeNet_gen.h"


CInspectionDemoGoogLeNet::CInspectionDemoGoogLeNet() {
  // Empty by design
}

CInspectionDemoGoogLeNet::~CInspectionDemoGoogLeNet() {
  // Empty by design
}

bool CInspectionDemoGoogLeNet::Initialize() {
  is_weight_transposed = true;  // The weight matrix is transposed.
  if (!ReserveMemory(11909616, 1544512)) {
    return false;
  }

  set_num_layers(72);
  set_num_output_layers(3);

  Layer_0();
  Layer_1();
  Layer_2();
  Layer_3();
  Layer_4();
  Layer_5();
  Layer_6();
  Layer_7();
  Layer_8();
  Layer_9();
  Layer_10();
  Layer_11();
  Layer_12();
  Layer_13();
  Layer_14();
  Layer_15();
  Layer_16();
  Layer_17();
  Layer_18();
  Layer_19();
  Layer_20();
  Layer_21();
  Layer_22();
  Layer_23();
  Layer_24();
  Layer_25();
  Layer_26();
  Layer_27();
  Layer_28();
  Layer_29();
  Layer_30();
  Layer_31();
  Layer_32();
  Layer_33();
  Layer_34();
  Layer_35();
  Layer_36();
  Layer_37();
  Layer_38();
  Layer_39();
  Layer_40();
  Layer_41();
  Layer_42();
  Layer_43();
  Layer_44();
  Layer_45();
  Layer_46();
  Layer_47();
  Layer_48();
  Layer_49();
  Layer_50();
  Layer_51();
  Layer_52();
  Layer_53();
  Layer_54();
  Layer_55();
  Layer_56();
  Layer_57();
  Layer_58();
  Layer_59();
  Layer_60();
  Layer_61();
  Layer_62();
  Layer_63();
  Layer_64();
  Layer_65();
  Layer_66();
  Layer_67();
  Layer_68();
  Layer_69();
  Layer_70();
  Layer_71();

  return true;
}

//Layer_0: Convolution Layer
//  ->: conv1
//  ->: conv1_relu
//  ->: max_pooling2d_1
void CInspectionDemoGoogLeNet::Layer_0() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(0).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 224;  // Input Width
  conf.h = 224;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 3;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: conv1
  //->: conv1_relu
  //->: max_pooling2d_1
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x7;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 0;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x3030303;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(0);
  layer.name = "max_pooling2d_1";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 224;
  layer.input_dim[1] = 224;
  layer.input_dim[2] = 3;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 56;
  layer.output_dim[1] = 56;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = false;
}//end of  Layer_0

//Layer_1: Convolution Layer
//  ->: batch_normalization_1
//  ->: batch_normalization_1
//  ->: batch_normalization_1
void CInspectionDemoGoogLeNet::Layer_1() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(1).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 56;  // Input Width
  conf.h = 56;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 401408;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: batch_normalization_1
  //->: batch_normalization_1
  //->: batch_normalization_1
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 14464;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(1);
  layer.name = "batch_normalization_1";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 56;
  layer.input_dim[1] = 56;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 56;
  layer.output_dim[1] = 56;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_1

//Layer_2: Convolution Layer
//  ->: conv2_reduce
//  ->: conv2_reduce_relu
void CInspectionDemoGoogLeNet::Layer_2() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(2).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 56;  // Input Width
  conf.h = 56;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: conv2_reduce
  //->: conv2_reduce_relu
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 19712;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(2);
  layer.name = "conv2_reduce";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 56;
  layer.input_dim[1] = 56;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 56;
  layer.output_dim[1] = 56;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_2

//Layer_3: Convolution Layer
//  ->: conv2
//  ->: batch_normalization_2
//  ->: batch_normalization_2
//  ->: conv2_relu
//  ->: max_pooling2d_2
void CInspectionDemoGoogLeNet::Layer_3() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(3).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 56;  // Input Width
  conf.h = 56;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1154048;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: conv2
  //->: batch_normalization_2
  //->: batch_normalization_2
  //->: conv2_relu
  //->: max_pooling2d_2
  conf.run[0].m = 192;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 24960;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(3);
  layer.name = "max_pooling2d_2";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1154048;
  layer.output_size = 301056;
  layer.input_dim[0] = 56;
  layer.input_dim[1] = 56;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 192;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_3

//Layer_4: Convolution Layer
//  ->: inc3a_out1
//  ->: inc3a_out1_relu
void CInspectionDemoGoogLeNet::Layer_4() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(4).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 192;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1154048;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 401408;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3a_out1
  //->: inc3a_out1_relu
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 136448;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(4);
  layer.name = "inc3a_out1";
  layer.type = LT_CONV;
  layer.input_offs = 1154048;
  layer.output_offs = 401408;
  layer.output_size = 100352;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 192;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_4

//Layer_5: Convolution Layer
//  ->: inc3a_proj3
//  ->: inc3a_proj3_relu
void CInspectionDemoGoogLeNet::Layer_5() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(5).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 192;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1154048;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3a_proj3
  //->: inc3a_proj3_relu
  conf.run[0].m = 96;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 150912;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(5);
  layer.name = "inc3a_proj3";
  layer.type = LT_CONV;
  layer.input_offs = 1154048;
  layer.output_offs = 0;
  layer.output_size = 150528;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 192;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 96;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_5

//Layer_6: Convolution Layer
//  ->: inc3a_out3
void CInspectionDemoGoogLeNet::Layer_6() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(6).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 96;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 501760;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3a_out3
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 172352;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(6);
  layer.name = "inc3a_out3";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 501760;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 96;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_6

//Layer_7: Convolution Layer
//  ->: inc3a_proj5
//  ->: inc3a_proj5_relu
void CInspectionDemoGoogLeNet::Layer_7() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(7).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 192;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1154048;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3a_proj5
  //->: inc3a_proj5_relu
  conf.run[0].m = 16;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 283712;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(7);
  layer.name = "inc3a_proj5";
  layer.type = LT_CONV;
  layer.input_offs = 1154048;
  layer.output_offs = 0;
  layer.output_size = 25088;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 192;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 16;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_7

//Layer_8: Convolution Layer
//  ->: inc3a_out5
void CInspectionDemoGoogLeNet::Layer_8() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(8).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 16;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 702464;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3a_out5
  conf.run[0].m = 32;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x5;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 287712;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(8);
  layer.name = "inc3a_out5";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 702464;
  layer.output_size = 50176;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 16;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 32;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_8

//Layer_9: Convolution Layer
//  ->: max_pooling2d_3
void CInspectionDemoGoogLeNet::Layer_9() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(9).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 192;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1154048;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: max_pooling2d_3
  conf.run[0].m = 192;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 306720;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(9);
  layer.name = "max_pooling2d_3";
  layer.type = LT_CONV;
  layer.input_offs = 1154048;
  layer.output_offs = 0;
  layer.output_size = 301056;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 192;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 192;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_9

//Layer_10: Convolution Layer
//  ->: inc3a_pool
void CInspectionDemoGoogLeNet::Layer_10() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(10).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 192;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 752640;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3a_pool
  conf.run[0].m = 32;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 306720;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(10);
  layer.name = "inc3a_pool";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 752640;
  layer.output_size = 50176;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 192;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 32;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_10

//Layer_11: Concatenate Layer
//	->: concatenate_1
void CInspectionDemoGoogLeNet::Layer_11() {
  fpga_layer& layer = get_layer(11);
  layer.name = "concatenate_1";
  layer.type = LT_CONCAT;
  layer.input_offs = 401408;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_11

//Layer_12: Convolution Layer
//  ->: inc3a_concat
//  ->: inc3a_concat
void CInspectionDemoGoogLeNet::Layer_12() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(12).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3a_concat
  //->: inc3a_concat
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 314208;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(12);
  layer.name = "inc3a_concat";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_12

//Layer_13: Convolution Layer
//  ->: inc3b_out1
//  ->: inc3b_out1_relu
//  ->: inc3b_proj3
//  ->: inc3b_proj3_relu
//  ->: inc3b_out3
//  ->: inc3b_proj5
//  ->: inc3b_proj5_relu
//  ->: inc3b_out5
//  ->: max_pooling2d_4
//  ->: inc3b_pool
void CInspectionDemoGoogLeNet::Layer_13() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(13).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000001010101
  conf.topo = 0x55;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 791872;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->7 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3b_out1
  //->: inc3b_out1_relu
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 333664;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 1
  //--------------------------------------------------
  //->: inc3b_proj3
  //->: inc3b_proj3_relu
  conf.run[1].m = 128;  // Output Channels
  conf.run[1].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[1].p = 0x1;  // Filter Width and Height
  conf.run[1].pz = 1;  // Filter Depth
  conf.run[1].weight_buf.mem = weights_mem_;
  conf.run[1].weight_buf.offs = 371296;
  conf.run[1].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[1].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[1].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[1].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[1].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[1].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[1].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[1].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 2
  //--------------------------------------------------
  //->: inc3b_out3
  conf.run[2].m = 192;  // Output Channels
  conf.run[2].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[2].p = 0x3;  // Filter Width and Height
  conf.run[2].pz = 1;  // Filter Depth
  conf.run[2].weight_buf.mem = weights_mem_;
  conf.run[2].weight_buf.offs = 408928;
  conf.run[2].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[2].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[2].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[2].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[2].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[2].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[2].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[2].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 3
  //--------------------------------------------------
  //->: inc3b_proj5
  //->: inc3b_proj5_relu
  conf.run[3].m = 32;  // Output Channels
  conf.run[3].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[3].p = 0x1;  // Filter Width and Height
  conf.run[3].pz = 1;  // Filter Depth
  conf.run[3].weight_buf.mem = weights_mem_;
  conf.run[3].weight_buf.offs = 631008;
  conf.run[3].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[3].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[3].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[3].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[3].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[3].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[3].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[3].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 4
  //--------------------------------------------------
  //->: inc3b_out5
  conf.run[4].m = 96;  // Output Channels
  conf.run[4].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[4].p = 0x5;  // Filter Width and Height
  conf.run[4].pz = 1;  // Filter Depth
  conf.run[4].weight_buf.mem = weights_mem_;
  conf.run[4].weight_buf.offs = 640800;
  conf.run[4].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[4].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[4].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[4].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[4].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[4].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[4].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[4].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 5
  //--------------------------------------------------
  //->: max_pooling2d_4
  conf.run[5].m = 256;  // Output Channels
  conf.run[5].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[5].p = 0x1;  // Filter Width and Height
  conf.run[5].pz = 1;  // Filter Depth
  conf.run[5].weight_buf.mem = weights_mem_;
  conf.run[5].weight_buf.offs = 752096;
  conf.run[5].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[5].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[5].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[5].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[5].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[5].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[5].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[5].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 6
  //--------------------------------------------------
  //->: inc3b_pool
  conf.run[6].m = 64;  // Output Channels
  conf.run[6].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[6].p = 0x1;  // Filter Width and Height
  conf.run[6].pz = 1;  // Filter Depth
  conf.run[6].weight_buf.mem = weights_mem_;
  conf.run[6].weight_buf.offs = 752096;
  conf.run[6].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[6].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[6].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[6].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[6].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[6].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[6].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[6].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(13);
  layer.name = "concatenate_2";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 791872;
  layer.output_size = 752640;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 480;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_13

//Layer_14: Convolution Layer
//  ->: inc3b_concat
//  ->: inc3b_concat
//  ->: max_pooling2d_5
void CInspectionDemoGoogLeNet::Layer_14() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(14).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 480;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 791872;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 603712;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc3b_concat
  //->: inc3b_concat
  //->: max_pooling2d_5
  conf.run[0].m = 480;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 771168;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(14);
  layer.name = "max_pooling2d_5";
  layer.type = LT_CONV;
  layer.input_offs = 791872;
  layer.output_offs = 603712;
  layer.output_size = 188160;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 480;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 480;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_14

//Layer_15: Convolution Layer
//  ->: inc4a_out1
//  ->: inc4a_out1_relu
void CInspectionDemoGoogLeNet::Layer_15() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(15).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 480;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 603712;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 227392;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4a_out1
  //->: inc4a_out1_relu
  conf.run[0].m = 192;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 807200;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(15);
  layer.name = "inc4a_out1";
  layer.type = LT_CONV;
  layer.input_offs = 603712;
  layer.output_offs = 227392;
  layer.output_size = 75264;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 480;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 192;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_15

//Layer_16: Convolution Layer
//  ->: inc4a_proj3
//  ->: inc4a_proj3_relu
void CInspectionDemoGoogLeNet::Layer_16() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(16).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 480;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 603712;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4a_proj3
  //->: inc4a_proj3_relu
  conf.run[0].m = 96;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 918688;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(16);
  layer.name = "inc4a_proj3";
  layer.type = LT_CONV;
  layer.input_offs = 603712;
  layer.output_offs = 0;
  layer.output_size = 37632;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 480;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 96;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_16

//Layer_17: Convolution Layer
//  ->: inc4a_out3
void CInspectionDemoGoogLeNet::Layer_17() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(17).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 96;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 302656;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4a_out3
  conf.run[0].m = 208;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 974688;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(17);
  layer.name = "inc4a_out3";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 302656;
  layer.output_size = 81536;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 96;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 208;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_17

//Layer_18: Convolution Layer
//  ->: inc4a_proj5
//  ->: inc4a_proj5_relu
void CInspectionDemoGoogLeNet::Layer_18() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(18).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 480;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 603712;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4a_proj5
  //->: inc4a_proj5_relu
  conf.run[0].m = 16;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1155328;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(18);
  layer.name = "inc4a_proj5";
  layer.type = LT_CONV;
  layer.input_offs = 603712;
  layer.output_offs = 0;
  layer.output_size = 6272;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 480;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 16;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_18

//Layer_19: Convolution Layer
//  ->: inc4a_out5
void CInspectionDemoGoogLeNet::Layer_19() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(19).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 16;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 384192;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4a_out5
  conf.run[0].m = 48;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x5;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1165088;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(19);
  layer.name = "inc4a_out5";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 384192;
  layer.output_size = 18816;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 16;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 48;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_19

//Layer_20: Convolution Layer
//  ->: max_pooling2d_6
void CInspectionDemoGoogLeNet::Layer_20() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(20).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 480;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 603712;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: max_pooling2d_6
  conf.run[0].m = 480;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1193344;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(20);
  layer.name = "max_pooling2d_6";
  layer.type = LT_CONV;
  layer.input_offs = 603712;
  layer.output_offs = 0;
  layer.output_size = 188160;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 480;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 480;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_20

//Layer_21: Convolution Layer
//  ->: inc4a_pool
void CInspectionDemoGoogLeNet::Layer_21() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(21).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 480;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 403008;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4a_pool
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1193344;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(21);
  layer.name = "inc4a_pool";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 403008;
  layer.output_size = 25088;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 480;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_21

//Layer_22: Concatenate Layer
//	->: concatenate_3
void CInspectionDemoGoogLeNet::Layer_22() {
  fpga_layer& layer = get_layer(22);
  layer.name = "concatenate_3";
  layer.type = LT_CONCAT;
  layer.input_offs = 227392;
  layer.output_offs = 227392;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_22

//Layer_23: Convolution Layer
//  ->: inc4a_concat
//  ->: inc4a_concat
void CInspectionDemoGoogLeNet::Layer_23() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(23).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 227392;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 26688;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4a_concat
  //->: inc4a_concat
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1230848;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(23);
  layer.name = "inc4a_concat";
  layer.type = LT_CONV;
  layer.input_offs = 227392;
  layer.output_offs = 26688;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_23

//Layer_24: Convolution Layer
//  ->: inc4b_out1
//  ->: inc4b_out1_relu
void CInspectionDemoGoogLeNet::Layer_24() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(24).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 26688;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 428096;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4b_out1
  //->: inc4b_out1_relu
  conf.run[0].m = 160;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1269248;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(24);
  layer.name = "inc4b_out1";
  layer.type = LT_CONV;
  layer.input_offs = 26688;
  layer.output_offs = 428096;
  layer.output_size = 62720;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 160;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_24

//Layer_25: Convolution Layer
//  ->: inc4b_proj3
//  ->: inc4b_proj3_relu
void CInspectionDemoGoogLeNet::Layer_25() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(25).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 26688;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 227392;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4b_proj3
  //->: inc4b_proj3_relu
  conf.run[0].m = 112;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1362240;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(25);
  layer.name = "inc4b_proj3";
  layer.type = LT_CONV;
  layer.input_offs = 26688;
  layer.output_offs = 227392;
  layer.output_size = 43904;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 112;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_25

//Layer_26: Convolution Layer
//  ->: inc4b_out3
void CInspectionDemoGoogLeNet::Layer_26() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(26).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 112;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 227392;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 490816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4b_out3
  conf.run[0].m = 224;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1427488;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(26);
  layer.name = "inc4b_out3";
  layer.type = LT_CONV;
  layer.input_offs = 227392;
  layer.output_offs = 490816;
  layer.output_size = 87808;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 112;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 224;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_26

//Layer_27: Convolution Layer
//  ->: inc4b_proj5
//  ->: inc4b_proj5_relu
void CInspectionDemoGoogLeNet::Layer_27() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(27).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 26688;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4b_proj5
  //->: inc4b_proj5_relu
  conf.run[0].m = 24;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1654240;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(27);
  layer.name = "inc4b_proj5";
  layer.type = LT_CONV;
  layer.input_offs = 26688;
  layer.output_offs = 0;
  layer.output_size = 9408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 24;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_27

//Layer_28: Convolution Layer
//  ->: inc4b_out5
void CInspectionDemoGoogLeNet::Layer_28() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(28).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 24;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 578624;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4b_out5
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x5;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1668624;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(28);
  layer.name = "inc4b_out5";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 578624;
  layer.output_size = 25088;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 24;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_28

//Layer_29: Convolution Layer
//  ->: max_pooling2d_7
void CInspectionDemoGoogLeNet::Layer_29() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(29).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 26688;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 227392;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: max_pooling2d_7
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1724560;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(29);
  layer.name = "max_pooling2d_7";
  layer.type = LT_CONV;
  layer.input_offs = 26688;
  layer.output_offs = 227392;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_29

//Layer_30: Convolution Layer
//  ->: inc4b_pool
void CInspectionDemoGoogLeNet::Layer_30() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(30).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 227392;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 603712;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4b_pool
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1724560;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(30);
  layer.name = "inc4b_pool";
  layer.type = LT_CONV;
  layer.input_offs = 227392;
  layer.output_offs = 603712;
  layer.output_size = 25088;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_30

//Layer_31: Concatenate Layer
//	->: concatenate_4
void CInspectionDemoGoogLeNet::Layer_31() {
  fpga_layer& layer = get_layer(31);
  layer.name = "concatenate_4";
  layer.type = LT_CONCAT;
  layer.input_offs = 428096;
  layer.output_offs = 428096;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_31

//Layer_32: Convolution Layer
//  ->: inc4b_concat
//  ->: inc4b_concat
void CInspectionDemoGoogLeNet::Layer_32() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(32).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 428096;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 227392;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4b_concat
  //->: inc4b_concat
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1762064;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(32);
  layer.name = "inc4b_concat";
  layer.type = LT_CONV;
  layer.input_offs = 428096;
  layer.output_offs = 227392;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_32

//Layer_33: Convolution Layer
//  ->: inc4c_out1
//  ->: inc4c_out1_relu
//  ->: inc4c_proj3
//  ->: inc4c_proj3_relu
//  ->: inc4c_out3
//  ->: inc4c_proj5
//  ->: inc4c_proj5_relu
//  ->: inc4c_out5
//  ->: max_pooling2d_8
//  ->: inc4c_pool
void CInspectionDemoGoogLeNet::Layer_33() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(33).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000001010101
  conf.topo = 0x55;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 227392;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 428096;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->7 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4c_out1
  //->: inc4c_out1_relu
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1800464;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 1
  //--------------------------------------------------
  //->: inc4c_proj3
  //->: inc4c_proj3_relu
  conf.run[1].m = 128;  // Output Channels
  conf.run[1].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[1].p = 0x1;  // Filter Width and Height
  conf.run[1].pz = 1;  // Filter Depth
  conf.run[1].weight_buf.mem = weights_mem_;
  conf.run[1].weight_buf.offs = 1874960;
  conf.run[1].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[1].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[1].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[1].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[1].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[1].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[1].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[1].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 2
  //--------------------------------------------------
  //->: inc4c_out3
  conf.run[2].m = 256;  // Output Channels
  conf.run[2].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[2].p = 0x3;  // Filter Width and Height
  conf.run[2].pz = 1;  // Filter Depth
  conf.run[2].weight_buf.mem = weights_mem_;
  conf.run[2].weight_buf.offs = 1949456;
  conf.run[2].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[2].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[2].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[2].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[2].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[2].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[2].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[2].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 3
  //--------------------------------------------------
  //->: inc4c_proj5
  //->: inc4c_proj5_relu
  conf.run[3].m = 24;  // Output Channels
  conf.run[3].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[3].p = 0x1;  // Filter Width and Height
  conf.run[3].pz = 1;  // Filter Depth
  conf.run[3].weight_buf.mem = weights_mem_;
  conf.run[3].weight_buf.offs = 2245392;
  conf.run[3].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[3].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[3].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[3].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[3].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[3].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[3].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[3].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 4
  //--------------------------------------------------
  //->: inc4c_out5
  conf.run[4].m = 64;  // Output Channels
  conf.run[4].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[4].p = 0x5;  // Filter Width and Height
  conf.run[4].pz = 1;  // Filter Depth
  conf.run[4].weight_buf.mem = weights_mem_;
  conf.run[4].weight_buf.offs = 2259776;
  conf.run[4].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[4].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[4].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[4].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[4].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[4].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[4].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[4].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 5
  //--------------------------------------------------
  //->: max_pooling2d_8
  conf.run[5].m = 512;  // Output Channels
  conf.run[5].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[5].p = 0x1;  // Filter Width and Height
  conf.run[5].pz = 1;  // Filter Depth
  conf.run[5].weight_buf.mem = weights_mem_;
  conf.run[5].weight_buf.offs = 2315712;
  conf.run[5].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[5].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[5].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[5].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[5].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[5].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[5].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[5].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 6
  //--------------------------------------------------
  //->: inc4c_pool
  conf.run[6].m = 64;  // Output Channels
  conf.run[6].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[6].p = 0x1;  // Filter Width and Height
  conf.run[6].pz = 1;  // Filter Depth
  conf.run[6].weight_buf.mem = weights_mem_;
  conf.run[6].weight_buf.offs = 2315712;
  conf.run[6].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[6].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[6].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[6].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[6].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[6].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[6].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[6].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(33);
  layer.name = "concatenate_5";
  layer.type = LT_CONV;
  layer.input_offs = 227392;
  layer.output_offs = 428096;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_33

//Layer_34: Convolution Layer
//  ->: inc4c_concat
//  ->: inc4c_concat
void CInspectionDemoGoogLeNet::Layer_34() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(34).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 428096;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 227392;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4c_concat
  //->: inc4c_concat
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 2353216;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(34);
  layer.name = "inc4c_concat";
  layer.type = LT_CONV;
  layer.input_offs = 428096;
  layer.output_offs = 227392;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_34

//Layer_35: Convolution Layer
//  ->: inc4d_out1
//  ->: inc4d_out1_relu
//  ->: inc4d_proj3
//  ->: inc4d_proj3_relu
//  ->: inc4d_out3
//  ->: inc4d_proj5
//  ->: inc4d_proj5_relu
//  ->: inc4d_out5
//  ->: max_pooling2d_9
//  ->: inc4d_pool
void CInspectionDemoGoogLeNet::Layer_35() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(35).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000001010101
  conf.topo = 0x55;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 227392;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 451264;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->7 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4d_out1
  //->: inc4d_out1_relu
  conf.run[0].m = 112;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 2391616;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 1
  //--------------------------------------------------
  //->: inc4d_proj3
  //->: inc4d_proj3_relu
  conf.run[1].m = 144;  // Output Channels
  conf.run[1].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[1].p = 0x1;  // Filter Width and Height
  conf.run[1].pz = 1;  // Filter Depth
  conf.run[1].weight_buf.mem = weights_mem_;
  conf.run[1].weight_buf.offs = 2456864;
  conf.run[1].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[1].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[1].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[1].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[1].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[1].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[1].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[1].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 2
  //--------------------------------------------------
  //->: inc4d_out3
  conf.run[2].m = 288;  // Output Channels
  conf.run[2].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[2].p = 0x3;  // Filter Width and Height
  conf.run[2].pz = 1;  // Filter Depth
  conf.run[2].weight_buf.mem = weights_mem_;
  conf.run[2].weight_buf.offs = 2540608;
  conf.run[2].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[2].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[2].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[2].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[2].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[2].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[2].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[2].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 3
  //--------------------------------------------------
  //->: inc4d_proj5
  //->: inc4d_proj5_relu
  conf.run[3].m = 32;  // Output Channels
  conf.run[3].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[3].p = 0x1;  // Filter Width and Height
  conf.run[3].pz = 1;  // Filter Depth
  conf.run[3].weight_buf.mem = weights_mem_;
  conf.run[3].weight_buf.offs = 2914944;
  conf.run[3].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[3].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[3].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[3].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[3].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[3].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[3].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[3].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 4
  //--------------------------------------------------
  //->: inc4d_out5
  conf.run[4].m = 64;  // Output Channels
  conf.run[4].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[4].p = 0x5;  // Filter Width and Height
  conf.run[4].pz = 1;  // Filter Depth
  conf.run[4].weight_buf.mem = weights_mem_;
  conf.run[4].weight_buf.offs = 2933952;
  conf.run[4].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[4].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[4].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[4].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[4].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[4].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[4].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[4].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 5
  //--------------------------------------------------
  //->: max_pooling2d_9
  conf.run[5].m = 512;  // Output Channels
  conf.run[5].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[5].p = 0x1;  // Filter Width and Height
  conf.run[5].pz = 1;  // Filter Depth
  conf.run[5].weight_buf.mem = weights_mem_;
  conf.run[5].weight_buf.offs = 3008320;
  conf.run[5].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[5].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[5].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[5].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[5].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[5].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[5].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[5].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 6
  //--------------------------------------------------
  //->: inc4d_pool
  conf.run[6].m = 64;  // Output Channels
  conf.run[6].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[6].p = 0x1;  // Filter Width and Height
  conf.run[6].pz = 1;  // Filter Depth
  conf.run[6].weight_buf.mem = weights_mem_;
  conf.run[6].weight_buf.offs = 3008320;
  conf.run[6].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[6].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[6].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[6].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[6].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[6].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[6].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[6].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(35);
  layer.name = "concatenate_6";
  layer.type = LT_CONV;
  layer.input_offs = 227392;
  layer.output_offs = 451264;
  layer.output_size = 206976;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 528;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_35

//Layer_36: Convolution Layer
//  ->: inc4d_concat
//  ->: inc4d_concat
void CInspectionDemoGoogLeNet::Layer_36() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(36).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 451264;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 244288;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4d_concat
  //->: inc4d_concat
  conf.run[0].m = 528;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3045824;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(36);
  layer.name = "inc4d_concat";
  layer.type = LT_CONV;
  layer.input_offs = 451264;
  layer.output_offs = 244288;
  layer.output_size = 206976;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 528;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_36

//Layer_37: Convolution Layer
//  ->: inc4e_out1
//  ->: inc4e_out1_relu
void CInspectionDemoGoogLeNet::Layer_37() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(37).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 244288;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 764864;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4e_out1
  //->: inc4e_out1_relu
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3085408;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(37);
  layer.name = "inc4e_out1";
  layer.type = LT_CONV;
  layer.input_offs = 244288;
  layer.output_offs = 764864;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_37

//Layer_38: Convolution Layer
//  ->: inc4e_proj3
//  ->: inc4e_proj3_relu
void CInspectionDemoGoogLeNet::Layer_38() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(38).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 244288;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 451264;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4e_proj3
  //->: inc4e_proj3_relu
  conf.run[0].m = 160;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3252320;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(38);
  layer.name = "inc4e_proj3";
  layer.type = LT_CONV;
  layer.input_offs = 244288;
  layer.output_offs = 451264;
  layer.output_size = 62720;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 160;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_38

//Layer_39: Convolution Layer
//  ->: inc4e_out3
void CInspectionDemoGoogLeNet::Layer_39() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(39).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 160;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 451264;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 865216;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4e_out3
  conf.run[0].m = 320;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3356832;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(39);
  layer.name = "inc4e_out3";
  layer.type = LT_CONV;
  layer.input_offs = 451264;
  layer.output_offs = 865216;
  layer.output_size = 125440;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 160;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 320;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_39

//Layer_40: Convolution Layer
//  ->: inc4e_proj5
//  ->: inc4e_proj5_relu
void CInspectionDemoGoogLeNet::Layer_40() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(40).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 244288;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4e_proj5
  //->: inc4e_proj5_relu
  conf.run[0].m = 32;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3818784;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(40);
  layer.name = "inc4e_proj5";
  layer.type = LT_CONV;
  layer.input_offs = 244288;
  layer.output_offs = 0;
  layer.output_size = 12544;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 32;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_40

//Layer_41: Convolution Layer
//  ->: inc4e_out5
void CInspectionDemoGoogLeNet::Layer_41() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(41).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 32;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 990656;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4e_out5
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x5;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3840096;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(41);
  layer.name = "inc4e_out5";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 990656;
  layer.output_size = 50176;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 32;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_41

//Layer_42: Convolution Layer
//  ->: max_pooling2d_10
void CInspectionDemoGoogLeNet::Layer_42() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(42).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 244288;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 451264;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: max_pooling2d_10
  conf.run[0].m = 528;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3988320;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(42);
  layer.name = "max_pooling2d_10";
  layer.type = LT_CONV;
  layer.input_offs = 244288;
  layer.output_offs = 451264;
  layer.output_size = 206976;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 528;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_42

//Layer_43: Convolution Layer
//  ->: inc4e_pool
void CInspectionDemoGoogLeNet::Layer_43() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(43).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 451264;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1040832;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4e_pool
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3988320;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(43);
  layer.name = "inc4e_pool";
  layer.type = LT_CONV;
  layer.input_offs = 451264;
  layer.output_offs = 1040832;
  layer.output_size = 50176;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_43

//Layer_44: Concatenate Layer
//	->: concatenate_7
void CInspectionDemoGoogLeNet::Layer_44() {
  fpga_layer& layer = get_layer(44);
  layer.name = "concatenate_7";
  layer.type = LT_CONCAT;
  layer.input_offs = 764864;
  layer.output_offs = 764864;
  layer.output_size = 326144;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 832;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_44

//Layer_45: Convolution Layer
//  ->: inc4e_concat
//  ->: inc4e_concat
//  ->: max_pooling2d_11
void CInspectionDemoGoogLeNet::Layer_45() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(45).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 764864;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 683328;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc4e_concat
  //->: inc4e_concat
  //->: max_pooling2d_11
  conf.run[0].m = 832;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4072032;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(45);
  layer.name = "max_pooling2d_11";
  layer.type = LT_CONV;
  layer.input_offs = 764864;
  layer.output_offs = 683328;
  layer.output_size = 81536;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 832;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_45

//Layer_46: Convolution Layer
//  ->: inc5a_out1
//  ->: inc5a_out1_relu
void CInspectionDemoGoogLeNet::Layer_46() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(46).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 683328;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 532800;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5a_out1
  //->: inc5a_out1_relu
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4134112;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(46);
  layer.name = "inc5a_out1";
  layer.type = LT_CONV;
  layer.input_offs = 683328;
  layer.output_offs = 532800;
  layer.output_size = 25088;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_46

//Layer_47: Convolution Layer
//  ->: inc5a_proj3
//  ->: inc5a_proj3_relu
void CInspectionDemoGoogLeNet::Layer_47() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(47).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 683328;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5a_proj3
  //->: inc5a_proj3_relu
  conf.run[0].m = 160;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4374752;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(47);
  layer.name = "inc5a_proj3";
  layer.type = LT_CONV;
  layer.input_offs = 683328;
  layer.output_offs = 0;
  layer.output_size = 15680;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 160;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_47

//Layer_48: Convolution Layer
//  ->: inc5a_out3
void CInspectionDemoGoogLeNet::Layer_48() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(48).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 160;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 557888;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5a_out3
  conf.run[0].m = 320;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4525344;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(48);
  layer.name = "inc5a_out3";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 557888;
  layer.output_size = 31360;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 160;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 320;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_48

//Layer_49: Convolution Layer
//  ->: inc5a_proj5
//  ->: inc5a_proj5_relu
void CInspectionDemoGoogLeNet::Layer_49() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(49).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 683328;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5a_proj5
  //->: inc5a_proj5_relu
  conf.run[0].m = 32;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4987296;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(49);
  layer.name = "inc5a_proj5";
  layer.type = LT_CONV;
  layer.input_offs = 683328;
  layer.output_offs = 0;
  layer.output_size = 3136;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 32;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_49

//Layer_50: Convolution Layer
//  ->: inc5a_out5
void CInspectionDemoGoogLeNet::Layer_50() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(50).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 32;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 589248;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5a_out5
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x5;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5017824;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(50);
  layer.name = "inc5a_out5";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 589248;
  layer.output_size = 12544;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 32;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_50

//Layer_51: Convolution Layer
//  ->: max_pooling2d_12
void CInspectionDemoGoogLeNet::Layer_51() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(51).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 683328;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 451264;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: max_pooling2d_12
  conf.run[0].m = 832;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5166048;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(51);
  layer.name = "max_pooling2d_12";
  layer.type = LT_CONV;
  layer.input_offs = 683328;
  layer.output_offs = 451264;
  layer.output_size = 81536;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 832;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_51

//Layer_52: Convolution Layer
//  ->: inc5a_pool
void CInspectionDemoGoogLeNet::Layer_52() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(52).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 451264;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 601792;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5a_pool
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5166048;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(52);
  layer.name = "inc5a_pool";
  layer.type = LT_CONV;
  layer.input_offs = 451264;
  layer.output_offs = 601792;
  layer.output_size = 12544;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_52

//Layer_53: Concatenate Layer
//	->: concatenate_8
void CInspectionDemoGoogLeNet::Layer_53() {
  fpga_layer& layer = get_layer(53);
  layer.name = "concatenate_8";
  layer.type = LT_CONCAT;
  layer.input_offs = 532800;
  layer.output_offs = 532800;
  layer.output_size = 81536;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 832;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_53

//Layer_54: Convolution Layer
//  ->: inc5a_concat
//  ->: inc5a_concat
void CInspectionDemoGoogLeNet::Layer_54() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(54).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 532800;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 451264;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5a_concat
  //->: inc5a_concat
  conf.run[0].m = 832;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5286624;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(54);
  layer.name = "inc5a_concat";
  layer.type = LT_CONV;
  layer.input_offs = 532800;
  layer.output_offs = 451264;
  layer.output_size = 81536;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 832;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_54

//Layer_55: Convolution Layer
//  ->: inc5b_out1
//  ->: inc5b_out1_relu
//  ->: inc5b_proj3
//  ->: inc5b_proj3_relu
//  ->: inc5b_out3
//  ->: inc5b_proj5
//  ->: inc5b_proj5_relu
//  ->: inc5b_out5
//  ->: max_pooling2d_13
//  ->: inc5b_pool
void CInspectionDemoGoogLeNet::Layer_55() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(55).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000001010101
  conf.topo = 0x55;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 832;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 451264;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 551616;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->7 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5b_out1
  //->: inc5b_out1_relu
  conf.run[0].m = 384;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5348704;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 1
  //--------------------------------------------------
  //->: inc5b_proj3
  //->: inc5b_proj3_relu
  conf.run[1].m = 192;  // Output Channels
  conf.run[1].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[1].p = 0x1;  // Filter Width and Height
  conf.run[1].pz = 1;  // Filter Depth
  conf.run[1].weight_buf.mem = weights_mem_;
  conf.run[1].weight_buf.offs = 5709408;
  conf.run[1].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[1].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[1].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[1].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[1].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[1].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[1].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[1].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[1].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[1].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 2
  //--------------------------------------------------
  //->: inc5b_out3
  conf.run[2].m = 384;  // Output Channels
  conf.run[2].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[2].p = 0x3;  // Filter Width and Height
  conf.run[2].pz = 1;  // Filter Depth
  conf.run[2].weight_buf.mem = weights_mem_;
  conf.run[2].weight_buf.offs = 5890016;
  conf.run[2].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[2].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[2].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[2].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[2].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[2].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[2].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[2].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[2].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[2].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 3
  //--------------------------------------------------
  //->: inc5b_proj5
  //->: inc5b_proj5_relu
  conf.run[3].m = 48;  // Output Channels
  conf.run[3].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[3].p = 0x1;  // Filter Width and Height
  conf.run[3].pz = 1;  // Filter Depth
  conf.run[3].weight_buf.mem = weights_mem_;
  conf.run[3].weight_buf.offs = 6554848;
  conf.run[3].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[3].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[3].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[3].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[3].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[3].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[3].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[3].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[3].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[3].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 4
  //--------------------------------------------------
  //->: inc5b_out5
  conf.run[4].m = 128;  // Output Channels
  conf.run[4].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[4].p = 0x5;  // Filter Width and Height
  conf.run[4].pz = 1;  // Filter Depth
  conf.run[4].weight_buf.mem = weights_mem_;
  conf.run[4].weight_buf.offs = 6600384;
  conf.run[4].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[4].conv_pad = 0x2020202;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[4].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[4].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[4].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[4].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[4].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[4].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[4].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[4].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 5
  //--------------------------------------------------
  //->: max_pooling2d_13
  conf.run[5].m = 832;  // Output Channels
  conf.run[5].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[5].p = 0x1;  // Filter Width and Height
  conf.run[5].pz = 1;  // Filter Depth
  conf.run[5].weight_buf.mem = weights_mem_;
  conf.run[5].weight_buf.offs = 6822336;
  conf.run[5].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[5].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[5].pool_enable = 1;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[5].pool_size = 0x303;  // bits [7:0] = width, bits [15:8] = height
  conf.run[5].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[5].pool_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[5].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[5].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[5].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[5].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)
  //--------------------------------------------------
  //RUN : 6
  //--------------------------------------------------
  //->: inc5b_pool
  conf.run[6].m = 128;  // Output Channels
  conf.run[6].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[6].p = 0x1;  // Filter Width and Height
  conf.run[6].pz = 1;  // Filter Depth
  conf.run[6].weight_buf.mem = weights_mem_;
  conf.run[6].weight_buf.offs = 6822336;
  conf.run[6].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[6].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[6].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[6].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[6].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[6].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[6].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[6].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[6].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[6].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(55);
  layer.name = "concatenate_9";
  layer.type = LT_CONV;
  layer.input_offs = 451264;
  layer.output_offs = 551616;
  layer.output_size = 100352;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 832;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_55

//Layer_56: Convolution Layer
//  ->: inc5b_concat
//  ->: inc5b_concat
void CInspectionDemoGoogLeNet::Layer_56() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(56).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 551616;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 451264;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: inc5b_concat
  //->: inc5b_concat
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 6942912;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(56);
  layer.name = "inc5b_concat";
  layer.type = LT_CONV;
  layer.input_offs = 551616;
  layer.output_offs = 451264;
  layer.output_size = 100352;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_56

//Layer_57: Convolution Layer
//  ->: average_pooling2d_3
void CInspectionDemoGoogLeNet::Layer_57() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(57).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 451264;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 16;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: average_pooling2d_3
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7019200;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x707;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x2539;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(57);
  layer.name = "flatten_3";
  layer.type = LT_CONV;
  layer.input_offs = 451264;
  layer.output_offs = 16;
  layer.output_size = 2048;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1024;
  layer.output_dim_size = 1;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_57

//Layer_58: Convolution Layer
//  ->: loss3_dence
void CInspectionDemoGoogLeNet::Layer_58() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(58).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 1;  // Input Width
  conf.h = 1;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 16;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: loss3_dence
  conf.run[0].m = 2;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7019200;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(58);
  layer.name = "loss3_dence";
  layer.type = LT_CONV;
  layer.input_offs = 16;
  layer.output_offs = 0;
  layer.output_size = 4;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_58

//Layer_59: SoftMax Layer
//	->: loss3
void CInspectionDemoGoogLeNet::Layer_59() {
  fpga_layer& layer = get_layer(59);
  layer.name = "loss3";
  layer.type = LT_SOFTMAX;
  layer.input_offs = 0;
  layer.output_offs = 48;
  layer.output_size = 4;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 2;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2;
  layer.output_dim_size = 3;
  layer.is_output = true;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
  layer.softmax_axis = 2;
  output_layers_[0] = &layer;
}//end of  Layer_59

//Layer_60: Convolution Layer
//  ->: average_pooling2d_2
void CInspectionDemoGoogLeNet::Layer_60() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(60).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 244288;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 227392;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: average_pooling2d_2
  conf.run[0].m = 528;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7022032;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x505;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x303;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x291F;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(60);
  layer.name = "average_pooling2d_2";
  layer.type = LT_CONV;
  layer.input_offs = 244288;
  layer.output_offs = 227392;
  layer.output_size = 16896;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 4;
  layer.output_dim[1] = 4;
  layer.output_dim[2] = 528;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_60

//Layer_61: Convolution Layer
//  ->: loss2_conv1
//  ->: loss2_conv1_relu
void CInspectionDemoGoogLeNet::Layer_61() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(61).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 4;  // Input Width
  conf.h = 4;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 528;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 227392;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 6208;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: loss2_conv1
  //->: loss2_conv1_relu
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7022032;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(61);
  layer.name = "loss2_conv1";
  layer.type = LT_CONV;
  layer.input_offs = 227392;
  layer.output_offs = 6208;
  layer.output_size = 4096;
  layer.input_dim[0] = 4;
  layer.input_dim[1] = 4;
  layer.input_dim[2] = 528;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 4;
  layer.output_dim[1] = 4;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_61

//Layer_62: Flatten Layer
//	->: flatten_2
void CInspectionDemoGoogLeNet::Layer_62() {
  fpga_layer& layer = get_layer(62);
  layer.name = "flatten_2";
  layer.type = LT_FLATTEN;
  layer.input_offs = 6208;
  layer.output_offs = 2112;
  layer.output_size = 4096;
  layer.input_dim[0] = 4;
  layer.input_dim[1] = 4;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 2048;
  layer.output_dim_size = 1;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_62

//Layer_63: Convolution Layer
//  ->: loss2_dence1
//  ->: loss2_dence1_relu
void CInspectionDemoGoogLeNet::Layer_63() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(63).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 1;  // Input Width
  conf.h = 1;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 2112;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 64;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: loss2_dence1
  //->: loss2_dence1_relu
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7105744;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(63);
  layer.name = "loss2_dence1";
  layer.type = LT_CONV;
  layer.input_offs = 2112;
  layer.output_offs = 64;
  layer.output_size = 2048;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = false;
}//end of  Layer_63

//Layer_64: Convolution Layer
//  ->: loss2_dence2
void CInspectionDemoGoogLeNet::Layer_64() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(64).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 1;  // Input Width
  conf.h = 1;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 64;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: loss2_dence2
  conf.run[0].m = 2;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9467600;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(64);
  layer.name = "loss2_dence2";
  layer.type = LT_CONV;
  layer.input_offs = 64;
  layer.output_offs = 0;
  layer.output_size = 4;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_64

//Layer_65: SoftMax Layer
//	->: loss2
void CInspectionDemoGoogLeNet::Layer_65() {
  fpga_layer& layer = get_layer(65);
  layer.name = "loss2";
  layer.type = LT_SOFTMAX;
  layer.input_offs = 0;
  layer.output_offs = 32;
  layer.output_size = 4;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 2;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2;
  layer.output_dim_size = 3;
  layer.is_output = true;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
  layer.softmax_axis = 2;
  output_layers_[1] = &layer;
}//end of  Layer_65

//Layer_66: Convolution Layer
//  ->: average_pooling2d_1
void CInspectionDemoGoogLeNet::Layer_66() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(66).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 26688;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 10304;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: average_pooling2d_1
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9470432;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x505;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x303;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x291F;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(66);
  layer.name = "average_pooling2d_1";
  layer.type = LT_CONV;
  layer.input_offs = 26688;
  layer.output_offs = 10304;
  layer.output_size = 16384;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 4;
  layer.output_dim[1] = 4;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_66

//Layer_67: Convolution Layer
//  ->: loss1_conv1
//  ->: loss1_conv1_relu
void CInspectionDemoGoogLeNet::Layer_67() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(67).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 4;  // Input Width
  conf.h = 4;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 10304;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 6208;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: loss1_conv1
  //->: loss1_conv1_relu
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9470432;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(67);
  layer.name = "loss1_conv1";
  layer.type = LT_CONV;
  layer.input_offs = 10304;
  layer.output_offs = 6208;
  layer.output_size = 4096;
  layer.input_dim[0] = 4;
  layer.input_dim[1] = 4;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 4;
  layer.output_dim[1] = 4;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_67

//Layer_68: Flatten Layer
//	->: flatten_1
void CInspectionDemoGoogLeNet::Layer_68() {
  fpga_layer& layer = get_layer(68);
  layer.name = "flatten_1";
  layer.type = LT_FLATTEN;
  layer.input_offs = 6208;
  layer.output_offs = 2112;
  layer.output_size = 4096;
  layer.input_dim[0] = 4;
  layer.input_dim[1] = 4;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 2048;
  layer.output_dim_size = 1;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_68

//Layer_69: Convolution Layer
//  ->: loss1_dense1
//  ->: loss1_dense1_relu
void CInspectionDemoGoogLeNet::Layer_69() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(69).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 1;  // Input Width
  conf.h = 1;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 2112;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 64;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: loss1_dense1
  //->: loss1_dense1_relu
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9544928;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(69);
  layer.name = "loss1_dense1";
  layer.type = LT_CONV;
  layer.input_offs = 2112;
  layer.output_offs = 64;
  layer.output_size = 2048;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = false;
}//end of  Layer_69

//Layer_70: Convolution Layer
//  ->: loss1_dense2
void CInspectionDemoGoogLeNet::Layer_70() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(70).conv_conf_v1;
  conf_v1.header.size = sizeof(conf_v1);
  conf_v1.header.device_type = DMP_DV_DEV_CONV;
  conf_v1.header.version = 1;
  dmp_dv_cmdraw_conv_v0& conf = conf_v1.conv_cmd;
  conf.header.size = sizeof(conf);
  conf.header.device_type = DMP_DV_DEV_CONV;
  conf.header.version = 0;
  // Topo: 00000000000000000000000000000001
  conf.topo = 0x1;  // [31:0] Output Destination of each run, 0 = UBUF, 1 = EXTMEM

  // Input Configuration:
  conf.w = 1;  // Input Width
  conf.h = 1;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 64;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 16;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: loss1_dense2
  conf.run[0].m = 2;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 11906784;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(70);
  layer.name = "loss1_dense2";
  layer.type = LT_CONV;
  layer.input_offs = 64;
  layer.output_offs = 16;
  layer.output_size = 4;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_70

//Layer_71: SoftMax Layer
//	->: loss1
void CInspectionDemoGoogLeNet::Layer_71() {
  fpga_layer& layer = get_layer(71);
  layer.name = "loss1";
  layer.type = LT_SOFTMAX;
  layer.input_offs = 16;
  layer.output_offs = 0;
  layer.output_size = 4;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 2;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2;
  layer.output_dim_size = 3;
  layer.is_output = true;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
  layer.softmax_axis = 2;
  output_layers_[2] = &layer;
}//end of  Layer_71

