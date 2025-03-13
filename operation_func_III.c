#include "push_swap.h"
#include <unistd.h>


void rra(t_stack *stack)
{
    int i;
    int temp;

    if (stack->size_a < 2)
        return;
    temp = stack->a[stack->size_a - 1];
    i = stack->size_a - 1;
    while (i > 0)
    {
        stack->a[i] = stack->a[i - 1];
        i--;
    }
    stack->a[0] = temp;
    write(1, "rra\n", 4);
}
void rrb(t_stack *stack)
{
    int i;
    int temp;

    if (stack->size_b < 2)
        return;
    temp = stack->b[stack->size_b - 1];
    i = stack->size_b - 1;
    while (i > 0)
    {
        stack->b[i] = stack->b[i - 1];
        i--;
    }
    stack->b[0] = temp;
    write(1, "rrb\n", 4);
}
void rrr(t_stack *stack)
{
    rra(stack);
    rrb(stack);
    write(1, "rrr\n", 4);
}
