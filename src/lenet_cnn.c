/*
 * lenet_cnn.cpp
 *
 *  Created on: 2018年1月5日
 *      Author: admin
 */
#include <string.h>
#include "lenet_matrix.h"
#include "lenet_cnn.h"

/* Layers */
struct conv1_layer Conv_1;
struct conv3_layer Conv_3;
struct conv4_layer Conv_4;
struct dense7_layer Dense_7;
struct dense8_layer Dense_8;


/* Features of the layers*/
float image1[CONV_1_OUTPUT_NUMBER][CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
float image2[POOLING_2_OUTPUT_NUMBER][POOLING_2_OUTPUT_SIZE][POOLING_2_OUTPUT_SIZE];
float image3[CONV_3_OUTPUT_NUMBER][CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
float image4[CONV_4_OUTPUT_NUMBER][CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
float image5[POOLING_5_OUTPUT_NUMBER][POOLING_5_OUTPUT_SIZE][POOLING_5_OUTPUT_SIZE];
float image6[FLATTEN_6_OUTPUT_NUMBER];
float image7[DENSE_7_OUTPUT_NUMBER];
float image8[DENSE_8_OUTPUT_NUMBER];
int cnn(float picture[FEATURE_SIZE][FEATURE_SIZE])
{
    forward_Conv_1(picture);
    forward_Pooling_2();
    forward_Conv_3();
    forward_Conv_4();
    forward_Pooling_5();
    forward_Flatten_6();
    forward_Dense_7();
    return forward_Dense_8();
}


/*
 * 函数名称：forward_Conv_1
 * 功能：Conv_1的正向传播计算
 * 输入：图像矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void forward_Conv_1(float picture[][FEATURE_SIZE])
{
    for(int i = 0; i < CONV_1_OUTPUT_NUMBER; i++)
    {
        float temp[CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
        matrix_convolution_28_5(picture, Conv_1.maps[i].W, temp);
        matrix_matrice_tanh_24(temp, image1[i], Conv_1.bias[i]);
    }
}

/*
 * 函数名称：forward_Pooling_2
 * 功能：Pooling_2的正向传播计算
 * 输入：无
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void forward_Pooling_2()
{
    for(int i = 0; i < POOLING_2_OUTPUT_NUMBER; i++)
    {
        matrix_pooling_24(image1[i], image2[i]);
    }
}

/*
 * 函数名称：forward_Conv_3
 * 功能：Conv_3的正向传播计算
 * 输入：无
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void forward_Conv_3()
{
    for(int i = 0; i < CONV_3_OUTPUT_NUMBER; i++)
    {
        float temp[CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
        float weight_part[POOLING_2_OUTPUT_NUMBER][CONV_3_KERNEL_SIZE][CONV_3_KERNEL_SIZE];
        for (int j = 0; j < POOLING_2_OUTPUT_NUMBER; j++)
        {
            memcpy(weight_part[j], Conv_3.maps[i * POOLING_2_OUTPUT_NUMBER + j].W, sizeof(float) * CONV_3_KERNEL_SIZE * CONV_3_KERNEL_SIZE);
        }
        matrix_multi_convolution_12_3(image2, weight_part, temp);
        matrix_matrice_tanh_10(temp, image3[i], Conv_3.bias[i]);
    }
}


/*
 * 函数名称：forward_Conv_4
 * 功能：Conv_4的正向传播计算
 * 输入：无
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void forward_Conv_4()
{
    for(int i = 0; i < CONV_4_OUTPUT_NUMBER; i++)
    {
        float temp[CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
        float weight_part[CONV_3_OUTPUT_NUMBER][CONV_4_KERNEL_SIZE][CONV_4_KERNEL_SIZE];
        for (int j = 0; j < CONV_3_OUTPUT_NUMBER; j++)
        {
            memcpy(weight_part[j], Conv_4.maps[i * CONV_3_OUTPUT_NUMBER + j].W, sizeof(float) * CONV_4_KERNEL_SIZE * CONV_4_KERNEL_SIZE);
        }
        matrix_multi_convolution_10_3(image3, weight_part, temp);
        matrix_matrice_tanh_8(temp, image4[i], Conv_4.bias[i]);
    }
}


/*
 * 函数名称：forward_Pooling_5
 * 功能：Pooling_5的正向传播计算
 * 输入：无
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void forward_Pooling_5()
{
    for(int i = 0; i < POOLING_5_OUTPUT_NUMBER; i++)
    {
        matrix_pooling_8(image4[i], image5[i]);
    }
}


/*
 * 函数名称：forward_Flatten_6
 * 功能：Flatten_6的正向传播计算
 * 输入：无
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 按照先层，再长，再高顺序赋值(2018-1-8)
 */
void forward_Flatten_6()
{
    for(int i = 0; i < POOLING_5_OUTPUT_NUMBER; i++)
    {
        for(int j = 0; j < POOLING_5_OUTPUT_SIZE; j++)
        {
            for(int k = 0; k < POOLING_5_OUTPUT_SIZE; k++)
            {
                image6[j * POOLING_5_OUTPUT_SIZE * POOLING_5_OUTPUT_NUMBER + k * POOLING_5_OUTPUT_NUMBER + i] = image5[i][j][k];
            }
        }
    }
}


/*
 * 函数名称：forward_Dense_7
 * 功能：Dense_7的正向传播计算
 * 输入：无
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void forward_Dense_7()
{
    float temp[DENSE_7_OUTPUT_NUMBER];
    matrix_MMV_256_128(image6, Dense_7.W, temp);
    matrix_vector_tanh_128(temp, image7, Dense_7.bias);
}

/*
 * 函数名称：forward_Dense_8
 * 功能：Dense_8的正向传播计算
 * 输入：无
 * 输出：预测值
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 把softmax的输入从image7改为temp(2018-1-8)
 */
int forward_Dense_8()
{
    float temp[DENSE_8_OUTPUT_NUMBER];
    matrix_MMV_128_10(image7, Dense_8.W, temp);
    return matrix_softmax_10(temp, image8, Dense_7.bias);
}

