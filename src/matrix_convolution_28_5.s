# matrix_convolution_28_5.s

.globl matrix_convolution_28_5_s
matrix_convolution_28_5_s:	#a0 - feature addr, a1 - weight addr, a2 - result addr

	addi a4, a1, 0  						# mv a4, a1

	# Load Weights
	addi   x0,x0,0    #y.load 0x100, x14, 5
    addi   a4,a4,20
    addi   x0,x0,0    #y.load 0x114, x14, 5
    addi   a4,a4,20
    addi   x0,x0,0    #y.load 0x128, x14, 5
    addi   a4,a4,20
    addi   x0,x0,0    #y.load 0x13c, x14, 5
    addi   a4,a4,20
    addi   x0,x0,0    #y.load 0x150, x14, 5


    lui    t0,0x0000
	addi   t0,t0,24							# i = 24
loop_i:										# Horizonal Move Loop
	addi a3, a0, 0							# mv a3, a0
	addi a5, a2, 0							# mv a5, a2

	# Load Feature Initially
	addi   x0,x0,0    #y.load 0x0, x13, 5
    addi   a3,a3,112						# 28 * 4 = 112
    addi   x0,x0,0    #y.load 0x14, x13, 5
    addi   a3,a3,112						# 28 * 4 = 112
    addi   x0,x0,0    #y.load 0x28, x13, 5
    addi   a3,a3,112						# 28 * 4 = 112
    addi   x0,x0,0    #y.load 0x3c, x13, 5
    addi   a3,a3,112						# 28 * 4 = 112
    addi   x0,x0,0    #y.load 0x50, x13, 5

    lui    t1,0x0000
	addi   t1,t1,24							# j = 24
loop_j:										# Vertical Move Loop
	addi   x0,x0,0    #y.cmac x7, x10, x11, 25   #t2
	sw	   t2,0(a5)							# store
	addi   a5, a5, 96						# a5 = a5 + 96
	addi   x0,x0,0    #y.shift dat, 5
	addi   a3,a3,112
	addi   x0,x0,0    #y.load 0x50, x13, 5

	addi   t1,t1,-1
    bne    t1,x0,loop_j						# loop_j end

    addi   a0, a0, 4
    addi   a2, a2, 4

    addi   t0,t0,-1
    bne    t0,x0,loop_i						# loop_i end

    jalr   x0,x1,0	  						#ret








