/*
 * lenet_cnn.cpp
 *
 *  Created on: 2018��1��5��
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
int image1[CONV_1_OUTPUT_NUMBER][CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
int image2[POOLING_2_OUTPUT_NUMBER][POOLING_2_OUTPUT_SIZE][POOLING_2_OUTPUT_SIZE];
int image3[CONV_3_OUTPUT_NUMBER][CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
int image4[CONV_4_OUTPUT_NUMBER][CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
int image5[POOLING_5_OUTPUT_NUMBER][POOLING_5_OUTPUT_SIZE][POOLING_5_OUTPUT_SIZE];
int image6[FLATTEN_6_OUTPUT_NUMBER];
int image7[DENSE_7_OUTPUT_NUMBER];
int image8[DENSE_8_OUTPUT_NUMBER];
int cnn(int picture[FEATURE_SIZE][FEATURE_SIZE])
{
    printf("In cnn.\n");
    forward_Conv_1(picture);
    printf("Conv1 end.\n");
    forward_Pooling_2();
    printf("Pooling2 end.\n");
    forward_Conv_3();
    printf("Conv3 end.\n");
    forward_Conv_4();
    printf("Conv4 end.\n");
    forward_Pooling_5();
    printf("Pooling5 end.\n");
    forward_Flatten_6();
    printf("Flatten6 end.\n");
    forward_Dense_7();
    printf("Dense7 end.\n");
    return forward_Dense_8();
}


/*
 * �������ƣ�forward_Conv_1
 * ���ܣ�Conv_1�����򴫲�����
 * ���룺ͼ�����
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��Ϊ������(2018-1-10)
 */
void forward_Conv_1(int picture[][FEATURE_SIZE])
{
    for(int i = 0; i < CONV_1_OUTPUT_NUMBER; i++)
    {
        int temp[CONV_1_OUTPUT_SIZE][CONV_1_OUTPUT_SIZE];
        matrix_convolution_28_5(picture, Conv_1.maps[i].W, temp);
        matrix_matrice_tanh_24(temp, image1[i], Conv_1.bias[i]);
    }
}

/*
 * �������ƣ�forward_Pooling_2
 * ���ܣ�Pooling_2�����򴫲�����
 * ���룺��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��Ϊ������(2018-1-10)
 */
void forward_Pooling_2()
{
    for(int i = 0; i < POOLING_2_OUTPUT_NUMBER; i++)
    {
        matrix_pooling_24(image1[i], image2[i]);
    }
}

/*
 * �������ƣ�forward_Conv_3
 * ���ܣ�Conv_3�����򴫲�����
 * ���룺��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��Ϊ������(2018-1-10)
 */
void forward_Conv_3()
{
    for(int i = 0; i < CONV_3_OUTPUT_NUMBER; i++)
    {
        int temp[CONV_3_OUTPUT_SIZE][CONV_3_OUTPUT_SIZE];
        int weight_part[POOLING_2_OUTPUT_NUMBER][CONV_3_KERNEL_SIZE][CONV_3_KERNEL_SIZE];
        for (int j = 0; j < POOLING_2_OUTPUT_NUMBER; j++)
        {
            memcpy(weight_part[j], Conv_3.maps[i * POOLING_2_OUTPUT_NUMBER + j].W, sizeof(int) * CONV_3_KERNEL_SIZE * CONV_3_KERNEL_SIZE);
        }
        matrix_multi_convolution_12_3(image2, weight_part, temp);
        matrix_matrice_tanh_10(temp, image3[i], Conv_3.bias[i]);
    }
}


/*
 * �������ƣ�forward_Conv_4
 * ���ܣ�Conv_4�����򴫲�����
 * ���룺��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��Ϊ������(2018-1-10)
 */
void forward_Conv_4()
{
    for(int i = 0; i < CONV_4_OUTPUT_NUMBER; i++)
    {
        int temp[CONV_4_OUTPUT_SIZE][CONV_4_OUTPUT_SIZE];
        int weight_part[CONV_3_OUTPUT_NUMBER][CONV_4_KERNEL_SIZE][CONV_4_KERNEL_SIZE];
        for (int j = 0; j < CONV_3_OUTPUT_NUMBER; j++)
        {
            memcpy(weight_part[j], Conv_4.maps[i * CONV_3_OUTPUT_NUMBER + j].W, sizeof(int) * CONV_4_KERNEL_SIZE * CONV_4_KERNEL_SIZE);
        }
        matrix_multi_convolution_10_3(image3, weight_part, temp);
        matrix_matrice_tanh_8(temp, image4[i], Conv_4.bias[i]);
    }
}


/*
 * �������ƣ�forward_Pooling_5
 * ���ܣ�Pooling_5�����򴫲�����
 * ���룺��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��Ϊ������(2018-1-10)
 */
void forward_Pooling_5()
{
    for(int i = 0; i < POOLING_5_OUTPUT_NUMBER; i++)
    {
        matrix_pooling_8(image4[i], image5[i]);
    }
}


/*
 * �������ƣ�forward_Flatten_6
 * ���ܣ�Flatten_6�����򴫲�����
 * ���룺��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. �����Ȳ㣬�ٳ����ٸ�˳��ֵ(2018-1-8)
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
 * �������ƣ�forward_Dense_7
 * ���ܣ�Dense_7�����򴫲�����
 * ���룺��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��Ϊ������(2018-1-10)
 */
void forward_Dense_7()
{
    int temp[DENSE_7_OUTPUT_NUMBER];
    matrix_MMV_256_128(image6, Dense_7.W, temp);
    matrix_vector_tanh_128(temp, image7, Dense_7.bias);
}

/*
 * �������ƣ�forward_Dense_8
 * ���ܣ�Dense_8�����򴫲�����
 * ���룺��
 * �����Ԥ��ֵ
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��softmax�������image7��Ϊtemp(2018-1-8)
 */
int forward_Dense_8()
{
    int temp[DENSE_8_OUTPUT_NUMBER];
    matrix_MMV_128_10(image7, Dense_8.W, temp);
    return matrix_softmax_10(temp, image8, Dense_7.bias);
}

