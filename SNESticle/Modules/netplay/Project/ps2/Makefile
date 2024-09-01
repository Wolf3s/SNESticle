TARGET = netplay.irx
SOURCE  = 
SOURCE += ../../Source/common ../../Source/ps2/iop

INCLUDE = -I../../Source/common -I../../Source/ps2/common  -I../../Source/ps2/iop

# -G0 -EL -mcpu=r3000
OBJ	= netplay_iop.o netserver.o netsys.o netclient.o netsocket.o netprint.o netpacket.o netqueue.o
CFLAGS	= -D_IOP -O2 -Werror -Wall -I$(PS2SDK)/iop/include -I$(PS2SDK)/common/include $(INCLUDE) -fomit-frame-pointer
LDFLAGS = -Wl,-s -nostdlib -L$(PS2SDK)/iop/lib -G0
LIBS	= -lkernel -lps2ip
all: $(TARGET)


vpath % $(SOURCE)

$(TARGET): $(OBJ)
	rm -f $(TARGET)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LIBS)

.s.o:
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o *.irx $(TARGET)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.iopglobal 