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
