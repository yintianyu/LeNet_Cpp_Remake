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
void matrix_add_24(int dst[][24], int src[][24]);

void matrix_add_10(int dst[][10], int src[][10]);

void matrix_add_8(int dst[][8], int src[][8]);


/*
 * 函数名称：matrix_convolution
 * 功能：矩阵卷积运算
 * 输入：原图像矩阵，filter，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 */
void matrix_convolution_28_5(int picture[][28],
        int kernel[][5],
        int result[][24]);


void matrix_convolution_12_3(int picture[][12],
        int kernel[][3],
        int result[][10]);

void matrix_convolution_10_3(int picture[][10],
        int kernel[][3],
        int result[][8]);

/*
 * 函数名称：matrix_multi_convolution
 * 功能：多层矩阵卷积运算
 * 输入：原图像矩阵，filter，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void matrix_multi_convolution_12_3(int pictures[][12][12],
        int kernel[][3][3],
        int result[10][10]);

void matrix_multi_convolution_10_3(int pictures[][10][10],
        int kernel[][3][3],
        int result[8][8]);

/*
 * 函数名称：matrix_matrice_tanh
 * 功能：计算矩阵每个元素加上偏置后的tanh
 * 输入：原图像矩阵，结果矩阵，偏置
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 */
void matrix_matrice_tanh_24(int input[][24],
        int output[][24], int bias);

void matrix_matrice_tanh_10(int input[][10],
        int output[][10], int bias);

void matrix_matrice_tanh_8(int input[][8],
        int output[][8], int bias);

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
void matrix_vector_tanh_128(int input[128],
        int output[128],
        int bias[128]);

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
int matrix_softmax_10(int input[10],
        int output[10],
        int bias[10]);



/*
 * 函数名称：matrix_pooling
 * 功能：计算矩阵的maxpooling(限定了filter为2)
 * 输入：原图像矩阵，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      3. 改为C风格(2018-1-9)
 */
void matrix_pooling_24(int input[24][24], int output[12][12]);

void matrix_pooling_8(int input[8][8], int output[4][4]);

/*
 * 函数名称：matrix_MMV
 * 功能：矩阵乘向量运算
 * 输入：原图像向量，权重矩阵，结果向量
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. temp的类型由int改为float
 */
void matrix_MMV_256_128(int x[256], int weight[128][256], int output[128]);

void matrix_MMV_128_10(int x[128], int weight[10][128], int output[10]);


/*
 * 函数名称：matrix_CMAC_5_s
 * 功能：调用CMAC模块进行计算
 * 输入：data地址，weight地址
 * 输出：乘累加结果
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. temp的类型由int改为float
 */
#ifdef RISCV
extern int matrix_CMAC_5_s(int *data, int *weight, int FeatureSize);
extern int matrix_CMAC_3_s(int *data, int *weight, int FeatureSize);
extern int matrix_MMV_256_s(int *data, int *weight);
extern int matrix_MMV_128_s(int *data, int *weight);
extern void matrix_convolution_28_5_s(int picture[][28],
        int kernel[][5],
        int result[][24]);
extern void matrix_convolution_12_3_s(int picture[][12],
        int kernel[][3],
        int result[][10]);
extern void matrix_convolution_10_3_s(int picture[][10],
        int kernel[][3],
        int result[][8]);
#endif // RISCV

#endif /* LENET_MATRIX_H_ */
