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
#if (defined RISCV) || (defined RISCV_DLA)
dattp** image1[6] = {(dattp**)(0xF0030000 + 2304 * 0), (dattp**)(0xF0030000 + 2304 * 1), (dattp**)(0xF0030000 + 2304 * 2), (dattp**)(0xF0030000 + 2304 * 3), (dattp**)(0xF0030000 + 2304 * 4)\
        , (dattp**)(0xF0030000 + 2304 * 5)};
dattp** image2[6] = {(dattp**)(0xF0033600 + 576 * 0), (dattp**)(0xF0033600 + 576 * 1), (dattp**)(0xF0033600 + 576 * 2)\
        , (dattp**)(0xF0033600 + 576 * 3), (dattp**)(0xF0033600 + 576 * 4), (dattp**)(0xF0033600 + 576 * 5)};
dattp** image3[8] = {(dattp**)(0xF0034380 + 400 * 0), (dattp**)(0xF0034380 + 400 * 1), (dattp**)(0xF0034380 + 400 * 2)\
        , (dattp**)(0xF0034380 + 400 * 3), (dattp**)(0xF0034380 + 400 * 4), (dattp**)(0xF0034380 + 400 * 5), (dattp**)(0xF0034380 + 400 * 6)\
        , (dattp**)(0xF0034380 + 400 * 7)};
dattp** image4[16] = {(dattp**)(0xF0035000 + 256 * 0), (dattp**)(0xF0035000 + 256 * 1), (dattp**)(0xF0035000 + 256 * 2)\
        , (dattp**)(0xF0035000 + 256 * 3), (dattp**)(0xF0035000 + 256 * 4), (dattp**)(0xF0035000 + 256 * 5), (dattp**)(0xF0035000 + 256 * 6)\
        , (dattp**)(0xF0035000 + 256 * 7), (dattp**)(0xF0035000 + 256 * 8), (dattp**)(0xF0035000 + 256 * 9), (dattp**)(0xF0035000 + 256 * 10)\
        , (dattp**)(0xF0035000 + 256 * 11), (dattp**)(0xF0035000 + 256 * 12), (dattp**)(0xF0035000 + 256 * 13), (dattp**)(0xF0035000 + 256 * 14)\
        , (dattp**)(0xF0035000 + 256 * 15)};
dattp** image5[16] = {(dattp**)(0xF0036000 + 64 * 0), (dattp**)(0xF0036000 + 64 * 1), (dattp**)(0xF0036000 + 64 * 2), (dattp**)(0xF0036000 + 64 * 3)\
        , (dattp**)(0xF0036000 + 64 * 4), (dattp**)(0xF0036000 + 64 * 5), (dattp**)(0xF0036000 + 64 * 6), (dattp**)(0xF0036000 + 64 * 7)\
        , (dattp**)(0xF0036000 + 64 * 8), (dattp**)(0xF0036000 + 64 * 9), (dattp**)(0xF0036000 + 64 * 10), (dattp**)(0xF0036000 + 64 * 11)\
        , (dattp**)(0xF0036000 + 64 * 12), (dattp**)(0xF0036000 + 64 * 13), (dattp**)(0xF0036000 + 64 * 14), (dattp**)(0xF0036000 + 64 * 15)};
dattp* image6 = (dattp*)0xF0036400;
dattp* image7 = (dattp*)0xF0036800;
dattp* image8 = (dattp*)0xF0036a00;
#endif
#ifdef X86
dattp image1[CONV_1_OUTPUT_NUMBER][CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
dattp image2[POOLING_2_OUTPUT_NUMBER][POOLING_2_OUTPUT_SIZE][POOLING_2_OUTPUT_SIZE];
dattp image3[CONV_3_OUTPUT_NUMBER][CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
dattp image4[CONV_4_OUTPUT_NUMBER][CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
dattp image5[POOLING_5_OUTPUT_NUMBER][POOLING_5_OUTPUT_SIZE][POOLING_5_OUTPUT_SIZE];
dattp image6[FLATTEN_6_OUTPUT_NUMBER];
dattp image7[DENSE_7_OUTPUT_NUMBER];
dattp image8[DENSE_8_OUTPUT_NUMBER];
#endif
dattp cnn(dattp picture[FEATURE_SIZE][FEATURE_SIZE])
{
#ifdef RISCV
    //printf("In cnn.\n");
#endif
    forward_Conv_1(picture);
#ifdef X86_DEBUG
//    for (int i = 0; i < CONV_1_OUTPUT_NUMBER; i++)
//    {
//        for (int j = 0; j < CONV_1_OUTPUT_SIZE; j++)
//        {
//            for (int k = 0; k < CONV_1_OUTPUT_SIZE; k++)
//            {
//                printf("%f ", ((float)image1[i][j][k]) / 4096);
//            }
//            printf("\n");
//        }
//        printf("************************************************\n\n");
//    }
#endif
#ifdef RISCV
    printf("Conv1 end.\n");
#ifdef RISCV_DEBUG
//    for (int i = 0; i < 24; i ++)
//    {
//        for(int j = 0; j < 24; j++)
//        {
//            printf("%x ", image1[0][i * 24 + j]);
//        }
//        printf("\n");
//    }
//    printf("\n\n\n\n");
#endif
#endif
    forward_Pooling_2();
#ifdef RISCV
    printf("Pooling2 end.\n");
#endif
#ifdef RISCV_DEBUG
    for (int i = 0; i < 12; i ++)
    {
        for(int j = 0; j < 12; j++)
        {
            printf("%x ", image2[0][i * 12 + j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
#endif
    forward_Conv_3();
#ifdef X86_DEBUG
//    for (int i = 0; i < CONV_3_OUTPUT_NUMBER; i++)
//    {
//        for (int j = 0; j < CONV_3_OUTPUT_SIZE; j++)
//        {
//            for (int k = 0; k < CONV_3_OUTPUT_SIZE; k++)
//            {
//                printf("%f ", ((float)image3[i][j][k]) / 4096);
//            }
//            printf("\n");
//        }
//        printf("************************************************\n\n");
//    }
#endif
#ifdef RISCV
    printf("Conv3 end.\n");
#ifdef RISCV_DEBUG
    for (int i = 0; i < 10; i ++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%x ", image3[0][i * 10 + j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
#endif
#endif
    forward_Conv_4();
#ifdef X86_DEBUG
//    for (int i = 0; i < CONV_4_OUTPUT_NUMBER; i++)
//    {
//        for (int j = 0; j < CONV_4_OUTPUT_SIZE; j++)
//        {
//            for (int k = 0; k < CONV_4_OUTPUT_SIZE; k++)
//            {
//                printf("%f ", ((float)image4[i][j][k]) / 4096);
//            }
//            printf("\n");
//        }
//        printf("************************************************\n\n");
//    }
#endif
#ifdef RISCV
    printf("Conv4 end.\n");
#ifdef RISCV_DEBUG
    for (int i = 0; i < 8; i ++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%x ", image4[0][i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
#endif
#endif
    forward_Pooling_5();
#ifdef RISCV
    printf("Pooling5 end.\n");
#ifdef RISCV_DEBUG
    for (int i = 0; i < 4; i ++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%x ", image5[0][i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
#endif
#endif
    forward_Flatten_6();
#ifdef RISCV
    printf("Flatten6 end.\n");
#endif
    forward_Dense_7();
#ifdef X86_DEBUG
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%f ", ((float)image7[i * 8 + j]) / 4096);
        }
        printf("\n");
    }
    printf("*************************************************\n");
#endif
#ifdef RISCV
    printf("Dense7 end.\n");
#ifdef RISCV_DEBUG
    for (int i = 0; i < 16; i ++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%x ", image7[i * 8 + j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
#endif
#endif
    dattp temp = forward_Dense_8();
#ifdef X86_DEBUG
    for(int i = 0; i < 10; i++)
    {
        printf("%f ", ((float)image8[i]) / 4096);
        printf("\n");
    }
    printf("*************************************************\n");
#endif
    return temp;
}


/*
 * 函数名称：forward_Conv_1
 * 功能：Conv_1的正向传播计算
 * 输入：图像矩阵
 * 输出：无
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为定点数(2018-1-10)
 */
void forward_Conv_1(dattp picture[][FEATURE_SIZE])
{
    for(int i = 0; i < CONV_1_OUTPUT_NUMBER; i++)
    {
        dattp temp[CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
#if (defined X86) || (defined RISCV)
        matrix_convolution_28_5(picture, Conv_1.maps[i].W, temp);
#endif // X86 || RISCV
#ifdef RISCV_DEBUG
        matrix_convolution_28_5_s(picture, Conv_1.maps[i].W, temp);
#endif // RISCV
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
 *      2. 改为定点数(2018-1-10)
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
 *      2. 改为定点数(2018-1-10)
 */
void forward_Conv_3()
{
    for(int i = 0; i < CONV_3_OUTPUT_NUMBER; i++)
    {
        dattp temp[CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
        dattp weight_part[POOLING_2_OUTPUT_NUMBER][CONV_3_KERNEL_SIZE][CONV_3_KERNEL_SIZE];
        for (int j = 0; j < POOLING_2_OUTPUT_NUMBER; j++)
        {
            memcpy(weight_part[j], Conv_3.maps[i * POOLING_2_OUTPUT_NUMBER + j].W, sizeof(dattp) * CONV_3_KERNEL_SIZE * CONV_3_KERNEL_SIZE);
        }
//        printf("i == %x\n", i);
//        for (int j = 0; j < CONV_3_KERNEL_SIZE; j++)
//        {
//            for(int k = 0; k < CONV_3_KERNEL_SIZE; k++)
//            {
//                printf("%x ", weight_part[0][j][k]);
//            }
//            printf("\n");
//        }
#ifdef X86
        matrix_multi_convolution_12_3(image2, weight_part, temp);
#endif // X86
#if (defined RISCV) || (defined RISCV_DEBUG)
        matrix_multi_convolution_12_3(image2[0], weight_part, temp);
#endif
//        printf("i == %x\n", i);
//        for (int j = 0; j < CONV_3_OUTPUT_SIZE; j++)
//        {
//            for(int k = 0; k < CONV_3_OUTPUT_SIZE; k++)
//            {
//                printf("%x ", temp[j][k]);
//            }
//            printf("\n");
//        }
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
 *      2. 改为定点数(2018-1-10)
 */
void forward_Conv_4()
{
    for(int i = 0; i < CONV_4_OUTPUT_NUMBER; i++)
    {
        dattp temp[CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
        dattp weight_part[CONV_3_OUTPUT_NUMBER][CONV_4_KERNEL_SIZE][CONV_4_KERNEL_SIZE];
        for (int j = 0; j < CONV_3_OUTPUT_NUMBER; j++)
        {
            memcpy(weight_part[j], Conv_4.maps[i * CONV_3_OUTPUT_NUMBER + j].W, sizeof(dattp) * CONV_4_KERNEL_SIZE * CONV_4_KERNEL_SIZE);
        }
        matrix_multi_convolution_10_3(image3[0], weight_part, temp);
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
 *      2. 改为定点数(2018-1-10)
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
#ifdef X86
                image6[j * POOLING_5_OUTPUT_SIZE * POOLING_5_OUTPUT_NUMBER + k * POOLING_5_OUTPUT_NUMBER + i] = image5[i][j][k];
#endif // X86
#if (defined RISCV) || (defined RISCV_DLA)
                image6[j * POOLING_5_OUTPUT_SIZE * POOLING_5_OUTPUT_NUMBER + k * POOLING_5_OUTPUT_NUMBER + i] = image5[i][j * POOLING_5_OUTPUT_SIZE + k];
#endif // (defined RISCV) || (defined RISCV_DLA)
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
 *      2. 改为定点数(2018-1-10)
 */
void forward_Dense_7()
{
    dattp temp[DENSE_7_OUTPUT_NUMBER];
    matrix_MMV_256_128(image6, Dense_7.W, temp);
//    printf("Dense7 temp:\n");
//    for(int i = 0; i < DENSE_7_OUTPUT_NUMBER;i++)
//    {
//        printf("0x%x\n", temp[i]);
//    }
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
dattp forward_Dense_8()
{
    dattp temp[DENSE_8_OUTPUT_NUMBER];
    matrix_MMV_128_10(image7, Dense_8.W, temp);
//    printf("Dense8 temp:\n");
//    for(int i = 0; i < DENSE_8_OUTPUT_NUMBER;i++)
//    {
//        printf("0x%x\n", temp[i]);
//    }
    return matrix_softmax_10(temp, image8, Dense_7.bias);
}

