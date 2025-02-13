#include "push_swap.h"
// This function checks if the stack is sorted.
int	ft_checksorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	stack_a = stack_a->next; 
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
