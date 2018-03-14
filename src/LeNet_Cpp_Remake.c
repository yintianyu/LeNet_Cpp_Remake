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
#ifdef X86
    dattp feature[BATCH_SIZE][FEATURE_SIZE][FEATURE_SIZE] = {0};
    unsigned char Mnist_Label[BATCH_SIZE] = {0};
#endif // X86
#if (defined RISCV) || (defined RISCV_DLA)
    dattp **feature[5] = {(dattp**)0xF00231B8, (dattp**)(0xF00231B8 + 3136 * 1), (dattp**)(0xF00231B8 + 3136 * 2), (dattp**)(0xF00231B8 + 3136 * 3), (dattp**)(0xF00231B8 + 3136 * 4)};
    unsigned char *Mnist_Label = (unsigned char*)0xF0026EF8;
#endif
    int correct_count = 0;
    int read_status;
#ifdef RISCV
    printf("Let's Start!\n");
#endif
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
        dattp reference;
        dattp answer;
#ifdef X86
        read_status = read_Mnist(t * BATCH_SIZE, (t + 1) * BATCH_SIZE, feature, Mnist_Label);
#endif
#ifdef RISCV
        printf("Read Mnist Finished.\n");
        printf("Label[0] = 0x%x\n", Mnist_Label[0]);
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
                printf("Batch No.0x%x, Picture No.0x%x Correct!\n", t, j);
                correct_count++;
            }
            else
            {
                printf("Batch No.0x%x, Picture No.0x%x Incorrect: 0x%x:0x%x\n", t, j, answer, reference);
            }
        }

    }
    printf("Finished! Correct Number:0x%x.\n", correct_count);
	return 0;
}


