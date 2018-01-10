/*
 * lenet_define.h
 *
 *  Created on: 2018年1月5日
 *      Author: admin
 */

#ifndef LENET_DEFINE_H_
#define LENET_DEFINE_H_
#include <stdio.h>
#ifdef RISCV
#include "sc_print.h"
#define printf sc_printf
#endif
#define BATCH_SIZE 20
#define FEATURE_SIZE 28
#define RESULT_SORT 10
#define LOOP_TIME 500
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

#ifdef RISCV
#define SIZE_DATA (4)
#define SIZE_FEATURE (SIZE_DATA * FEATURE_SIZE * FEATURE_SIZE) //The number of bytes in each feature
#define SIZE_LABEL (1)

//Memory Address Bias
#define BIAS_CONV1_WEIGHT (0)
#define BIAS_CONV1_BIAS (SIZE_DATA * CONV_1_KERNEL_SIZE * CONV_1_KERNEL_SIZE * CONV_1_OUTPUT_NUMBER)
#define BIAS_CONV3_WEIGHT (BIAS_CONV1_BIAS + SIZE_DATA * CONV_1_OUTPUT_NUMBER)
#define BIAS_CONV3_BIAS (BIAS_CONV3_WEIGHT + SIZE_DATA * CONV_3_KERNEL_SIZE * CONV_3_KERNEL_SIZE * CONV_3_OUTPUT_NUMBER * POOLING_2_OUTPUT_NUMBER)
#define BIAS_CONV4_WEIGHT (BIAS_CONV3_BIAS + SIZE_DATA * CONV_3_OUTPUT_NUMBER)
#define BIAS_CONV4_BIAS (BIAS_CONV4_WEIGHT + SIZE_DATA * CONV_4_KERNEL_SIZE * CONV_4_KERNEL_SIZE * CONV_4_OUTPUT_NUMBER * CONV_3_OUTPUT_NUMBER)
#define BIAS_DENSE7_WEIGHT (BIAS_CONV4_WEIGHT + SIZE_DATA * CONV_4_OUTPUT_NUMBER)
#define BIAS_DENSE7_BIAS (BIAS_DENSE7_WEIGHT + SIZE_DATA * DENSE_7_INPUT_NUMBER * DENSE_7_OUTPUT_NUMBER)
#define BIAS_DENSE8_WEIGHT (BIAS_DENSE7_BIAS + SIZE_DATA * DENSE_7_OUTPUT_NUMBER)
#define BIAS_DENSE8_BIAS (BIAS_DENSE8_WEIGHT + SIZE_DATA * DENSE_8_INPUT_NUMBER * DENSE_8_OUTPUT_NUMBER)

#define BIAS_MNIST_FEATURE (BIAS_DENSE8_BIAS + SIZE_DATA * DENSE_8_OUTPUT_NUMBER)
#define BIAS_MNIST_LABEL (BIAS_MNIST_FEATURE + 500 * LOOP_TIME)

//Memeory Address
#define ADDRESS_USER_START (0x80000)
#define ADDRESS_CONV1_WEIGHT (ADDRESS_USER_START + BIAS_CONV1_WEIGHT)
#define ADDRESS_CONV1_BIAS (ADDRESS_USER_START + BIAS_CONV1_BIAS)
#define ADDRESS_CONV3_WEIGHT (ADDRESS_USER_START + BIAS_CONV3_WEIGHT)
#define ADDRESS_CONV3_BIAS (ADDRESS_USER_START + BIAS_CONV3_BIAS)
#define ADDRESS_CONV4_WEIGHT (ADDRESS_USER_START + BIAS_CONV4_WEIGHT)
#define ADDRESS_CONV4_BIAS (ADDRESS_USER_START + BIAS_CONV4_BIAS)
#define ADDRESS_DENSE7_WEIGHT (ADDRESS_USER_START + BIAS_DENSE7_WEIGHT)
#define ADDRESS_DENSE7_BIAS (ADDRESS_USER_START + BIAS_DENSE7_BIAS)
#define ADDRESS_DENSE8_WEIGHT (ADDRESS_USER_START + BIAS_DENSE8_WEIGHT)
#define ADDRESS_DENSE8_BIAS (ADDRESS_USER_START + BIAS_DENSE8_BIAS)

#define ADDRESS_MNIST_FEATURE (ADDRESS_USER_START + BIAS_MNIST_FEATURE)
#define ADDRESS_MNIST_LABEL (ADDRESS_USER_START + BIAS_MNIST_LABEL)


#endif



#endif /* LENET_DEFINE_H_ */
