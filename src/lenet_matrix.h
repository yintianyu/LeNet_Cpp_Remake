/*
 * lenet_matrix.h
 *
 *  Created on: 2018��1��6��
 *      Author: admin
 */

#ifndef LENET_MATRIX_H_
#define LENET_MATRIX_H_


#include <stdio.h>
#include "lenet_math.h"
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
void matrix_add_24(float dst[][24], float src[][24]);

void matrix_add_10(float dst[][10], float src[][10]);

void matrix_add_8(float dst[][8], float src[][8]);


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
        float result[][24]);


void matrix_convolution_12_3(float picture[][12],
        float kernel[][3],
        float result[][10]);

void matrix_convolution_10_3(float picture[][10],
        float kernel[][3],
        float result[][8]);

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
        float result[10][10]);

void matrix_multi_convolution_10_3(float pictures[][10][10],
        float kernel[][3][3],
        float result[8][8]);

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
        float output[][24], float bias);

void matrix_matrice_tanh_10(float input[][10],
        float output[][10], float bias);

void matrix_matrice_tanh_8(float input[][8],
        float output[][8], float bias);

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
        float bias[128]);

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
        float bias[10]);



/*
 * �������ƣ�matrix_pooling
 * ���ܣ���������maxpooling(�޶���filterΪ2)
 * ���룺ԭͼ����󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      3. ��ΪC���(2018-1-9)
 */
void matrix_pooling_24(float input[24][24], float output[12][12]);

void matrix_pooling_8(float input[8][8], float output[4][4]);

/*
 * �������ƣ�matrix_MMV
 * ���ܣ��������������
 * ���룺ԭͼ��������Ȩ�ؾ��󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. temp��������int��Ϊfloat
 */
void matrix_MMV_256_128(float x[256], float weight[128][256], float output[128]);

void matrix_MMV_128_10(float x[128], float weight[10][128], float output[10]);

#endif /* LENET_MATRIX_H_ */
