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
#include "lenet_define.h"
/*
 * �������ƣ�matrix_add
 * ���ܣ�����ӷ�����
 * ���룺Ŀ�����ԭ����
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��dst+=dst+src;��Ϊdst=dst+src;(2018-1-8)
 *      3. ��ΪC���(2018-1-9)
 *      4. ��Ϊ������(2018-1-10)
 */
void matrix_add_24(dattp dst[][24], dattp src[][24])
{
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 24; j++)
        {
            dst[i][j] = dst[i][j] + src[i][j];
        }
    }
}

void matrix_add_10(dattp dst[][10], dattp src[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            dst[i][j] = dst[i][j] + src[i][j];
        }
    }
}

void matrix_add_8(dattp dst[][8], dattp src[][8])
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
 *      3. ��Ϊ������(2018-1-10)
 */
#if (defined X86) || (defined RISCV)
void matrix_convolution_28_5(dattp picture[][28],
        dattp kernel[][5],
        dattp result[][24])
{
    int result_size = 24;
    int kernel_size = 5;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
            dattp temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += ((ldattp)picture[i + k][j + l] * (ldattp)kernel[k][l]) >> FLOATPOINT;
                }
            }
            result[i][j] = temp;
        }
    }
    return;
}
#endif // X86

#ifdef RISCV

#endif

#if (defined X86) || (defined RISCV)
void matrix_convolution_12_3(dattp picture[][12],
        dattp kernel[][3],
        dattp result[][10])
{
    int result_size = 10;
    int kernel_size = 3;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
            dattp temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += ((ldattp)picture[i + k][j + l] * (ldattp)kernel[k][l]) >> FLOATPOINT;
                }
            }
            result[i][j] = temp;
        }
    }
    return;
}
#endif // X86

#if (defined X86) || (defined RISCV)
void matrix_convolution_10_3(dattp picture[][10],
        dattp kernel[][3],
        dattp result[][8])
{
    int result_size = 8;
    int kernel_size = 3;
    for(int i = 0; i < result_size; i++)
    {
        for(int j = 0; j < result_size; j++)
        {
            dattp temp = 0;
            for(int k = 0; k < kernel_size; k++)
            {
                for(int l = 0; l < kernel_size; l++)
                {
                    temp += ((ldattp)picture[i + k][j + l] * (ldattp)kernel[k][l]) >> FLOATPOINT;
                }
            }
            result[i][j] = temp;

        }
    }
    return;
}
#endif // X86

/*
 * �������ƣ�matrix_multi_convolution
 * ���ܣ�������������
 * ���룺ԭͼ�����filter���������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 */
void matrix_multi_convolution_12_3(dattp pictures[][12][12],
        dattp kernel[][3][3],
        dattp result[10][10])
{
    int picture_size=12;
    int kernel_size = 3;
    int picture_number = 6;
    dattp aggregate[10][10] = {0};
    dattp temp[10][10];
    for(int i = 0; i < picture_number; i++)
    {
#if (defined X86) || (defined RISCV)
        matrix_convolution_12_3(pictures[i], kernel[i], temp);
#endif // X86
#ifdef RISCV_DLA
        matrix_convolution_12_3_s(pictures[i], kernel[i], temp);
#endif
        matrix_add_10(aggregate, temp);
    }
    memcpy(result, aggregate, sizeof(dattp) * (picture_size - kernel_size + 1) * (picture_size - kernel_size + 1));
}

void matrix_multi_convolution_10_3(dattp pictures[][10][10],
        dattp kernel[][3][3],
        dattp result[8][8])
{
    int picture_size=10;
    int kernel_size = 3;
    int picture_number = 8;
    dattp aggregate[8][8] = {0};
    dattp temp[8][8];
    for(int i = 0; i < picture_number; i++)
    {
#if (defined X86) || (defined RISCV)
        matrix_convolution_10_3(pictures[i], kernel[i], temp);
#endif // X86
#ifdef RISCV_DLA
        matrix_convolution_10_3_s(pictures[i], kernel[i], temp);
#endif
        matrix_add_8(aggregate, temp);
    }
    memcpy(result, aggregate, sizeof(dattp) * (picture_size - kernel_size + 1) * (picture_size - kernel_size + 1));
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
void matrix_matrice_tanh_24(dattp input[][24],
        dattp output[][24], dattp bias)
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

void matrix_matrice_tanh_10(dattp input[][10],
        dattp output[][10], dattp bias)
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

void matrix_matrice_tanh_8(dattp input[][8],
        dattp output[][8], dattp bias)
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
void matrix_vector_tanh_128(dattp input[128],
        dattp output[128],
        dattp bias[128])
{
    int size = 128;
    for(int i = 0; i < size; i++)
    {
        dattp temp = input[i] + bias[i];
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
dattp matrix_softmax_10(dattp input[10],
        dattp output[10],
        dattp bias[10])
{
    int inputsize = 10;
    dattp temp = 0;
    dattp index = 0;
    for(int i = 0; i < inputsize; i++)
    {
        temp += math_exp(input[i] + bias[i]);
    }
    for(int i = 0; i < inputsize; i++)
    {
        output[i] = ((ldattp)(input[i] + bias[i]) << FLOATPOINT) / temp;
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
 *      2. ��ΪC���(2018-1-9)
 *      3. ��Ϊ������(2018-1-10)
 */
void matrix_pooling_24(dattp input[24][24], dattp output[12][12])
{
    int size = 24;
    for(int i = 0;i < size; i += 2)
    {
        for(int j = 0;j < size; j += 2)
        {
            dattp temp1 = input[i][j] > input[i][j + 1] ? input[i][j] : input[i][j + 1];
            dattp temp2 = input[i + 1][j] > input[i + 1][j + 1] ? input[i + 1][j] : input[i + 1][j + 1];
            output[i >> 1][j >> 1] = temp1 > temp2 ? temp1 : temp2;
        }
    }
    return;
}
void matrix_pooling_8(dattp input[8][8], dattp output[4][4])
{
    int size = 8;
    for(int i = 0;i < size; i += 2)
    {
        for(int j = 0;j < size; j += 2)
        {
            dattp temp1 = input[i][j] > input[i][j + 1] ? input[i][j] : input[i][j + 1];
            dattp temp2 = input[i + 1][j] > input[i + 1][j + 1] ? input[i + 1][j] : input[i + 1][j + 1];
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
 *      3. ��Ϊ������(2018-1-10)
 */
void matrix_MMV_256_128(dattp x[256], dattp weight[128][256], dattp output[128])
{
    int input_size = 256;
    int output_size = 128;
    for(int i = 0; i < output_size; i++)
    {
#if (defined X86) || (defined RISCV)
        dattp temp = 0;
        for(int j = 0; j < input_size; j++)
        {
            temp += ((ldattp)x[j] * (ldattp)weight[i][j]) >> FLOATPOINT;
        }
        output[i] = temp;
#endif // X86
#ifdef RISCV_DLA
        output[i] = matrix_MMV_256_s(x, weight[i]);
#endif // RISCV
    }
    return;
}

void matrix_MMV_128_10(dattp x[128], dattp weight[10][128], dattp output[10])
{
    int input_size = 128;
    int output_size = 10;
    for(int i = 0; i < output_size; i++)
    {
#if (defined X86) || (defined RISCV)
        dattp temp = 0;
        for(int j = 0; j < input_size; j++)
        {
            temp += ((ldattp)x[j] * (ldattp)weight[i][j]) >> FLOATPOINT;
        }
        output[i] = temp;
#endif // X86
#ifdef RISCV_DLA
        output[i] = matrix_MMV_128_s(x, weight[i]);
#endif // RISCV
    }
    return;
}
