/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:16:51 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/18 10:16:55 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_instructions.h"
#include "ft_stack.h"
#include "ft_push_swap.h"

/*
** f(current, stack, num_in_stack)
*/

int		ft_greater_than(int current, t_stack *a, int in_stack)
{
	(void)a;
	return ((current < in_stack) ? 1 : 0);
}

int		ft_index_than(int current, t_stack *a, int in_stack)
{
	int		nearest;

	nearest = ft_nearest_number_for(a, current);
	return ((in_stack == nearest) ? 1 : 0);
}

int		ft_markup(t_stack *a, int i, int (*f)(int, t_stack*, int))
{
	int		first;
	int		current;
	int		counter;

	first = a->stack[i];
	current = first;
	counter = 1;
	while (--i != -1)
		if (f(current, a, a->stack[i]))
		{
			current = a->stack[i];
			++counter;
		}
	i = a->top + 1;
	while (a->stack[--i] != first)
		if (f(current, a, a->stack[i]))
		{
			current = a->stack[i];
			++counter;
		}
	return (counter);
}

int		ft_find_markup(t_stack *a, int (*f)(int, t_stack*, int))
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
		temp = ft_markup(a, i, f);
		if (max < temp)
		{
			max = temp;
			max_i = i;
		}
	}
	return (max_i);
}

void	ft_markup_marks(t_stack *a, int markup_head_i,
			int (*f)(int, t_stack*, int))
{
	int		j;
	int		first;
	int		current;

	j = markup_head_i;
	first = a->stack[j];
	a->marks[j] = 1;
	current = first;
	while (--j != -1)
		if (f(current, a, a->stack[j]))
		{
			current = a->stack[j];
			a->marks[j] = 1;
		}
	j = a->top + 1;
	while (a->stack[--j] != first)
		if (f(current, a, a->stack[j]))
		{
			current = a->stack[j];
			a->marks[j] = 1;
		}
}
