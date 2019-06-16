
#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define ABS(x) ((x > 0) ? x : -x)
# include "libft.h"
# include "ft_stack.h"

void	ft_algorithm(t_stack *a, t_stack *b, t_lstr *lstr);
int		ft_road_to_top_rotate(t_stack *a, int number);
int		ft_road_to_top_reverse_rotate(t_stack *a, int number);
int		ft_road_to_top_best(t_stack *stack, int number);

#endif
