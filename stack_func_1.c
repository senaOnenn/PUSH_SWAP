/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:50:20 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 13:26:40 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n",3);
}

void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!*stack || !((*stack)->next))
		return ;
	first = *stack;
	stack = &first->next;
	
	last = *stack;
	while(last->next) //listenin sonuna git
		last = last->next;
	last->next = first; //eski ilk elemanı sonuna ekle
	first->next = NULL; //eksi ilk eleman şimdi son, next i null
}

void ra(t_stack **a)
{
    rotate(a);
	write(1, "ra\n",3);
}

void rb(t_stack **b)
{
    rotate(b);
	write(1, "rb\n",3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n",3);
}