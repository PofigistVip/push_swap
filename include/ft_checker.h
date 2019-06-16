#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include "ft_common.h"
# include "ft_stack.h"
# include "ft_checker.h"

int		ft_read_and_do_instructions(t_stack *a, t_stack *b,
			t_checker_options *opt);
void	ft_show_debug(t_stack *a, t_stack *b, char *instruction, int first);

#endif