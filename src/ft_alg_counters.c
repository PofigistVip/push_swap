
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "ft_instructions.h"
#include "ft_stack.h"
#include "ft_push_swap.h"

int		ft_after_max_el(t_stack *stack)
{
	int		i;
	int		max;
	int		max_i;

	i = -1;
	max = INT_MIN;
	while (++i <= stack->top)
		if (max < stack->stack[i])
		{
			max = stack->stack[i];
			max_i = i;
		}
	if (max_i - 1 < 0)
		return (stack->stack[stack->top]);
	return (stack->stack[max_i - 1]);
}

int		ft_nearest_number_for(t_stack *stack, int number)
{
	int		num_i;
	int		distance;
	int		i;

	distance = INT_MAX;
	i = stack->top + 1;
	num_i = -1;
	while (--i >= 0)
	{
		if (stack->stack[i] > number && stack->stack[i] - number < distance)
		{
			distance = stack->stack[i] - number;
			num_i = i;
		}
	}
	if (num_i == -1)
		return (ft_after_max_el(stack));
	return (stack->stack[num_i]);
}

void	ft_count_ra_rb(t_stack *a, t_stack *b, int *current)
{
	current[1] = ft_road_to_top_rotate(b, current[3]);
	current[0] = ft_road_to_top_rotate(a, current[4]);
	current[2] = (current[0] > current[1]) ? current[0] : current[1];
}

void	ft_count_rra_rb(t_stack *a, t_stack *b, int *current)
{
	current[1] = ft_road_to_top_rotate(b, current[3]);
	current[0] = ft_road_to_top_reverse_rotate(a, current[4]);
	current[2] = current[0] + current[1];
	current[0] = -current[0];
}

void	ft_count_ra_rrb(t_stack *a, t_stack *b, int *current)
{
	current[1] = ft_road_to_top_reverse_rotate(b, current[3]);
	current[0] = ft_road_to_top_rotate(a, current[4]);
	current[2] = current[0] + current[1];
	current[1] = -current[1];
}

void	ft_count_rra_rrb(t_stack *a, t_stack *b, int *current)
{
	current[1] = ft_road_to_top_reverse_rotate(b, current[3]);
	current[0] = ft_road_to_top_reverse_rotate(a, current[4]);
	current[2] = (current[0] > current[1]) ? current[0] : current[1];
	current[0] = -current[0];
	current[1] = -current[1];
}
