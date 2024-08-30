#include "push_swap.h"

int	is_sorted_stack(t_stack *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	length_stack(t_stack *node)
{
	int	count;

	count = 0;
	if (!node)
		return (0);
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += (str[i] - '0');
		i++;
	}
	return (number * sign);
}
