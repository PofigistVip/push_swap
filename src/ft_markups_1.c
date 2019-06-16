#include "libft.h"
#include "ft_instructions.h"
#include "ft_stack.h"
#include "ft_push_swap.h"

int		ft_greater_markup_core_inner(t_stack *a, t_stack *b, t_lstr *lstr,
			int *markup_size)
{
	int			temp_size;

	ft_stack_swap(a);
	temp_size = ft_markup(a, a->top, &ft_greater_than);
	if (temp_size > *markup_size)
	{
		ft_bzero(a->marks, (a->top + 1) * sizeof(char));
		*markup_size = temp_size;
		ft_stack_swap(a);
		ft_inst_sa(a, b, lstr);
		ft_markup_marks(a, a->top, &ft_greater_than);
		return (1);
	}
	ft_stack_swap(a);
	return (0);
}

void	ft_greater_markup_core(t_stack *a, t_stack *b, t_lstr *lstr)
{
	int			markup_head_i;
	int			markup_size;

	markup_head_i = ft_find_markup(a, &ft_greater_than);
	ft_markup_marks(a, markup_head_i, &ft_greater_than);
	markup_size = ft_stack_marks_count(a);
	while (ft_stack_marks_count(a) != a->top + 1)
		if (a->top >= 1 && (ft_greater_markup_core_inner(a, b, lstr, &markup_size) == 1))
			;
		else if (a->marks[a->top] == 1)
			ft_inst_ra(a, b, lstr);
		else
			ft_inst_pb(a, b, lstr);
	if (a->marks[a->top] == 0)
		ft_inst_pb(a, b, lstr);
}

int		ft_index_markup_core_inner(t_stack *a, t_stack *b, t_lstr *lstr,
			int *markup_size)
{
	int			temp_size;

	ft_stack_swap(a);
	temp_size = ft_markup(a, a->top, &ft_index_than);
	if (temp_size > *markup_size)
	{
		ft_bzero(a->marks, (a->top + 1) * sizeof(char));
		*markup_size = temp_size;
		ft_stack_swap(a);
		ft_inst_sa(a, b, lstr);
		ft_markup_marks(a, a->top, &ft_index_than);
		return (1);
	}
	ft_stack_swap(a);
	return (0);
}

void	ft_index_markup_core(t_stack *a, t_stack *b, t_lstr *lstr)
{
	int			markup_head_i;
	int			markup_size;

	markup_head_i = ft_find_markup(a, &ft_index_than);
	ft_markup_marks(a, markup_head_i, &ft_index_than);
	markup_size = ft_stack_marks_count(a);
	while (ft_stack_marks_count(a) != a->top + 1)
		if (a->top >= 1 && (ft_greater_markup_core_inner(a, b, lstr, &markup_size) == 1))
			;
		else if (a->marks[a->top] == 1)
			ft_inst_ra(a, b, lstr);
		else
			ft_inst_pb(a, b, lstr);
	if (a->marks[a->top] == 0)
		ft_inst_pb(a, b, lstr);
}