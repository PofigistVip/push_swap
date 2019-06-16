
#include <limits.h>
#include "libft.h"
#include "ft_instructions.h"
#include "ft_stack.h"
#include "ft_push_swap.h"

int		ft_greater_markup(t_stack *a, int i)
{
	int		first;
	int		current;
	int		counter;

	first = a->stack[i];
	current = first;
	counter = 1;
	while (--i != -1)
		if (current < a->stack[i])
		{
			current = a->stack[i];
			++counter;
		}
	i = a->top + 1;
	while (a->stack[--i] != first)
		if (current < a->stack[i])
		{
			current = a->stack[i];
			++counter;
		}
	return (counter);
}

int		ft_find_greater_markup(t_stack *a)
{
	int		i;
	int		max;
	int		max_i;
	int		temp;

	max = 0;
	max_i = -1;
	i = a->top + 1;
	while (--i >= 0)
	{
		temp = ft_greater_markup(a, i);
		if (max < temp)
		{
			max = temp;
			max_i = i;
		}
	}
	return (max_i);
}

void	ft_greater_markup_marks(t_stack *a, int markup_head_i)
{
	int		j;
	int		first;
	int		current;

	j =  markup_head_i;
	first = a->stack[j];
	a->marks[j] = 1;
	current = first;
	while (--j != -1)
		if (current < a->stack[j])
		{
			current = a->stack[j];
			a->marks[j] = 1;
		}
	j = a->top + 1;
	while (a->stack[--j] != first)
		if (current < a->stack[j])
		{
			current = a->stack[j];
			a->marks[j] = 1;
		}
}

int		ft_greater_markup_core_inner(t_stack *a, t_stack *b, t_lstr *lstr,
			int *markup_size)
{
	int			temp_size;

	ft_stack_swap(a);
	temp_size = ft_greater_markup(a, a->top);
	if (temp_size > *markup_size)
	{
		ft_bzero(a->marks, (a->top + 1) * sizeof(char));
		*markup_size = temp_size;
		ft_stack_swap(a);
		ft_inst_sa(a, b, lstr);
		ft_greater_markup_marks(a, a->top);
		return (1);
	}
	ft_stack_swap(a);
	return (0);
}

void	ft_greater_markup_core(t_stack *a, t_stack *b, t_lstr *lstr)
{
	int			markup_head_i;
	int			markup_size;
	int			i;

	markup_head_i = ft_find_greater_markup(a);
	ft_greater_markup_marks(a, markup_head_i);
	markup_size = ft_stack_marks_count(a);
	i = a->top + 1;
	while (ft_stack_marks_count(a) != a->top + 1)
	{
		if (a->top >= 1 && (ft_greater_markup_core_inner(a, b, lstr, &markup_size) == 1))
			;
		else if (a->marks[a->top] == 1)
		{
			ft_inst_ra(a, b, lstr);
			++i;
		}
		else
		{
			ft_inst_pb(a, b, lstr);
		}
	}
	if (a->marks[a->top] == 0)
	{
		ft_inst_pb(a, b, lstr);
	}
}

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

int		ft_pull_a(t_stack *a, t_stack *b)
{
	int		i;
	int		min_moves;
	int		min_i;
	int		summ;
	int		nearest;

	i = b->top + 1;
	min_moves = -1;
	while (--i >= 0)
	{
		nearest = ft_nearest_number_for(a, b->stack[i]);
		summ = ft_road_to_top_best(b, b->stack[i]);
		if (summ < 0)
			summ = -summ;
		if (ft_road_to_top_best(a, nearest) < 0)
			summ += -ft_road_to_top_best(a, nearest);
		else
			summ += ft_road_to_top_best(a, nearest);
		if (min_moves == -1 || summ < min_moves)
		{
			min_moves = summ;
			min_i = i;
		}
	}
	return (min_i);
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

int		ft_make_moves(t_stack *a, t_stack *b, t_lstr *lstr, int bi)
{
	int		moves_ab[2];
	int	nearest;
	int	moves;

	moves_ab[1] = ft_road_to_top_best(b, b->stack[bi]);
	nearest = ft_nearest_number_for(a, b->stack[bi]);
	moves_ab[0] = ft_road_to_top_best(a, nearest);
	ft_do_moves_optimal(a, b, lstr, moves_ab);
	ft_inst_pa(a, b, lstr);
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

void	ft_algorithm(t_stack *a, t_stack *b, t_lstr *lstr)
{
	t_stack		*a_copy;
	t_lstr		*alg1_lstr;
	t_lstr		*alg2_lstr;
	int			min_i;

	(void)alg1_lstr;
	(void)alg2_lstr;
	ft_greater_markup_core(a, b, lstr);
	while (b->top != -1)
	{
		min_i = ft_pull_a(a, b);
		ft_make_moves(a, b, lstr, min_i);
	}
	ft_set_min_on_top(a, b, lstr);
}