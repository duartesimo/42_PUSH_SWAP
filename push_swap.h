#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

long	ft_atol(char *str);
char	**ft_split(char const *s, char c);
void	add_node(t_stack **stack, int num);
int		error_syntax(char *str_n);
int		error_duplicate(t_stack *node, int num);
void	free_stack(t_stack **node);
void	free_errors(t_stack **stack_a);
void	start_stack(t_stack **stack, char **argv);
int		is_sorted_stack(t_stack *node);
int		length_stack(t_stack *node);
t_stack	*find_max(t_stack *node);
t_stack	*find_min(t_stack *node);
t_stack	*get_last_node(t_stack *node);
t_stack	*get_cheapest(t_stack *node);
void	current_index(t_stack *node);
void	set_cheapest(t_stack *node);
void	prepare_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	prepare_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	prep_for_push(t_stack **node, t_stack *top_node, char stack);
void	sort_three(t_stack **stack);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap);

#endif