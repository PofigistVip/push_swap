#include "libft.h"
#include "ft_stack.h"
#include "ft_instructions.h"

int		ft_inst_sa(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)b;
	ft_stack_swap(a);
	if (lstr)
		ft_lstr_insert_sn(lstr, "sa\n", 3, lstr->length);
	return (1);
}

int		ft_inst_sb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)a;
	ft_stack_swap(b);
	if (lstr)
		ft_lstr_insert_sn(lstr, "sb\n", 3, lstr->length);
	return (1);
}

int		ft_inst_ss(t_stack *a, t_stack *b, t_lstr *lstr)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
	if (lstr)
		ft_lstr_insert_sn(lstr, "ss\n", 3, lstr->length);
	return (1);
}

int		ft_inst_pa(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)b;
	if (b->top != -1)
	{
		ft_stack_push(a, ft_stack_pop(b));
		a->marks[a->top] = b->marks[b->top + 1];
	}	
	if (lstr)
		ft_lstr_insert_sn(lstr, "pa\n", 3, lstr->length);
	return (1);
}

int		ft_inst_pb(t_stack *a, t_stack *b, t_lstr *lstr)
{
	(void)a;
	if (a->top != -1)
	{
		ft_stack_push(b, ft_stack_pop(a));
		b->marks[b->top] = a->marks[a->top + 1];
	}	
	if (lstr)
		ft_lstr_insert_sn(lstr, "pb\n", 3, lstr->length);
	return (1);
}
