OBJECTS = main.o history.o print.o
SRCS = main.c history.c print.c

CFLAGS = -g -Wall
TARGET = 20190216

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) -Wall

clean:
	rm -f $(OBJECTS) $(TARGET)
