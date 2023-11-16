#macro definitions
TARGET=exec
DIR = objs/
FILES = main print add
SRC = $(addsuffix .c,$(FILES))
OBJ = $(addprefix $(DIR)addsuffix .o,$(FILES))
CFLAGS+= -Wall -Wextra -Werror

#rule(s) name/file to be created : rule dependencies
#{tab}command to execute
#{tab}additional commands...

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	gcc -c $(SRC)

crun: all
	./$(TARGET)

test:
	echo $(FILES)

clean:
	rm $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all