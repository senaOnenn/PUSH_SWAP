/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:38:24 by eonen             #+#    #+#             */
/*   Updated: 2025/08/23 18:45:46 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_stack **a, t_stack **b)
{
    t_stack *temp;
    
    if(!*a)
        return;
    temp = *a; //a nın tepesini al
    *a = (*a)->next; //a dan çıakr
    temp->next = *b;//b nin tepesine koy
    *b=temp;
    write(1,"pb\n",3);
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *temp;
    
    if (!*b)
        return;
    temp = *b;
    *b = (*b)->next;
    temp->next  = *a;
    *a = temp;
    write(1,"pa\n",3);
}