#include "push_swap.h"

static void	push(t_stack **dest, t_stack **source)
{
	t_stack	*node;

	if (!(*source))
		return ;
	node = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	node->prev = NULL;
	if (!(*dest))
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	push(stack_a, stack_b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a, int print)
{
	push(stack_b, stack_a);
	if (print)
		write(1, "pb\n", 3);
}
