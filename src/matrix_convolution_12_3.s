# matrix_convolution_12_3.s
.globl matrix_convolution_12_3_s
matrix_convolution_12_3_s:
	addi a4, a1, 0  						# mv a4, a1

	# Load Weights
	addi   x0,x0,0    #y.load 0x100, x14, 3
    addi   a4,a4,12
    addi   x0,x0,0    #y.load 0x10c, x14, 3
    addi   a4,a4,12
    addi   x0,x0,0    #y.load 0x118, x14, 3



    lui    t0,0x0000
	addi   t0,t0,10							# i = 10
loop_i:										# Horizonal Move Loop
	addi a3, a0, 0							# mv a3, a0
	addi a5, a2, 0							# mv a5, a2

	# Load Feature Initially
	addi   x0,x0,0    #y.load 0x0, x13, 3
    addi   a3,a3,48							# 28 * 4 = 112
    addi   x0,x0,0    #y.load 0xc, x13, 3
    addi   a3,a3,48							# 28 * 4 = 112
    addi   x0,x0,0    #y.load 0x18, x13, 3


    lui    t1,0x0000
	addi   t1,t1,10							# j = 10
loop_j:										# Vertical Move Loop
	addi   x0,x0,0    #y.cmac x7, x10, x11, 9   #t2
	sw	   t2,0(a5)							# store
	addi   a5, a5, 40						# a5 = a5 + 40
	addi   x0,x0,0    #y.shift dat, 3
	addi   a3,a3,48
	addi   x0,x0,0    #y.load 0x18, x13, 3

	addi   t1,t1,-1
    bne    t1,x0,loop_j						# loop_j end

    addi   a0, a0, 4
    addi   a2, a2, 4

    addi   t0,t0,-1
    bne    t0,x0,loop_i						# loop_i end

    jalr   x0,x1,0	  						#ret
