#include "push_swap.h"
#include <unistd.h>

void ra(t_stack *stack)
{
    int i;
    int temp;

    if (stack->size_a < 2)
        return;
    temp = stack->a[0];
    i = 0;
    while (i < stack->size_a - 1)
    {
        stack->a[i] = stack->a[i + 1];
        i++;
    }
    stack->a[stack->size_a - 1] = temp;
    write(1, "ra\n", 3);
}
void rb(t_stack *stack)
{
    int i;
    int temp;

    if (stack->size_b < 2)
        return;
    temp = stack->b[0];
    i = 0;
    while (i < stack->size_b - 1)
    {
        stack->b[i] = stack->b[i + 1];
        i++;
    }
    stack->b[stack->size_b - 1] = temp;
    write(1, "rb\n", 3);
}
void rr(t_stack *stack)
{
    ra(stack);
    rb(stack);
    write(1, "rr\n", 3);
}
