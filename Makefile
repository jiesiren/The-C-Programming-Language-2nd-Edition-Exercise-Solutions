CC = gcc
CFLAGS = -W -Wall -std=c18 -pedantic
OUT_DIR = bin
ALL_BIN = $(patsubst %.c,$(OUT_DIR)/%,$(wildcard *.c))

all: $(ALL_BIN)

$(OUT_DIR)/%: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f $(OUT_DIR)/*
