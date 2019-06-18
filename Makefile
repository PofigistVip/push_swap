CFLAGS=-Wall -Wextra -Werror
PUSH_SWAP_SRC=$(addprefix src/, \
	push_swap.c \
	ft_algorithm.c \
	ft_alg_counters.c \
	ft_algorithm_1.c \
	ft_markups.c \
	ft_markups_1.c \
	ft_road_to_top.c \
	ft_get_args.c \
	ft_instructions.c \
	ft_instructions_1.c \
	ft_instructions_2.c \
	ft_stack.c \
	ft_stack_1.c)
CHECKER_SRC=$(addprefix src/, \
	checker.c \
	ft_debug.c \
	ft_get_args.c \
	ft_instructions.c  \
	ft_instructions_1.c \
	ft_instructions_2.c \
	ft_read_and_do_instructions.c \
	ft_stack.c \
	ft_stack_1.c)
LIBFT=lib/libft
NAME1=push_swap
NAME2=checker

all:
	@echo "libft creating..."
	@make -C $(LIBFT) re
	@echo "push_swap creating..."
	@gcc $(CFLAGS) -o $(NAME1) $(PUSH_SWAP_SRC) -I include/ -I $(LIBFT) -L $(LIBFT) -lft
	@echo "checker creating"
	@gcc $(CFLAGS) -o $(NAME2) $(CHECKER_SRC) -I include/ -I $(LIBFT) -L $(LIBFT) -lft
	@echo "Build complete!"

$(NAME1):
	@echo "libft creating..."
	@make -C $(LIBFT) re
	@echo "push_swap creating..."
	@gcc $(CFLAGS) -o $(NAME1) $(PUSH_SWAP_SRC) -I include/ -I $(LIBFT) -L $(LIBFT) -lft

$(NAME2):
	@echo "libft creating..."
	@make -C $(LIBFT) re
	@echo "checker creating"
	@gcc $(CFLAGS) -o $(NAME2) $(CHECKER_SRC) -I include/ -I $(LIBFT) -L $(LIBFT) -lft

clean:
	@echo "libft cleaning..."
	@make -C $(LIBFT) clean
	@echo "Clean complete!"

fclean:
	@echo "fclean started..."
	@make -C $(LIBFT) fclean
	@rm -f push_swap checker
	@echo "fclean complete"

re: fclean all