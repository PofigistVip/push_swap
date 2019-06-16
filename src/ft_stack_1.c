#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "ft_stack.h"

void			ft_stack_reverse_rotate(t_stack *stack)
{
	int		temp;

	if (stack == NULL || stack->top < 1)
		return ;
	temp = stack->stack[0];
	ft_memmove(stack->stack, stack->stack + 1, stack->top * sizeof(int));
	stack->stack[stack->top] = temp;
	temp = stack->marks[0];
	ft_memmove(stack->marks, stack->marks + 1, stack->top * sizeof(char));
	stack->marks[stack->top] = temp;
}

void			ft_stack_free(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	free((*stack)->stack);
	free((*stack)->marks);
	free(*stack);
	*stack = NULL;
}

int				ft_stack_contains(t_stack *stack, int numb)
{
	int i;

	if (stack)
	{
		i = -1;
		while (++i <=stack->top)
			if (stack->stack[i] == numb)
				return (1);
	}
	return (0);
}

int				ft_stack_marks_count(t_stack *stack)
{
	int		i;
	int		counter;

	counter = 0;
	i = stack->top + 1;
	while (--i >= 0)
		if (stack->marks[i] == 1)
			++counter;
	return (counter);
}

t_stack			*ft_stack_copy(t_stack *stack)
{
	t_stack		*new_stack;

	if (stack == NULL)
		return (NULL);
	if ((new_stack = ft_stack_new(stack->size)) == NULL)
		return (NULL);
	new_stack->top = stack->top;
	if (new_stack->top != -1)
	{
		ft_memmove(new_stack->stack, stack->stack, (new_stack->top + 1) * sizeof(int));
		ft_memmove(new_stack->marks, stack->marks, (new_stack->top + 1) * sizeof(char));
	}
	return (new_stack);
}
