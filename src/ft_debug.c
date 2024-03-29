/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:14:25 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/18 10:14:29 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_stack.h"

void	ft_show_line(t_stack *stack, int i)
{
	char	*num;

	if (stack->top < i)
		ft_putstr("             ");
	else
	{
		num = ft_itoa(stack->stack[i]);
		ft_putcharn_fd(1, ' ', 13 - ft_strlen(num));
		ft_putstr(num);
		free(num);
	}
}

void	ft_show_debug(t_stack *a, t_stack *b, char *instruction, int first)
{
	int		i;

	ft_putstr((first) ? "First" : "After '");
	if (!first)
		ft_putstr(instruction);
	ft_putstr((first) ? "\n" : "':\n");
	ft_putstr("*======A======*======B======*\n");
	i = a->size;
	while (--i >= 0)
	{
		ft_putchar('|');
		ft_show_line(a, i);
		ft_putchar('|');
		ft_show_line(b, i);
		ft_putstr("|\n");
	}
	ft_putstr("*=============*=============*\n");
}
