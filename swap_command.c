#include "push_swap.h"

static void	swap(t_stack **node)
{
	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return ;
	*node = (*node)->next;
	(*node)->prev->prev = *node;
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	(*node)->next = (*node)->prev;
	(*node)->prev = NULL;
}

void	sa(t_stack **stack_a, int print)
{
	swap(stack_a);
	if (print)
		write (1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print)
{
	swap(stack_b);
	if (print)
		write (1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		write (1, "ss\n", 3); 
}
