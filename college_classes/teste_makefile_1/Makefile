CC = /usr/bin/gcc
OBJS = programa.o teste.o
TARGET = programa

%.o: %.c
	$(CC) -c $<

all: $(OBJS)
	$(CC) *.o -o $(TARGET)

clean:
	@rm -rf *.o $(TARGET)