/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:01:27 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/15 12:01:31 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
typedef struct	s_stack
{
	int		*stack;
	char	*marks;
	int		top;
	int		size;
}				t_stack;

t_stack			*ft_stack_new(int size);
int				ft_stack_pop(t_stack *stack);
void			ft_stack_push(t_stack *stack, int numb);
void			ft_stack_swap(t_stack *stack);
void			ft_stack_rotate(t_stack *stack);
void			ft_stack_reverse_rotate(t_stack *stack);
void			ft_stack_free(t_stack **stack);
int				ft_stack_contains(t_stack *stack, int numb);
int				ft_stack_marks_count(t_stack	*stack);
t_stack			*ft_stack_copy(t_stack *stack);

#endif
