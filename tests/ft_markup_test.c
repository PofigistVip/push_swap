#include <stdio.h>
#include "libft.h"
#include "ft_stack.h"

int		ft_greater_markup(t_stack *a, int i);
int		ft_find_greater_markup(t_stack *a);
void	ft_greater_markup_marks(t_stack *a, int markup_head_i);

void	ft_greater_markup_test(t_stack *a)
{
	int		i;
	
	i = a->top + 1;
	while (--i >= 0)
	{
		ft_putstr("Head ");
		ft_putnbr(a->stack[i]);
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("]\tMarkup size = ");
		ft_putnbr(ft_greater_markup(a, i));
		ft_putchar('\n');
	}
}

void	ft_find_greater_markup_test(t_stack *a)
{
	int		markup_head_i;

	markup_head_i = ft_find_greater_markup(a);
	ft_putstr("Greater markup is ");
	ft_putnbr(a->stack[markup_head_i]);
	ft_putchar('[');
	ft_putnbr(markup_head_i);
	ft_putstr("]\n");
}

void	ft_greater_markup_marks_test(t_stack *a)
{
	int		markup_head_i;
	int		i;

	markup_head_i = ft_find_greater_markup(a);
	ft_greater_markup_marks(a, markup_head_i);
	i = a->top + 1;
	ft_putstr("TOP\n");
	while (--i >= 0)
	{
		ft_putnbr(a->stack[i]);
		ft_putchar('[');
		ft_putnbr(i);
		ft_putchar(']');
		ft_putstr((a->marks[i] == 1) ? "marked\n" : "\n");
	}
}

int		main(void)
{
	t_stack		*a;

	a = ft_stack_new(10);
	ft_stack_push(a, 9);
	ft_stack_push(a, 1);
	ft_stack_push(a, 7);
	ft_stack_push(a, 6);
	ft_stack_push(a, 4);
	ft_stack_push(a, 0);
	ft_stack_push(a, 3);
	ft_stack_push(a, 8);
	ft_stack_push(a, 2);
	ft_stack_push(a, 5);
	ft_greater_markup_test(a);
	ft_find_greater_markup_test(a);
	ft_greater_markup_marks_test(a);
	return (0);
}