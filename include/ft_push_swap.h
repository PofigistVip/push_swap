/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:24:49 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/18 10:24:54 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define ABS(x) ((x > 0) ? x : -x)
# include "libft.h"
# include "ft_stack.h"

void	ft_algorithm(t_stack *a, t_lstr **lstr);
int		ft_greater_than(int current, t_stack *a, int in_stack);
int		ft_index_than(int current, t_stack *a, int in_stack);
int		ft_markup(t_stack *a, int i, int (*f)(int, t_stack*, int));
int		ft_find_markup(t_stack *a, int (*f)(int, t_stack*, int));
void	ft_markup_marks(t_stack *a, int markup_head_i,
			int (*f)(int, t_stack*, int));
int		ft_greater_markup_core_inner(t_stack *a, t_stack *b, t_lstr *lstr,
			int *markup_size);
void	ft_greater_markup_core(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_index_markup_core_inner(t_stack *a, t_stack *b, t_lstr *lstr,
			int *markup_size);
void	ft_index_markup_core(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_nearest_number_for(t_stack *stack, int number);
int		ft_road_to_top_rotate(t_stack *a, int number);
int		ft_road_to_top_reverse_rotate(t_stack *a, int number);
int		ft_road_to_top_best(t_stack *stack, int number);

void	ft_count_ra_rb(t_stack *a, t_stack *b, int *current);
void	ft_count_rra_rb(t_stack *a, t_stack *b, int *current);
void	ft_count_ra_rrb(t_stack *a, t_stack *b, int *current);
void	ft_count_rra_rrb(t_stack *a, t_stack *b, int *current);

void	ft_set_min(int *min, int *current);
int		*ft_pull_a(t_stack *a, t_stack *b);
void	ft_do_moves_optimal(t_stack *a, t_stack *b, t_lstr *lstr,
			int *moves_ab);
int		ft_min_el(t_stack *a);
void	ft_set_min_on_top(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_after_max_el(t_stack *stack);

#endif
