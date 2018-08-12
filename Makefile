CC=g++
GCC_OPT = -O2 -Wall -Wextra -Werror -std=c++11
GCC_LNK = -lpthread -lncurses
SRC_PATH = src/cpp/
BIN = bin/

SRCS=$(wildcard $(SRC_PATH)*.cpp)
OBJS=$(patsubst %.cpp, %.o, $(notdir $(SRCS)))

$(BIN)%.o: $(SRC_PATH)%.cpp
	$(CC) -c -o $@ $< $(GCC_OPT)

main: $(addprefix $(BIN), $(OBJS))
	$(CC) $(GCC_OPT) $^ -o main.exe $(GCC_LNK)

run:
	./main.exe

clean:
	rm $(BIN)*
	rm main.exe
