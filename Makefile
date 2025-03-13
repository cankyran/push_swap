NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= operation_func_III.c operation_func_II.c operation_func_I.c \
		  free_error_func.c utils_funcs_II.c utils_funcs_I.c \
		  sort_func_II.c sort_func_I.c check_args.c push_swap.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ push_swap compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "🗑️ Object files cleaned!"

fclean: clean
	@rm -rf $(NAME)
	@echo "🗑️ All build files removed!"

re: fclean all

.PHONY: all re clean fclean
