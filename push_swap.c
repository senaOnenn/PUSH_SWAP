/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:54 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 18:12:23 by eonen            ###   ########.fr       */
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

	// Stack boyutunu al ve indexleri ayarla
	size = stack_size(a);
	set_index(a, size);

	// Küçük listeler için özel sıralama
	if (size == 2)
		sa(&a); // 2 eleman swap
	else if (size == 3)
		three_sorting(&a);
	else if (size == 5)
		five_sorting(&a, &b); // 5 eleman için özel fonksiyon
	else
	{
		// Daha büyük listeler için chunk boyutunu ayarla
		if (size <= 100)
			chunk_size = 5;
		else
			chunk_size = 20;

		// Chunk mantığıyla push
		push_chunk(&a, &b, chunk_size, size);
	}

	// B'den A'ya geri al
	get_back(&a, &b);

	// Hafızayı temizle
	free_stack(&a);
	free_stack(&b);

	return (0);
}
