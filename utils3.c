/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:55:55 by eonen             #+#    #+#             */
/*   Updated: 2025/09/03 17:09:06 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_pos_a(t_stack *a, int b)
{
	t_stack	*current;
	int		min;
	int		max;
	int		position;

	if (!a)
		return (0);
	current = a;
	min = find_min_index(a);
	max = find_max_index(a);
	position = 0;
	if (b < min || b > max)
		return (find_position(a, min));
	while (current->next)
	{
		if (b > current->index && b < current->next->index)
			return (position + 1);
		current = current->next;
		position++;
	}
	return (position + 1);
}

int	find_target_pos_b(t_stack *b, int a)
{
	t_stack	*current;
	int		min;
	int		max;
	int		position;

	if (!b)
		return (0);
	current = b;
	min = find_min_index(b);
	max = find_max_index(b);
	position = 0;
	if (a < min || a > max)
		return (find_position(b, max));
	while (current->next)
	{
		if (a < current->index && a > current->next->index)
			return (position + 1);
		current = current->next;
		position++;
	}
	return (position + 1);
}

int	has_dup(t_stack *a, int new_value)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == new_value)
			return (1);
		a = a->next;
	}
	return (0);
}
