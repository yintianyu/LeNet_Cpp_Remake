# matrix_mmv_256.s

.globl matrix_MMV_256_s
matrix_MMV_256_s:

    lui    a3,0x0000
	addi   a3,a3,0x04	#a3 = 4;
	lui    t1,0x0000

loop:
	addi   x0,x0,0    #y.load 0x0, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0x14, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0x28, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0x3c, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0x50, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0x64, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0x78, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0x8c, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0xa0, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0xb4, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0xc8, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0xdc, x10, 5
	addi   a0,a0,20
	addi   x0,x0,0    #y.load 0xf0, x10, 4

	addi   x0,x0,0    #y.load 0x100, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x114, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x128, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x13c, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x150, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x164, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x178, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x18c, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x1a0, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x1b4, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x1c8, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x1dc, x11, 5
	addi   a1,a1,20
	addi   x0,x0,0    #y.load 0x1f0, x11, 4

    lui    a4,0x0000
	addi   a4,a4,0x00
    lui    a5,0x0000
    addi   a5,a5,0x100
    addi   x0,x0,0    #y.cmac x5, x14, x15, 64  #t0 saves the temp result, t1 saves the aggregate
    add    t1,t1,t0

    addi   a3,a3,-1
    bne    a3,x0,loop

    addi   a0,t1,0

    jalr   x0,x1,0	  #ret


