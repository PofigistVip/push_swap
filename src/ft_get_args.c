
#include <stdlib.h>
#include "libft.h"
#include "ft_stack.h"
#include "ft_checker.h"

void				ft_splited_free(char ***splited)
{
	int		i;

	if (*splited)
	{
		i = 0;
		while ((*splited)[i])
			free((*splited)[i++]);
		free(*splited);
		*splited = NULL;
	}
}

int					ft_opt_free(t_checker_options **opt)
{
	if ((*opt)->arguments)
		ft_splited_free(&((*opt)->arguments));
	free(*opt);
	*opt = NULL;
	return (0);
}

int					ft_get_args(t_stack *a, t_checker_options *opt)
{
	int				i;
	int				numb;
	int				ok;

	i = opt->argc;
	ok = 1;
	while (--i >= 0)
		if (ft_isint(opt->arguments[i]))
		{
			numb = ft_atoi(opt->arguments[i]);
			if (ft_stack_contains(a, numb))
				return (0);
			ft_stack_push(a, numb);
		}
		else if (opt->is_checker && ft_strcmp(opt->arguments[i], "-d") == 0)
			opt->debug = 1;
		else
		{
			ok = 0;
			break ;
		}
	ft_splited_free(&(opt->arguments));
	return (ok);
}
