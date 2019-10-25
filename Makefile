CC = gcc
CFLAGS = -W -Wall -std=c18 -pedantic
OUT_DIR = bin
ALL_BIN = $(patsubst %.c,%,$(wildcard *.c))

all: $(patsubst %,$(OUT_DIR)/%,$(ALL_BIN))

.PHONY: $(ALL_BIN)

$(ALL_BIN): %: $(OUT_DIR)/%

$(OUT_DIR)/%: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f $(OUT_DIR)/*
