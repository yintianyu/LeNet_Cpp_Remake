//============================================================================
// Name        : LeNet_Cpp_Remake.cpp
// Author      : Yin Tianyu
// Version     :
// Copyright   : Yin Tianyu 2017-2018 All Rights Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "lenet_define.h"
#include "lenet_commonfunc.h"
#include "lenet_cnn.h"


int main() {
    int feature[BATCH_SIZE][FEATURE_SIZE][FEATURE_SIZE] = {0};
    int Mnist_Label[BATCH_SIZE] = {0};
    int correct_count = 0;
    int read_status;
    read_status = read_data();
#ifdef RISCV
    printf("Read Data Finished.\n");
#endif
    if(0 != read_status)
    {
        printf("read_status: %d\n",read_status);
        return 2;
    }
    for(int t = 0; t < LOOP_TIME; t++)
    {
        int reference;
        int answer;
        read_status = read_Mnist(t * BATCH_SIZE, (t + 1) * BATCH_SIZE, feature, Mnist_Label);
#ifdef RISCV
        printf("Read Mnist Finished.\n");
#endif
        if(0 != read_status)
        {
            printf("read_status: %d\n",read_status);
            return 1;
        }
        for(int j = 0; j < BATCH_SIZE; j++)
        {
            reference = cnn(feature[j]);
            answer = Mnist_Label[j];
            if (answer == reference)
            {
                printf("Batch No.%d, Picture No.%d Correct!\n", t, j);
                correct_count++;
            }
            else
            {
                printf("Batch No.%d, Picture No.%d Incorrect: %d:%d\n", t, j, answer, reference);
            }
        }

    }
    printf("Finished! Correct Number:%d.\n", correct_count);
	return 0;
}


