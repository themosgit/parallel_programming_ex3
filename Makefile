OBJS	= 3.1.o 3.2.o
OUT	= ask1,ask2

OBJS0	= 3.1.o
SOURCE0	= 3.1.c
HEADER0	= timer.h
OUT0	= ask1

OBJS1	= 3.2.o
SOURCE1	= 3.2.c
HEADER1	= timer.h
OUT1	= ask2

CC	 = mpicc
FLAGS	 = -c -Wall
LFLAGS	 = -lpthread

all: ask1 ask2

ask1: $(OBJS0) $(LFLAGS)
	$(CC) -g $(OBJS0) -o $(OUT0)

ask2: $(OBJS1) $(LFLAGS)
	$(CC) -g $(OBJS1) -o $(OUT1)

3.1.o: 3.1.c
	$(CC) $(FLAGS) 3.1.c 

3.2.o: 3.2.c
	$(CC) $(FLAGS) 3.2.c 


clean:
	rm -f $(OBJS) $(OUT)