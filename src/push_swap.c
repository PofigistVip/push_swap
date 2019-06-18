/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:59:38 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/15 11:59:40 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_common.h"
#include "libft.h"
#include "ft_stack.h"
#include "ft_push_swap.h"

int					ft_push_swap_error(t_stack **a, t_checker_options	*opt)
{
	if (a != NULL)
		ft_stack_free(a);
	if (opt != NULL)
		ft_opt_free(&opt);
	ft_putstr_fd("Error\n", 1);
	return (0);
}

int					ft_solved(t_stack *a, t_stack *b)
{
	int i;

	if (b->top != -1)
		return (0);
	if (a->top == 0)
		return (1);
	i = a->top + 1;
	while (--i > 0)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (0);
	}
	return (1);
}

int					main(int argc, char **argv)
{
	t_stack				*a;
	t_checker_options	*opt;
	t_lstr				*lstr;

	if ((opt = ft_get_opt(argc, argv, 0)) == NULL)
		return (0);
	if ((a = ft_stack_new(opt->argc)) == NULL)
		return (ft_opt_free(&opt));
	if (!ft_get_args(a, opt))
		return (ft_push_swap_error(&a, opt));
	lstr = NULL;
	ft_algorithm(a, &lstr);
	ft_lstr_put(lstr);
	ft_lstr_destroy(&lstr);
	ft_stack_free(&a);
	return (ft_opt_free(&opt));
}
