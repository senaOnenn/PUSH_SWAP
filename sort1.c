/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:32:18 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 21:34:11 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b); // küçük indeksleri b ye yolla
			write(1, "pb\n", 3);
			rb(b); // b nin kuyruğuna at, küçükler arkada dursun
		}
		else
		{
			pb(a, b); // büyük indeksleri direkt pushla
		}
		size--;
	}
}

void	three_sorting(t_stack **a)
{
	int first;
	int second;
	int third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
    if(first > second && second < third && first < third) //1. > 2.< 3
    {
        sa(a);
        write(1,"sa\n",3);
    }
    else if(first > second && second > third)//3>2>1
    {
        sa(a);
        write(1,"sa\n",3);
        rra(a);
        write(1,"rra\n",4);
    }
    else if(first > second && second < third && first > third)
    {
        ra(a);
        write(1,"ra\n",3);
    }
    else if(first < second && second > third && first < third)
    {
        sa(a);
        write(1,"sa\n",3);
        ra(a);
        write(1,"ra\n",3);
    }
    else if(first < second && second > third && first > third)
    {
        rra(a);
        write(1,"rra\n",3);
    }
}

void calculate_cost(t_stack *a, t_stack *b)
{
    t_stack *temp;
    int position;
    int size_a;
    int size_b;
    
    temp = b;
    size_a = stack_size(a);
    size_b = stack_size(b);
    
    while(temp)
    {
        position = find_position(a, temp->index); //temp b nin A da nereye gireceğini bul
        if(position <= size_a / 2)
            temp->cost_a = position; //normal rotate
        else
            temp->cost_a = position - size_a; //reverse rotate
        temp = temp->next;
    }
}