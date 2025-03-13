/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:53:06 by mucankir          #+#    #+#             */
/*   Updated: 2025/02/19 18:53:07 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
}	t_stack;

//Moves
void 	pa(t_stack *stack);
void 	pb(t_stack *stack);
void 	sa(t_stack *stack);
void 	sb(t_stack *stack);
void 	ss(t_stack *stack);
void 	ra(t_stack *stack);
void 	rb(t_stack *stack);
void 	rr(t_stack *stack);
void 	rra(t_stack *stack);
void 	rrb(t_stack *stack);
void	rrr(t_stack *stack);

//Stack
void 	free_stack(t_stack *stack);
void 	bublesort(int *arr, int len);
void	push_swap(char **args, int ac);
void 	stack_to_index(t_stack *stack, int ac);
void 	init_stack(t_stack *stack, char **args, int ac);

//Sortings
int 	is_sorted(t_stack *stack);
int 	sort_three(t_stack *stack);
void	radix_sort(t_stack *stack);
void	radix_sort(t_stack *stack);
void	four_or_five_args(t_stack *stack);
void	sort_stack(t_stack *stack, int ac);
void	radix_b(t_stack *stack, int max_bit, int i);
void 	create_index(t_stack *stack, int *values, int ac);

//Utils
int		ft_isdigit(char c);
int		ft_strlen(const char *s);
int 	check_isdigit(char **args);
int 	check_duplicate(char **args, int ac);
int 	check_args_limits(char **args, int ac);
int		ft_strcmp(const char *s1, const char *s2);

long	ft_atol(const char *str);

char	*ft_strdup(const char *s1);
char 	*ft_strjoin(char *s1, char *s2);
char	**ft_split(const char *s, char c);

void 	check_args(char **args, int ac);
void 	free_args(char *joined, char **args);
void	print_error(t_stack *stack, char *error);

#endif