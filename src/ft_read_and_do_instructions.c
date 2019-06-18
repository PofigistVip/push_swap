
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_stack.h"
#include "ft_instructions.h"
#include "ft_checker.h"

t_lstr	*ft_read(void)
{
	t_lstr	*lstr;
	char	buffer[1001];
	int		readed;

	if ((lstr = ft_lstr_new_empty()) == NULL)
		return (NULL);
	while ((readed = read(0, buffer, 1000)) > 0)
	{
		buffer[readed] = 0;
		ft_lstr_insert_s(lstr, buffer, lstr->length);
	}
	return (lstr);
}

int		ft_do_instruction(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		ft_inst_sa(a, b, NULL);
	else if (ft_strcmp(instruction, "sb") == 0)
		ft_inst_sb(a, b, NULL);
	else if (ft_strcmp(instruction, "ss") == 0)
		ft_inst_ss(a, b, NULL);
	else if (ft_strcmp(instruction, "pa") == 0)
		ft_inst_pa(a, b, NULL);
	else if (ft_strcmp(instruction, "pb") == 0)
		ft_inst_pb(a, b, NULL);
	else if (ft_strcmp(instruction, "ra") == 0)
		ft_inst_ra(a, b, NULL);
	else if (ft_strcmp(instruction, "rb") == 0)
		ft_inst_rb(a, b, NULL);
	else if (ft_strcmp(instruction, "rr") == 0)
		ft_inst_rr(a, b, NULL);
	else if (ft_strcmp(instruction, "rra") == 0)
		ft_inst_rra(a, b, NULL);
	else if (ft_strcmp(instruction, "rrb") == 0)
		ft_inst_rrb(a, b, NULL);
	else if (ft_strcmp(instruction, "rrr") == 0)
		ft_inst_rrr(a, b, NULL);
	else
		return (0);
	return (1);
}

int		ft_read_free(t_stack *a, t_stack *b, char **instructions, int ok)
{
	int i;

	i = -1;
	while (instructions[++i])
		free(instructions[i]);
	free(instructions);
	if (!ok)
	{
		ft_stack_free(&a);
		ft_stack_free(&b);
	}
	return (ok);
}

int		ft_read_and_do_instructions(t_stack *a, t_stack *b,
			t_checker_options *opt)
{
	t_lstr	*lstr;
	char	**instructions;
	int		i;
	int		ok;

	if ((lstr = ft_read()) == NULL)
		return (0);
	if ((instructions = ft_strsplit(lstr->str, '\n')) == NULL)
	{
		ft_lstr_destroy(&lstr);
		return (0);
	}
	ft_lstr_destroy(&lstr);
	ok = 1;
	if (opt->debug)
		ft_show_debug(a, b, NULL, 1);
	i = 0;
	while (ok && instructions[i])
	{
		ok = ft_do_instruction(a, b, instructions[i++]);
		if (opt->debug)
			ft_show_debug(a, b, instructions[i - 1], 0);
	}	
	return (ft_read_free(a, b, instructions, ok));
}