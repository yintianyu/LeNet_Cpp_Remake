/*
 * lenet_matrix.c
 *
 *  Created on: 2018年1月9日
 *      Author: admin
 */



#include <stdio.h>
#include <string.h>
#include "lenet_math.h"
#include "lenet_matrix.h"
#include "lenet_define.h"
/*
 * 函数名称：matrix_add
 * 功能：矩阵加法运算
 * 输入：目标矩阵，原矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 由dst+=dst+src;改为dst=dst+src;(2018-1-8)
 *      3. 改为C风格(2018-1-9)
 *      4. 改为定点数(2018-1-10)
 */
void matrix_add_24(int dst[][24], int src[][24])
{
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 24; j++)
        {
            dst[i][j] = dst[i][j] + src[i][j];
        }
    }
}

void matrix_add_10(int dst[][10], int src[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            dst[i][j] = dst[i][j] + src[i][j];
        }
    }
}

void matrix_add_8(int dst[][8], int src[][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            dst[i][j] = dst[i][j] + src[i][j];
        }
    }
}

/*
 * 函数名称：matrix_convolution
 * 功能：矩阵卷积运算
 * 输入：原图像矩阵，filter，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 *      3. 改为定点数(2018-1-10)
 */
void matrix_convolution_28_5(int picture[][28],
        int kernel[][5],
        int result[][24])
{
    int result_size = 24;
    int kernel_size = 5;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
#ifdef X86
            int temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += picture[i + k][j + l] * kernel[k][l] >> FLOATPOINT;
                }
            }
            result[i][j] = temp;
#endif // X86
#ifdef RISCV
            result[i][j] = matrix_CMAC_5_s(&picture[i][j], &kernel[0][0], FEATURE_SIZE * SIZE_DATA);
#endif
        }
    }
    return;
}

void matrix_convolution_12_3(int picture[][12],
        int kernel[][3],
        int result[][10])
{
    int result_size = 10;
    int kernel_size = 3;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
#ifdef X86
            int temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += picture[i + k][j + l] * kernel[k][l] >> FLOATPOINT;
                }
            }
            result[i][j] = temp;
#endif // X86
#ifdef RISCV
            result[i][j] = matrix_CMAC_3_s(&picture[i][j], &kernel[0][0], 12 * SIZE_DATA);
#endif // RISCV
        }
    }
    return;
}

void matrix_convolution_10_3(int picture[][10],
        int kernel[][3],
        int result[][8])
{
    int result_size = 8;
    int kernel_size = 3;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
#ifdef X86
            int temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += picture[i + k][j + l] * kernel[k][l] >> FLOATPOINT;
                }
            }
            result[i][j] = temp;
#endif // X86
#ifdef RISCV
            result[i][j] = matrix_CMAC_3_s(&picture[i][j], &kernel[0][0], 10 * SIZE_DATA);
#endif // RISCV
        }
    }
    return;
}

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
        int result[10][10])
{
    int picture_size=12;
    int kernel_size = 3;
    int picture_number = 6;
    int aggregate[10][10] = {0};
    int temp[10][10];
    for(int i = 0; i < picture_number; i++)
    {
        matrix_convolution_12_3(pictures[i], kernel[i], temp);
        matrix_add_10(aggregate, temp);
    }
    memcpy(result, aggregate, sizeof(int) * (picture_size - kernel_size + 1) * (picture_size - kernel_size + 1));
}

void matrix_multi_convolution_10_3(int pictures[][10][10],
        int kernel[][3][3],
        int result[8][8])
{
    int picture_size=10;
    int kernel_size = 3;
    int picture_number = 8;
    int aggregate[8][8] = {0};
    int temp[8][8];
    for(int i = 0; i < picture_number; i++)
    {
        matrix_convolution_10_3(pictures[i], kernel[i], temp);
        matrix_add_8(aggregate, temp);
    }
    memcpy(result, aggregate, sizeof(int) * (picture_size - kernel_size + 1) * (picture_size - kernel_size + 1));
}

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
        int output[][24], int bias)
{
    int size = 24;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            output[i][j] = math_tanh(input[i][j] + bias);
        }
    }
    return;
}

void matrix_matrice_tanh_10(int input[][10],
        int output[][10], int bias)
{
    int size = 10;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            output[i][j] = math_tanh(input[i][j] + bias);
        }
    }
    return;
}

void matrix_matrice_tanh_8(int input[][8],
        int output[][8], int bias)
{
    int size = 8;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            output[i][j] = math_tanh(input[i][j] + bias);
        }
    }
    return;
}
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
        int bias[128])
{
    int size = 128;
    for(int i = 0; i < size; i++)
    {
        int temp = input[i] + bias[i];
        output[i] = math_tanh(temp);
    }
    return;
}


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
        int bias[10])
{
    int inputsize = 10;
    int temp = 0;
    int index = 0;
    for(int i = 0; i < inputsize; i++)
    {
        temp += math_exp(input[i] + bias[i]);
    }
    for(int i = 0; i < inputsize; i++)
    {
        output[i] = ((input[i] + bias[i]) << FLOATPOINT) / temp;
    }
    for(int i = 0; i < inputsize; i++)
    {
        index = output[i] > output[index] ? i : index;
    }
    return index;
}



/*
 * 函数名称：matrix_pooling
 * 功能：计算矩阵的maxpooling(限定了filter为2)
 * 输入：原图像矩阵，结果矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 *      3. 改为定点数(2018-1-10)
 */
void matrix_pooling_24(int input[24][24], int output[12][12])
{
    int size = 24;
    for(int i = 0;i < size; i += 2)
    {
        for(int j = 0;j < size; j += 2)
        {
            int temp1 = input[i][j] > input[i][j + 1] ? input[i][j] : input[i][j + 1];
            int temp2 = input[i + 1][j] > input[i + 1][j + 1] ? input[i + 1][j] : input[i + 1][j + 1];
            output[i >> 1][j >> 1] = temp1 > temp2 ? temp1 : temp2;
        }
    }
    return;
}
void matrix_pooling_8(int input[8][8], int output[4][4])
{
    int size = 8;
    for(int i = 0;i < size; i += 2)
    {
        for(int j = 0;j < size; j += 2)
        {
            int temp1 = input[i][j] > input[i][j + 1] ? input[i][j] : input[i][j + 1];
            int temp2 = input[i + 1][j] > input[i + 1][j + 1] ? input[i + 1][j] : input[i + 1][j + 1];
            output[i >> 1][j >> 1] = temp1 > temp2 ? temp1 : temp2;
        }
    }
    return;
}

/*
 * 函数名称：matrix_MMV
 * 功能：矩阵乘向量运算
 * 输入：原图像向量，权重矩阵，结果向量
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. temp的类型由int改为float
 *      3. 改为定点数(2018-1-10)
 */
void matrix_MMV_256_128(int x[256], int weight[128][256], int output[128])
{
    int input_size = 256;
    int output_size = 128;
    for(int i = 0; i < output_size; i++)
    {
        int temp = 0;
        for(int j = 0; j < input_size; j++)
        {
            temp += (x[j] * weight[i][j]) >> FLOATPOINT;
        }
        output[i] = temp;
    }
    return;
}

void matrix_MMV_128_10(int x[128], int weight[10][128], int output[10])
{
    int input_size = 128;
    int output_size = 10;
    for(int i = 0; i < output_size; i++)
    {
        int temp = 0;
        for(int j = 0; j < input_size; j++)
        {
            temp += x[j] * weight[i][j] >> FLOATPOINT;
        }
        output[i] = temp;
    }
    return;
}
