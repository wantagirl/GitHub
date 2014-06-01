SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = mingw32-gcc
CCFLAGS = -g -Wall -O0

main : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< $(CCFLAGS)

clean:
	rm *.o