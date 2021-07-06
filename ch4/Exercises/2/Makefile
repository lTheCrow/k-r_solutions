CFLAGS = -I includes -m32
OUT = atof
WINC = WINC
LINC = LINC

ifeq ($(OS),Windows_NT)
	CC = mingw32-gcc
	WINC = clean
else
	CC = gcc
	LINC = clean
endif


all: main.o getline.o atof.o 
	@$(CC) main.o getline.o atof.o -o $(OUT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(WINC):
	@del *.o
	@del $(OUT).exe

$(LINC):
	@rm *.o
	@rm $(OUT)