#规则1 targer:requirement
#规则2 tab后是需要执行的命令，@目标文件，^所有依赖文件，<第一个依赖文件
#隐含规则 .o依赖于.c

#env
CC = mingw32-gcc
CFLAGS = -g -Wall -O0

#objs
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)

#target
main : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o