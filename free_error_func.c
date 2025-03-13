/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nd_error_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:53:18 by mucankir          #+#    #+#             */
/*   Updated: 2025/02/19 18:53:19 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"
#include    <unistd.h>

void free_args(char *joined, char **args)
{
    int i;

    if (args)
    {
        i = 0;
        while (args[i])
        {
            free(args[i]);
            i++;
        }
        free(args);
    }
    if (joined)
        free(joined);
       
}
void    free_stack(t_stack *stack)
{
    if (stack->a)
        free(stack->a);
    if (stack->b)
        free(stack->b);
    if (stack)
        free(stack);
}
void	print_error(t_stack *stack, char *error)
{
    if (stack)
        free_stack(stack);
        
    write(2, error,ft_strlen(error));
    exit(1);
}