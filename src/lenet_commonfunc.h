/*
 * lenet_commonfunc.h
 *
 *  Created on: 2018��1��5��
 *      Author: admin
 */

#ifndef LENET_COMMONFUNC_H_
#define LENET_COMMONFUNC_H_
#include "lenet_define.h"


int read_Mnist(int begin_number, int end_number, int Feature[][FEATURE_SIZE][FEATURE_SIZE], unsigned char label[]);
int read_data();

#endif /* LENET_COMMONFUNC_H_ */
