#include "libft.h"
#include "ft_stack.h"
#include "ft_instructions.h"

int		ft_inst_ra(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)b;
	ft_stack_rotate(a);
	if (lstr)
		ft_lstr_insert_sn(lstr, "ra\n", 3, lstr->length);
	return (1);
}

int		ft_inst_rb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)a;
	ft_stack_rotate(b);
	if (lstr)
		ft_lstr_insert_sn(lstr, "rb\n", 3, lstr->length);
	return (1);
}

int		ft_inst_rr(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_rotate(a);
	ft_stack_rotate(b);
	if (lstr)
		ft_lstr_insert_sn(lstr, "rr\n", 3, lstr->length);
	return (1);
}

int		ft_inst_rra(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)b;
	ft_stack_reverse_rotate(a);
	if (lstr)
		ft_lstr_insert_sn(lstr, "rra\n", 4, lstr->length);
	return (1);
}

int		ft_inst_rrb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)a;
	ft_stack_reverse_rotate(b);
	if (lstr)
		ft_lstr_insert_sn(lstr, "rrb\n", 4, lstr->length);
	return (1);
}
