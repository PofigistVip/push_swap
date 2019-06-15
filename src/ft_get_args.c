
#include "libft.h"
#include "ft_stack.h"

int		ft_get_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		numb;

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
		else
			return (0);
	}
	return (1);
}