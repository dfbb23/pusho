NAME = push_swap

SRC = big_sort.c check_error.c ft_apply1.c ft_case_ab.c \
      ft_case_ba.c ft_checksorted.c ft_find.c ft_free.c \
      ft_rotate_type.c push_swap.c ft_process.c ft_checkdup.c\
	  operasion2.c operation.c operation3.c

# LIBFT = ./libft/libft.a
# INCLUDE = -L ./libft -lft -I ./libft

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules for compiling object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

# Ensure libft is compiled
# $(LIBFT):
# 	make -C libft

# Clean object files
clean:
	rm -f $(OBJ)
# make -C libft clean

# Clean all generated files
fclean: clean
	rm -f $(NAME)
# make -C libft fclean

# Rebuild all
re: fclean all

# Default target
all: $(NAME)

.PHONY: all clean fclean re
