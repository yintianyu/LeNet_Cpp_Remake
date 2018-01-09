/*
 * lenet_matrix.h
 *
 *  Created on: 2018年1月6日
 *      Author: admin
 */

#ifndef LENET_MATRIX_H_
#define LENET_MATRIX_H_


#include <stdio.h>
#include "lenet_math.h"
/*
 * 函数名称：matrix_add
 * 功能：矩阵加法运算
 * 输入：目标矩阵，原矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 由dst+=dst+src;改为dst=dst+src;(2018-1-8)
 *      3. 改为C风格(2018-1-9)
 */
void matrix_add_24(float dst[][24], float src[][24]);

void matrix_add_10(float dst[][10], float src[][10]);

void matrix_add_8(float dst[][8], float src[][8]);


/*
 * 函数名称：matrix_convolution
 * 功能：矩阵卷积运算
 * 输入：原图像矩阵，filter，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 */
void matrix_convolution_28_5(float picture[][28],
        float kernel[][5],
        float result[][24]);


void matrix_convolution_12_3(float picture[][12],
        float kernel[][3],
        float result[][10]);

void matrix_convolution_10_3(float picture[][10],
        float kernel[][3],
        float result[][8]);

/*
 * 函数名称：matrix_multi_convolution
 * 功能：多层矩阵卷积运算
 * 输入：原图像矩阵，filter，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void matrix_multi_convolution_12_3(float pictures[][12][12],
        float kernel[][3][3],
        float result[10][10]);

void matrix_multi_convolution_10_3(float pictures[][10][10],
        float kernel[][3][3],
        float result[8][8]);

/*
 * 函数名称：matrix_matrice_tanh
 * 功能：计算矩阵每个元素加上偏置后的tanh
 * 输入：原图像矩阵，结果矩阵，偏置
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 */
void matrix_matrice_tanh_24(float input[][24],
        float output[][24], float bias);

void matrix_matrice_tanh_10(float input[][10],
        float output[][10], float bias);

void matrix_matrice_tanh_8(float input[][8],
        float output[][8], float bias);

/*
 * 函数名称：matrix_vector_tanh
 * 功能：计算向量每个元素加上偏置后的tanh
 * 输入：原图像矩阵，结果矩阵，偏置
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 把output[size] = ...改为output[i] = ...(2018-1-8)
 *      3. 改为C风格(2018-1-9)
 */
void matrix_vector_tanh_128(float input[128],
        float output[128],
        float bias[128]);

/*
 * 函数名称：matrix_softmax
 * 功能：计算向量每个元素加上偏置后的softmax
 * 输入：原图像矩阵，结果矩阵，偏置
 * 输出：比较后的输出数值
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 增加了softmax计算结果的输出(2018-1-8)
 *      3. 改为C风格(2018-1-9)
 */
int matrix_softmax_10(float input[10],
        float output[10],
        float bias[10]);



/*
 * 函数名称：matrix_pooling
 * 功能：计算矩阵的maxpooling(限定了filter为2)
 * 输入：原图像矩阵，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      3. 改为C风格(2018-1-9)
 */
void matrix_pooling_24(float input[24][24], float output[12][12]);

void matrix_pooling_8(float input[8][8], float output[4][4]);

/*
 * 函数名称：matrix_MMV
 * 功能：矩阵乘向量运算
 * 输入：原图像向量，权重矩阵，结果向量
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. temp的类型由int改为float
 */
void matrix_MMV_256_128(float x[256], float weight[128][256], float output[128]);

void matrix_MMV_128_10(float x[128], float weight[10][128], float output[10]);

#endif /* LENET_MATRIX_H_ */
