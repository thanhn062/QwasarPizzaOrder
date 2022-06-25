# CC = gcc

# CFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror

# TARGET = project_name

# SOURCES := $(shell find $(SOURCEDIR/lib) -name '*.c')

# OBJECTS = $(SOURCES:.c=.o)

# $(TARGET): $(OBJECTS)
# 	$(CC) $(CFLAGS) -o $@ $^ 

# .PHONY: clean fclean

# clean:
# 	@rm $(OBJECTS)

# fclean: clean
# 	@rm $(TARGET)
# <----- Left in Program for when Migrated to differnt IDE ----->

# #macro definitions
# #change target and file for project
# TARGET = main  
# FILES = main
# #       main.c print.c add.c
# SRC = $(addsuffix .c,$(FILES))
# #       main.o print.o add.o
# OBJ = $(addsuffix .o,$(FILES))

# CFLAGS += -Wall -Wextra -Werror 

# #-fsantize=address

# #rules
# #rule name/file to be created: rule dependencies
# #{tab}command to execute
# #{tab}addintional commands...
# #@,<,^
# #@ = rule/target
# #^ = expand macro
# #< = first element of macro

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

# clean:
# 	rm -f $(OBJ)

# fclean: clean	
# 	rm -f $(TARGET)

# #remove everything and recompile
# re: fclean all

