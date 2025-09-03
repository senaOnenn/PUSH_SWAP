/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:31:37 by eonen             #+#    #+#             */
/*   Updated: 2025/09/03 17:12:37 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost_a(t_stack *a, int index)
{
	int	position;

	position = find_position(a, index);
	if (position <= stack_size(a) / 2)
		return (position);
	else
		return (position - stack_size(a));
}

int	calculate_cost_b(t_stack *b, int index)
{
	int	position;

	if (b)
		position = find_target_pos_b(b, index);
	else
		position = 0;
	if (position <= stack_size(b) / 2)
		return (position);
	else
		return (position - stack_size(b));
}

void	calculate_cost_a_to_b(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		temp->cost_a = calculate_cost_a(a, temp->index);
		temp->cost_b = calculate_cost_b(b, temp->index);
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

t_stack	*find_cheapest_to_push(t_stack *a)
{
	t_stack	*temp;
	t_stack	*cheapest;
	int		min_value;

	if (!a)
		return (NULL);
	cheapest = a;
	temp = a;
	min_value = a->total_cost;
	while (temp)
	{
		if (temp->total_cost < min_value)
		{
			min_value = temp->total_cost;
			cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest);
}
