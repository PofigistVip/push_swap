
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "ft_instructions.h"
#include "ft_stack.h"
#include "ft_push_swap.h"


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
	ft_index_markup_core(a_copy, b, alg2_lstr);
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
