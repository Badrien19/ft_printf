/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:21:18 by badrien           #+#    #+#             */
/*   Updated: 2020/02/05 16:13:53 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strndup(char *s, int size)
{
	char	*new;
	int		i;

	i = 0;
	if (size < 0)
		return (NULL);
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (0);
	while (i < size)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*add_space_back(char *s, int size, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (size < 0)
		return (NULL);
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (0);
	while (i < size && s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	while (i < size)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*add_space_before(char *s, int size, char c)
{
	char	*new;
	int		i;
	int		y;

	i = 0;
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (0);
	while (s[i] != '\0')
		i++;
	y = size - i;
	i = 0;
	while (y)
	{
		new[i] = c;
		y--;
		i++;
	}
	while (s[y] != '\0')
	{
		new[i] = s[y];
		y++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*add_zero_front(char *s, int size)
{
	char	*new;
	int		signe;
	int		i;

	i = 0;
	if (size < 0)
		return (NULL);
	signe = s[i] == '-' ? (1) : (0);
	if (!(new = malloc(sizeof(char) * size + signe)))
		return (0);
	while (s[i] != '\0')
		i++;
	new[size + signe] = '\0';
	while (i)
	{
		if (s[i - 1] == '-')
			break ;
		new[size-- - 1 + signe] = s[i-- - 1];
	}
	while (size + signe > 0)
		new[size-- - 1 + signe] = '0';
	if (s[0] == '-')
		new[0] = '-';
	return (new);
}

char	*add_zero_front_zero(char *s, int size)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (0);
	while (s[i] != '\0')
		i++;
	new[size] = '\0';
	while (i)
	{
		if (s[i - 1] == '-')
			break ;
		new[size - 1] = s[i - 1];
		size--;
		i--;
	}
	while (size > 0)
	{
		new[size - 1] = '0';
		size--;
	}
	if (s[0] == '-')
		new[0] = '-';
	return (new);
}
