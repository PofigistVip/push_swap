#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include "ft_stack.h"
# include "ft_checker.h"

typedef struct	s_checker_options
{
	int		debug;
}				t_checker_options;


int		ft_get_args(int argc, char **argv, t_stack *a,
			t_checker_options **opt);
int		ft_read_and_do_instructions(t_stack *a, t_stack *b,
			t_checker_options *opt);
int		ft_show_debug(t_stack *a, t_stack *b, char *instruction, int first);

#endif