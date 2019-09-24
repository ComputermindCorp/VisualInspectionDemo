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
#pragma once

#include "dmp_network.h"

class CInspectionDemoGoogLeNet : public CDMP_Network {
 private:
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 0 | FPGA-Layer | Convolution | (224, 224, 3) | (56, 56, 64) | - | - |
  | 0-0 | conv1 | Convolution | (224, 224, 3) | (112, 112, 64) | - | 14464 |
  | 0-0 | max_pooling2d_1 | Pooling | (112, 112, 64) | (56, 56, 64) | - | - |

  */
  void Layer_0();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 1 | FPGA-Layer | Convolution | (56, 56, 64) | (56, 56, 64) | - | - |
  | 1-0 | batch_normalization_1 | Convolution | (56, 56, 64) | (56, 56, 64) | - | 5248 |

  */
  void Layer_1();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 2 | FPGA-Layer | Convolution | (56, 56, 64) | (56, 56, 64) | - | - |
  | 2-0 | conv2_reduce | Convolution | (56, 56, 64) | (56, 56, 64) | - | 5248 |

  */
  void Layer_2();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 3 | FPGA-Layer | Convolution | (56, 56, 64) | (28, 28, 192) | - | - |
  | 3-0 | conv2 | Convolution | (56, 56, 64) | (56, 56, 192) | - | 111488 |
  | 3-0 | max_pooling2d_2 | Pooling | (56, 56, 192) | (28, 28, 192) | - | - |

  */
  void Layer_3();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 4 | FPGA-Layer | Convolution | (28, 28, 192) | (28, 28, 64) | - | - |
  | 4-0 | inc3a_out1 | Convolution | (28, 28, 192) | (28, 28, 64) | - | 14464 |

  */
  void Layer_4();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 5 | FPGA-Layer | Convolution | (28, 28, 192) | (28, 28, 96) | - | - |
  | 5-0 | inc3a_proj3 | Convolution | (28, 28, 192) | (28, 28, 96) | - | 21440 |

  */
  void Layer_5();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 6 | FPGA-Layer | Convolution | (28, 28, 96) | (28, 28, 128) | - | - |
  | 6-0 | inc3a_out3 | Convolution | (28, 28, 96) | (28, 28, 128) | - | 111360 |

  */
  void Layer_6();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 7 | FPGA-Layer | Convolution | (28, 28, 192) | (28, 28, 16) | - | - |
  | 7-0 | inc3a_proj5 | Convolution | (28, 28, 192) | (28, 28, 16) | - | 4000 |

  */
  void Layer_7();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 8 | FPGA-Layer | Convolution | (28, 28, 16) | (28, 28, 32) | - | - |
  | 8-0 | inc3a_out5 | Convolution | (28, 28, 16) | (28, 28, 32) | - | 19008 |

  */
  void Layer_8();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 9 | FPGA-Layer | Convolution | (28, 28, 192) | (28, 28, 192) | - | - |
  | 9-0 | max_pooling2d_3 | Pooling | (28, 28, 192) | (28, 28, 192) | - | - |

  */
  void Layer_9();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 10 | FPGA-Layer | Convolution | (28, 28, 192) | (28, 28, 32) | - | - |
  | 10-0 | inc3a_pool | Convolution | (28, 28, 192) | (28, 28, 32) | - | 7488 |

  */
  void Layer_10();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 11 | FPGA-Layer | Concatenate | (28, 28, 256) | (28, 28, 256) | - | - |

  */
  void Layer_11();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 12 | FPGA-Layer | Convolution | (28, 28, 256) | (28, 28, 256) | - | - |
  | 12-0 | inc3a_concat | Convolution | (28, 28, 256) | (28, 28, 256) | - | 19456 |

  */
  void Layer_12();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 13 | FPGA-Layer | Convolution | (28, 28, 256) | (28, 28, 480) | - | - |
  | 13-0 | inc3b_out1 | Convolution | (28, 28, 256) | (28, 28, 128) | - | 37632 |
  | 13-1 | inc3b_proj3 | Convolution | (28, 28, 256) | (28, 28, 128) | - | 37632 |
  | 13-2 | inc3b_out3 | Convolution | (28, 28, 128) | (28, 28, 192) | - | 222080 |
  | 13-3 | inc3b_proj5 | Convolution | (28, 28, 256) | (28, 28, 32) | - | 9792 |
  | 13-4 | inc3b_out5 | Convolution | (28, 28, 32) | (28, 28, 96) | - | 111296 |
  | 13-5 | max_pooling2d_4 | Pooling | (28, 28, 256) | (28, 28, 256) | - | - |
  | 13-6 | inc3b_pool | Convolution | (28, 28, 256) | (28, 28, 64) | - | 19072 |

  */
  void Layer_13();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 14 | FPGA-Layer | Convolution | (28, 28, 480) | (14, 14, 480) | - | - |
  | 14-0 | inc3b_concat | Convolution | (28, 28, 480) | (28, 28, 480) | - | 36032 |
  | 14-0 | max_pooling2d_5 | Pooling | (28, 28, 480) | (14, 14, 480) | - | - |

  */
  void Layer_14();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 15 | FPGA-Layer | Convolution | (14, 14, 480) | (14, 14, 192) | - | - |
  | 15-0 | inc4a_out1 | Convolution | (14, 14, 480) | (14, 14, 192) | - | 111488 |

  */
  void Layer_15();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 16 | FPGA-Layer | Convolution | (14, 14, 480) | (14, 14, 96) | - | - |
  | 16-0 | inc4a_proj3 | Convolution | (14, 14, 480) | (14, 14, 96) | - | 56000 |

  */
  void Layer_16();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 17 | FPGA-Layer | Convolution | (14, 14, 96) | (14, 14, 208) | - | - |
  | 17-0 | inc4a_out3 | Convolution | (14, 14, 96) | (14, 14, 208) | - | 180640 |

  */
  void Layer_17();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 18 | FPGA-Layer | Convolution | (14, 14, 480) | (14, 14, 16) | - | - |
  | 18-0 | inc4a_proj5 | Convolution | (14, 14, 480) | (14, 14, 16) | - | 9760 |

  */
  void Layer_18();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 19 | FPGA-Layer | Convolution | (14, 14, 16) | (14, 14, 48) | - | - |
  | 19-0 | inc4a_out5 | Convolution | (14, 14, 16) | (14, 14, 48) | - | 28256 |

  */
  void Layer_19();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 20 | FPGA-Layer | Convolution | (14, 14, 480) | (14, 14, 480) | - | - |
  | 20-0 | max_pooling2d_6 | Pooling | (14, 14, 480) | (14, 14, 480) | - | - |

  */
  void Layer_20();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 21 | FPGA-Layer | Convolution | (14, 14, 480) | (14, 14, 64) | - | - |
  | 21-0 | inc4a_pool | Convolution | (14, 14, 480) | (14, 14, 64) | - | 37504 |

  */
  void Layer_21();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 22 | FPGA-Layer | Concatenate | (14, 14, 512) | (14, 14, 512) | - | - |

  */
  void Layer_22();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 23 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 512) | - | - |
  | 23-0 | inc4a_concat | Convolution | (14, 14, 512) | (14, 14, 512) | - | 38400 |

  */
  void Layer_23();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 24 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 160) | - | - |
  | 24-0 | inc4b_out1 | Convolution | (14, 14, 512) | (14, 14, 160) | - | 92992 |

  */
  void Layer_24();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 25 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 112) | - | - |
  | 25-0 | inc4b_proj3 | Convolution | (14, 14, 512) | (14, 14, 112) | - | 65248 |

  */
  void Layer_25();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 26 | FPGA-Layer | Convolution | (14, 14, 112) | (14, 14, 224) | - | - |
  | 26-0 | inc4b_out3 | Convolution | (14, 14, 112) | (14, 14, 224) | - | 226752 |

  */
  void Layer_26();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 27 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 24) | - | - |
  | 27-0 | inc4b_proj5 | Convolution | (14, 14, 512) | (14, 14, 24) | - | 14384 |

  */
  void Layer_27();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 28 | FPGA-Layer | Convolution | (14, 14, 24) | (14, 14, 64) | - | - |
  | 28-0 | inc4b_out5 | Convolution | (14, 14, 24) | (14, 14, 64) | - | 55936 |

  */
  void Layer_28();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 29 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 512) | - | - |
  | 29-0 | max_pooling2d_7 | Pooling | (14, 14, 512) | (14, 14, 512) | - | - |

  */
  void Layer_29();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 30 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 64) | - | - |
  | 30-0 | inc4b_pool | Convolution | (14, 14, 512) | (14, 14, 64) | - | 37504 |

  */
  void Layer_30();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 31 | FPGA-Layer | Concatenate | (14, 14, 512) | (14, 14, 512) | - | - |

  */
  void Layer_31();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 32 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 512) | - | - |
  | 32-0 | inc4b_concat | Convolution | (14, 14, 512) | (14, 14, 512) | - | 38400 |

  */
  void Layer_32();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 33 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 512) | - | - |
  | 33-0 | inc4c_out1 | Convolution | (14, 14, 512) | (14, 14, 128) | - | 74496 |
  | 33-1 | inc4c_proj3 | Convolution | (14, 14, 512) | (14, 14, 128) | - | 74496 |
  | 33-2 | inc4c_out3 | Convolution | (14, 14, 128) | (14, 14, 256) | - | 295936 |
  | 33-3 | inc4c_proj5 | Convolution | (14, 14, 512) | (14, 14, 24) | - | 14384 |
  | 33-4 | inc4c_out5 | Convolution | (14, 14, 24) | (14, 14, 64) | - | 55936 |
  | 33-5 | max_pooling2d_8 | Pooling | (14, 14, 512) | (14, 14, 512) | - | - |
  | 33-6 | inc4c_pool | Convolution | (14, 14, 512) | (14, 14, 64) | - | 37504 |

  */
  void Layer_33();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 34 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 512) | - | - |
  | 34-0 | inc4c_concat | Convolution | (14, 14, 512) | (14, 14, 512) | - | 38400 |

  */
  void Layer_34();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 35 | FPGA-Layer | Convolution | (14, 14, 512) | (14, 14, 528) | - | - |
  | 35-0 | inc4d_out1 | Convolution | (14, 14, 512) | (14, 14, 112) | - | 65248 |
  | 35-1 | inc4d_proj3 | Convolution | (14, 14, 512) | (14, 14, 144) | - | 83744 |
  | 35-2 | inc4d_out3 | Convolution | (14, 14, 144) | (14, 14, 288) | - | 374336 |
  | 35-3 | inc4d_proj5 | Convolution | (14, 14, 512) | (14, 14, 32) | - | 19008 |
  | 35-4 | inc4d_out5 | Convolution | (14, 14, 32) | (14, 14, 64) | - | 74368 |
  | 35-5 | max_pooling2d_9 | Pooling | (14, 14, 512) | (14, 14, 512) | - | - |
  | 35-6 | inc4d_pool | Convolution | (14, 14, 512) | (14, 14, 64) | - | 37504 |

  */
  void Layer_35();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 36 | FPGA-Layer | Convolution | (14, 14, 528) | (14, 14, 528) | - | - |
  | 36-0 | inc4d_concat | Convolution | (14, 14, 528) | (14, 14, 528) | - | 39584 |

  */
  void Layer_36();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 37 | FPGA-Layer | Convolution | (14, 14, 528) | (14, 14, 256) | - | - |
  | 37-0 | inc4e_out1 | Convolution | (14, 14, 528) | (14, 14, 256) | - | 166912 |

  */
  void Layer_37();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 38 | FPGA-Layer | Convolution | (14, 14, 528) | (14, 14, 160) | - | - |
  | 38-0 | inc4e_proj3 | Convolution | (14, 14, 528) | (14, 14, 160) | - | 104512 |

  */
  void Layer_38();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 39 | FPGA-Layer | Convolution | (14, 14, 160) | (14, 14, 320) | - | - |
  | 39-0 | inc4e_out3 | Convolution | (14, 14, 160) | (14, 14, 320) | - | 461952 |

  */
  void Layer_39();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 40 | FPGA-Layer | Convolution | (14, 14, 528) | (14, 14, 32) | - | - |
  | 40-0 | inc4e_proj5 | Convolution | (14, 14, 528) | (14, 14, 32) | - | 21312 |

  */
  void Layer_40();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 41 | FPGA-Layer | Convolution | (14, 14, 32) | (14, 14, 128) | - | - |
  | 41-0 | inc4e_out5 | Convolution | (14, 14, 32) | (14, 14, 128) | - | 148224 |

  */
  void Layer_41();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 42 | FPGA-Layer | Convolution | (14, 14, 528) | (14, 14, 528) | - | - |
  | 42-0 | max_pooling2d_10 | Pooling | (14, 14, 528) | (14, 14, 528) | - | - |

  */
  void Layer_42();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 43 | FPGA-Layer | Convolution | (14, 14, 528) | (14, 14, 128) | - | - |
  | 43-0 | inc4e_pool | Convolution | (14, 14, 528) | (14, 14, 128) | - | 83712 |

  */
  void Layer_43();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 44 | FPGA-Layer | Concatenate | (14, 14, 832) | (14, 14, 832) | - | - |

  */
  void Layer_44();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 45 | FPGA-Layer | Convolution | (14, 14, 832) | (7, 7, 832) | - | - |
  | 45-0 | inc4e_concat | Convolution | (14, 14, 832) | (14, 14, 832) | - | 62080 |
  | 45-0 | max_pooling2d_11 | Pooling | (14, 14, 832) | (7, 7, 832) | - | - |

  */
  void Layer_45();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 46 | FPGA-Layer | Convolution | (7, 7, 832) | (7, 7, 256) | - | - |
  | 46-0 | inc5a_out1 | Convolution | (7, 7, 832) | (7, 7, 256) | - | 240640 |

  */
  void Layer_46();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 47 | FPGA-Layer | Convolution | (7, 7, 832) | (7, 7, 160) | - | - |
  | 47-0 | inc5a_proj3 | Convolution | (7, 7, 832) | (7, 7, 160) | - | 150592 |

  */
  void Layer_47();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 48 | FPGA-Layer | Convolution | (7, 7, 160) | (7, 7, 320) | - | - |
  | 48-0 | inc5a_out3 | Convolution | (7, 7, 160) | (7, 7, 320) | - | 461952 |

  */
  void Layer_48();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 49 | FPGA-Layer | Convolution | (7, 7, 832) | (7, 7, 32) | - | - |
  | 49-0 | inc5a_proj5 | Convolution | (7, 7, 832) | (7, 7, 32) | - | 30528 |

  */
  void Layer_49();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 50 | FPGA-Layer | Convolution | (7, 7, 32) | (7, 7, 128) | - | - |
  | 50-0 | inc5a_out5 | Convolution | (7, 7, 32) | (7, 7, 128) | - | 148224 |

  */
  void Layer_50();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 51 | FPGA-Layer | Convolution | (7, 7, 832) | (7, 7, 832) | - | - |
  | 51-0 | max_pooling2d_12 | Pooling | (7, 7, 832) | (7, 7, 832) | - | - |

  */
  void Layer_51();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 52 | FPGA-Layer | Convolution | (7, 7, 832) | (7, 7, 128) | - | - |
  | 52-0 | inc5a_pool | Convolution | (7, 7, 832) | (7, 7, 128) | - | 120576 |

  */
  void Layer_52();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 53 | FPGA-Layer | Concatenate | (7, 7, 832) | (7, 7, 832) | - | - |

  */
  void Layer_53();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 54 | FPGA-Layer | Convolution | (7, 7, 832) | (7, 7, 832) | - | - |
  | 54-0 | inc5a_concat | Convolution | (7, 7, 832) | (7, 7, 832) | - | 62080 |

  */
  void Layer_54();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 55 | FPGA-Layer | Convolution | (7, 7, 832) | (7, 7, 1024) | - | - |
  | 55-0 | inc5b_out1 | Convolution | (7, 7, 832) | (7, 7, 384) | - | 360704 |
  | 55-1 | inc5b_proj3 | Convolution | (7, 7, 832) | (7, 7, 192) | - | 180608 |
  | 55-2 | inc5b_out3 | Convolution | (7, 7, 192) | (7, 7, 384) | - | 664832 |
  | 55-3 | inc5b_proj5 | Convolution | (7, 7, 832) | (7, 7, 48) | - | 45536 |
  | 55-4 | inc5b_out5 | Convolution | (7, 7, 48) | (7, 7, 128) | - | 221952 |
  | 55-5 | max_pooling2d_13 | Pooling | (7, 7, 832) | (7, 7, 832) | - | - |
  | 55-6 | inc5b_pool | Convolution | (7, 7, 832) | (7, 7, 128) | - | 120576 |

  */
  void Layer_55();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 56 | FPGA-Layer | Convolution | (7, 7, 1024) | (7, 7, 1024) | - | - |
  | 56-0 | inc5b_concat | Convolution | (7, 7, 1024) | (7, 7, 1024) | - | 76288 |

  */
  void Layer_56();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 57 | FPGA-Layer | Convolution | (7, 7, 1024) | (1024,) | - | - |
  | 57-0 | average_pooling2d_3 | Pooling | (7, 7, 1024) | (1, 1, 1024) | - | - |

  */
  void Layer_57();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 58 | FPGA-Layer | Convolution | (1, 1, 1024) | (1, 1, 2) | - | - |
  | 58-0 | loss3_dence | InnerProduct | (1, 1, 1024) | (1, 1, 2) | - | 2832 |

  */
  void Layer_58();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 59 | FPGA-Layer | SoftMax | (1, 1, 2) | (1, 1, 2) | - | - |

  */
  void Layer_59();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 60 | FPGA-Layer | Convolution | (14, 14, 528) | (4, 4, 528) | - | - |
  | 60-0 | average_pooling2d_2 | Pooling | (14, 14, 528) | (4, 4, 528) | - | - |

  */
  void Layer_60();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 61 | FPGA-Layer | Convolution | (4, 4, 528) | (4, 4, 128) | - | - |
  | 61-0 | loss2_conv1 | Convolution | (4, 4, 528) | (4, 4, 128) | - | 83712 |

  */
  void Layer_61();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 62 | FPGA-Layer | Flatten | (4, 4, 128) | (2048,) | - | - |

  */
  void Layer_62();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 63 | FPGA-Layer | Convolution | (1, 1, 2048) | (1, 1, 1024) | - | - |
  | 63-0 | loss2_dence1 | InnerProduct | (1, 1, 2048) | (1, 1, 1024) | - | 2361856 |

  */
  void Layer_63();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 64 | FPGA-Layer | Convolution | (1, 1, 1024) | (1, 1, 2) | - | - |
  | 64-0 | loss2_dence2 | InnerProduct | (1, 1, 1024) | (1, 1, 2) | - | 2832 |

  */
  void Layer_64();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 65 | FPGA-Layer | SoftMax | (1, 1, 2) | (1, 1, 2) | - | - |

  */
  void Layer_65();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 66 | FPGA-Layer | Convolution | (14, 14, 512) | (4, 4, 512) | - | - |
  | 66-0 | average_pooling2d_1 | Pooling | (14, 14, 512) | (4, 4, 512) | - | - |

  */
  void Layer_66();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 67 | FPGA-Layer | Convolution | (4, 4, 512) | (4, 4, 128) | - | - |
  | 67-0 | loss1_conv1 | Convolution | (4, 4, 512) | (4, 4, 128) | - | 74496 |

  */
  void Layer_67();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 68 | FPGA-Layer | Flatten | (4, 4, 128) | (2048,) | - | - |

  */
  void Layer_68();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 69 | FPGA-Layer | Convolution | (1, 1, 2048) | (1, 1, 1024) | - | - |
  | 69-0 | loss1_dense1 | InnerProduct | (1, 1, 2048) | (1, 1, 1024) | - | 2361856 |

  */
  void Layer_69();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 70 | FPGA-Layer | Convolution | (1, 1, 1024) | (1, 1, 2) | - | - |
  | 70-0 | loss1_dense2 | InnerProduct | (1, 1, 1024) | (1, 1, 2) | - | 2832 |

  */
  void Layer_70();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 71 | FPGA-Layer | SoftMax | (1, 1, 2) | (1, 1, 2) | - | - |

  */
  void Layer_71();

 public:
  virtual bool Initialize();
  CInspectionDemoGoogLeNet();
  virtual ~CInspectionDemoGoogLeNet();
};
