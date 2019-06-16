
#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define ABS(x) ((x > 0) ? x : -x)
# include "libft.h"
# include "ft_stack.h"

void	ft_algorithm(t_stack *a, t_stack *b, t_lstr **lstr);
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

#endif
