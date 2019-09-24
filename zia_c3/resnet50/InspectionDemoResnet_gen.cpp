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

#include "InspectionDemoResnet_gen.h"


CInspectionDemoResnet::CInspectionDemoResnet() {
  // Empty by design
}

CInspectionDemoResnet::~CInspectionDemoResnet() {
  // Empty by design
}

bool CInspectionDemoResnet::Initialize() {
  is_weight_transposed = true;  // The weight matrix is transposed.
  if (!ReserveMemory(26186640, 4646400)) {
    return false;
  }

  set_num_layers(88);
  set_num_output_layers(1);

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
  Layer_72();
  Layer_73();
  Layer_74();
  Layer_75();
  Layer_76();
  Layer_77();
  Layer_78();
  Layer_79();
  Layer_80();
  Layer_81();
  Layer_82();
  Layer_83();
  Layer_84();
  Layer_85();
  Layer_86();
  Layer_87();

  return true;
}

//Layer_0: Convolution Layer
//  ->: conv1
//  ->: bn_conv1
//  ->: bn_conv1
//  ->: activation_1
//  ->: max_pooling2d_1
void CInspectionDemoResnet::Layer_0() {
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
  conf.input_buf.offs = 387200;

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
  //->: bn_conv1
  //->: bn_conv1
  //->: activation_1
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
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(0);
  layer.name = "max_pooling2d_1";
  layer.type = LT_CONV;
  layer.input_offs = 387200;
  layer.output_offs = 0;
  layer.output_size = 387200;
  layer.input_dim[0] = 224;
  layer.input_dim[1] = 224;
  layer.input_dim[2] = 3;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = false;
}//end of  Layer_0

//Layer_1: Convolution Layer
//  ->: res2a_branch2a
//  ->: bn2a_branch2a
//  ->: bn2a_branch2a
//  ->: activation_2
void CInspectionDemoResnet::Layer_1() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 774400;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2a_branch2a
  //->: bn2a_branch2a
  //->: bn2a_branch2a
  //->: activation_2
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
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
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(1);
  layer.name = "res2a_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 774400;
  layer.output_size = 387200;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_1

//Layer_2: Convolution Layer
//  ->: res2a_branch2b
//  ->: bn2a_branch2b
//  ->: bn2a_branch2b
//  ->: activation_3
void CInspectionDemoResnet::Layer_2() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 774400;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 387200;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2a_branch2b
  //->: bn2a_branch2b
  //->: bn2a_branch2b
  //->: activation_3
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 19712;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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
  layer.name = "res2a_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 774400;
  layer.output_offs = 387200;
  layer.output_size = 387200;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_2

//Layer_3: Convolution Layer
//  ->: res2a_branch2c
//  ->: bn2a_branch2c
//  ->: bn2a_branch2c
void CInspectionDemoResnet::Layer_3() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 387200;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 3097600;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2a_branch2c
  //->: bn2a_branch2c
  //->: bn2a_branch2c
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 57216;
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

  fpga_layer& layer = get_layer(3);
  layer.name = "res2a_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 387200;
  layer.output_offs = 3097600;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_3

//Layer_4: Convolution Layer
//  ->: res2a_branch1
//  ->: bn2a_branch1
//  ->: bn2a_branch1
void CInspectionDemoResnet::Layer_4() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1548800;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2a_branch1
  //->: bn2a_branch1
  //->: bn2a_branch1
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 76672;
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

  fpga_layer& layer = get_layer(4);
  layer.name = "res2a_branch1";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1548800;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_4

//Layer_5: Convolution Layer
//  ->: add_1
void CInspectionDemoResnet::Layer_5() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 3097600;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 1548800;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_1
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 96128;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(5);
  layer.name = "add_1";
  layer.type = LT_CONV;
  layer.input_offs = 3097600;
  layer.output_offs = 0;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_5

//Layer_6: Convolution Layer
//  ->: activation_4
//  ->: activation_4
void CInspectionDemoResnet::Layer_6() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 3097600;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_4
  //->: activation_4
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 96128;
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

  fpga_layer& layer = get_layer(6);
  layer.name = "activation_4";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 3097600;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_6

//Layer_7: Convolution Layer
//  ->: res2b_branch2a
//  ->: bn2b_branch2a
//  ->: bn2b_branch2a
//  ->: activation_5
void CInspectionDemoResnet::Layer_7() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 3097600;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 387200;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2b_branch2a
  //->: bn2b_branch2a
  //->: bn2b_branch2a
  //->: activation_5
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 115584;
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
  layer.name = "res2b_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 3097600;
  layer.output_offs = 387200;
  layer.output_size = 387200;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_7

//Layer_8: Convolution Layer
//  ->: res2b_branch2b
//  ->: bn2b_branch2b
//  ->: bn2b_branch2b
//  ->: activation_6
void CInspectionDemoResnet::Layer_8() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 387200;

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
  //->: res2b_branch2b
  //->: bn2b_branch2b
  //->: bn2b_branch2b
  //->: activation_6
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 134656;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(8);
  layer.name = "res2b_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 387200;
  layer.output_offs = 0;
  layer.output_size = 387200;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_8

//Layer_9: Convolution Layer
//  ->: res2b_branch2c
//  ->: bn2b_branch2c
//  ->: bn2b_branch2c
void CInspectionDemoResnet::Layer_9() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1548800;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2b_branch2c
  //->: bn2b_branch2c
  //->: bn2b_branch2c
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 172160;
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

  fpga_layer& layer = get_layer(9);
  layer.name = "res2b_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1548800;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_9

//Layer_10: Convolution Layer
//  ->: add_2
void CInspectionDemoResnet::Layer_10() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1548800;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 3097600;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_2
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 191616;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(10);
  layer.name = "add_2";
  layer.type = LT_CONV;
  layer.input_offs = 1548800;
  layer.output_offs = 0;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_10

//Layer_11: Convolution Layer
//  ->: activation_7
//  ->: activation_7
void CInspectionDemoResnet::Layer_11() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(11).conv_conf_v1;
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 3097600;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_7
  //->: activation_7
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 191616;
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

  fpga_layer& layer = get_layer(11);
  layer.name = "activation_7";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 3097600;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_11

//Layer_12: Convolution Layer
//  ->: res2c_branch2a
//  ->: bn2c_branch2a
//  ->: bn2c_branch2a
//  ->: activation_8
void CInspectionDemoResnet::Layer_12() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 3097600;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 387200;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2c_branch2a
  //->: bn2c_branch2a
  //->: bn2c_branch2a
  //->: activation_8
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 211072;
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
  layer.name = "res2c_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 3097600;
  layer.output_offs = 387200;
  layer.output_size = 387200;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_12

//Layer_13: Convolution Layer
//  ->: res2c_branch2b
//  ->: bn2c_branch2b
//  ->: bn2c_branch2b
//  ->: activation_9
void CInspectionDemoResnet::Layer_13() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(13).conv_conf_v1;
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 387200;

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
  //->: res2c_branch2b
  //->: bn2c_branch2b
  //->: bn2c_branch2b
  //->: activation_9
  conf.run[0].m = 64;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 230144;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(13);
  layer.name = "res2c_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 387200;
  layer.output_offs = 0;
  layer.output_size = 387200;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 64;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_13

//Layer_14: Convolution Layer
//  ->: res2c_branch2c
//  ->: bn2c_branch2c
//  ->: bn2c_branch2c
void CInspectionDemoResnet::Layer_14() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 64;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1548800;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res2c_branch2c
  //->: bn2c_branch2c
  //->: bn2c_branch2c
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 267648;
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

  fpga_layer& layer = get_layer(14);
  layer.name = "res2c_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1548800;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 64;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_14

//Layer_15: Convolution Layer
//  ->: add_3
void CInspectionDemoResnet::Layer_15() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1548800;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 3097600;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_3
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 287104;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(15);
  layer.name = "add_3";
  layer.type = LT_CONV;
  layer.input_offs = 1548800;
  layer.output_offs = 0;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_15

//Layer_16: Convolution Layer
//  ->: activation_10
//  ->: activation_10
void CInspectionDemoResnet::Layer_16() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 2408448;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_10
  //->: activation_10
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 287104;
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
  layer.name = "activation_10";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 2408448;
  layer.output_size = 1548800;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 55;
  layer.output_dim[1] = 55;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_16

//Layer_17: Convolution Layer
//  ->: res3a_branch2a
//  ->: bn3a_branch2a
//  ->: bn3a_branch2a
//  ->: activation_11
void CInspectionDemoResnet::Layer_17() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 2408448;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 200704;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3a_branch2a
  //->: bn3a_branch2a
  //->: bn3a_branch2a
  //->: activation_11
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 306560;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 2;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(17);
  layer.name = "res3a_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 2408448;
  layer.output_offs = 200704;
  layer.output_size = 200704;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_17

//Layer_18: Convolution Layer
//  ->: res3a_branch2b
//  ->: bn3a_branch2b
//  ->: bn3a_branch2b
//  ->: activation_12
void CInspectionDemoResnet::Layer_18() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 200704;

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
  //->: res3a_branch2b
  //->: bn3a_branch2b
  //->: bn3a_branch2b
  //->: activation_12
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 344192;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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
  layer.name = "res3a_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 200704;
  layer.output_offs = 0;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_18

//Layer_19: Convolution Layer
//  ->: res3a_branch2c
//  ->: bn3a_branch2c
//  ->: bn3a_branch2c
void CInspectionDemoResnet::Layer_19() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1605632;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3a_branch2c
  //->: bn3a_branch2c
  //->: bn3a_branch2c
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 492416;
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

  fpga_layer& layer = get_layer(19);
  layer.name = "res3a_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1605632;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_19

//Layer_20: Convolution Layer
//  ->: res3a_branch1
//  ->: bn3a_branch1
//  ->: bn3a_branch1
void CInspectionDemoResnet::Layer_20() {
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
  conf.w = 55;  // Input Width
  conf.h = 55;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 2408448;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3a_branch1
  //->: bn3a_branch1
  //->: bn3a_branch1
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 567680;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(20);
  layer.name = "res3a_branch1";
  layer.type = LT_CONV;
  layer.input_offs = 2408448;
  layer.output_offs = 802816;
  layer.output_size = 802816;
  layer.input_dim[0] = 55;
  layer.input_dim[1] = 55;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_20

//Layer_21: Convolution Layer
//  ->: add_4
void CInspectionDemoResnet::Layer_21() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1605632;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 802816;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_4
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 716672;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(21);
  layer.name = "add_4";
  layer.type = LT_CONV;
  layer.input_offs = 1605632;
  layer.output_offs = 0;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_21

//Layer_22: Convolution Layer
//  ->: activation_13
//  ->: activation_13
void CInspectionDemoResnet::Layer_22() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(22).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1605632;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_13
  //->: activation_13
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 716672;
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

  fpga_layer& layer = get_layer(22);
  layer.name = "activation_13";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1605632;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_22

//Layer_23: Convolution Layer
//  ->: res3b_branch2a
//  ->: bn3b_branch2a
//  ->: bn3b_branch2a
//  ->: activation_14
void CInspectionDemoResnet::Layer_23() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1605632;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 200704;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3b_branch2a
  //->: bn3b_branch2a
  //->: bn3b_branch2a
  //->: activation_14
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 755072;
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
  layer.name = "res3b_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 1605632;
  layer.output_offs = 200704;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_23

//Layer_24: Convolution Layer
//  ->: res3b_branch2b
//  ->: bn3b_branch2b
//  ->: bn3b_branch2b
//  ->: activation_15
void CInspectionDemoResnet::Layer_24() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 200704;

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
  //->: res3b_branch2b
  //->: bn3b_branch2b
  //->: bn3b_branch2b
  //->: activation_15
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 829568;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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
  layer.name = "res3b_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 200704;
  layer.output_offs = 0;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_24

//Layer_25: Convolution Layer
//  ->: res3b_branch2c
//  ->: bn3b_branch2c
//  ->: bn3b_branch2c
void CInspectionDemoResnet::Layer_25() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3b_branch2c
  //->: bn3b_branch2c
  //->: bn3b_branch2c
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 977792;
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

  fpga_layer& layer = get_layer(25);
  layer.name = "res3b_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_25

//Layer_26: Convolution Layer
//  ->: add_5
void CInspectionDemoResnet::Layer_26() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 1605632;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_5
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1053056;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(26);
  layer.name = "add_5";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 0;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_26

//Layer_27: Convolution Layer
//  ->: activation_16
//  ->: activation_16
void CInspectionDemoResnet::Layer_27() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1605632;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_16
  //->: activation_16
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1053056;
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
  layer.name = "activation_16";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1605632;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_27

//Layer_28: Convolution Layer
//  ->: res3c_branch2a
//  ->: bn3c_branch2a
//  ->: bn3c_branch2a
//  ->: activation_17
void CInspectionDemoResnet::Layer_28() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1605632;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 200704;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3c_branch2a
  //->: bn3c_branch2a
  //->: bn3c_branch2a
  //->: activation_17
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1091456;
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

  fpga_layer& layer = get_layer(28);
  layer.name = "res3c_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 1605632;
  layer.output_offs = 200704;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_28

//Layer_29: Convolution Layer
//  ->: res3c_branch2b
//  ->: bn3c_branch2b
//  ->: bn3c_branch2b
//  ->: activation_18
void CInspectionDemoResnet::Layer_29() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 200704;

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
  //->: res3c_branch2b
  //->: bn3c_branch2b
  //->: bn3c_branch2b
  //->: activation_18
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1165952;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(29);
  layer.name = "res3c_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 200704;
  layer.output_offs = 0;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_29

//Layer_30: Convolution Layer
//  ->: res3c_branch2c
//  ->: bn3c_branch2c
//  ->: bn3c_branch2c
void CInspectionDemoResnet::Layer_30() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3c_branch2c
  //->: bn3c_branch2c
  //->: bn3c_branch2c
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1314176;
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
  layer.name = "res3c_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_30

//Layer_31: Convolution Layer
//  ->: add_6
void CInspectionDemoResnet::Layer_31() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(31).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 1605632;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_6
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1389440;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(31);
  layer.name = "add_6";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 0;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_31

//Layer_32: Convolution Layer
//  ->: activation_19
//  ->: activation_19
void CInspectionDemoResnet::Layer_32() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1605632;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_19
  //->: activation_19
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1389440;
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
  layer.name = "activation_19";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1605632;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_32

//Layer_33: Convolution Layer
//  ->: res3d_branch2a
//  ->: bn3d_branch2a
//  ->: bn3d_branch2a
//  ->: activation_20
void CInspectionDemoResnet::Layer_33() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(33).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1605632;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 200704;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3d_branch2a
  //->: bn3d_branch2a
  //->: bn3d_branch2a
  //->: activation_20
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1427840;
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

  fpga_layer& layer = get_layer(33);
  layer.name = "res3d_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 1605632;
  layer.output_offs = 200704;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_33

//Layer_34: Convolution Layer
//  ->: res3d_branch2b
//  ->: bn3d_branch2b
//  ->: bn3d_branch2b
//  ->: activation_21
void CInspectionDemoResnet::Layer_34() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 200704;

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
  //->: res3d_branch2b
  //->: bn3d_branch2b
  //->: bn3d_branch2b
  //->: activation_21
  conf.run[0].m = 128;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1502336;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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
  layer.name = "res3d_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 200704;
  layer.output_offs = 0;
  layer.output_size = 200704;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 128;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_34

//Layer_35: Convolution Layer
//  ->: res3d_branch2c
//  ->: bn3d_branch2c
//  ->: bn3d_branch2c
void CInspectionDemoResnet::Layer_35() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(35).conv_conf_v1;
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
  conf.c = 128;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res3d_branch2c
  //->: bn3d_branch2c
  //->: bn3d_branch2c
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1650560;
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

  fpga_layer& layer = get_layer(35);
  layer.name = "res3d_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 128;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_35

//Layer_36: Convolution Layer
//  ->: add_7
void CInspectionDemoResnet::Layer_36() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 1605632;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_7
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1725824;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(36);
  layer.name = "add_7";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 0;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_36

//Layer_37: Convolution Layer
//  ->: activation_22
//  ->: activation_22
void CInspectionDemoResnet::Layer_37() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 1204224;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_22
  //->: activation_22
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1725824;
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
  layer.name = "activation_22";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 1204224;
  layer.output_size = 802816;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 28;
  layer.output_dim[1] = 28;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_37

//Layer_38: Convolution Layer
//  ->: res4a_branch2a
//  ->: bn4a_branch2a
//  ->: bn4a_branch2a
//  ->: activation_23
void CInspectionDemoResnet::Layer_38() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1204224;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 100352;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res4a_branch2a
  //->: bn4a_branch2a
  //->: bn4a_branch2a
  //->: activation_23
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1764224;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
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
  layer.name = "res4a_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 1204224;
  layer.output_offs = 100352;
  layer.output_size = 100352;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_38

//Layer_39: Convolution Layer
//  ->: res4a_branch2b
//  ->: bn4a_branch2b
//  ->: bn4a_branch2b
//  ->: activation_24
void CInspectionDemoResnet::Layer_39() {
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
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 100352;

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
  //->: res4a_branch2b
  //->: bn4a_branch2b
  //->: bn4a_branch2b
  //->: activation_24
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 1912704;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(39);
  layer.name = "res4a_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 100352;
  layer.output_offs = 0;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_39

//Layer_40: Convolution Layer
//  ->: res4a_branch2c
//  ->: bn4a_branch2c
//  ->: bn4a_branch2c
void CInspectionDemoResnet::Layer_40() {
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
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res4a_branch2c
  //->: bn4a_branch2c
  //->: bn4a_branch2c
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 2503552;
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

  fpga_layer& layer = get_layer(40);
  layer.name = "res4a_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_40

//Layer_41: Convolution Layer
//  ->: res4a_branch1
//  ->: bn4a_branch1
//  ->: bn4a_branch1
void CInspectionDemoResnet::Layer_41() {
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
  conf.w = 28;  // Input Width
  conf.h = 28;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 1204224;

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
  //->: res4a_branch1
  //->: bn4a_branch1
  //->: bn4a_branch1
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 2801024;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
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
  layer.name = "res4a_branch1";
  layer.type = LT_CONV;
  layer.input_offs = 1204224;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 28;
  layer.input_dim[1] = 28;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_41

//Layer_42: Convolution Layer
//  ->: add_8
void CInspectionDemoResnet::Layer_42() {
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 401408;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_8
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3393408;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(42);
  layer.name = "add_8";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_42

//Layer_43: Convolution Layer
//  ->: activation_25
//  ->: activation_25
void CInspectionDemoResnet::Layer_43() {
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_25
  //->: activation_25
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3393408;
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

  fpga_layer& layer = get_layer(43);
  layer.name = "activation_25";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_43

//Layer_44: Convolution Layer
//  ->: res4b_branch2a
//  ->: bn4b_branch2a
//  ->: bn4b_branch2a
//  ->: activation_26
void CInspectionDemoResnet::Layer_44() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(44).conv_conf_v1;
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 100352;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res4b_branch2a
  //->: bn4b_branch2a
  //->: bn4b_branch2a
  //->: activation_26
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3469696;
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

  fpga_layer& layer = get_layer(44);
  layer.name = "res4b_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 100352;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_44

//Layer_45: Convolution Layer
//  ->: res4b_branch2b
//  ->: bn4b_branch2b
//  ->: bn4b_branch2b
//  ->: activation_27
void CInspectionDemoResnet::Layer_45() {
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
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 100352;

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
  //->: res4b_branch2b
  //->: bn4b_branch2b
  //->: bn4b_branch2b
  //->: activation_27
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 3765632;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(45);
  layer.name = "res4b_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 100352;
  layer.output_offs = 0;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_45

//Layer_46: Convolution Layer
//  ->: res4b_branch2c
//  ->: bn4b_branch2c
//  ->: bn4b_branch2c
void CInspectionDemoResnet::Layer_46() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
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
  //->: res4b_branch2c
  //->: bn4b_branch2c
  //->: bn4b_branch2c
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4356480;
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

  fpga_layer& layer = get_layer(46);
  layer.name = "res4b_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_46

//Layer_47: Convolution Layer
//  ->: add_9
void CInspectionDemoResnet::Layer_47() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 802816;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_9
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4653952;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(47);
  layer.name = "add_9";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_47

//Layer_48: Convolution Layer
//  ->: activation_28
//  ->: activation_28
void CInspectionDemoResnet::Layer_48() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_28
  //->: activation_28
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4653952;
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

  fpga_layer& layer = get_layer(48);
  layer.name = "activation_28";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_48

//Layer_49: Convolution Layer
//  ->: res4c_branch2a
//  ->: bn4c_branch2a
//  ->: bn4c_branch2a
//  ->: activation_29
void CInspectionDemoResnet::Layer_49() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 100352;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res4c_branch2a
  //->: bn4c_branch2a
  //->: bn4c_branch2a
  //->: activation_29
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 4730240;
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
  layer.name = "res4c_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 100352;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_49

//Layer_50: Convolution Layer
//  ->: res4c_branch2b
//  ->: bn4c_branch2b
//  ->: bn4c_branch2b
//  ->: activation_30
void CInspectionDemoResnet::Layer_50() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 100352;

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
  //->: res4c_branch2b
  //->: bn4c_branch2b
  //->: bn4c_branch2b
  //->: activation_30
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5026176;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(50);
  layer.name = "res4c_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 100352;
  layer.output_offs = 0;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_50

//Layer_51: Convolution Layer
//  ->: res4c_branch2c
//  ->: bn4c_branch2c
//  ->: bn4c_branch2c
void CInspectionDemoResnet::Layer_51() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
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
  //->: res4c_branch2c
  //->: bn4c_branch2c
  //->: bn4c_branch2c
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5617024;
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

  fpga_layer& layer = get_layer(51);
  layer.name = "res4c_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_51

//Layer_52: Convolution Layer
//  ->: add_10
void CInspectionDemoResnet::Layer_52() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 802816;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_10
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5914496;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(52);
  layer.name = "add_10";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_52

//Layer_53: Convolution Layer
//  ->: activation_31
//  ->: activation_31
void CInspectionDemoResnet::Layer_53() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(53).conv_conf_v1;
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_31
  //->: activation_31
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5914496;
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

  fpga_layer& layer = get_layer(53);
  layer.name = "activation_31";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_53

//Layer_54: Convolution Layer
//  ->: res4d_branch2a
//  ->: bn4d_branch2a
//  ->: bn4d_branch2a
//  ->: activation_32
void CInspectionDemoResnet::Layer_54() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 100352;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res4d_branch2a
  //->: bn4d_branch2a
  //->: bn4d_branch2a
  //->: activation_32
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 5990784;
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
  layer.name = "res4d_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 100352;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_54

//Layer_55: Convolution Layer
//  ->: res4d_branch2b
//  ->: bn4d_branch2b
//  ->: bn4d_branch2b
//  ->: activation_33
void CInspectionDemoResnet::Layer_55() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(55).conv_conf_v1;
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
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 100352;

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
  //->: res4d_branch2b
  //->: bn4d_branch2b
  //->: bn4d_branch2b
  //->: activation_33
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 6286720;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(55);
  layer.name = "res4d_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 100352;
  layer.output_offs = 0;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_55

//Layer_56: Convolution Layer
//  ->: res4d_branch2c
//  ->: bn4d_branch2c
//  ->: bn4d_branch2c
void CInspectionDemoResnet::Layer_56() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
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
  //->: res4d_branch2c
  //->: bn4d_branch2c
  //->: bn4d_branch2c
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 6877568;
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

  fpga_layer& layer = get_layer(56);
  layer.name = "res4d_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_56

//Layer_57: Convolution Layer
//  ->: add_11
void CInspectionDemoResnet::Layer_57() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 802816;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_11
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7175040;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(57);
  layer.name = "add_11";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_57

//Layer_58: Convolution Layer
//  ->: activation_34
//  ->: activation_34
void CInspectionDemoResnet::Layer_58() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_34
  //->: activation_34
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7175040;
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

  fpga_layer& layer = get_layer(58);
  layer.name = "activation_34";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_58

//Layer_59: Convolution Layer
//  ->: res4e_branch2a
//  ->: bn4e_branch2a
//  ->: bn4e_branch2a
//  ->: activation_35
void CInspectionDemoResnet::Layer_59() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(59).conv_conf_v1;
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 100352;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res4e_branch2a
  //->: bn4e_branch2a
  //->: bn4e_branch2a
  //->: activation_35
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7251328;
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

  fpga_layer& layer = get_layer(59);
  layer.name = "res4e_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 100352;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_59

//Layer_60: Convolution Layer
//  ->: res4e_branch2b
//  ->: bn4e_branch2b
//  ->: bn4e_branch2b
//  ->: activation_36
void CInspectionDemoResnet::Layer_60() {
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
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 100352;

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
  //->: res4e_branch2b
  //->: bn4e_branch2b
  //->: bn4e_branch2b
  //->: activation_36
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 7547264;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(60);
  layer.name = "res4e_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 100352;
  layer.output_offs = 0;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_60

//Layer_61: Convolution Layer
//  ->: res4e_branch2c
//  ->: bn4e_branch2c
//  ->: bn4e_branch2c
void CInspectionDemoResnet::Layer_61() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 256;  // Input Channels
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
  //->: res4e_branch2c
  //->: bn4e_branch2c
  //->: bn4e_branch2c
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 8138112;
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

  fpga_layer& layer = get_layer(61);
  layer.name = "res4e_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_61

//Layer_62: Convolution Layer
//  ->: add_12
void CInspectionDemoResnet::Layer_62() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(62).conv_conf_v1;
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 802816;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_12
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 8435584;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(62);
  layer.name = "add_12";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_62

//Layer_63: Convolution Layer
//  ->: activation_37
//  ->: activation_37
void CInspectionDemoResnet::Layer_63() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 802816;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_37
  //->: activation_37
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 8435584;
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
  layer.name = "activation_37";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 802816;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_63

//Layer_64: Convolution Layer
//  ->: res4f_branch2a
//  ->: bn4f_branch2a
//  ->: bn4f_branch2a
//  ->: activation_38
void CInspectionDemoResnet::Layer_64() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 802816;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 100352;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res4f_branch2a
  //->: bn4f_branch2a
  //->: bn4f_branch2a
  //->: activation_38
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 8511872;
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

  fpga_layer& layer = get_layer(64);
  layer.name = "res4f_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 802816;
  layer.output_offs = 100352;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_64

//Layer_65: Convolution Layer
//  ->: res4f_branch2b
//  ->: bn4f_branch2b
//  ->: bn4f_branch2b
//  ->: activation_39
void CInspectionDemoResnet::Layer_65() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(65).conv_conf_v1;
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
  conf.c = 256;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 100352;

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
  //->: res4f_branch2b
  //->: bn4f_branch2b
  //->: bn4f_branch2b
  //->: activation_39
  conf.run[0].m = 256;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 8807808;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(65);
  layer.name = "res4f_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 100352;
  layer.output_offs = 0;
  layer.output_size = 100352;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 256;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_65

//Layer_66: Convolution Layer
//  ->: res4f_branch2c
//  ->: bn4f_branch2c
//  ->: bn4f_branch2c
void CInspectionDemoResnet::Layer_66() {
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
  conf.c = 256;  // Input Channels
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
  //->: res4f_branch2c
  //->: bn4f_branch2c
  //->: bn4f_branch2c
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9398656;
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

  fpga_layer& layer = get_layer(66);
  layer.name = "res4f_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 256;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_66

//Layer_67: Convolution Layer
//  ->: add_13
void CInspectionDemoResnet::Layer_67() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 802816;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_13
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9696128;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(67);
  layer.name = "add_13";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_67

//Layer_68: Convolution Layer
//  ->: activation_40
//  ->: activation_40
void CInspectionDemoResnet::Layer_68() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(68).conv_conf_v1;
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 602112;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_40
  //->: activation_40
  conf.run[0].m = 1024;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9696128;
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

  fpga_layer& layer = get_layer(68);
  layer.name = "activation_40";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 602112;
  layer.output_size = 401408;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 14;
  layer.output_dim[1] = 14;
  layer.output_dim[2] = 1024;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_68

//Layer_69: Convolution Layer
//  ->: res5a_branch2a
//  ->: bn5a_branch2a
//  ->: bn5a_branch2a
//  ->: activation_41
void CInspectionDemoResnet::Layer_69() {
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
  conf.w = 14;  // Input Width
  conf.h = 14;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 602112;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 50176;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res5a_branch2a
  //->: bn5a_branch2a
  //->: bn5a_branch2a
  //->: activation_41
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 9772416;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
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
  layer.name = "res5a_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 602112;
  layer.output_offs = 50176;
  layer.output_size = 50176;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_69

//Layer_70: Convolution Layer
//  ->: res5a_branch2b
//  ->: bn5a_branch2b
//  ->: bn5a_branch2b
//  ->: activation_42
void CInspectionDemoResnet::Layer_70() {
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
  conf.w = 7;  // Input Width
  conf.h = 7;  // Input Height
  conf.z = 1;  // Input Depth
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 50176;

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
  //->: res5a_branch2b
  //->: bn5a_branch2b
  //->: bn5a_branch2b
  //->: activation_42
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 10363776;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(70);
  layer.name = "res5a_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 50176;
  layer.output_offs = 0;
  layer.output_size = 50176;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_70

//Layer_71: Convolution Layer
//  ->: res5a_branch2c
//  ->: bn5a_branch2c
//  ->: bn5a_branch2c
void CInspectionDemoResnet::Layer_71() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(71).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
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
  //->: res5a_branch2c
  //->: bn5a_branch2c
  //->: bn5a_branch2c
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 12724608;
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

  fpga_layer& layer = get_layer(71);
  layer.name = "res5a_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_71

//Layer_72: Convolution Layer
//  ->: res5a_branch1
//  ->: bn5a_branch1
//  ->: bn5a_branch1
void CInspectionDemoResnet::Layer_72() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(72).conv_conf_v1;
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
  conf.c = 1024;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 602112;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 200704;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res5a_branch1
  //->: bn5a_branch1
  //->: bn5a_branch1
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 13908864;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x202;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 0;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x0;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x0;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(72);
  layer.name = "res5a_branch1";
  layer.type = LT_CONV;
  layer.input_offs = 602112;
  layer.output_offs = 200704;
  layer.output_size = 200704;
  layer.input_dim[0] = 14;
  layer.input_dim[1] = 14;
  layer.input_dim[2] = 1024;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_72

//Layer_73: Convolution Layer
//  ->: add_14
void CInspectionDemoResnet::Layer_73() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(73).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 200704;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_14
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 16272768;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(73);
  layer.name = "add_14";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 0;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_73

//Layer_74: Convolution Layer
//  ->: activation_43
//  ->: activation_43
void CInspectionDemoResnet::Layer_74() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(74).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
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
  //->: activation_43
  //->: activation_43
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 16272768;
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

  fpga_layer& layer = get_layer(74);
  layer.name = "activation_43";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 401408;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_74

//Layer_75: Convolution Layer
//  ->: res5b_branch2a
//  ->: bn5b_branch2a
//  ->: bn5b_branch2a
//  ->: activation_44
void CInspectionDemoResnet::Layer_75() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(75).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 401408;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 50176;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res5b_branch2a
  //->: bn5b_branch2a
  //->: bn5b_branch2a
  //->: activation_44
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 16424832;
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

  fpga_layer& layer = get_layer(75);
  layer.name = "res5b_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 401408;
  layer.output_offs = 50176;
  layer.output_size = 50176;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_75

//Layer_76: Convolution Layer
//  ->: res5b_branch2b
//  ->: bn5b_branch2b
//  ->: bn5b_branch2b
//  ->: activation_45
void CInspectionDemoResnet::Layer_76() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(76).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 50176;

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
  //->: res5b_branch2b
  //->: bn5b_branch2b
  //->: bn5b_branch2b
  //->: activation_45
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 17606016;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(76);
  layer.name = "res5b_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 50176;
  layer.output_offs = 0;
  layer.output_size = 50176;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_76

//Layer_77: Convolution Layer
//  ->: res5b_branch2c
//  ->: bn5b_branch2c
//  ->: bn5b_branch2c
void CInspectionDemoResnet::Layer_77() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(77).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 200704;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res5b_branch2c
  //->: bn5b_branch2c
  //->: bn5b_branch2c
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 19966848;
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

  fpga_layer& layer = get_layer(77);
  layer.name = "res5b_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 200704;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_77

//Layer_78: Convolution Layer
//  ->: add_15
void CInspectionDemoResnet::Layer_78() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(78).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 200704;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 0;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 401408;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_15
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 21151104;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(78);
  layer.name = "add_15";
  layer.type = LT_CONV;
  layer.input_offs = 200704;
  layer.output_offs = 0;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_78

//Layer_79: Convolution Layer
//  ->: activation_46
//  ->: activation_46
void CInspectionDemoResnet::Layer_79() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(79).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 405536;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_46
  //->: activation_46
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 21151104;
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

  fpga_layer& layer = get_layer(79);
  layer.name = "activation_46";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 405536;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_79

//Layer_80: Convolution Layer
//  ->: res5c_branch2a
//  ->: bn5c_branch2a
//  ->: bn5c_branch2a
//  ->: activation_47
void CInspectionDemoResnet::Layer_80() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(80).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 405536;

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
  //->: res5c_branch2a
  //->: bn5c_branch2a
  //->: bn5c_branch2a
  //->: activation_47
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 21303168;
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

  fpga_layer& layer = get_layer(80);
  layer.name = "res5c_branch2a";
  layer.type = LT_CONV;
  layer.input_offs = 405536;
  layer.output_offs = 0;
  layer.output_size = 50176;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_80

//Layer_81: Convolution Layer
//  ->: res5c_branch2b
//  ->: bn5c_branch2b
//  ->: bn5c_branch2b
//  ->: activation_48
void CInspectionDemoResnet::Layer_81() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(81).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 200704;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: res5c_branch2b
  //->: bn5c_branch2b
  //->: bn5c_branch2b
  //->: activation_48
  conf.run[0].m = 512;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x3;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 22484352;
  conf.run[0].weight_fmt = 3;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x1010101;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
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

  fpga_layer& layer = get_layer(81);
  layer.name = "res5c_branch2b";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 200704;
  layer.output_size = 50176;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 512;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_81

//Layer_82: Convolution Layer
//  ->: res5c_branch2c
//  ->: bn5c_branch2c
//  ->: bn5c_branch2c
void CInspectionDemoResnet::Layer_82() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(82).conv_conf_v1;
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
  conf.c = 512;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 200704;

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
  //->: res5c_branch2c
  //->: bn5c_branch2c
  //->: bn5c_branch2c
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 24845184;
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

  fpga_layer& layer = get_layer(82);
  layer.name = "res5c_branch2c";
  layer.type = LT_CONV;
  layer.input_offs = 200704;
  layer.output_offs = 0;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 512;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_82

//Layer_83: Convolution Layer
//  ->: add_16
void CInspectionDemoResnet::Layer_83() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(83).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 0;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 204832;

  conf.eltwise_buf.mem = io_mem_;
  conf.eltwise_buf.offs = 405536;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 1;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: add_16
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 26029440;
  conf.run[0].weight_fmt = 0;  // Weight format (0 = random access blocks, 1 = compact stream, 3 = 8-bit qunatized stream)
  conf.run[0].conv_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].conv_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].conv_dilation = 0x0;  // bits [7:0] = X dilation, bits [15:8] = Y dilation
  conf.run[0].pool_enable = 2;  // 0 = disabled, 1 = max pooling, 2 = average pooling
  conf.run[0].pool_size = 0x101;  // bits [7:0] = width, bits [15:8] = height
  conf.run[0].pool_stride = 0x101;  // bits [7:0] = X stride, bits [15:8] = Y stride
  conf.run[0].pool_pad = 0x0;  // bits [7:0] = left padding, bits [15:8] = right padding, bits [23:16] = top padding, bits [31:24] = bottom padding
  conf.run[0].pool_avg_param = 0x3C00;  // Usually set to 1/pool_size^2 in FP16 format when using average pooling (average pooling assumes square size)
  conf.run[0].actfunc = 0;  // Activation Function: 0 = None, 1 = Tanh, 2 = Leaky ReLU, 3 = Sigmoid, 4 = PReLU, 5 = ELU, 6 = ReLU6
  conf.run[0].actfunc_param = 0x0;  // Leaky ReLU parameter (NOTE: 0x2E66 is 0.1 in FP16)
  conf.run[0].rectifi_en = 0;  // Rectification, i.e. max(0, x) (NOTE: Can be applied after non-ReLU activation function)

  fpga_layer& layer = get_layer(83);
  layer.name = "add_16";
  layer.type = LT_CONV;
  layer.input_offs = 0;
  layer.output_offs = 204832;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_83

//Layer_84: Convolution Layer
//  ->: activation_49
//  ->: activation_49
void CInspectionDemoResnet::Layer_84() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(84).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 204832;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 4128;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: activation_49
  //->: activation_49
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 3;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 26029440;
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

  fpga_layer& layer = get_layer(84);
  layer.name = "activation_49";
  layer.type = LT_CONV;
  layer.input_offs = 204832;
  layer.output_offs = 4128;
  layer.output_size = 200704;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 7;
  layer.output_dim[1] = 7;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_84

//Layer_85: Convolution Layer
//  ->: avg_pool
void CInspectionDemoResnet::Layer_85() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(85).conv_conf_v1;
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
  conf.c = 2048;  // Input Channels
  conf.input_circular_offset = 0x8000;  // The weight matrix is transposed.
  conf.input_buf.mem = io_mem_;
  conf.input_buf.offs = 4128;

  // Output Configuration:
  conf.output_buf.mem = io_mem_;
  conf.output_buf.offs = 32;

  conf.eltwise_buf.mem = NULL;
  conf.eltwise_buf.offs = 0;  // Input byte address for elementwise add (0 = UBUF Input Buffer)
  conf.output_mode = 0;  // 0 = concat, 1 = eltwise add

  // Runs Configuration:
  // ->1 run(s)
  //--------------------------------------------------
  //RUN : 0
  //--------------------------------------------------
  //->: avg_pool
  conf.run[0].m = 2048;  // Output Channels
  conf.run[0].conv_enable = 0;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 26181504;
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

  fpga_layer& layer = get_layer(85);
  layer.name = "avg_pool";
  layer.type = LT_CONV;
  layer.input_offs = 4128;
  layer.output_offs = 32;
  layer.output_size = 4096;
  layer.input_dim[0] = 7;
  layer.input_dim[1] = 7;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2048;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_85

//Layer_86: Convolution Layer
//  ->: fc1000
void CInspectionDemoResnet::Layer_86() {
  dmp_dv_cmdraw_conv_v1& conf_v1 = get_layer(86).conv_conf_v1;
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
  conf.input_buf.offs = 32;

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
  //->: fc1000
  conf.run[0].m = 2;  // Output Channels
  conf.run[0].conv_enable = 1;  // 1 = Enabled, 0 = Disabled
  conf.run[0].p = 0x1;  // Filter Width and Height
  conf.run[0].pz = 1;  // Filter Depth
  conf.run[0].weight_buf.mem = weights_mem_;
  conf.run[0].weight_buf.offs = 26181504;
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

  fpga_layer& layer = get_layer(86);
  layer.name = "fc1000";
  layer.type = LT_CONV;
  layer.input_offs = 32;
  layer.output_offs = 16;
  layer.output_size = 4;
  layer.input_dim[0] = 1;
  layer.input_dim[1] = 1;
  layer.input_dim[2] = 2048;
  layer.input_dim_size = 3;
  layer.output_dim[0] = 1;
  layer.output_dim[1] = 1;
  layer.output_dim[2] = 2;
  layer.output_dim_size = 3;
  layer.is_output = false;
  layer.is_f32_output = false;
  layer.is_input_hw_layout = true;
}//end of  Layer_86

//Layer_87: SoftMax Layer
//	->: fc1000_softmax
void CInspectionDemoResnet::Layer_87() {
  fpga_layer& layer = get_layer(87);
  layer.name = "fc1000_softmax";
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
  output_layers_[0] = &layer;
}//end of  Layer_87

