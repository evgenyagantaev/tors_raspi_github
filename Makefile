TARGET=./bin/tors
LIBS=-lbcm2835 -lncurses -lpthread -lm

all: $(TARGET)

$(TARGET): ./obj/main.o
	gcc main.c -o $(TARGET) $(LIBS) -g
./obj/main.o: main.c main.h
	gcc main.c -c -o ./obj/main.o -g

clean:
	rm -rf ./obj/*.o $(TARGET)
