CC:=gcc
CFLAGS:=-std=c17 -Wall
PROJECT:=app

SRC_FILES=$(wildcard src/*.c)
OBJ_FILES=$(SRC_FILES:.c=.o)

DEPS=$(SRC_FILES:.c=.h)
HEADERS=$(filter %.h, $(filter-out main%, $(DEPS)))

all: clean build
build: $(PROJECT)

%.o: %.c $(HEADERS)
	@echo "Creating object... \n"
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROJECT): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses

clean:
	rm -rf $(PROJECT) $(OBJ_FILES)

.PHONY: build clean all

