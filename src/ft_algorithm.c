
#include "libft.h"
#include "ft_stack.h"

int		ft_greater_markup(t_stack *a, int i)
{
	int		j;
	int		first;
	int		current;
	int		counter;

	first = a->stack[i];
	current = first;
	counter = 1;
	j = i;
	while (--j != -1)
		if (current < a->stack[j])
		{
			current = a->stack[j];
			++counter;
		}
	j = a->top + 1;
	while (a->stack[--j] != first)
		if (current < a->stack[j])
		{
			current = a->stack[j];
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

void	ft_algorithm(t_stack *a, t_stack *b, t_lstr *lstr)
{
	t_stack		*a_copy;
	t_lstr		*alg1_lstr;
	t_lstr		*alg2_lstr;

	(void)a;
	(void)b;
	(void)lstr;
	ft_lstr_insert_s(lstr, "rra\npb\nsa\nrra\npa", lstr->length);
}