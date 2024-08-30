#include "push_swap.h"

static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	prepare_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

void	prep_for_push(t_stack **node, t_stack *top_node, char stack)
{
	while (*node != top_node)
	{
		if (stack == 'a')
		{
			if (top_node->above_median)
				ra(node, 1);
			else
				rra(node, 1);
		}
		else if (stack == 'b')
		{
			if (top_node->above_median)
				rb(node, 1);
			else
				rrb(node, 1);
		}
	}
}
