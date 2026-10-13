CC = gcc
CFLAGS = -Wall -Wextra -lm
SRCS = $(wildcard *.c)
TARGET = lab2

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(TARGET)

.PHONY: all clean
