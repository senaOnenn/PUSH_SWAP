/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:57:32 by eonen             #+#    #+#             */
/*   Updated: 2025/08/22 19:40:03 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

int	find_max_bits(t_stack *stack)
{
	int max;

	max = 0;
	while (stack) // stackin sonuna kadar gez
	{
		if (stack->index > max)
			max = stack->index; //en büyük indeksi bul
        stack = stack-> next;
	}
}