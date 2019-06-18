/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:16:00 by larlyne           #+#    #+#             */
/*   Updated: 2019/06/18 10:16:03 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_stack.h"
#include "ft_instructions.h"

int		ft_inst_rrr(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_reverse_rotate(a);
	ft_stack_reverse_rotate(b);
	if (lstr)
		ft_lstr_insert_sn(lstr, "rrr\n", 4, lstr->length);
	return (1);
}
