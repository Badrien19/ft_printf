/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:37:33 by badrien           #+#    #+#             */
/*   Updated: 2019/11/27 16:16:12 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *convert_c(va_list ap) // si il donne un \0 je dois afficher le "\0" etc i guess
{
	char *c;
	c = malloc(sizeof(2) * 2);
	c[0] = va_arg(ap, int);
	c[1] = '\0';

	return (c);
}

char *convert_s(va_list ap) // .(nb) le nb de caractre || - nb espace apres || nb nombre d'espace apres
{
	char *temp;
	int i;
	char *s; // faut faire un malloc sinon la variable n'existe plus en sortie

	temp = va_arg(ap, char*);
	i = 0;
	s = malloc(sizeof(char) * (ft_strlen(temp) + 1));
	while (temp[i] != '\0')
	{
		s[i] = temp[i];
		i++;
	}
	s[i] = '\0';
	if(i == 0)
		ft_memcpy(s, "(null)", 6);
	return (s);
}

char *convert_p(va_list ap)
{
	void *adress;
	char *s;

	adress = va_arg(ap, void*);

	s = get_adress(adress, 1);

	return (s);
}

char *convert_di(va_list ap)
{
	int i;
	char *s;

	i = va_arg(ap, int);
	s = get_int(i);

	return (s);
}

char *convert_u(va_list ap) // to do get_unsigned_int
{
	unsigned int i;
	char *s;

	i = va_arg(ap, unsigned int);
	s = get_unsigned_int(i);

	return (s);
}

char *convert_xx(va_list ap, int o)
{
	char *s;
	int i;

	i = va_arg(ap, int);
	s = get_hexa(i, o);

	return (s);
}

char *convert_pourcent()
{
	char *c;
	c = malloc(sizeof(2) * 2);
	c[0] = '%';
	c[1] = '\0';

	return (c);
}