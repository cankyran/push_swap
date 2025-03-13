#include "push_swap.h"

int sort_three(t_stack *stack)
{
    if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[0] < stack->a[2])
        sa(stack);
    else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
    {
        sa(stack);
        rra(stack);
    }
    else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[0] > stack->a[2])
        ra(stack);
    else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[0] < stack->a[2])
    {
        sa(stack);
        ra(stack);
    }
    else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[0] > stack->a[2])
        rra(stack);
    return (1);
}

void	four_or_five_args(t_stack *stack)
{
	while (stack->size_b <= 1)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			pb(stack);
		else
			ra(stack);
	}
	if (stack->b[0] == 0)
		sb(stack);
	if (stack->a[2] != 4)
	{
		if (stack->a[0] == 4)
			ra(stack); 
		else
			rra(stack);
	}
	if (stack->a[0] > stack->a[1])
		sa(stack);
	pa(stack);
    pa(stack);
}
void create_index(t_stack *stack, int *values, int ac)
{
    int i;
    int j;
    int temp;

    i = 0;
    while(i < ac)
    {
        temp = stack->a[i];
        j = 0;
        while (j < ac)
        {
            if (temp == values[j])
            {
                stack->a[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
}
void stack_to_index(t_stack *stack, int ac)
{
    int i;
    int *values;

    values = malloc(sizeof(int) * ac);
    if (!values)
        print_error(stack, "Error\n");
    i = 0;
    while (i < ac)
    {
        values[i] = stack->a[i];
        i++;
    }
    bublesort(values, ac);
    create_index(stack, values, ac);
    free(values);
}
