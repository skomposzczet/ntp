OUTPUT = main

CC=g++
CFLAGS+=-Wall -pedantic -g -MMD -MP
CFFLAGS=-Wall -O2

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=${SRC:.cpp=.d}

CFLAGS+=$(DEP_FLAGS)

all: $(OUTPUT) run

$(OUTPUT): $(OBJ)
	@$(CC) $(OBJ) -o $@ $(LFLAGS)
	
%.o: %.cpp
	@$(CC) -c $(CFLAGS) $<

.PHONY: clean run debug check

run:
	@./$(OUTPUT)

clean:
	@rm -f $(OUTPUT) $(OBJ) *.d

check: 
	@valgrind ./$(OUTPUT)

debug:
	@gdb ./$(OUTPUT)

-include $(DEP) 
