BIN = pelmeni

FLAGS ?= -O3

COMPILER ?= $(CXX)

WINBUILD = 0
ifdef OS
	ifeq ($(OS),Windows_NT)
		WINBUILD = 1
	endif
endif

SRC = $(shell find ./Pelmeni -name "*.cpp")

ifeq ($(WINBUILD),0)
OBJ = $(SRC:%.cpp=obj/linux/%.o)
else
OBJ = $(SRC:%.cpp=obj/win/%.o)
endif

all: $(BIN)

ifeq ($(WINBUILD),0)
$(BIN): $(OBJ)
	$(COMPILER) $(OBJ) -o $@
obj/linux/%.o: %.cpp
	$(shell mkdir -p obj/linux/Pelmeni)
	$(COMPILER) -c $< -o $@ -std=c++17 $(FLAGS)
else
$(BIN): $(OBJ)
	$(COMPILER) $(OBJ) -o $@
obj/win/%.o: %.cpp
	$(shell mkdir -p obj/win/Pelmeni)
	$(COMPILER) -c $< -o $@ -std=c++17 $(FLAGS)
endif

clean:
	rm -rf obj
