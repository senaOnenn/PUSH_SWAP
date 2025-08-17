/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:54 by eonen             #+#    #+#             */
/*   Updated: 2025/08/17 16:22:42 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
    t_stack *a = NULL;
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!is_valid(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
        t_stack *node = malloc(sizeof(t_stack));
        if(!node)
            return (1);
        node->value = ft_atol(argv[i]);
        node->next = NULL;
        
        add_back(&a,node); //stack_a nın sonuna ekleme
        i++;
	}
}