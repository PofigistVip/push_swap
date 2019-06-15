
#include <stdlib.h>
#include "libft.h"
#include "ft_stack.h"
#include "ft_checker.h"

t_checker_options	*ft_create_options(void)
{
	t_checker_options	*opt;

	if ((opt = (t_checker_options*)malloc(sizeof(t_checker_options))) == NULL)
		return (NULL);
	opt->debug = 0;
	return (opt);
}	

int					ft_get_args(int argc, char **argv, t_stack *a,
						t_checker_options **opt)
{
	int					i;
	int					numb;

	if ((*opt = ft_create_options()) == NULL)
		return (0);
	i = argc;
	while (--i > 0)
	{
		if (ft_isint(argv[i]))
		{
			numb = ft_atoi(argv[i]);
			if (ft_stack_contains(a, numb))
				return (0);
			ft_stack_push(a, numb);
		}
		else if (ft_strcmp(argv[i], "-d") == 0)
			(*opt)->debug = 1;
		else
			return (0);
	}
	return (1);
}