/*
 * lenet_matrix.c
 *
 *  Created on: 2018��1��9��
 *      Author: admin
 */



#include <stdio.h>
#include <string.h>
#include "lenet_math.h"
#include "lenet_matrix.h"
/*
 * �������ƣ�matrix_add
 * ���ܣ�����ӷ�����
 * ���룺Ŀ�����ԭ����
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��dst+=dst+src;��Ϊdst=dst+src;(2018-1-8)
 *      3. ��ΪC���(2018-1-9)
 */
void matrix_add_24(float dst[][24], float src[][24])
{
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 24; j++)
        {
            dst[i][j] = dst[i][j] + src[i][j];
        }
    }
}

void matrix_add_10(float dst[][10], float src[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            dst[i][j] = dst[i][j] + src[i][j];
        }
    }
}

void matrix_add_8(float dst[][8], float src[][8])
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
 * �������ƣ�matrix_convolution
 * ���ܣ�����������
 * ���룺ԭͼ�����filter���������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��ΪC���(2018-1-9)
 */
void matrix_convolution_28_5(float picture[][28],
        float kernel[][5],
        float result[][24])
{
    int result_size = 24;
    int kernel_size = 5;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
            float temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += picture[i + k][j + l] * kernel[k][l];
                }
            }
            result[i][j] = temp;
        }
    }
    return;
}

void matrix_convolution_12_3(float picture[][12],
        float kernel[][3],
        float result[][10])
{
    int result_size = 10;
    int kernel_size = 3;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
            float temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += picture[i + k][j + l] * kernel[k][l];
                }
            }
            result[i][j] = temp;
        }
    }
    return;
}

void matrix_convolution_10_3(float picture[][10],
        float kernel[][3],
        float result[][8])
{
    int result_size = 8;
    int kernel_size = 3;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
            float temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += picture[i + k][j + l] * kernel[k][l];
                }
            }
            result[i][j] = temp;
        }
    }
    return;
}

/*
 * �������ƣ�matrix_multi_convolution
 * ���ܣ�������������
 * ���룺ԭͼ�����filter���������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 */
void matrix_multi_convolution_12_3(float pictures[][12][12],
        float kernel[][3][3],
        float result[10][10])
{
    int picture_size=12;
    int kernel_size = 3;
    int picture_number = 6;
    float aggregate[10][10] = {0};
    float temp[10][10];
    for(int i = 0; i < picture_number; i++)
    {
        matrix_convolution_12_3(pictures[i], kernel[i], temp);
        matrix_add_10(aggregate, temp);
    }
    memcpy(result, aggregate, sizeof(float) * (picture_size - kernel_size + 1) * (picture_size - kernel_size + 1));
}

void matrix_multi_convolution_10_3(float pictures[][10][10],
        float kernel[][3][3],
        float result[8][8])
{
    int picture_size=10;
    int kernel_size = 3;
    int picture_number = 8;
    float aggregate[8][8] = {0};
    float temp[8][8];
    for(int i = 0; i < picture_number; i++)
    {
        matrix_convolution_10_3(pictures[i], kernel[i], temp);
        matrix_add_8(aggregate, temp);
    }
    memcpy(result, aggregate, sizeof(float) * (picture_size - kernel_size + 1) * (picture_size - kernel_size + 1));
}

/*
 * �������ƣ�matrix_matrice_tanh
 * ���ܣ��������ÿ��Ԫ�ؼ���ƫ�ú��tanh
 * ���룺ԭͼ����󣬽������ƫ��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��ΪC���(2018-1-9)
 */
void matrix_matrice_tanh_24(float input[][24],
        float output[][24], float bias)
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

void matrix_matrice_tanh_10(float input[][10],
        float output[][10], float bias)
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

void matrix_matrice_tanh_8(float input[][8],
        float output[][8], float bias)
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
 * �������ƣ�matrix_vector_tanh
 * ���ܣ���������ÿ��Ԫ�ؼ���ƫ�ú��tanh
 * ���룺ԭͼ����󣬽������ƫ��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��output[size] = ...��Ϊoutput[i] = ...(2018-1-8)
 *      3. ��ΪC���(2018-1-9)
 */
void matrix_vector_tanh_128(float input[128],
        float output[128],
        float bias[128])
{
    int size = 128;
    for(int i = 0; i < size; i++)
    {
        float temp = input[i] + bias[i];
        output[i] = math_tanh(temp);
    }
    return;
}


/*
 * �������ƣ�matrix_softmax
 * ���ܣ���������ÿ��Ԫ�ؼ���ƫ�ú��softmax
 * ���룺ԭͼ����󣬽������ƫ��
 * ������ȽϺ�������ֵ
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ������softmax�����������(2018-1-8)
 *      3. ��ΪC���(2018-1-9)
 */
int matrix_softmax_10(float input[10],
        float output[10],
        float bias[10])
{
    int inputsize = 10;
    float temp = 0;
    int index = 0;
    for(int i = 0; i < inputsize; i++)
    {
        temp += math_exp(input[i] + bias[i]);
    }
    for(int i = 0; i < inputsize; i++)
    {
        output[i] = (input[i] + bias[i]) / temp;
    }
    for(int i = 0; i < inputsize; i++)
    {
        index = output[i] > output[index] ? i : index;
    }
    return index;
}



/*
 * �������ƣ�matrix_pooling
 * ���ܣ���������maxpooling(�޶���filterΪ2)
 * ���룺ԭͼ����󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      3. ��ΪC���(2018-1-9)
 */
void matrix_pooling_24(float input[24][24], float output[12][12])
{
    int size = 24;
    for(int i = 0;i < size; i += 2)
    {
        for(int j = 0;j < size; j += 2)
        {
            float temp1 = input[i][j] > input[i][j + 1] ? input[i][j] : input[i][j + 1];
            float temp2 = input[i + 1][j] > input[i + 1][j + 1] ? input[i + 1][j] : input[i + 1][j + 1];
            output[i >> 1][j >> 1] = temp1 > temp2 ? temp1 : temp2;
        }
    }
    return;
}
void matrix_pooling_8(float input[8][8], float output[4][4])
{
    int size = 8;
    for(int i = 0;i < size; i += 2)
    {
        for(int j = 0;j < size; j += 2)
        {
            float temp1 = input[i][j] > input[i][j + 1] ? input[i][j] : input[i][j + 1];
            float temp2 = input[i + 1][j] > input[i + 1][j + 1] ? input[i + 1][j] : input[i + 1][j + 1];
            output[i >> 1][j >> 1] = temp1 > temp2 ? temp1 : temp2;
        }
    }
    return;
}

/*
 * �������ƣ�matrix_MMV
 * ���ܣ��������������
 * ���룺ԭͼ��������Ȩ�ؾ��󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. temp��������int��Ϊfloat
 */
void matrix_MMV_256_128(float x[256], float weight[128][256], float output[128])
{
    int input_size = 256;
    int output_size = 128;
    for(int i = 0; i < output_size; i++)
    {
        float temp = 0;
        for(int j = 0; j < input_size; j++)
        {
            temp += x[j] * weight[i][j];
        }
        output[i] = temp;
    }
    return;
}

void matrix_MMV_128_10(float x[128], float weight[10][128], float output[10])
{
    int input_size = 128;
    int output_size = 10;
    for(int i = 0; i < output_size; i++)
    {
        float temp = 0;
        for(int j = 0; j < input_size; j++)
        {
            temp += x[j] * weight[i][j];
        }
        output[i] = temp;
    }
    return;
}
