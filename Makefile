# Makefile - Tarea en clase: Ordenamiento y Búsqueda
# IE-0117 - I-2026

CC     = gcc
CFLAGS = -Wall -Wextra
TARGET = algoritmos

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.c algoritmos.c algoritmos.h
	$(CC) $(CFLAGS) main.c algoritmos.c -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
