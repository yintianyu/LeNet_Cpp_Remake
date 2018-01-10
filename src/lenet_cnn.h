/*
 * lenet_cnn.h
 *
 *  Created on: 2018��1��5��
 *      Author: admin
 */

#ifndef LENET_CNN_H_
#define LENET_CNN_H_
#include "lenet_define.h"
int cnn(int picture[FEATURE_SIZE][FEATURE_SIZE]);
//void cnn_init();


/*typedef*/
struct maps1{
    int W[CONV_1_KERNEL_SIZE][CONV_1_KERNEL_SIZE];
};

struct maps3{
    int W[CONV_3_KERNEL_SIZE][CONV_3_KERNEL_SIZE];
};

struct maps4{
    int W[CONV_4_KERNEL_SIZE][CONV_4_KERNEL_SIZE];
};

struct conv1_layer{
    struct maps1 maps[CONV_1_MAP_NUMBER];
    int bias[CONV_1_OUTPUT_NUMBER];
};

struct conv3_layer{
    struct maps3 maps[CONV_3_MAP_NUMBER];
    int bias[CONV_3_OUTPUT_NUMBER];
};

struct conv4_layer{
    struct maps4 maps[CONV_4_MAP_NUMBER];
    int bias[CONV_4_OUTPUT_NUMBER];
};

struct dense7_layer{
    int W[DENSE_7_OUTPUT_NUMBER][DENSE_7_INPUT_NUMBER];
    int bias[DENSE_7_OUTPUT_NUMBER];
};

struct dense8_layer{
    int W[DENSE_8_OUTPUT_NUMBER][DENSE_8_INPUT_NUMBER];
    int bias[DENSE_8_OUTPUT_NUMBER];
};
//
//template<int MAP_NUM, int KERNEL_SIZE, int OUTPUT_NUMBER, int OUT_SIZE>
//void cnn_init_onelayer(conv_layer<MAP_NUM, KERNEL_SIZE, OUTPUT_NUMBER, OUT_SIZE> *pstLayer, float initnumber);

void forward_Conv_1(int picture[][FEATURE_SIZE]);
void forward_Pooling_2();
void forward_Conv_3();
void forward_Conv_4();
void forward_Pooling_5();
void forward_Flatten_6();
void forward_Dense_7();
int forward_Dense_8();


/*ȫ�ֱ�������*/

extern struct conv1_layer Conv_1;
extern struct conv3_layer Conv_3;
extern struct conv4_layer Conv_4;
extern struct dense7_layer Dense_7;
extern struct dense8_layer Dense_8;

extern int image1[CONV_1_OUTPUT_NUMBER][CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
extern int image2[POOLING_2_OUTPUT_NUMBER][POOLING_2_OUTPUT_SIZE][POOLING_2_OUTPUT_SIZE];
extern int image3[CONV_3_OUTPUT_NUMBER][CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
extern int image4[CONV_4_OUTPUT_NUMBER][CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
extern int image5[POOLING_5_OUTPUT_NUMBER][POOLING_5_OUTPUT_SIZE][POOLING_5_OUTPUT_SIZE];
extern int image6[FLATTEN_6_OUTPUT_NUMBER];
extern int image7[DENSE_7_OUTPUT_NUMBER];

#endif /* LENET_CNN_H_ */
