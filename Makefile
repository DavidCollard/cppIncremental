CC=g++
GCC_OPT = -O2 -Wall -Wextra -Werror
SRC_PATH = src/cpp/
BIN = bin/

$(BIN)%.o: $(SRC_PATH)%.cpp
	$(CC) -c -o $@ $< $(GCC_OPT)

main: $(BIN)main.o $(BIN)AbstractCommand.o
	$(CC) $(GCC_OPT) $^ -o main.exe

run:
	./main.exe

clean:
	rm $(BIN)*
	rm main.exe