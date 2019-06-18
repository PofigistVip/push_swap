/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:23:33 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/18 10:24:03 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMON_H
# define FT_COMMON_H
# include "ft_stack.h"

typedef struct		s_checker_options
{
	int		is_checker;
	int		argc;
	char	**arguments;
	int		debug;
}					t_checker_options;

void				ft_splited_free(char ***splited);
t_checker_options	*ft_get_opt(int argc, char **argv, int checker);
int					ft_opt_free(t_checker_options **opt);
int					ft_get_args(t_stack *a, t_checker_options *opt);

#endif
