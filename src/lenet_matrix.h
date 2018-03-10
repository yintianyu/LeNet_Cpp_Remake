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
void matrix_add_24(dattp dst[][24], dattp src[][24]);

void matrix_add_10(dattp dst[][10], dattp src[][10]);

void matrix_add_8(dattp dst[][8], dattp src[][8]);


/*
 * �������ƣ�matrix_convolution
 * ���ܣ�����������
 * ���룺ԭͼ�����filter���������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��ΪC���(2018-1-9)
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
 * �������ƣ�matrix_multi_convolution
 * ���ܣ�������������
 * ���룺ԭͼ�����filter���������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 */
void matrix_multi_convolution_12_3(dattp pictures[][12][12],
        dattp kernel[][3][3],
        dattp result[10][10]);

void matrix_multi_convolution_10_3(dattp pictures[][10][10],
        dattp kernel[][3][3],
        dattp result[8][8]);

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
        dattp output[][24], dattp bias);

void matrix_matrice_tanh_10(dattp input[][10],
        dattp output[][10], dattp bias);

void matrix_matrice_tanh_8(dattp input[][8],
        dattp output[][8], dattp bias);

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
        dattp bias[128]);

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
        dattp bias[10]);



/*
 * �������ƣ�matrix_pooling
 * ���ܣ���������maxpooling(�޶���filterΪ2)
 * ���룺ԭͼ����󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      3. ��ΪC���(2018-1-9)
 */
void matrix_pooling_24(dattp input[24][24], dattp output[12][12]);

void matrix_pooling_8(dattp input[8][8], dattp output[4][4]);

/*
 * �������ƣ�matrix_MMV
 * ���ܣ��������������
 * ���룺ԭͼ��������Ȩ�ؾ��󣬽������
 * �������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. temp��������int��Ϊfloat
 */
void matrix_MMV_256_128(dattp x[256], dattp weight[128][256], dattp output[128]);

void matrix_MMV_128_10(dattp x[128], dattp weight[10][128], dattp output[10]);


/*
 * �������ƣ�matrix_CMAC_5_s
 * ���ܣ�����CMACģ����м���
 * ���룺data��ַ��weight��ַ
 * ��������ۼӽ��
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. temp��������int��Ϊfloat
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
