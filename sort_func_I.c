#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	size;
	int	max_bits;
	
	max_bits = 0;
	size = stack->size_a;
	while (size > 1 && ++max_bits)
		size /= 2;
	return (max_bits);
}
void	radix_b(t_stack *stack, int max_bit, int i)
{
	int	size_b;

	size_b = stack->size_b;
	while (size_b-- && i <= max_bit && !is_sorted(stack))
	{
		if (((stack->b[0] >> i) & 1) == 0)
			rb(stack);
		else
			pa(stack);
	}

	if (is_sorted(stack))
	{
		while (stack->size_b != 0)
			pa(stack);
	}
}

void	radix_sort(t_stack *stack)
{
	int	max_bit;
	int	i;
	int	size;
	max_bit = get_max_bits(stack);
	i = -1;
	while (++i <= max_bit)
	{
		size = stack->size_a;
		while (size-- && !is_sorted(stack))
		{
			if (((stack->a[0] >> i) & 1) == 0)
				pb(stack);
			else
				ra(stack);
		}
		radix_b(stack, max_bit, i + 1);
	}
	while (stack->size_b != 0)
		pa(stack);
}

void sort_stack(t_stack *stack, int ac)
{
    if (ac == 2)
        sa(stack);
    else if (ac == 3)
        sort_three(stack);
    else
    {
        stack_to_index(stack, ac);
        if (ac == 4 || ac == 5)
			four_or_five_args(stack);
		else
			radix_sort(stack);
    }	
}
