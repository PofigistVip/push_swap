/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:01:03 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/15 12:01:05 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "ft_stack.h"

t_stack			*ft_stack_new(int size)
{
	t_stack		*stack;

	if (size <= 0 || (stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	if ((stack->stack = (int*)malloc(size * sizeof(int))) == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->top = -1;
	stack->size = size;
	return (stack);
}

int				ft_stack_pop(t_stack *stack)
{
	if (stack == NULL || stack->top == -1)
		return (0);
	return (stack->stack[stack->top--]);
}

void			ft_stack_push(t_stack *stack, int numb)
{
	if (stack == NULL || stack->top + 1 == stack->size)
		return ;
	stack->stack[++stack->top] = numb;
}

void			ft_stack_swap(t_stack *stack)
{
	int		temp;

	if (stack != NULL && stack->top >= 1)
	{
		temp = stack->stack[stack->top];
		stack->stack[stack->top] = stack->stack[stack->top - 1];
		stack->stack[stack->top - 1] = temp;
	}
}

void			ft_stack_rotate(t_stack *stack)
{
	int		temp;

	if (stack == NULL || stack->top < 1)
		return ;
	temp = stack->stack[stack->top];
	ft_memmove(stack->stack + 1, stack->stack, stack->top * sizeof(int));
	stack->stack[0] = temp;
}

void			ft_stack_reverse_rotate(t_stack *stack)
{
	int		temp;

	if (stack == NULL || stack->top < 1)
		return ;
	temp = stack->stack[0];
	ft_memmove(stack->stack, stack->stack + 1, stack->top * sizeof(int));
	stack->stack[stack->top] = temp;
}

void			ft_stack_free(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	free((*stack)->stack);
	free(*stack);
	*stack = NULL;
}

void			ft_stack_show(t_stack *stack)
{
	int		i;

	if (stack == NULL)
		return ;
	i = -1;
	while (++i <= stack->top)
	{
		ft_putnbr(stack->stack[i]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

int				ft_stack_contains(t_stack *stack, int numb)
{
	int i;

	if (stack)
	{
		i = -1;
		while (++i <=stack->top)
			if (stack->stack[i] == numb)
				return (1);
	}
	return (0);
}