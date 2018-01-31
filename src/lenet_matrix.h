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
void matrix_add_24(int dst[][24], int src[][24]);

void matrix_add_10(int dst[][10], int src[][10]);

void matrix_add_8(int dst[][8], int src[][8]);


/*
 * �������ƣ�matrix_convolution
 * ���ܣ�����������
 * ���룺ԭͼ�����filter���������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��ΪC���(2018-1-9)
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
 * �������ƣ�matrix_multi_convolution
 * ���ܣ�������������
 * ���룺ԭͼ�����filter���������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 */
void matrix_multi_convolution_12_3(int pictures[][12][12],
        int kernel[][3][3],
        int result[10][10]);

void matrix_multi_convolution_10_3(int pictures[][10][10],
        int kernel[][3][3],
        int result[8][8]);

/*
 * �������ƣ�matrix_matrice_tanh
 * ���ܣ��������ÿ��Ԫ�ؼ���ƫ�ú��tanh
 * ���룺ԭͼ����󣬽������ƫ��
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��ΪC���(2018-1-9)
 */
void matrix_matrice_tanh_24(int input[][24],
        int output[][24], int bias);

void matrix_matrice_tanh_10(int input[][10],
        int output[][10], int bias);

void matrix_matrice_tanh_8(int input[][8],
        int output[][8], int bias);

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
void matrix_vector_tanh_128(int input[128],
        int output[128],
        int bias[128]);

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
int matrix_softmax_10(int input[10],
        int output[10],
        int bias[10]);



/*
 * �������ƣ�matrix_pooling
 * ���ܣ���������maxpooling(�޶���filterΪ2)
 * ���룺ԭͼ����󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      3. ��ΪC���(2018-1-9)
 */
void matrix_pooling_24(int input[24][24], int output[12][12]);

void matrix_pooling_8(int input[8][8], int output[4][4]);

/*
 * �������ƣ�matrix_MMV
 * ���ܣ��������������
 * ���룺ԭͼ��������Ȩ�ؾ��󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. temp��������int��Ϊfloat
 */
void matrix_MMV_256_128(int x[256], int weight[128][256], int output[128]);

void matrix_MMV_128_10(int x[128], int weight[10][128], int output[10]);


/*
 * �������ƣ�matrix_CMAC_5_s
 * ���ܣ�����CMACģ����м���
 * ���룺data��ַ��weight��ַ
 * ��������ۼӽ��
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. temp��������int��Ϊfloat
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
