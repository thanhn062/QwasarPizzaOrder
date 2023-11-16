CC = gcc # clang
OBJ = 
CFLAGS = #-g3 -fsanitize=address -Wall -Wextra -Werror# -fsantize=
SRC = ./src/main.c #./src/menu.c 
# SOURCES := $(shell find $(SOURCEDIR/lib) -name '*.c')
# OBJECTS = $(SOURCES:.c=.o)
TARGET = clui2
#  $(OBJ)
# all: $(TARGET) to add in re fclean all run
$(TARGET):
	@$(CC) $(CFLAGS) $(SRC) -o $@

# #remove everything and recompile
re: fclean $(TARGET) run

.PHONY: clean

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(TARGET)

.PHONY: run

run:
	@./$(TARGET)

#rules
#rule name/file to be created: rule dependencies
#{tab}command to execute
#{tab}addintional commands...
#@,<,^
#@ = rule/target
#^ = expand macro
#< = first element of macro

# --> Left in Program for when Migrated to differnt IDE 

# #macro definitions
# #change target and file for project
# TARGET = main  
# FILES = main
# #       main.c print.c add.c
# SRC = $(addsuffix .c,$(FILES))
# #       main.o print.o add.o
# OBJ = $(addsuffix .o,$(FILES))

# CFLAGS += -Wall -Wextra -Werror

# #rules we make up that are not files
# .PHONY: all clean fclean re

# all: $(TARGET) 
# #@ before rule silences them

# $(TARGET): $(OBJ)
# 	gcc -o $(TARGET) $(OBJ)

# $(OBJ): $(SRC)
# 	gcc -c  $(CFLAGS) $(SRC)

# crun : all
# 	./$(TARGET)
