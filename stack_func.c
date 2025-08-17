/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:50 by eonen             #+#    #+#             */
/*   Updated: 2025/08/17 16:24:53 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(long value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if(!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return(node);
}

void add_back(t_stack **stack_a, t_stack *node)
{
    t_stack *temp;
    
    if(!*stack_a) //eğer liste boşsa
    {
        *stack_a = node; //yeni eleman direkt başa alınır
        return;
    }
    temp = *stack_a; //tempi listenin başına işaretleriz
    while(temp->next) //listenin sonuna kadar gidilir 
        temp = temp->next;
    temp->next  = node; //son düğümün nextine yeni eleman bağlanır
}

