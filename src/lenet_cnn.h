/*
 * lenet_cnn.h
 *
 *  Created on: 2018年1月5日
 *      Author: admin
 */

#ifndef LENET_CNN_H_
#define LENET_CNN_H_
#include "lenet_define.h"
int cnn(float picture[FEATURE_SIZE][FEATURE_SIZE]);
//void cnn_init();


/*typedef*/
template <int KERNEL_SIZE>
struct kernel{
    float W[KERNEL_SIZE][KERNEL_SIZE];
//    float delta_W[KERNEL_SIZE][KERNEL_SIZE];
};


template<int MAP_NUM, int KERNEL_SIZE, int OUTPUT_NUM, int OUT_SIZE>
struct conv_layer{
    struct kernel<KERNEL_SIZE> maps[MAP_NUM];
    float bias[OUTPUT_NUM];
//    float delta_bias[OUTPUT_NUM];
//    float Loss[OUTPUT_NUM][OUT_SIZE][OUT_SIZE];
};

template<int input_number, int output_number>
struct dense_layer{
    float W[output_number][input_number];
    float bias[output_number];
};

//
//template<int MAP_NUM, int KERNEL_SIZE, int OUTPUT_NUMBER, int OUT_SIZE>
//void cnn_init_onelayer(conv_layer<MAP_NUM, KERNEL_SIZE, OUTPUT_NUMBER, OUT_SIZE> *pstLayer, float initnumber);

void forward_Conv_1(float picture[][FEATURE_SIZE]);
void forward_Pooling_2();
void forward_Conv_3();
void forward_Conv_4();
void forward_Pooling_5();
void forward_Flatten_6();
void forward_Dense_7();
int forward_Dense_8();


/*全局变量声明*/

extern struct conv_layer<CONV_1_MAP_NUMBER, CONV_1_KERNEL_SIZE, CONV_1_OUTPUT_NUMBER, CONV_1_OUTPUT_SIZE> Conv_1;
extern struct conv_layer<CONV_3_MAP_NUMBER, CONV_3_KERNEL_SIZE, CONV_3_OUTPUT_NUMBER, CONV_3_OUTPUT_SIZE> Conv_3;
extern struct conv_layer<CONV_4_MAP_NUMBER, CONV_4_KERNEL_SIZE, CONV_4_OUTPUT_NUMBER, CONV_4_OUTPUT_SIZE> Conv_4;
extern struct dense_layer<DENSE_7_INPUT_NUMBER, DENSE_7_OUTPUT_NUMBER> Dense_7;
extern struct dense_layer<DENSE_8_INPUT_NUMBER, DENSE_8_OUTPUT_NUMBER> Dense_8;

extern float image1[CONV_1_OUTPUT_NUMBER][CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
extern float image2[POOLING_2_OUTPUT_NUMBER][POOLING_2_OUTPUT_SIZE][POOLING_2_OUTPUT_SIZE];
extern float image3[CONV_3_OUTPUT_NUMBER][CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
extern float image4[CONV_4_OUTPUT_NUMBER][CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
extern float image5[POOLING_5_OUTPUT_NUMBER][POOLING_5_OUTPUT_SIZE][POOLING_5_OUTPUT_SIZE];
extern float image6[FLATTEN_6_OUTPUT_NUMBER];
extern float image7[DENSE_7_OUTPUT_NUMBER];

#endif /* LENET_CNN_H_ */
