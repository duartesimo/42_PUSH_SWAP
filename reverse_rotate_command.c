#include "push_swap.h"

static void	reverse_rotate(t_stack **node)
{
	t_stack	*last_node;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return ;
	last_node = get_last_node(*node);
	last_node->prev->next = NULL;
	last_node->next = *node;
	last_node->prev = NULL;
	*node = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_b != cheap->target_node && *stack_a != cheap)
		rrr(stack_a, stack_b, 1);
	current_index(*stack_a);
	current_index(*stack_b);
}
