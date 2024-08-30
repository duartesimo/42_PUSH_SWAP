#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	error(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_b);
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

static int	check_line(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (!ft_strcmp(command, "pa"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(command, "pb"))
		pb(stack_b, stack_a, 0);
	else if (!ft_strcmp(command, "sa"))
		sa(stack_a, 0);
	else if (!ft_strcmp(command, "sb"))
		sb(stack_b, 0);
	else if (!ft_strcmp(command, "ss"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(command, "ra"))
		ra(stack_a, 0);
	else if (!ft_strcmp(command, "rb"))
		rb(stack_b, 0);
	else if (!ft_strcmp(command, "rr"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(command, "rra"))
		rra(stack_a, 0);
	else if (!ft_strcmp(command, "rrb"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(command, "rrr"))
		rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

static void	run_commands(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	char	c;
	char	*command;

	command = malloc(4);
	i = 0;
	while (read(0, &c, 1))
	{
		if (c == '\n' || i > 2)
		{
			command[i] = '\0';
			if (!check_line(stack_a, stack_b, command))
			{
				free(command);
				error(stack_a, stack_b);
			}
			free(command);
			command = malloc(4);
			i = 0;
		}
		else
			command[i++] = c;
	}
	free(command);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	start_stack(&stack_a, argv + 1);
	run_commands(&stack_a, &stack_b);
	if (!stack_b && is_sorted_stack(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}
