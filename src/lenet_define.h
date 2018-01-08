/*
 * lenet_define.h
 *
 *  Created on: 2018年1月5日
 *      Author: admin
 */

#ifndef LENET_DEFINE_H_
#define LENET_DEFINE_H_
#include <iostream>
using namespace std;

#define BATCH_SIZE 200
#define FEATURE_SIZE 28
#define RESULT_SORT 10
#define LOOP_TIME 50
#define UPDATE_NUMBER 20



//层的参数
#define CONV_1_MAP_NUMBER (6)
#define CONV_1_OUTPUT_NUMBER (6)
#define CONV_1_OUTPUT_SIZE (24)
#define CONV_1_KERNEL_SIZE (5)

#define POOLING_2_OUTPUT_NUMBER (6)
#define POOLING_2_OUTPUT_SIZE (12)

#define CONV_3_MAP_NUMBER (6 * 8)
#define CONV_3_OUTPUT_NUMBER (8)
#define CONV_3_OUTPUT_SIZE (10)
#define CONV_3_KERNEL_SIZE (3)

#define CONV_4_MAP_NUMBER (8 * 16)
#define CONV_4_OUTPUT_NUMBER (16)
#define CONV_4_OUTPUT_SIZE (8)
#define CONV_4_KERNEL_SIZE (3)


#define POOLING_5_OUTPUT_NUMBER (16)
#define POOLING_5_OUTPUT_SIZE (4)

#define FLATTEN_6_INPUT_SIZE (4)
#define FLATTEN_6_INPUT_NUMBER (16)
#define FLATTEN_6_OUTPUT_NUMBER (256)

#define DENSE_7_INPUT_NUMBER (256)
#define DENSE_7_OUTPUT_NUMBER (128)

#define DENSE_8_INPUT_NUMBER (128)
#define DENSE_8_OUTPUT_NUMBER (10)

/*Typedef*/
typedef enum{
    NORMAL,
    INIT,
    UPDATE
}cnn_status;





#endif /* LENET_DEFINE_H_ */
