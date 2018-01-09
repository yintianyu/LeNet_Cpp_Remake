/*
 * lenet_math.h
 *
 *  Created on: 2018��1��6��
 *      Author: admin
 */

#ifndef LENET_MATH_H_
#define LENET_MATH_H_
#include <stdio.h>
float math_tanh(const float x);
float math_exp(const float x);


/*
 * �������ƣ�power
 * ���ܣ�����˷�
 * ���룺float������intָ��
 * �����float ������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 *      2. ��ΪC���(2018-1-9)
 */
float power(const float x, const int n);

int factorial(const int x);


#endif /* LENET_MATH_H_ */

