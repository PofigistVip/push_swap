CHECKER_SRC=$(addprefix ../src/,checker.c ft_debug.c ft_get_args.c ft_instructions.c ft_read_and_do_instructions.c ft_stack.c)

checker:
	make -C ../lib/libft re
	rm -f checker
	gcc -o checker $(CHECKER_SRC) -I ../include -I ../lib/libft -L ../lib/libft -lft