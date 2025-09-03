/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:54:42 by eonen             #+#    #+#             */
/*   Updated: 2025/09/03 17:14:43 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_free_arr(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_arr(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_word_count(char *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && (i == 0 || str[i - 1] == c)))
			word_count++;
		i++;
	}
	return (word_count);
}

char	*seperate_words(char *str, int *i, char c)
{
	int		start;
	int		len;
	char	*word;
	int		j;

	while (str[*i] == c)
		(*i)++;
	start = *i;
	while (str[*i] && str[*i] != c)
		(*i)++;
	len = *i - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	j = -1;
	while (++j < len)
		word[j] = str[start + j];
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	**result;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	word_count = ft_word_count(str, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	while (j < word_count)
	{
		result[j] = seperate_words((char *)str, &i, c);
		if (!result[j])
		{
			free_arr(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}
