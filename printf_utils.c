/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:33:26 by badrien           #+#    #+#             */
/*   Updated: 2019/11/27 15:11:17 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return (&dest[i] + 1);
		i++;
	}
	return (NULL);
}

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

size_t	ft_strlen(const char *chaine)
{
	size_t i;
	if(chaine ==  NULL)
		return (0);
	i = 0;
	while (chaine[i] != '\0')
		i++;
	return (i);
}