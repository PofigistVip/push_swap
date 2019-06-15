/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:24:05 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/15 12:24:15 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "ft_stack.h"

int		ft_test_msg(char *str, int ret)
{
	char c;

	c = '\n';
	while (*str)
		write(1, str++, 1);
	write(1, &c, 1);
	return (ret);
}

int		ft_stack_new_test(void)
{
	t_stack *stk;

	stk = ft_stack_new(0);
	if (stk != NULL)
		return (ft_test_msg("ft_stack_new(0) should not create object", 0));
	stk = ft_stack_new(-1);
	if (stk != NULL)
		return (ft_test_msg("ft_stack_new with negative var 'size' should not create object", 0));
	stk = ft_stack_new(1);
	if (stk == NULL)
		return (ft_test_msg("ft_stack_new with positive var 'size' must create object", 0));
	if (stk->size != 1)
		return (ft_test_msg("ft_stack_new must set field 'size'", 0));
	if (stk->top != -1)
		return (ft_test_msg("ft_stack_new must set field 'top' in -1(empty stack)", 0));
	if (stk->stack == NULL)
		return (ft_test_msg("ft_stack_new must create array of values (pointer 'stack')", 0));
	ft_stack_free(&stk);
	return (ft_test_msg("ft_stack_new is correct", 1));
}

int		ft_stack_push_test(void)
{
	t_stack *stk;

	stk = ft_stack_new(2);
	ft_stack_push(stk, 11);
	if (stk->top != 0)
		return (ft_test_msg("ft_stack_push used on empty stack must set field 'top' in 0", 0));
	if (stk->stack[stk->top] != 11)
		return (ft_test_msg("ft_stack_push must set number in 'top' index of inner array", 0));
	ft_stack_push(stk, 12);
	if (stk->top != 1)
		return (ft_test_msg("ft_stack_push used on stack with one element must set field 'top' in 1", 0));
	if (stk->stack[0] != 11)
		return (ft_test_msg("ft_stack_push do something wrong with previous element", 0));
	if (stk->stack[stk->top] != 12)
		return (ft_test_msg("ft_stack_push must set number in 'top' index of inner array", 0));
	ft_stack_push(stk, 13);
	if (stk->top != 1)
		return (ft_test_msg("ft_stack_push used on full stack must change no field 'top'", 0));
	if (stk->stack[stk->top] != 12)
		return (ft_test_msg("ft_stack_push used on full stack must change no top element", 0));
	ft_stack_free(&stk);
	return (ft_test_msg("ft_stack_push is correct", 1));
}

int		ft_stack_pop_test(void)
{
	t_stack	*stk;
	int		poped;

	stk = NULL;
	if (ft_stack_pop(stk) != 0)
		return (ft_test_msg("ft_stack_pop must return 0 if pointer on stack is NULL", 0));
	stk = ft_stack_new(4);
	if (ft_stack_pop(stk) != 0)
		return (ft_test_msg("ft_stack_pop must return 0 if stack is empty", 0));
	ft_stack_push(stk, 1);
	ft_stack_push(stk, 2);
	ft_stack_push(stk, 3);
	ft_stack_push(stk, 4);
	if (ft_stack_pop(stk) != 4)
		return (ft_test_msg("ft_stack_pop returned wrong value", 0));
	if (stk->top == 3)
		return (ft_test_msg("ft_stack_pop didn't change field 'top'", 0));
	if (stk->top != 2)
		return (ft_test_msg("ft_stack_pop change field 'top' very strange (WTF?)", 0));
	if (ft_stack_pop(stk) != 3)
		return (ft_test_msg("ft_stack_pop returned wrong value", 0));
	if (stk->top == 2)
		return (ft_test_msg("ft_stack_pop didn't change field 'top'", 0));
	if (stk->top != 1)
		return (ft_test_msg("ft_stack_pop change field 'top' very strange (WTF?)", 0));
	if (ft_stack_pop(stk) != 2)
		return (ft_test_msg("ft_stack_pop returned wrong value", 0));
	if (stk->top == 1)
		return (ft_test_msg("ft_stack_pop didn't change field 'top'", 0));
	if (stk->top != 0)
		return (ft_test_msg("ft_stack_pop change field 'top' very strange (WTF?)", 0));
	if (ft_stack_pop(stk) != 1)
		return (ft_test_msg("ft_stack_pop returned wrong value", 0));
	if (stk->top == 0)
		return (ft_test_msg("ft_stack_pop didn't change field 'top'", 0));
	if (stk->top != -1)
		return (ft_test_msg("ft_stack_pop must set field 'top' in -1 if last element was popped", 0));
	ft_stack_free(&stk);
	return (ft_test_msg("ft_stack_pop is correct", 1));
}

int		ft_stack_rotate_test(void)
{
	t_stack *stk;

	stk = ft_stack_new(3);
	ft_stack_push(stk, 5);
	ft_stack_rotate(stk);
	if (stk->top != 0)
		return (ft_test_msg("ft_stack_rotate must not change field 'top'", 0));
	if (stk->stack[stk->top] != 5)
		return (ft_test_msg("ft_stack_rotate rotate one element somewhere (WTF?)", 0));
	ft_stack_push(stk, -5);
	ft_stack_rotate(stk);
	if (stk->top != 1)
		return (ft_test_msg("ft_stack_rotate must not change field 'top'", 0));
	if (stk->stack[0] == 5 && stk->stack[1] == -5)
		return (ft_test_msg("ft_stack_rotate didn't rotate elements", 1));
	if (stk->stack[stk->top] != 5)
		return (ft_test_msg("ft_stack_rotate rotate elements wrong", 0));
	if (stk->stack[0] != -5)
		return (ft_test_msg("ft_stack_rotate rotate elements wrong", 0));
	ft_stack_push(stk, 10);
	ft_stack_rotate(stk);
	if (stk->top != 2)
		return (ft_test_msg("ft_stack_rotate must not change field 'top'", 0));
	if (stk->stack[0] == -5 && stk->stack[1] == 5 && stk->stack[2] == 10)
		return (ft_test_msg("ft_stack_rotate didn't rotate elements", 0));
	if (stk->stack[stk->top] != 5 || stk->stack[1] != -5 || stk->stack[0] != 10)
		return (ft_test_msg("ft_stack_rotate rotate elements wrong", 0));
	ft_stack_free(&stk);
	return (ft_test_msg("ft_stack_rotate is correct", 1));
}

int		ft_stack_reverse_rotate_test(void)
{
	t_stack *stk;

	stk = ft_stack_new(3);
	ft_stack_push(stk, 5);
	ft_stack_reverse_rotate(stk);
	if (stk->top != 0)
		return (ft_test_msg("ft_stack_reverse_rotate must not change field 'top'", 0));
	if (stk->stack[stk->top] != 5)
		return (ft_test_msg("ft_stack_reverse_rotate rotate one element somewhere (WTF?)", 0));
	ft_stack_push(stk, -5);
	ft_stack_reverse_rotate(stk);
	if (stk->top != 1)
		return (ft_test_msg("ft_stack_reverse_rotate must not change field 'top'", 0));
	if (stk->stack[0] == 5 && stk->stack[1] == -5)
		return (ft_test_msg("ft_stack_reverse_rotate didn't rotate elements", 0));
	if (stk->stack[stk->top] != 5 || stk->stack[0] != -5)
		return (ft_test_msg("ft_stack_reverse_rotate rotate elements wrong", 0));
	ft_stack_push(stk, 10);
	ft_stack_reverse_rotate(stk);
	if (stk->top != 2)
		return (ft_test_msg("ft_stack_reverse_rotate must not change field 'top'", 0));
	if (stk->stack[0] == 5 && stk->stack[1] == -5 && stk->stack[2] == 10)
		return (ft_test_msg("ft_stack_reverse_rotate didn't rotate elements", 0));
	if (stk->stack[2] != -5 || stk->stack[1] != 10 || stk->stack[0] != 5)
		return (ft_test_msg("ft_stack_reverse_rotate rotate elements wrong", 0));
	ft_stack_free(&stk);
	return (ft_test_msg("ft_stack_reverse_rotate is correct", 1));
}

int		ft_stack_swap_test(void)
{
	t_stack	*stk;

	stk = ft_stack_new(5);
	ft_stack_push(stk, 1);
	ft_stack_push(stk, 2);
	ft_stack_push(stk, 3);
	ft_stack_swap(stk);
	if (stk->top != 2)
		return (ft_test_msg("ft_stack_swap didn't should change field 'top' (WTF?)", 0));
	if (stk->stack[stk->top] == 3 || stk->stack[stk->top - 1] == 2)
		return (ft_test_msg("ft_stack_swap didn't swap elements", 0));
	if (stk->stack[stk->top] != 2 || stk->stack[stk->top - 1] != 3)
		return (ft_test_msg("ft_stack_swap swap numbers wrong (WTF?)", 0));
	ft_stack_push(stk, INT_MAX);
	ft_stack_push(stk, INT_MIN);
	ft_stack_swap(stk);
	if (stk->stack[stk->top] != INT_MAX || stk->stack[stk->top - 1] != INT_MIN)
		return (ft_test_msg("ft_stack_swap swap numbers wrong (WTF?)", 0));
	ft_stack_free(&stk);
	return (ft_test_msg("ft_stack_swap is correct", 1));
}

int		main(void)
{
	if (!ft_stack_new_test())
		return (0);
	if (!ft_stack_push_test())
		return (0);
	if (!ft_stack_pop_test())
		return (0);
	if (!ft_stack_swap_test())
		return (0);
	if (!ft_stack_rotate_test())
		return (0);
	if (!ft_stack_reverse_rotate_test())
		return (0);
}