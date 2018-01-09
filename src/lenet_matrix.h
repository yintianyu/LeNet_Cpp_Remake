/*
 * lenet_matrix.h
 *
 *  Created on: 2018��1��6��
 *      Author: admin
 */

#ifndef LENET_MATRIX_H_
#define LENET_MATRIX_H_


#include <cstdio>
#include "lenet_math.h"
using namespace std;
/*
 * �������ƣ�matrix_add
 * ���ܣ�����ӷ�����
 * ���룺Ŀ�����ԭ����
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��dst+=dst+src;��Ϊdst=dst+src;(2018-1-8)
 */
template<int picture_size>
void matrix_add(float dst[picture_size][picture_size], const float src[picture_size][picture_size])
{
    for(int i = 0; i < picture_size; i++)
    {
        for(int j = 0; j < picture_size; j++)
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
 */
template<int picture_size, int kernel_size>
void matrix_convolution(const float picture[][picture_size],
        const float kernel[][kernel_size],
        float result[][picture_size - kernel_size + 1])
{
    int result_size = picture_size - kernel_size + 1;
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
template<int picture_size, int picture_number, int kernel_size>
void matrix_multi_convolution(const float pictures[picture_number][picture_size][picture_size],
        const float kernel[picture_number][kernel_size][kernel_size],
        float result[picture_size - kernel_size + 1][picture_size - kernel_size + 1])
{
    float aggregate[picture_size - kernel_size + 1][picture_size - kernel_size + 1] = {0};
    float temp[picture_size - kernel_size + 1][picture_size - kernel_size + 1];
    for(int i = 0; i < picture_number; i++)
    {
        matrix_convolution<picture_size, kernel_size>(pictures[i], kernel[i], temp);
        matrix_add<picture_size - kernel_size + 1>(aggregate, temp);
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
 */
template<int size>
void matrix_matrice_tanh(const float input[][size],
        float output[][size], const float &bias)
{
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
 */
template<int size>
void matrix_vector_tanh(const float input[size],
        float output[size],
        const float bias[size])
{
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
 */
template<int inputsize>
int matrix_softmax(const float input[inputsize],
        float output[inputsize],
        const float bias[inputsize])
{
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
 */
template<int size>
void matrix_pooling(float input[size][size], float output[size / 2][size / 2])
{
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
template<int input_size, int output_size>
void matrix_MMV(float x[input_size], float weight[output_size][input_size], float output[output_size])
{
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

#endif /* LENET_MATRIX_H_ */
