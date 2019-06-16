
#ifndef FT_COMMON_H
# define FT_COMMON_H
# include "ft_stack.h"

typedef struct	s_checker_options
{
	int		is_checker;
	int		argc;
	char	**arguments;
	int		debug;
}				t_checker_options;

void	ft_splited_free(char ***splited);
int		ft_get_args(t_stack *a, t_checker_options *opt);

#endif
