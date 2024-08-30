#include "push_swap.h"

static void	rotate(t_stack **node)
{
	t_stack	*last_node;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return ;
	last_node = get_last_node(*node);
	last_node->next = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rr(stack_a, stack_b, 1);
	current_index(*stack_a);
	current_index(*stack_b);
}
