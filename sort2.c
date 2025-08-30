/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:27:25 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 13:37:29 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b); // hem ra hem rb
		write(1, "rr\n", 3);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b); // hem rra hem rrb
		write(1, "rrr\n", 4);
		node->cost_a++;
		node->cost_b++;
	}
	while (node->cost_a > 0)
	{
		ra(a);
		write(1, "ra\n", 3);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(a);
		write(1, "rra\n", 4);
		node->cost_a++;
	}
	while (node->cost_b > 0)
	{
		rb(b);
		write(1, "rb\n", 3);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(b);
		write(1, "rrb\n", 4);
		node->cost_b++;
	}
	pa(a, b);
	write(1, "pa\n", 3);
}

void	push_all_to_a(t_stack **a, t_stack **b)
{
	t_stack *lowest;

	while (*b)
	{
        calculate_cost(*a,*b); //b deki tüm elemanlar için maliyet hesapla
        lowest = cheapest_action(*b);
        move (a,b,lowest);
	}
    sort_stack_a(a);
}

void sort_stack_a(t_stack **a)
{
    int position;
    int size;
    
    position = find_position(*a,0); //en küçük elemanın pozisyonu
    size = stack_size(*a);
    
    while(position > 0)
    {
        if(position <= size /2)
        {
            ra(a);
            write(1, "ra\n", 3);
        }
        else
        {
            rra(a);
            write(1,"rra\n",4);
        }
        position = find_position(*a,0);
    }
}