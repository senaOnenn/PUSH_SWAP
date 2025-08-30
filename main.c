/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:54 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 15:10:24 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		size;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	// Argümanları kontrol et ve A yığınına ekle
	while (i < argc)
	{
		if (!is_valid(argv[i]))
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			return (1);
		}
		add_back(&a, new_node(ft_atol(argv[i])));
		i++;
	}
	// Yığın boyutunu hesapla ve indeksleri ata
	size = stack_size(a);
	set_index(a, size);
	// Eğer yığın zaten sıralıysa çık
	if (is_sorted(a))
	{
		free_stack(&a);
		write(1, "stack sirali\n", 13);
		return (0);
	}
	// Yığın boyutuna göre sıralama yap
	if (size == 2)
	{
		if (a->index > a->next->index)
			sa(&a);
	}
	else if (size == 3)
	{
		three_sorting(&a);
	}
	else
	{
		big_sorting(&a, &b);
	}
	// Yığınları temizle
	free_stack(&a);
	free_stack(&b);
	return (0);
}
