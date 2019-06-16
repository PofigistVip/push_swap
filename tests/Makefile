CHECKER_SRC=$(addprefix ../src/, \
	checker.c \
	ft_debug.c \
	ft_get_args.c \
	ft_instructions.c  \
	ft_instructions_1.c \
	ft_instructions_2.c \
	ft_read_and_do_instructions.c \
	ft_stack.c \
	ft_stack_1.c)
PUSH_SWAP_SRC=$(addprefix ../src/, \
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

checker:
	make -C ../lib/libft re
	rm -f checker
	gcc -Wall -Werror -Wextra -o checker $(CHECKER_SRC) -I ../include -I ../lib/libft -L ../lib/libft -lft

push_swap:
	make -C ../lib/libft re
	rm -f push_swap
	gcc -Wall -Werror -Wextra -o push_swap $(PUSH_SWAP_SRC) -I ../include -I ../lib/libft -L ../lib/libft -lft

markup:
	make -C ../lib/libft re
	rm -f markup_test
	gcc -o markup_test ft_markup_test.c ../src/ft_stack.c ../src/ft_algorithm.c ../src/ft_road_to_top.c ../src/ft_instructions.c -I ../include -I ../lib/libft -L ../lib/libft -lft