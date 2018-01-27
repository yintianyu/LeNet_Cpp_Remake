#lenet_matrix_cmac_3.s

.globl matrix_CMAC_3_s
matrix_CMAC_3_s:
    addi   x0,x0,0    #y.load 0x0, x10, 5
    add    a0,a0,a2
    addi   x0,x0,0    #y.load 0xc, x10, 5
    add    a0,a0,a2
    addi   x0,x0,0    #y.load 0x18, x10, 5

    addi   x0,x0,0    #y.load 0x100, x11, 5
    addi   a1,a1,12
    addi   x0,x0,0    #y.load 0x10c, x11, 5
    addi   a1,a1,12
    addi   x0,x0,0    #y.load 0x118, x11, 5

    lui    a0,0x0000
	addi   a0,a0,0x00
    lui    a1,0x0000
    addi   a1,a1,0x100
    addi   x0,x0,0    #y.cmac x10, x10, x11, 9

    jalr   x0,x1,0	  #ret
