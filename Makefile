CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address,undefined
LDFLAGS = -lm
SRCS = $(wildcard *.c)
TARGET = lab2

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm $(TARGET)

.PHONY: all clean
