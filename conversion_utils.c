/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:37:39 by badrien           #+#    #+#             */
/*   Updated: 2020/01/29 16:37:47 by badrien          ###   ########.fr       */
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

char *get_adress(unsigned long long pt) // refaire
{
	char *s;

	s = get_hexa(pt, 1);
	
	s = ft_strjoin("0x",s);
	
	return(s);
}

char *get_hexa(unsigned long long nbr, int i)
{
	unsigned long long nbr_cpy;
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
	if(nbr == 0)
		i = 1;
	s = malloc(sizeof(char) * (i + 1));
	s[i--] = '\0';
	if(nbr_cpy == 0)
		s[0] = '0';
	nbr_cpy = nbr;
	while(nbr_cpy != 0)
	{
		s[i] = hexa[(nbr_cpy % 16)];
		nbr_cpy = nbr_cpy / 16;
		i--;
	}
	return(s);
}

char *get_unsigned_int(unsigned int nb)
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
	//if(nb == 0)
	//	i = -1;
	if (!(number = malloc(sizeof(char) * i + 2)))
		return (0);
	number[i + 1] = '\0';
	if(nb == 0)
		number[0] = '0';
	while (nb > 0)
	{
		number[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (number);
}

char *ft_strndup(char *s, int size)
{
	char *new;
	int i;

	i = 0;
	if(size < 0)
		return (NULL);
	new = malloc(sizeof(char) *  size + 1);

	while(i < size)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char *add_space_back(char *s, int size, char c)
{
	char *new;
	int i;

	i = 0;
	if(size < 0)
		return (NULL);
	new = malloc(sizeof(char) *  size + 1);

	while(i < size && s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	while(i < size)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char *add_space_before(char *s, int size, char c)
{
	char *new;
	int i;
	int y;

	i = 0;
	if(size < 0)
		return (NULL);
	new = malloc(sizeof(char) *  size + 1);

	while(s[i] != '\0')
		i++;
	y = size - i;
	i = 0;
	while(y)
	{
		new[i] = c;
		y--;
		i++;
	}
	while(s[y] != '\0')
	{
		new[i] = s[y];
		y++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char *add_zero_front(char *s, int size)
{
	char *new;
	int signe;
	int i;

	i = 0;
	signe = 0;
	if(size < 0)
		return (NULL);
	if(s[i] == '-')
		signe++;
	new = malloc(sizeof(char) *  size + signe);
	while(s[i] != '\0')
		i++;
	new[size + signe] = '\0';
	while(i)
	{
		if(s[i - 1 ] == '-')
			break;
		new[size - 1 + signe] = s[i - 1];
		size--;
		i--;
	}
	while (size + signe > 0)
	{
		new[size - 1 + signe] = '0';
		size--;
	}
	if(s[0] == '-')
		new[0] = '-';
	return(new);
}

char *add_zero_front_zero(char *s, int size)
{
	char *new;
	int i;

	i = 0;
	if(size < 0)
		return (NULL);
	new = malloc(sizeof(char) *  size + 1);
	while(s[i] != '\0')
		i++;
	new[size] = '\0';
	while(i)
	{
		if(s[i - 1 ] == '-')
			break;
		new[size - 1] = s[i - 1];
		size--;
		i--;
	}
	while (size > 0)
	{
		new[size - 1] = '0';
		size--;
	}
	if(s[0] == '-')
		new[0] = '-';
	return(new);
}