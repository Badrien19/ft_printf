/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:33:26 by badrien           #+#    #+#             */
/*   Updated: 2020/02/06 15:32:50 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	char			*ret;

	if (s2 == NULL)
		return (NULL);
	i = ft_strlen((char *)s1);
	if (!(ret = (char *)malloc(sizeof(char) * (i + ft_strlen((char*)s2) + 1))))
		return (0);
	if (s1 == NULL)
		ft_memcpy(ret, s2, ft_strlen((char*)s2) + 1);
	else
	{
		ft_memcpy(ret, s1, i);
		ft_memcpy(&ret[i], s2, ft_strlen((char*)s2) + 1);
	}
	free(s2);
	return (ret);
}

int		putstr_len(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return(0);
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	free(s);
	return (i);
}

size_t	ft_strlen(const char *chaine)
{
	size_t i;

	if (chaine == NULL)
		return (0);
	i = 0;
	while (chaine[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int						i;
	int						signe;
	unsigned long long int	value;
	unsigned long long int	max;

	i = 0;
	value = 0;
	signe = 1;
	max = 9223372036854775807;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		signe = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10;
		value = value + str[i] - '0';
		i++;
		if (value > max && signe == 1)
			return (-1);
		if (value > max + 1 && signe == -1)
			return (0);
	}
	return ((int)(value * signe));
}
