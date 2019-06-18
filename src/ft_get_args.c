
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

char				**ft_splited_args(int *argc, char **argv)
{
	t_lstr			*lstr;
	int				i;
	char			**splited;

	if ((lstr = ft_lstr_new_empty()) == NULL)
		return (NULL);
	i = 0;
	while (++i < *argc)
	{
		if (lstr->length != 0)
			ft_lstr_insert_c(lstr, ' ', 1, lstr->length);
		ft_lstr_insert_s(lstr, argv[i], lstr->length);
	}
	if ((splited = ft_strsplit(lstr->str, ' ')) == NULL)
		return (NULL);
	i = 0;
	while (splited[i])
		++i;
	*argc = i;
	ft_lstr_destroy(&lstr);
	return (splited);
}

t_checker_options 	*ft_get_opt(int argc, char **argv, int checker)
{
	t_checker_options	*opt;

	if (argc < 2)
		return (NULL);
	if ((opt = (t_checker_options*)malloc(sizeof(t_checker_options))) == NULL)
		return (NULL);
	opt->arguments = NULL;
	opt->debug = 0;
	if ((opt->arguments = ft_splited_args(&argc, argv)) == NULL)
	{
		free(opt);
		return (NULL);
	}
	if (argc == 0)
	{
		ft_splited_free(&(opt->arguments));
		free(opt);
		return (NULL);
	}
	opt->argc = argc;
	opt->is_checker = checker;
	return (opt);
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
