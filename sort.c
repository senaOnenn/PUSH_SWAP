/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:57:32 by eonen             #+#    #+#             */
/*   Updated: 2025/08/23 17:27:21 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	set_index(t_stack *a, int size)
{
	t_stack	*current;
	int		i;

	while (a)
	{
		i = 0;
		current = a;
		while (current)
		{
			if (a->value > curr->value)
				i++;
			current = current->next;
		}
		a->index = i;
		a = a->next;
	}
}

void	push_chunk(t_stack **a, t_stack **b, int chunk_size, int size)
{
	int i;
	int pushed_b;

	i = 0;
	pushed_b = 0;
	while(*a)
	{
		if((*a)->index <= i)//sıradaki en küçük indeksi buldu
		{
			pb(a,b); //a dan b ye yolla
			i++;
			pushed_b++;
		}
		else if((*a)->index <= i + chunk_size)
		{
			pb(a,b); //chunk aralığındaki değerleri gönder
			rb(b); //b yi rotate et, küçükler alta kalsın
			i++;
			pushed_b++;
		}
		else
			ra(a); //uygun chunk değilse a yı dönder
	}
}