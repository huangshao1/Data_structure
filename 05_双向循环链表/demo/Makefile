TRG=./bin/main
SRC=$(wildcard ./src/*.c)
OBJ=$(SRC:%.c=%.o)
CONFIG=-I./inc
CC=gcc
$(TRG):$(OBJ)
	$(CC) $(^) -o $(@) $(CONFIG)

%.o:%.c
	$(CC) $< -o $(@) $(CONFIG) -c
clean:
	rm ./bin/* ./src/*.o
