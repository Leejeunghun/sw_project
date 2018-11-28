
CC= gcc
CFLAGS= -Wall
OBJS= func1.o func2.o myapp.c
TARGET= myapp

$(TARGET):$(OBFT)
	$(CC) -o $(TARGET) $(OBJS)

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@
	echo "target $@"
	echo "newer source $?"
clean:
	rm -f $(TARGET) $(OBJS)
