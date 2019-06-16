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
		free(opt);
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

char				**ft_splited_args(int *argc, char **argv)
{
	t_lstr			*lstr;
	int				i;
	char			**splited;
	int				len;

	if ((lstr = ft_lstr_new_empty()) == NULL)
		return (NULL);
	i = 0;
	while (++i < *argc)
	{
		if (lstr->length != 0)
			ft_lstr_insert_c(lstr, ' ', 1, lstr->length);
		ft_lstr_insert_s(lstr, argv[i], lstr->length);
	}
	if ((splited = ft_strsplit(lstr->str, ' ')) == NULL)
		return (NULL);
	i = 0;
	while (splited[i])
		++i;
	*argc = i;
	ft_lstr_destroy(&lstr);
	return (splited);
}

t_checker_options 	*ft_get_opt(int argc, char **argv)
{
	t_checker_options	*opt;
	int					i;

	if (argc < 2)
		return (NULL);
	if ((opt = (t_checker_options*)malloc(sizeof(t_checker_options))) == NULL)
		return (NULL);
	opt->arguments = NULL;
	opt->debug = 0;
	if ((opt->arguments = ft_splited_args(&argc, argv)) == NULL)
	{
		free(opt);
		return (NULL);
	}
	if (argc == 0)
	{
		ft_splited_free(opt->arguments);
		free(opt);
		return (NULL);
	}
	opt->argc = argc;
	opt->is_checker = 0;
	return (opt);
}

int					main(int argc, char **argv)
{
	t_stack				*a;
	t_stack				*b;
	t_checker_options	*opt;
	t_lstr				*lstr;

	if ((opt = ft_get_opt(argc, argv)) == NULL)
		return (0);
	a = ft_stack_new(opt->argc);
	if (!ft_get_args(a, opt))
		return (ft_push_swap_error(&a, 0));
	if (a->top == -1)
	{
		ft_stack_free(&a);
		return (0);
	}
	b = ft_stack_new(opt->argc);
	lstr = ft_lstr_new_empty();
	ft_algorithm(a, b, lstr);
	ft_lstr_put(lstr);
	ft_lstr_destroy(&lstr);
	ft_stack_free(&a);
	ft_stack_free(&b);
	free(opt);
	return (0);
}