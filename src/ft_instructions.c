#include "libft.h"
#include "ft_stack.h"
#include "ft_instructions.h"

int		ft_inst_sa(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_swap(a);
	if (lstr)
		ft_lstr_append_sn(lstr, "sa\n", 3, lstr->length);
	return (1);
}
int		ft_inst_sb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_swap(b);
	if (lstr)
		ft_lstr_append_sn(lstr, "sb\n", 3, lstr->length);
	return (1);
}
int		ft_inst_ss(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
	if (lstr)
		ft_lstr_append_sn(lstr, "ss\n", 3, lstr->length);
	return (1);
}
int		ft_inst_pa(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_push(a, ft_stack_pop(b));
	if (lstr)
		ft_lstr_append_sn(lstr, "pa\n", 3, lstr->length);
	return (1);
}
int		ft_inst_pb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_push(b, ft_stack_pop(a));
	if (lstr)
		ft_lstr_append_sn(lstr, "pb\n", 3, lstr->length);
	return (1);
}
int		ft_inst_ra(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_rotate(a);
	if (lstr)
		ft_lstr_append_sn(lstr, "ra\n", 3, lstr->length);
	return (1);
}
int		ft_inst_rb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_rotate(b);
	if (lstr)
		ft_lstr_append_sn(lstr, "rb\n", 3, lstr->length);
	return (1);
}
int		ft_inst_rr(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_rotate(a);
	ft_stack_rotate(b);
	if (lstr)
		ft_lstr_append_sn(lstr, "rr\n", 3, lstr->length);
	return (1);
}
int		ft_inst_rra(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_reverse_rotate(a);
	if (lstr)
		ft_lstr_append_sn(lstr, "rra\n", 4, lstr->length);
	return (1);
}
int		ft_inst_rrb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_reverse_rotate(b);
	if (lstr)
		ft_lstr_append_sn(lstr, "rrb\n", 4, lstr->length);
	return (1);
}
int		ft_inst_rrr(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_reverse_rotate(a);
	ft_stack_reverse_rotate(b);
	if (lstr)
		ft_lstr_append_sn(lstr, "rrr\n", 4, lstr->length);
	return (1);
}
