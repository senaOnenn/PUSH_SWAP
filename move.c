/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:09:27 by eonen             #+#    #+#             */
/*   Updated: 2025/09/03 17:09:47 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a++;
		node->cost_b++;
	}
}

void	rotate_a_cost(t_stack **a, int *cost)
{
	while (*cost > 0)
	{
		ra(a);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rra(a);
		(*cost)++;
	}
}

void	rotate_b_cost(t_stack **b, int *cost)
{
	while (*cost > 0)
	{
		rb(b);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rrb(b);
		(*cost)++;
	}
}

void	move_a_to_b(t_stack **a, t_stack **b, t_stack *node)
{
	if (!a || !b || !node)
		return ;
	rotate_both(a, b, node);
	rotate_a_cost(a, &node->cost_a);
	rotate_b_cost(b, &node->cost_b);
	pb(a, b);
}

void	move(t_stack **a, t_stack **b, t_stack *node)
{
	if (!a || !b || !node)
		return ;
	rotate_both(a, b, node);
	rotate_a_cost(a, &node->cost_a);
	rotate_b_cost(b, &node->cost_b);
	pa(a, b);
}
