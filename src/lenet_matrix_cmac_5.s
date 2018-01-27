#lenet_matrix_cmac_5.s

.globl matrix_CMAC_5_s
matrix_CMAC_5_s:
    addi   x0,x0,0    #y.load 0x0, x10, 5
    add    a0,a0,a2
    addi   x0,x0,0    #y.load 0x14, x10, 5
    add    a0,a0,a2
    addi   x0,x0,0    #y.load 0x28, x10, 5
    add    a0,a0,a2
    addi   x0,x0,0    #y.load 0x3c, x10, 5
    add    a0,a0,a2
    addi   x0,x0,0    #y.load 0x50, x10, 5

    addi   x0,x0,0    #y.load 0x100, x11, 5
    addi   a1,a1,20
    addi   x0,x0,0    #y.load 0x114, x11, 5
    addi   a1,a1,20
    addi   x0,x0,0    #y.load 0x128, x11, 5
    addi   a1,a1,20
    addi   x0,x0,0    #y.load 0x13c, x11, 5
    addi   a1,a1,20
    addi   x0,x0,0    #y.load 0x150, x11, 5

    lui    a0,0x0000
	addi   a0,a0,0x00
    lui    a1,0x0000
    addi   a1,a1,0x100
    addi   x0,x0,0    #y.cmac x10, x10, x11, 25

    jalr   x0,x1,0	  #ret
