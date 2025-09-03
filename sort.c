/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:32:18 by eonen             #+#    #+#             */
/*   Updated: 2025/09/03 18:06:10 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sorting(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!a || stack_size(*a) != 3)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	if (first->index < second->index && second->index < third->index)
		return ;
	else if (first->index > second->index && first->index < third->index)
		sort_case_1(a);
	else if (first->index > second->index && second->index < third->index
		&& first->index > third->index)
		sort_case_2(a);
	else if (first->index < second->index && second->index > third->index
		&& first->index < third->index)
		sort_case_3(a);
	else if (first->index < second->index && second->index > third->index
		&& first->index > third->index)
		sort_case_4(a);
	else if (first->index > second->index && second->index > third->index)
		sort_case_5(a);
}

void	big_sorting(t_stack **a, t_stack **b)
{
	int	position;
	int	size;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	bigsorting_push_b(a, b);
	three_sorting(a);
	bigsorting_push_a(a, b);
	position = find_position(*a, 0);
	size = stack_size(*a);
	while (position > 0)
	{
		if (position <= size / 2)
			ra(a);
		else
			rra(a);
		position = find_position(*a, 0);
	}
	sort_stack_a(a);
}

void	sort_stack_a(t_stack **a)
{
	int	position;
	int	size;

	position = find_position(*a, 0);
	size = stack_size(*a);
	while (position > 0)
	{
		if (position <= size / 2)
		{
			ra(a);
		}
		else
		{
			rra(a);
		}
		position = find_position(*a, 0);
	}
}

void	bigsorting_push_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (stack_size(*a) > 3)
	{
		calculate_cost_a_to_b(*a, *b);
		cheapest = find_cheapest_to_push(*a);
		move_a_to_b(a, b, cheapest);
	}
}

void	bigsorting_push_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		calculate_cost_b_to_a(*a, *b);
		cheapest = cheapest_action(*b);
		if (!cheapest)
			break ;
		move(a, b, cheapest);
	}
}
