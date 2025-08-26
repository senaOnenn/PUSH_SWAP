/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:45:23 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 13:31:55 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					is_digit(int c);
int					is_valid(char *str);
long				ft_atol(const char *nptr);
void				free_stack(t_stack **stack);
t_stack				*new_node(long value);
void				add_back(t_stack **stack_a, t_stack *node);
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				push(t_stack **src, t_stack **dest);
void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
int					stack_size(t_stack *stack);
void				set_index(t_stack *a, int size);
void				push_chunk(t_stack **a, t_stack **b, int chunk_size,
						int size);
int					find_max_index(t_stack *stack);
int					find_position(t_stack *stack, int index);
void				get_back(t_stack **a, t_stack **b);

#endif