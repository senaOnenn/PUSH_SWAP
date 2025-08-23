/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:57:32 by eonen             #+#    #+#             */
/*   Updated: 2025/08/23 19:18:09 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	set_index(t_stack *a, int size)
{
	t_stack	*current;
	int		i;

	(void)size;
	while (a)
	{
		i = 0;
		current = a;
		while (current)
		{
			if (a->value > current->value)
				i++;
			current = current->next;
		}
		a->index = i;
		a = a->next;
	}
}

void	push_chunk(t_stack **a, t_stack **b, int chunk_size, int size)
{
	int	i;
	int	pushed_b;

	(void)size;
	i = 0;
	pushed_b = 0;
	while (*a)
	{
		if ((*a)->index <= i) // sıradaki en küçük indeksi buldu
		{
			pb(a, b); // a dan b ye yolla
			i++;
			pushed_b++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b); // chunk aralığındaki değerleri gönder
			rb(b);    // b yi rotate et, küçükler alta kalsın
			i++;
			pushed_b++;
		}
		else
			ra(a); // uygun chunk değilse a yı dönder
	}
}

int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	get_back(t_stack **a, t_stack **b)
{
	int max;
	int pos;

	while(*b)
	{
		max = find_max_index(*b);
		pos = find_position(*b,max);
		
		if(pos <= stack_size(*b) /2)
		{
			while((*b)->index != max)
				rb(b);
		}
		else
		{
			while((*b)->index != max)
				rrb(b);	
		}
		pa(a,b); //A ya push
	}
}