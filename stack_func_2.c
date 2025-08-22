/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:07:17 by eonen             #+#    #+#             */
/*   Updated: 2025/08/22 16:39:24 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next) // listnein sonuna git, prev sondan bir önceki olcak
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;   // sondan bir öncekinin bağını koparıp
	last->next = *stack; // son elemanı başa alıyoruz
	*stack = last;       // stack başını son eleman olarak güncelle
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
