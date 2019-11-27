/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:37:39 by badrien           #+#    #+#             */
/*   Updated: 2019/11/27 15:21:17 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*fill_number(int i, unsigned int nb, int signe)
{
	char *number;

	if (!(number = malloc(sizeof(char) * i + 2)))
		return (0);
	number[i + 1] = '\0';
	if (nb == 0)
		number[i] = '0';
	while (nb > 0)
	{
		number[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	if (signe == -1)
		number[0] = '-';
	return (number);
}

char	*get_int(int n)
{
	int				signe;
	int				i;
	unsigned int	nb;

	i = 0;
	signe = 1;
	if (n < 0)
		signe = -1;
	nb = (n < 0) ? (n * -1) : (n);
	n = nb;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (signe == -1)
		i++;
	if (nb >= 2147483648 && signe == -1)
		i = 10;
	return (fill_number(i, nb, signe));
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int i;

	i = 0;
	if (b == NULL)
		return (NULL);
	while (i < len)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	if (dest == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

char *get_adress(char *pt, int i)
{
	long long int nbr;
	char *s;
	char hexa[17];
	
	s = malloc(sizeof(char) * 15);
	if(i == 0)
		ft_memcpy(hexa, "0123456789ABCDEF\0", 17);
	else
		ft_memcpy(hexa, "0123456789abcdef\0", 17);
	ft_memcpy(s, "0x000000000000\0", 15);
	i = 13;
	nbr = (long long int)pt;
	while(i > 2)
	{
		s[i] = hexa[(nbr % 16)];
		nbr = nbr / 16;
		i--;
	}
	return(s);
}

char *get_hexa(int nbr, int i)
{
	unsigned int nbr_cpy;
	char *s;
	char hexa[17];

	nbr_cpy = nbr;
	ft_memcpy(hexa, "0123456789abcdef\0", 17);
	if(i == 0)
		ft_memcpy(hexa, "0123456789ABCDEF\0", 17);
	i = 0;
	while(nbr_cpy != 0)
	{
		nbr_cpy = nbr_cpy / 16;
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	s[i--] = '\0';
	nbr_cpy = nbr;
	while(nbr_cpy != 0)
	{
		s[i] = hexa[(nbr_cpy % 16)];
		nbr_cpy = nbr_cpy / 16;
		i--;
	}
	return(s);
}

char *get_unsigned_int(unsigned int nb) // TO DO
{
	unsigned int n;
	int i;
	char *number;

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
		number[i] = '0';
	while (nb > 0)
	{
		number[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (number);
}