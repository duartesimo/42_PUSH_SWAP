#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = find_max(*stack);
	if (biggest == *stack)
		ra(stack, 1);
	else if (biggest == (*stack)->next)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}

static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && 
		!(cheapest->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
	prep_for_push(stack_a, cheapest, 'a');
	prep_for_push(stack_b, cheapest->target_node, 'b');
	pb(stack_b, stack_a, 1);
}

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, 1);
}

static void	min_to_top(t_stack **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a)->value)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = length_stack(*stack_a);
	if (len-- > 3 && !is_sorted_stack(*stack_a))
		pb(stack_b, stack_a, 1);
	if (len-- > 3 && !is_sorted_stack(*stack_a))
		pb(stack_b, stack_a, 1);
	while (len-- > 3 && !is_sorted_stack(*stack_a))
	{
		prepare_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		prepare_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_to_top(stack_a);
}
