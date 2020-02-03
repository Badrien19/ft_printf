/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:33:26 by badrien           #+#    #+#             */
/*   Updated: 2020/02/03 16:13:56 by badrien          ###   ########.fr       */
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
	return (ret);
}

int		putstr_len(char *s)
{
	int i;

	i = 0;
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
