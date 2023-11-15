##
## EPITECH PROJECT, 2023
## bs_mypaint
## File description:
## Makefile
##

SRC = $(wildcard src/*.c) \
		$(wildcard src/*/*.c) \
		$(wildcard src/*/*/*.c) \

OBJ = $(SRC:.c=.o)

TARGET = my_paint

CFLAGS = -lcsfml-graphics -lcsfml-system\
-lcsfml-window -lcsfml-audio -W -Wall -Wextra -g3 -lm

all: $(TARGET)
	make clean

$(TARGET):
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
