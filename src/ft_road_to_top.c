#include "ft_stack.h"

static int	ft_road_find_element(t_stack *a, int number)
{
	int i;

	i = -1;
	while (++i <= a->top)
		if (number == a->stack[i])
			return (i);
	return (-1);
}

int			ft_road_to_top_rotate(t_stack *a, int number)
{
	int		index;

	index = ft_road_find_element(a, number);
	return (a->top - index);
}

int			ft_road_to_top_reverse_rotate(t_stack *a, int number)
{
	int		index;

	index = ft_road_find_element(a, number);
	if (index == a->top)
		return (0);
	return (index + 1);
}

int			ft_road_to_top_best(t_stack *stack, int number)
{
	int		rot;
	int		rrot;

	rot = ft_road_to_top_rotate(stack, number);
	rrot = ft_road_to_top_reverse_rotate(stack, number);
	return ((rot < rrot) ? rot : -rrot);
}
