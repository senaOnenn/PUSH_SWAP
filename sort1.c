/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:32:18 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 14:56:17 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->index <= stack_size(*a) / 2)
		{
			pb(a, b); // küçük indeksleri b ye yolla
			write(1, "pb\n", 3);
			
			calculate_cost(*a,*b);
			move(a,b,cheapest_action(*b));
		}
	}
	three_sorting(a);
}

void	three_sorting(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third) // 1. > 2.< 3
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	else if (first > second && second > third) // 3>2>1
	{
		sa(a);
		write(1, "sa\n", 3);
		rra(a);
		write(1, "rra\n", 4);
	}
	else if (first > second && second < third && first > third)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	else if (first < second && second > third && first < third)
	{
		sa(a);
		write(1, "sa\n", 3);
		ra(a);
		write(1, "ra\n", 3);
	}
	else if (first < second && second > third && first > third)
	{
		rra(a);
		write(1, "rra\n", 3);
	}
}

void big_sorting(t_stack **a, t_stack **b)
{
	int size;
	t_stack *lowest;
	
	pb(a,b);
	write(1,"pb\n",3);
	pb(a,b);
	write(1,"pb\n",3);
	
	size = stack_size(*a);
	while(size > 3)
	{
		calculate_cost(*a,*b);
		lowest = cheapest_action(*b);
		move(a,b,lowest);
		size--;
	}
	three_sorting(a);
	
	while(*b)
	{
		calculate_cost(*a,*b);
		lowest = cheapest_action(*b);
		move(a,b,lowest);
	}
	sort_stack_a(a);
}


void	calculate_cost(t_stack *a, t_stack *b)
{
	t_stack *temp;
	int position_a;
    int position_b;
	int size_a;
	int size_b;
	int cost_a_abs;
	int cost_b_abs;

	temp = b;
	size_a = stack_size(a);
	size_b = stack_size(b);

	while (temp)
	{
		position_a = find_position(a, temp->index);
		if (position_a <= size_a / 2)
			temp->cost_a = position_a;
		else
			temp->cost_a = position_a - size_a;

		position_b = find_position(b, temp->index);
		if(position_b <= size_b / 2)
			temp->cost_b = position_b;
		else
			temp->cost_b = position_b - size_b;

		cost_a_abs = ft_abs(temp->cost_a);
		cost_b_abs = ft_abs(temp->cost_b);
		
		if ((temp->cost_a >= 0 && temp->cost_b >= 0) || (temp->cost_a <= 0 && temp->cost_b <= 0))
		{
			if (cost_a_abs > cost_b_abs)
				temp->total_cost = cost_a_abs;
			else
				temp->total_cost = cost_b_abs;
		}
		else
			temp->total_cost = cost_a_abs + cost_b_abs;

		temp = temp->next;
	}
}

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    else
        return(n);
}

t_stack *cheapest_action(t_stack *b)
{
    t_stack *temp;
    t_stack *lowest;
    int min;
    int total;
    
    temp = b;
    lowest = b;
    min = ft_abs(temp->cost_a) + ft_abs(temp ->cost_b);
    while(temp)
    {
        total = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
        if(total < min)
        {
            min = total;
            lowest = temp;
        }
        temp = temp->next;
    }
    return(lowest);
}
