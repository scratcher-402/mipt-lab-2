CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm
SRCS = $(wildcard *.c)
TARGET = lab2

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm $(TARGET)

.PHONY: all clean
