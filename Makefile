CC = riscv32-unknown-elf-g++
OBJC = riscv32-unknown-elf-objcopy
CFLAGS = -DRISCV
VPATH = src
blddir = build
source = $(notdir $(wildcard src/*.cpp))
objects = $(source:%.c=$(blddir)/%.o)
$(blddir)/lenet.hex: $(blddir)/lenet.bin
	$(OBJC) -I binary -O ihex $^ $@

$(blddir)/lenet.bin: $(blddir)/lenet.elf
	$(OBJC) -O binary $^ $@

$(blddir)/lenet.elf: ${objects}
	$(CC) -o $@ $^ $(CFLAGS)

$(blddir)/lenet_cnn.o: lenet_cnn.cpp lenet_matrix.h lenet_cnn.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(blddir)/lenet_commonfunc.o: lenet_commonfunc.cpp lenet_commonfunc.h lenet_cnn.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(blddir)/lenet_math.o: lenet_math.cpp lenet_math.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(blddir)/LeNet_Cpp_Remake.o: LeNet_Cpp_Remake.cpp lenet_define.h lenet_commonfunc.h lenet_cnn.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm $(blddir)/*


