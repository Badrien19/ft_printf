/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:23:28 by badrien           #+#    #+#             */
/*   Updated: 2020/01/27 15:11:28 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**  liste of convertion
**  c: int converti en unsigned char
**  s: chaine de caractere si preciser nombre de lettre a afficher // TO CORRECT segfault
**  p: l'argument pointeur du type void * est afficher en hexadecimal
**  d: int converti en un chiffre decimal signé + si preciser le nombre de chiffre minimum
**  i: idem a d
**  u: unsigned int converti en un chiffre decimal non signe // TO CORRECT doit convertir en unsigned faire un get_unsigned_int
**  x: unsigned int converti en un chiffrehexadecimal non signe (abcdef)
**  X: unsigned int converti en un chiffrehexadecimal non signe (ABCDEF)
**  %: un caractere '%' est ecrit
**  
**	Bug random avec u X x avec 0 en argument
** 	Bug random avec multiple %p
** 
** refaire precision pointeur
** si chaine % seul
** \0 en c
*/

int	ft_printf(const char *template, ...)
{
	va_list ap;
	t_flag flag;
	int i;
	int taille;

	taille = 0;
	i = 0;
	va_start(ap, template);

	while(template[i] != '\0')
	{
		if(template[i] != '%')
		{
			taille += get_text(&template[i]);
			while (template[i] != '%' && template[i] != '\0')
				i++;
		}
		if(template[i] == '%')
		{
			flag = reset_flag(flag);
			flag = make_flag(&template[i], ap, flag);
			
			if(flag.type == '\0')
				return (0);
			//printf("flag.after = %d, flag.before = %d, flag.error = %d, flag.precison = %d, flag.type = %d, flag.zero = %d\n);", flag.after, flag.before, flag.error, flag.precison, flag.type, flag.zero);


			taille += get_conversion(ap, flag);
			while (is_conversion(template[++i]) == 0);
			i++;
		}
	}
	return (taille);
}

int get_text(const char *next)
{
    int i;

    i = 0;
    while (next[i] != '%' && next[i] != '\0')
			i++;
		write(1, next, i);
    
	return (i);
}

int get_conversion(va_list ap, t_flag flag)
{
	int i;

	i = 0;
	if(flag.type == 'c')
		i += putstr_len(convert_c(ap, flag));
	if(flag.type == 's')
		i += putstr_len(convert_s(ap, flag));
	if(flag.type == 'p')
		i += putstr_len(convert_p(ap, flag));
	if(flag.type == 'd' || flag.type == 'i')
		i += putstr_len(convert_di(ap, flag));
	if(flag.type == 'u')
		i += putstr_len(convert_u(ap, flag));
	if(flag.type == 'X')
		i += putstr_len(convert_xx(ap, 0, flag));
	if(flag.type == 'x')
		i += putstr_len(convert_xx(ap, 1, flag));
	if(flag.type == '%')
		i += putstr_len(convert_pourcent(flag));
	
	return (i);
}
