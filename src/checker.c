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
#include "libft.h"
#include "ft_stack.h"
#include "ft_checker.h"

static int			ft_checker_error(t_stack **a, t_checker_options	*opt)
{
	if (a != NULL)
		ft_stack_free(a);
	if (opt != NULL)
		ft_opt_free(&opt);
	ft_putstr_fd("Error\n", 2);
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

int					ft_clear(t_stack **a, t_stack **b,
						t_checker_options **opt, int err)
{
	if (a != NULL && *a != NULL)
		ft_stack_free(a);
	if (b != NULL && *b != NULL)
		ft_stack_free(b);
	if (opt != NULL && *opt != NULL)
		ft_opt_free(opt);
	if (err)
		ft_putstr_fd("Error\n", 2);
	return (0);
}

int					main(int argc, char **argv)
{
	t_stack				*a;
	t_stack				*b;
	t_checker_options	*opt;

	if ((opt = ft_get_opt(argc, argv, 1)) == NULL)
		return (0);
	if ((a = ft_stack_new(opt->argc)) == NULL)
		return (ft_opt_free(&opt));
	if (!ft_get_args(a, opt))
		return (ft_clear(&a, 0, &opt, 1));
	if (a->top == -1)
		return (ft_clear(&a, 0, &opt, 0));
	if ((b = ft_stack_new(opt->argc)) == NULL)
		return (ft_clear(&a, 0, &opt, 0));
	if (!ft_read_and_do_instructions(a, b, opt))
		return (ft_checker_error(0, opt));
	ft_putstr((ft_solved(a, b)) ? "OK\n" : "KO\n");
	return (ft_clear(&a, &b, &opt, 0));
}
