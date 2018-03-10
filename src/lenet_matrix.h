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
void matrix_add_24(dattp dst[][24], dattp src[][24]);

void matrix_add_10(dattp dst[][10], dattp src[][10]);

void matrix_add_8(dattp dst[][8], dattp src[][8]);


/*
 * 函数名称：matrix_convolution
 * 功能：矩阵卷积运算
 * 输入：原图像矩阵，filter，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 */
void matrix_convolution_28_5(dattp picture[][28],
        dattp kernel[][5],
        dattp result[][24]);


void matrix_convolution_12_3(dattp picture[][12],
        dattp kernel[][3],
        dattp result[][10]);

void matrix_convolution_10_3(dattp picture[][10],
        dattp kernel[][3],
        dattp result[][8]);

/*
 * 函数名称：matrix_multi_convolution
 * 功能：多层矩阵卷积运算
 * 输入：原图像矩阵，filter，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
void matrix_multi_convolution_12_3(dattp pictures[][12][12],
        dattp kernel[][3][3],
        dattp result[10][10]);

void matrix_multi_convolution_10_3(dattp pictures[][10][10],
        dattp kernel[][3][3],
        dattp result[8][8]);

/*
 * 函数名称：matrix_matrice_tanh
 * 功能：计算矩阵每个元素加上偏置后的tanh
 * 输入：原图像矩阵，结果矩阵，偏置
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 */
void matrix_matrice_tanh_24(dattp input[][24],
        dattp output[][24], dattp bias);

void matrix_matrice_tanh_10(dattp input[][10],
        dattp output[][10], dattp bias);

void matrix_matrice_tanh_8(dattp input[][8],
        dattp output[][8], dattp bias);

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
void matrix_vector_tanh_128(dattp input[128],
        dattp output[128],
        dattp bias[128]);

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
dattp matrix_softmax_10(dattp input[10],
        dattp output[10],
        dattp bias[10]);



/*
 * 函数名称：matrix_pooling
 * 功能：计算矩阵的maxpooling(限定了filter为2)
 * 输入：原图像矩阵，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      3. 改为C风格(2018-1-9)
 */
void matrix_pooling_24(dattp input[24][24], dattp output[12][12]);

void matrix_pooling_8(dattp input[8][8], dattp output[4][4]);

/*
 * 函数名称：matrix_MMV
 * 功能：矩阵乘向量运算
 * 输入：原图像向量，权重矩阵，结果向量
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. temp的类型由int改为float
 */
void matrix_MMV_256_128(dattp x[256], dattp weight[128][256], dattp output[128]);

void matrix_MMV_128_10(dattp x[128], dattp weight[10][128], dattp output[10]);


/*
 * 函数名称：matrix_CMAC_5_s
 * 功能：调用CMAC模块进行计算
 * 输入：data地址，weight地址
 * 输出：乘累加结果
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. temp的类型由int改为float
 */
#ifdef RISCV_DLA
extern dattp matrix_CMAC_5_s(dattp *data, dattp *weight, dattp FeatureSize);
extern dattp matrix_CMAC_3_s(dattp *data, dattp *weight, dattp FeatureSize);
extern dattp matrix_MMV_256_s(dattp *data, dattp *weight);
extern dattp matrix_MMV_128_s(dattp *data, dattp *weight);
extern void matrix_convolution_28_5_s(dattp picture[][28],
        dattp kernel[][5],
        dattp result[][24]);
extern void matrix_convolution_12_3_s(dattp picture[][12],
        dattp kernel[][3],
        dattp result[][10]);
extern void matrix_convolution_10_3_s(dattp picture[][10],
        dattp kernel[][3],
        dattp result[][8]);
#endif // RISCV_DLA

#endif /* LENET_MATRIX_H_ */
