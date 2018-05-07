TARGET=bin/tors

LIBS=-lbcm2835 -lncurses -lpthread -lm

SRC_PATH=src/

C_SRC = \
$(SRC_PATH)main_scheduler_obj.c \
$(SRC_PATH)gpio_obj.c

INC_PATH = inc/

C_INCLUDES =  \
-Iinc \
-I/usr/local/include
C_LIBS = \
-L/usr/local/lib

OBJ_PATH = obj/

OBJECTS = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(C_SRC))

CC = gcc
CFLAGS = -g
CFLAGS += $(C_INCLUDES) 
CFLAGS += $(C_LIBS) 
CFLAGS += $(LIBS)

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

$(OBJ_PATH)main_scheduler_obj.o: $(SRC_PATH)main_scheduler_obj.c   $(INC_PATH)main.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJ_PATH)gpio_obj.o: $(SRC_PATH)gpio_obj.c  $(INC_PATH)main.h $(INC_PATH)gpio_obj.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) -fR $(OBJ_PATH)*.o $(TARGET)
