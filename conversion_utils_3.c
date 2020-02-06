/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:27:04 by badrien           #+#    #+#             */
/*   Updated: 2020/02/06 15:21:17 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_adress(unsigned long long pt)
{
	char				*s;
	int					i;
	unsigned long long	nbr_cpy;
	char				hexa[17];

	i = 0;
	nbr_cpy = pt;
	ft_memcpy(hexa, "0123456789abcdef\0", 17);
	while (nbr_cpy != 0 && i++ != -1)
		nbr_cpy = nbr_cpy / 16;
	if (pt == 0)
		i = 1;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (0);
	s[i--] = '\0';
	if (nbr_cpy == 0)
		s[0] = '0';
	nbr_cpy = pt;
	while (nbr_cpy != 0)
	{
		s[i--] = hexa[(nbr_cpy % 16)];
		nbr_cpy = nbr_cpy / 16;
	}
	return (s);
}

char	*get_hexa(unsigned int nbr, int i)
{
	unsigned int	nbr_cpy;
	char			*s;
	char			hexa[17];

	nbr_cpy = nbr;
	ft_memcpy(hexa, "0123456789abcdef\0", 17);
	if (i == 0)
		ft_memcpy(hexa, "0123456789ABCDEF\0", 17);
	i = 0;
	while (nbr_cpy != 0 && i++ != -1)
		nbr_cpy = nbr_cpy / 16;
	if (nbr == 0)
		i = 1;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (0);
	s[i--] = '\0';
	if (nbr_cpy == 0)
		s[0] = '0';
	nbr_cpy = nbr;
	while (nbr_cpy != 0)
	{
		s[i--] = hexa[(nbr_cpy % 16)];
		nbr_cpy = nbr_cpy / 16;
	}
	return (s);
}

char	*get_unsigned_int(unsigned int nb)
{
	unsigned int	n;
	int				i;
	char			*number;

	i = 0;
	n = nb;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (!(number = malloc(sizeof(char) * i + 2)))
		return (0);
	number[i + 1] = '\0';
	if (nb == 0)
		number[0] = '0';
	while (nb > 0)
	{
		number[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (number);
}

char	*ft_strndup_free(char *s, int size)
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
	free(s);
	return (new);
}