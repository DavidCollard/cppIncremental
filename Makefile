CC=g++
GCC_OPT = -O2 -Wall -Wextra -Werror -std=c++11
SRC_PATH = src/cpp/
BIN = bin/

$(BIN)%.o: $(SRC_PATH)%.cpp
	$(CC) -c -o $@ $< $(GCC_OPT)

main: $(BIN)main.o $(BIN)AbstractCommand.o $(BIN)HelpCommand.o $(BIN)QuitCommand.o $(BIN)UnknownCommand.o $(BIN)ProcessInput.o
	$(CC) $(GCC_OPT) $^ -o main.exe -lpthread

run:
	./main.exe

clean:
	rm $(BIN)*
	rm main.exe
