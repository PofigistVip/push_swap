
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "ft_instructions.h"
#include "ft_stack.h"
#include "ft_push_swap.h"

int		ft_nearest_number_for(t_stack *stack, int number)
{
	int		num_i;
	int		distance;
	int		i;

	distance = INT_MAX;
	i = stack->top + 1;
	while (--i >= 0)
	{
		if (stack->stack[i] > number && stack->stack[i] - number < distance)
		{
			distance = stack->stack[i] - number;
			num_i = i;
		}
	}
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

void	ft_set_min(int *min, int *current)
{
	if (min[2] > current[2])
		ft_memmove(min, current, 5 * sizeof(int));
}

int		*ft_pull_a(t_stack *a, t_stack *b)
{
	int		*min;
	int		curr[5];
	int		i;

	min = (int*)ft_memalloc(5 * sizeof(int));
	min[2] = INT_MAX;
	i = b->top + 1;
	while (--i >= 0)
	{
		curr[3] = b->stack[i];
		curr[4] = ft_nearest_number_for(a, b->stack[i]);
		ft_count_ra_rb(a, b, curr);
		ft_set_min(min, curr);
		ft_count_ra_rrb(a, b, curr);
		ft_set_min(min, curr);
		ft_count_rra_rb(a, b, curr);
		ft_set_min(min, curr);
		ft_count_rra_rrb(a, b, curr);
		ft_set_min(min, curr);
	}
	return (min);
}

void	ft_do_moves_optimal(t_stack *a, t_stack *b, t_lstr *lstr, int *moves_ab)
{
	while ((moves_ab[0] > 0 && moves_ab[1] > 0) &&
		(moves_ab[0]-- && moves_ab[1]--))
		ft_inst_rr(a, b, lstr);
	while ((moves_ab[0] < 0 && moves_ab[1] < 0) &&
		(moves_ab[0]++ && moves_ab[1]++))
		ft_inst_rrr(a, b, lstr);
	while (moves_ab[0] != 0)
		if (moves_ab[0] > 0 && moves_ab[0]--)
			ft_inst_ra(a, b, lstr);
		else if (moves_ab[0]++)
			ft_inst_rra(a, b, lstr);
	while (moves_ab[1] != 0)
		if (moves_ab[1] > 0 && moves_ab[1]--)
			ft_inst_rb(a, b, lstr);
		else if (moves_ab[1]++)
			ft_inst_rrb(a, b, lstr);
}

int		ft_min_el(t_stack *a)
{
	int		min;
	int		i;

	min = INT_MAX;
	i = -1;
	while (++i <= a->top)
	{
		if (a->stack[i] < min)
			min = a->stack[i];
	}
	return (min);
}

void	ft_set_min_on_top(t_stack *a, t_stack *b, t_lstr *lstr)
{
	int		min_el;
	int		moves;

	min_el = ft_min_el(a);
	moves = ft_road_to_top_best(a, min_el);
	while (moves != 0)
		if (moves > 0 && moves--)
			ft_inst_ra(a, b, lstr);
		else if (moves++)
			ft_inst_rra(a, b, lstr);
}

void	ft_algorithm(t_stack *a, t_stack *b, t_lstr **lstr)
{
	t_stack		*a_copy;
	t_lstr		*alg1_lstr;
	t_lstr		*alg2_lstr;
	int			*min;

	a_copy = ft_stack_copy(a);
	alg1_lstr = ft_lstr_new_empty();
	ft_greater_markup_core(a, b, alg1_lstr);
	while (b->top != -1)
	{
		min = ft_pull_a(a, b);
		ft_do_moves_optimal(a, b, alg1_lstr, min);
		ft_inst_pa(a, b, alg1_lstr);
		free(min);
	}
	ft_set_min_on_top(a, b, alg1_lstr);

	alg2_lstr = ft_lstr_new_empty();
	ft_greater_markup_core(a_copy, b, alg2_lstr);
	while (b->top != -1)
	{
		min = ft_pull_a(a_copy, b);
		ft_do_moves_optimal(a_copy, b, alg2_lstr, min);
		ft_inst_pa(a_copy, b, alg2_lstr);
		free(min);
	}
	ft_set_min_on_top(a_copy, b, alg2_lstr);
	if (alg1_lstr->length < alg2_lstr->length)
	{
		*lstr = alg1_lstr;
		ft_lstr_destroy(&alg2_lstr);
	}
	else
	{
		*lstr = alg2_lstr;
		ft_lstr_destroy(&alg1_lstr);
	}
}