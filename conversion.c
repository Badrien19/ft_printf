/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:37:33 by badrien           #+#    #+#             */
/*   Updated: 2019/12/10 14:53:59 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *convert_c(va_list ap, t_flag flag) // OK
{
	char *c;
	c = malloc(sizeof(2) * 2);
	c[0] = va_arg(ap, int);
	c[1] = '\0';
	if(flag.after > (int)ft_strlen(c) && flag.after != -1) // le -
		c= add_space_back(c, flag.after, ' ');
	if(flag.before > (int)ft_strlen(c) && flag.before != -1) // le nombre
		c= add_space_before(c, flag.before, ' ');
	return (c);
}

char *convert_s(va_list ap, t_flag flag) // OK
{
	char *temp;
	int i;
	char *s;

	temp = va_arg(ap, char*);
	i = 0;
	if(temp == NULL)
		s = ft_strndup("(null)", 6);
	else
	{
		s = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		while (temp[i] != '\0')
		{
			s[i] = temp[i];
			i++;
		}
		s[i] = '\0';
	}
	if(flag.precison < (int)ft_strlen(s) && flag.precison != -1) // le .
		s = ft_strndup(s, flag.precison);
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if(flag.after > (int)ft_strlen(s) && flag.after != -1) // le -
		s= add_space_back(s, flag.after, ' ');
	if(flag.before > (int)ft_strlen(s) && flag.before != -1) // le nombre
		s= add_space_before(s, flag.before, ' ');
	return (s);
}

char *convert_p(va_list ap, t_flag flag) // OK 
{
	void *adress;
	char *s;

	adress = va_arg(ap, void*);

	s = get_adress(adress, 1);

	if(flag.after > (int)ft_strlen(s) && flag.after != -1) // le -
		s= add_space_back(s, flag.after, ' ');
	if(flag.before > (int)ft_strlen(s) && flag.before != -1) // le nombre
		s= add_space_before(s, flag.before, ' ');

	return (s);
}

char *convert_di(va_list ap, t_flag flag) // SEEMS ok 
{ // avec . le - compte pas, avec le 0 le zero compte
	int i;
	char *s;

	i = va_arg(ap, int);
	s = get_int(i);
	
	(i < 0) ? (i = 1) : (i = 0); 
	//printf("precision = %d && nbr de chiffre = %d\n", flag.precison, (int)ft_strlen(s) - i);
	// on applique d'abord la precision (on s'en fou du moins) -> retirer 1 si nombre negatif
	if(flag.precison != -1 && flag.precison > (int)ft_strlen(s) - i)
		s = add_zero_front(s, flag.precison);
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison != -1)
		s = add_space_before(s, flag.zero, ' ');
	if(flag.before != -1 && flag.before > (int)ft_strlen(s))
		s= add_space_before(s, flag.before, ' ');
	if(flag.after > (int)ft_strlen(s) && flag.after != -1)
		s= add_space_back(s, flag.after, ' ');
	// si champ minimal < precision on ignore le champ minimal

	return (s);
}

char *convert_u(va_list ap, t_flag flag)
{
	unsigned int i;
	char *s;

	i = va_arg(ap, unsigned int);
	s = get_unsigned_int(i);

	i = 1;
	if(flag.precison != -1 && flag.precison > (int)ft_strlen(s) -(int) i)
		s = add_zero_front(s, flag.precison);
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison != -1)
		s = add_space_before(s, flag.zero, ' ');
	if(flag.before != -1 && flag.before > (int)ft_strlen(s))
		s= add_space_before(s, flag.before, ' ');
	if(flag.after > (int)ft_strlen(s) && flag.after != -1)
		s= add_space_back(s, flag.after, ' ');

	return (s);
}

char *convert_xx(va_list ap, int o, t_flag flag)
{
	char *s;
	int i;

	i = va_arg(ap, int);
	s = get_hexa(i, o);

	i = 1;
	if(flag.precison != -1 && flag.precison > (int)ft_strlen(s) - i)
		s = add_zero_front(s, flag.precison);
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison != -1)
		s = add_space_before(s, flag.zero, ' ');
	if(flag.before != -1 && flag.before > (int)ft_strlen(s))
		s= add_space_before(s, flag.before, ' ');
	if(flag.after > (int)ft_strlen(s) && flag.after != -1)
		s= add_space_back(s, flag.after, ' ');

	return (s);
}

char *convert_pourcent(t_flag flag)
{
	char *c;
	c = malloc(sizeof(2) * 2);
	c[0] = '%';
	c[1] = '\0';
	if(flag.after > (int)ft_strlen(c) && flag.after != -1) // le -
		c= add_space_back(c, flag.after, ' ');
	if(flag.before > (int)ft_strlen(c) && flag.before != -1) // le nombre
		c= add_space_before(c, flag.before, ' ');
	if(flag.zero != -1 && flag.zero > (int)ft_strlen(c) && flag.precison == -1)
		c = add_zero_front_zero(c, flag.zero);
	return (c);
}