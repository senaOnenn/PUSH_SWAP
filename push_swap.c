/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:54 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 13:30:58 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int i;
	int size;
	int chunk_size;

	a = NULL;
	b = NULL;
	i = 1;
	
	if(argc < 2)
		return(0);
	while(i < argc)
	{
		if(!is_valid(argv[i]))
		{
			write(2,"Error\n",6);
			return(1);
		}
		add_back(&a,new_node(ft_atol(argv[i])));
		i++;
	}
	size = stack_size(a);
	set_index(a,size);
	if (size <= 100)
	{
        chunk_size = 5;
	}
	else
        chunk_size = 20;
	
	push_chunk(&a, &b, chunk_size, size);
	get_back(&a,&b);
	free_stack(&a);

}