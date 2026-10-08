GCC = nspire-gcc
AS  = nspire-as
GXX = nspire-g++
LD  = nspire-ld
GENZEHN = genzehn

GXXFLAGS = -Wall -Wextra -O2 -std=c++17
LDFLAGS = 
EXE = control_center.tns
OBJS = main.o

all: $(EXE)

%.o: %.cpp
	$(GXX) $(GXXFLAGS) -c $< -o $@

$(EXE): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o control_center.elf
	$(GENZEHN) --input control_center.elf --output $@ --real-time

clean:
	rm -f $(OBJS) control_center.elf $(EXE)
