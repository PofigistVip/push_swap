
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

t_lstr	*ft_alg_greater(t_stack *a, t_stack *b)
{
	int		*min;
	t_lstr	*lstr;

	lstr = ft_lstr_new_empty();
	ft_greater_markup_core(a, b, lstr);
	while (b->top != -1)
	{
		min = ft_pull_a(a, b);
		ft_do_moves_optimal(a, b, lstr, min);
		ft_inst_pa(a, b, lstr);
		free(min);
	}
	ft_set_min_on_top(a, b, lstr);
	return (lstr);
}

t_lstr	*ft_alg_index(t_stack *a, t_stack *b)
{
	int		*min;
	t_lstr	*lstr;

	lstr = ft_lstr_new_empty();
	ft_index_markup_core(a, b, lstr);
	while (b->top != -1)
	{
		min = ft_pull_a(a, b);
		ft_do_moves_optimal(a, b, lstr, min);
		ft_inst_pa(a, b, lstr);
		free(min);
	}
	ft_set_min_on_top(a, b, lstr);
	return (lstr);
}

int		ft_lstr_count_chars(t_lstr *lstr, char c)
{
	int		counter;
	char	*ptr;
	int		i;

	ptr = lstr->str;
	i = 0;
	counter = 0;
	while (i < lstr->length)
	{
		if (*ptr == c)
			++counter;
		++ptr;
		++i;
	}
	return (counter);
}

void	ft_algorithm(t_stack *a, t_lstr **lstr)
{
	t_stack		*b;
	t_stack		*a_copy;
	t_lstr		*alg1_lstr;
	t_lstr		*alg2_lstr;

	b = ft_stack_new(a->size);
	a_copy = ft_stack_copy(a);
	alg1_lstr = ft_alg_greater(a, b);
	alg2_lstr = ft_alg_index(a_copy, b);
	if (ft_lstr_count_chars(alg1_lstr, '\n') <
		ft_lstr_count_chars(alg2_lstr, '\n'))
	{
		*lstr = alg1_lstr;
		ft_lstr_destroy(&alg2_lstr);
	}
	else
	{
		*lstr = alg2_lstr;
		ft_lstr_destroy(&alg1_lstr);
	}
	ft_stack_free(&a_copy);
	ft_stack_free(&b);
}
