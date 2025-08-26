/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:54 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 20:18:42 by eonen            ###   ########.fr       */
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

	if (argc < 2)
		return (0); // Argüman yoksa çık

	// Argümanları kontrol et ve stack a'ya ekle
	while (i < argc)
	{
		if (!is_valid(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		add_back(&a, new_node(ft_atol(argv[i])));
		i++;
	}

}
