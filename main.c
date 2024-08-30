#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	start_stack(&stack_a, argv + 1);
	if (!is_sorted_stack(stack_a))
	{
		if (length_stack(stack_a) == 2)
			sa(&stack_a, 1);
		else if (length_stack(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
