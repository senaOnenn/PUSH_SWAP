/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:50:20 by eonen             #+#    #+#             */
/*   Updated: 2025/08/18 19:03:58 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ss(t_stack **a, t_stack **b)
{
	swap(&a);
	swap(&b);
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;         // kaynaktaki üst eleman temp e alınır
	*src = (*src)->next; // kaynaktaki üst eleman kaldırılır
	temp->next = *dest;  // tempi hedefin başına alırız
	*dest = temp;        // hedefin başı temp
}

void rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;
    
    if(!*stack || !())
}