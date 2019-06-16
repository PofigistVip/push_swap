
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "ft_instructions.h"
#include "ft_stack.h"
#include "ft_push_swap.h"

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

void	ft_do_moves_optimal(t_stack *a, t_stack *b, t_lstr *lstr,
			int *moves_ab)
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
