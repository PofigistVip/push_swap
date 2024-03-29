/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:24:20 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/18 10:24:22 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTIONS_H
# define FT_INSTRUCTIONS_H
# include "ft_stack.h"

int		ft_inst_sa(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_sb(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_ss(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_pa(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_pb(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_ra(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_rb(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_rr(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_rra(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_rrb(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_inst_rrr(t_stack *a, t_stack *b, t_lstr *lstr);

#endif
