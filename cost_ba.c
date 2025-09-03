/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:46:28 by eonen             #+#    #+#             */
/*   Updated: 2025/09/03 17:11:37 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_cost_a(t_stack *a, int index)
{
	int	size_a;
	int	position;

	size_a = stack_size(a);
	position = find_target_pos_a(a, index);
	if (position <= size_a / 2)
		return (position);
	else
		return (position - size_a);
}

int	reverse_cost_b(t_stack *b, int index)
{
	int	position;
	int	size_b;

	size_b = stack_size(b);
	position = find_position(b, index);
	if (position <= size_b / 2)
		return (position);
	else
		return (position - size_b);
}

void	calculate_cost_b_to_a(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (temp)
	{
		temp->cost_a = reverse_cost_a(a, temp->index);
		temp->cost_b = reverse_cost_b(b, temp->index);
		if ((temp->cost_a >= 0 && temp->cost_b >= 0) || (temp->cost_a < 0
				&& temp->cost_b < 0))
		{
			if (ft_abs(temp->cost_a) > ft_abs(temp->cost_b))
				temp->total_cost = ft_abs(temp->cost_a);
			else
				temp->total_cost = ft_abs(temp->cost_b);
		}
		else
			temp->total_cost = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
		temp = temp->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

t_stack	*cheapest_action(t_stack *b)
{
	t_stack	*temp;
	t_stack	*lowest;
	int		min_value;

	if (!b)
		return (NULL);
	temp = b;
	lowest = b;
	min_value = b->total_cost;
	while (temp)
	{
		if (temp->total_cost < min_value)
		{
			min_value = temp->total_cost;
			lowest = temp;
		}
		temp = temp->next;
	}
	return (lowest);
}
