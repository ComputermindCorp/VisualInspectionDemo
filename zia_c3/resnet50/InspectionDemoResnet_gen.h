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

class CInspectionDemoResnet : public CDMP_Network {
 private:
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 0 | FPGA-Layer | Convolution | (224, 224, 3) | (55, 55, 64) | - | - |
  | 0-0 | conv1 | Convolution | (224, 224, 3) | (112, 112, 64) | - | 14464 |
  | 0-0 | max_pooling2d_1 | Pooling | (112, 112, 64) | (55, 55, 64) | - | - |

  */
  void Layer_0();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 1 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 64) | - | - |
  | 1-0 | res2a_branch2a | Convolution | (55, 55, 64) | (55, 55, 64) | - | 5248 |

  */
  void Layer_1();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 2 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 64) | - | - |
  | 2-0 | res2a_branch2b | Convolution | (55, 55, 64) | (55, 55, 64) | - | 37504 |

  */
  void Layer_2();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 3 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 256) | - | - |
  | 3-0 | res2a_branch2c | Convolution | (55, 55, 64) | (55, 55, 256) | - | 19456 |

  */
  void Layer_3();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 4 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 256) | - | - |
  | 4-0 | res2a_branch1 | Convolution | (55, 55, 64) | (55, 55, 256) | - | 19456 |

  */
  void Layer_4();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 5 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 256) | - | - |
  | 5-0 | add_1 | Eltwise | (55, 55, 256) | (55, 55, 256) | - | - |

  */
  void Layer_5();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 6 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 256) | - | - |
  | 6-0 | activation_4 | Convolution | (55, 55, 256) | (55, 55, 256) | - | 19456 |

  */
  void Layer_6();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 7 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 64) | - | - |
  | 7-0 | res2b_branch2a | Convolution | (55, 55, 256) | (55, 55, 64) | - | 19072 |

  */
  void Layer_7();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 8 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 64) | - | - |
  | 8-0 | res2b_branch2b | Convolution | (55, 55, 64) | (55, 55, 64) | - | 37504 |

  */
  void Layer_8();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 9 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 256) | - | - |
  | 9-0 | res2b_branch2c | Convolution | (55, 55, 64) | (55, 55, 256) | - | 19456 |

  */
  void Layer_9();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 10 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 256) | - | - |
  | 10-0 | add_2 | Eltwise | (55, 55, 256) | (55, 55, 256) | - | - |

  */
  void Layer_10();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 11 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 256) | - | - |
  | 11-0 | activation_7 | Convolution | (55, 55, 256) | (55, 55, 256) | - | 19456 |

  */
  void Layer_11();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 12 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 64) | - | - |
  | 12-0 | res2c_branch2a | Convolution | (55, 55, 256) | (55, 55, 64) | - | 19072 |

  */
  void Layer_12();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 13 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 64) | - | - |
  | 13-0 | res2c_branch2b | Convolution | (55, 55, 64) | (55, 55, 64) | - | 37504 |

  */
  void Layer_13();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 14 | FPGA-Layer | Convolution | (55, 55, 64) | (55, 55, 256) | - | - |
  | 14-0 | res2c_branch2c | Convolution | (55, 55, 64) | (55, 55, 256) | - | 19456 |

  */
  void Layer_14();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 15 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 256) | - | - |
  | 15-0 | add_3 | Eltwise | (55, 55, 256) | (55, 55, 256) | - | - |

  */
  void Layer_15();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 16 | FPGA-Layer | Convolution | (55, 55, 256) | (55, 55, 256) | - | - |
  | 16-0 | activation_10 | Convolution | (55, 55, 256) | (55, 55, 256) | - | 19456 |

  */
  void Layer_16();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 17 | FPGA-Layer | Convolution | (55, 55, 256) | (28, 28, 128) | - | - |
  | 17-0 | res3a_branch2a | Convolution | (55, 55, 256) | (28, 28, 128) | - | 37632 |

  */
  void Layer_17();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 18 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 128) | - | - |
  | 18-0 | res3a_branch2b | Convolution | (28, 28, 128) | (28, 28, 128) | - | 148224 |

  */
  void Layer_18();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 19 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 512) | - | - |
  | 19-0 | res3a_branch2c | Convolution | (28, 28, 128) | (28, 28, 512) | - | 75264 |

  */
  void Layer_19();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 20 | FPGA-Layer | Convolution | (55, 55, 256) | (28, 28, 512) | - | - |
  | 20-0 | res3a_branch1 | Convolution | (55, 55, 256) | (28, 28, 512) | - | 148992 |

  */
  void Layer_20();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 21 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 21-0 | add_4 | Eltwise | (28, 28, 512) | (28, 28, 512) | - | - |

  */
  void Layer_21();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 22 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 22-0 | activation_13 | Convolution | (28, 28, 512) | (28, 28, 512) | - | 38400 |

  */
  void Layer_22();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 23 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 128) | - | - |
  | 23-0 | res3b_branch2a | Convolution | (28, 28, 512) | (28, 28, 128) | - | 74496 |

  */
  void Layer_23();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 24 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 128) | - | - |
  | 24-0 | res3b_branch2b | Convolution | (28, 28, 128) | (28, 28, 128) | - | 148224 |

  */
  void Layer_24();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 25 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 512) | - | - |
  | 25-0 | res3b_branch2c | Convolution | (28, 28, 128) | (28, 28, 512) | - | 75264 |

  */
  void Layer_25();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 26 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 26-0 | add_5 | Eltwise | (28, 28, 512) | (28, 28, 512) | - | - |

  */
  void Layer_26();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 27 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 27-0 | activation_16 | Convolution | (28, 28, 512) | (28, 28, 512) | - | 38400 |

  */
  void Layer_27();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 28 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 128) | - | - |
  | 28-0 | res3c_branch2a | Convolution | (28, 28, 512) | (28, 28, 128) | - | 74496 |

  */
  void Layer_28();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 29 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 128) | - | - |
  | 29-0 | res3c_branch2b | Convolution | (28, 28, 128) | (28, 28, 128) | - | 148224 |

  */
  void Layer_29();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 30 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 512) | - | - |
  | 30-0 | res3c_branch2c | Convolution | (28, 28, 128) | (28, 28, 512) | - | 75264 |

  */
  void Layer_30();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 31 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 31-0 | add_6 | Eltwise | (28, 28, 512) | (28, 28, 512) | - | - |

  */
  void Layer_31();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 32 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 32-0 | activation_19 | Convolution | (28, 28, 512) | (28, 28, 512) | - | 38400 |

  */
  void Layer_32();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 33 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 128) | - | - |
  | 33-0 | res3d_branch2a | Convolution | (28, 28, 512) | (28, 28, 128) | - | 74496 |

  */
  void Layer_33();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 34 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 128) | - | - |
  | 34-0 | res3d_branch2b | Convolution | (28, 28, 128) | (28, 28, 128) | - | 148224 |

  */
  void Layer_34();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 35 | FPGA-Layer | Convolution | (28, 28, 128) | (28, 28, 512) | - | - |
  | 35-0 | res3d_branch2c | Convolution | (28, 28, 128) | (28, 28, 512) | - | 75264 |

  */
  void Layer_35();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 36 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 36-0 | add_7 | Eltwise | (28, 28, 512) | (28, 28, 512) | - | - |

  */
  void Layer_36();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 37 | FPGA-Layer | Convolution | (28, 28, 512) | (28, 28, 512) | - | - |
  | 37-0 | activation_22 | Convolution | (28, 28, 512) | (28, 28, 512) | - | 38400 |

  */
  void Layer_37();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 38 | FPGA-Layer | Convolution | (28, 28, 512) | (14, 14, 256) | - | - |
  | 38-0 | res4a_branch2a | Convolution | (28, 28, 512) | (14, 14, 256) | - | 148480 |

  */
  void Layer_38();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 39 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 256) | - | - |
  | 39-0 | res4a_branch2b | Convolution | (14, 14, 256) | (14, 14, 256) | - | 590848 |

  */
  void Layer_39();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 40 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 1024) | - | - |
  | 40-0 | res4a_branch2c | Convolution | (14, 14, 256) | (14, 14, 1024) | - | 297472 |

  */
  void Layer_40();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 41 | FPGA-Layer | Convolution | (28, 28, 512) | (14, 14, 1024) | - | - |
  | 41-0 | res4a_branch1 | Convolution | (28, 28, 512) | (14, 14, 1024) | - | 592384 |

  */
  void Layer_41();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 42 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 42-0 | add_8 | Eltwise | (14, 14, 1024) | (14, 14, 1024) | - | - |

  */
  void Layer_42();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 43 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 43-0 | activation_25 | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | 76288 |

  */
  void Layer_43();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 44 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 256) | - | - |
  | 44-0 | res4b_branch2a | Convolution | (14, 14, 1024) | (14, 14, 256) | - | 295936 |

  */
  void Layer_44();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 45 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 256) | - | - |
  | 45-0 | res4b_branch2b | Convolution | (14, 14, 256) | (14, 14, 256) | - | 590848 |

  */
  void Layer_45();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 46 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 1024) | - | - |
  | 46-0 | res4b_branch2c | Convolution | (14, 14, 256) | (14, 14, 1024) | - | 297472 |

  */
  void Layer_46();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 47 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 47-0 | add_9 | Eltwise | (14, 14, 1024) | (14, 14, 1024) | - | - |

  */
  void Layer_47();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 48 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 48-0 | activation_28 | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | 76288 |

  */
  void Layer_48();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 49 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 256) | - | - |
  | 49-0 | res4c_branch2a | Convolution | (14, 14, 1024) | (14, 14, 256) | - | 295936 |

  */
  void Layer_49();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 50 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 256) | - | - |
  | 50-0 | res4c_branch2b | Convolution | (14, 14, 256) | (14, 14, 256) | - | 590848 |

  */
  void Layer_50();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 51 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 1024) | - | - |
  | 51-0 | res4c_branch2c | Convolution | (14, 14, 256) | (14, 14, 1024) | - | 297472 |

  */
  void Layer_51();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 52 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 52-0 | add_10 | Eltwise | (14, 14, 1024) | (14, 14, 1024) | - | - |

  */
  void Layer_52();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 53 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 53-0 | activation_31 | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | 76288 |

  */
  void Layer_53();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 54 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 256) | - | - |
  | 54-0 | res4d_branch2a | Convolution | (14, 14, 1024) | (14, 14, 256) | - | 295936 |

  */
  void Layer_54();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 55 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 256) | - | - |
  | 55-0 | res4d_branch2b | Convolution | (14, 14, 256) | (14, 14, 256) | - | 590848 |

  */
  void Layer_55();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 56 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 1024) | - | - |
  | 56-0 | res4d_branch2c | Convolution | (14, 14, 256) | (14, 14, 1024) | - | 297472 |

  */
  void Layer_56();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 57 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 57-0 | add_11 | Eltwise | (14, 14, 1024) | (14, 14, 1024) | - | - |

  */
  void Layer_57();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 58 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 58-0 | activation_34 | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | 76288 |

  */
  void Layer_58();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 59 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 256) | - | - |
  | 59-0 | res4e_branch2a | Convolution | (14, 14, 1024) | (14, 14, 256) | - | 295936 |

  */
  void Layer_59();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 60 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 256) | - | - |
  | 60-0 | res4e_branch2b | Convolution | (14, 14, 256) | (14, 14, 256) | - | 590848 |

  */
  void Layer_60();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 61 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 1024) | - | - |
  | 61-0 | res4e_branch2c | Convolution | (14, 14, 256) | (14, 14, 1024) | - | 297472 |

  */
  void Layer_61();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 62 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 62-0 | add_12 | Eltwise | (14, 14, 1024) | (14, 14, 1024) | - | - |

  */
  void Layer_62();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 63 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 63-0 | activation_37 | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | 76288 |

  */
  void Layer_63();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 64 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 256) | - | - |
  | 64-0 | res4f_branch2a | Convolution | (14, 14, 1024) | (14, 14, 256) | - | 295936 |

  */
  void Layer_64();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 65 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 256) | - | - |
  | 65-0 | res4f_branch2b | Convolution | (14, 14, 256) | (14, 14, 256) | - | 590848 |

  */
  void Layer_65();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 66 | FPGA-Layer | Convolution | (14, 14, 256) | (14, 14, 1024) | - | - |
  | 66-0 | res4f_branch2c | Convolution | (14, 14, 256) | (14, 14, 1024) | - | 297472 |

  */
  void Layer_66();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 67 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 67-0 | add_13 | Eltwise | (14, 14, 1024) | (14, 14, 1024) | - | - |

  */
  void Layer_67();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 68 | FPGA-Layer | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | - |
  | 68-0 | activation_40 | Convolution | (14, 14, 1024) | (14, 14, 1024) | - | 76288 |

  */
  void Layer_68();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 69 | FPGA-Layer | Convolution | (14, 14, 1024) | (7, 7, 512) | - | - |
  | 69-0 | res5a_branch2a | Convolution | (14, 14, 1024) | (7, 7, 512) | - | 591360 |

  */
  void Layer_69();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 70 | FPGA-Layer | Convolution | (7, 7, 512) | (7, 7, 512) | - | - |
  | 70-0 | res5a_branch2b | Convolution | (7, 7, 512) | (7, 7, 512) | - | 2360832 |

  */
  void Layer_70();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 71 | FPGA-Layer | Convolution | (7, 7, 512) | (7, 7, 2048) | - | - |
  | 71-0 | res5a_branch2c | Convolution | (7, 7, 512) | (7, 7, 2048) | - | 1184256 |

  */
  void Layer_71();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 72 | FPGA-Layer | Convolution | (14, 14, 1024) | (7, 7, 2048) | - | - |
  | 72-0 | res5a_branch1 | Convolution | (14, 14, 1024) | (7, 7, 2048) | - | 2363904 |

  */
  void Layer_72();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 73 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | - |
  | 73-0 | add_14 | Eltwise | (7, 7, 2048) | (7, 7, 2048) | - | - |

  */
  void Layer_73();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 74 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | - |
  | 74-0 | activation_43 | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | 152064 |

  */
  void Layer_74();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 75 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 512) | - | - |
  | 75-0 | res5b_branch2a | Convolution | (7, 7, 2048) | (7, 7, 512) | - | 1181184 |

  */
  void Layer_75();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 76 | FPGA-Layer | Convolution | (7, 7, 512) | (7, 7, 512) | - | - |
  | 76-0 | res5b_branch2b | Convolution | (7, 7, 512) | (7, 7, 512) | - | 2360832 |

  */
  void Layer_76();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 77 | FPGA-Layer | Convolution | (7, 7, 512) | (7, 7, 2048) | - | - |
  | 77-0 | res5b_branch2c | Convolution | (7, 7, 512) | (7, 7, 2048) | - | 1184256 |

  */
  void Layer_77();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 78 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | - |
  | 78-0 | add_15 | Eltwise | (7, 7, 2048) | (7, 7, 2048) | - | - |

  */
  void Layer_78();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 79 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | - |
  | 79-0 | activation_46 | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | 152064 |

  */
  void Layer_79();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 80 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 512) | - | - |
  | 80-0 | res5c_branch2a | Convolution | (7, 7, 2048) | (7, 7, 512) | - | 1181184 |

  */
  void Layer_80();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 81 | FPGA-Layer | Convolution | (7, 7, 512) | (7, 7, 512) | - | - |
  | 81-0 | res5c_branch2b | Convolution | (7, 7, 512) | (7, 7, 512) | - | 2360832 |

  */
  void Layer_81();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 82 | FPGA-Layer | Convolution | (7, 7, 512) | (7, 7, 2048) | - | - |
  | 82-0 | res5c_branch2c | Convolution | (7, 7, 512) | (7, 7, 2048) | - | 1184256 |

  */
  void Layer_82();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 83 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | - |
  | 83-0 | add_16 | Eltwise | (7, 7, 2048) | (7, 7, 2048) | - | - |

  */
  void Layer_83();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 84 | FPGA-Layer | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | - |
  | 84-0 | activation_49 | Convolution | (7, 7, 2048) | (7, 7, 2048) | - | 152064 |

  */
  void Layer_84();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 85 | FPGA-Layer | Convolution | (7, 7, 2048) | (1, 1, 2048) | - | - |
  | 85-0 | avg_pool | Pooling | (7, 7, 2048) | (1, 1, 2048) | - | - |

  */
  void Layer_85();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 86 | FPGA-Layer | Convolution | (1, 1, 2048) | (1, 1, 2) | - | - |
  | 86-0 | fc1000 | InnerProduct | (1, 1, 2048) | (1, 1, 2) | - | 5136 |

  */
  void Layer_86();
  /*!

  Layer description

  | ID | Layers | Type | Dim In | Dim Out | Param | Mem |
  | :- | :- | :-: | :-: | :-: | :-: | :-: |
  | 87 | FPGA-Layer | SoftMax | (1, 1, 2) | (1, 1, 2) | - | - |

  */
  void Layer_87();

 public:
  virtual bool Initialize();
  CInspectionDemoResnet();
  virtual ~CInspectionDemoResnet();
};
