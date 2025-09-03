/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:54 by eonen             #+#    #+#             */
/*   Updated: 2025/09/03 17:17:38 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**nums;
	int		is_split;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	is_split = 0;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (1);
		is_split = 1;
	}
	else
		nums = &argv[1];
	i = 0;
	while (nums[i])
	{
		if (!is_valid(nums[i]) || has_dup(a, ft_atol(nums[i])))
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			if (is_split)
				full_free_arr(nums);
			return (1);
		}
		add_back(&a, new_node(ft_atol(nums[i])));
		i++;
	}
	if (is_split)
		full_free_arr(nums);
	set_index(a);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			three_sorting(&a);
		else
			big_sorting(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
