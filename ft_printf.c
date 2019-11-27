/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:23:28 by badrien           #+#    #+#             */
/*   Updated: 2019/11/27 16:40:44 by badrien          ###   ########.fr       */
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
**  flag -0.* + chiffre  attention *.*
**  - ajout espace apres
**  0 ou chiffre avant ou les deux remplis d'espace ou zero si 0
**  . precision
**  * remplace un nombre
**
**
** TO DO: 
** mise en place d'une struc flag
** focntion qui imitialise les flags a 0
** fonction qui remplie les flag
** faire un par un ajouter les convertion avec flags
*/

int	ft_printf(const char *template, ...)
{
	char	*chaine;
	va_list ap;
	t_flag flag;
	int i;

	i = 0;
	chaine = NULL;
	va_start(ap, template);

	while(template[i] != '\0')
	{
		if(template[i] != '%')
		{
			chaine = ft_strjoin(chaine, get_text(&template[i]));
			while (template[i] != '%' && template[i] != '\0')
				i++;
		}
		if(template[i] == '%')
		{
			i++;
			
			flag = make_flag(template[i], ap, flag)
			//while(template[i] == '*' && template[i] != '\0') // ici je dois remplir la structure
			//	i++;
			chaine = get_conversion(ap, chaine, template[i]);
			i++;
		}
	}
	write(1, chaine, ft_strlen(chaine));
	return (0);
}

char *get_text(const char *next)
{
    int i;
    char *s;
    i = 0;
    while (next[i] != '%' && next[i] != '\0')
		i++;
    s = malloc(sizeof(char) * i + 1); // TO DO ; PROTECT 
    i = 0;
    while (next[i] != '%' && next[i] != '\0')
    {
        s[i] = next[i];
		i++;
    }
    s[i] = '\0';
	return (s);
}

char *get_conversion(va_list ap, char *chaine, char conversion)
{
	if(conversion == 'c')
		chaine = ft_strjoin(chaine, convert_c(ap));
	if(conversion == 's')
		chaine = ft_strjoin(chaine, convert_s(ap));
	if(conversion == 'p')
		chaine = ft_strjoin(chaine, convert_p(ap));
	if(conversion == 'd' || conversion == 'i')
		chaine = ft_strjoin(chaine, convert_di(ap));
	if(conversion == 'u')
		chaine = ft_strjoin(chaine, convert_u(ap));
	if(conversion == 'X')
		chaine = ft_strjoin(chaine, convert_xx(ap, 0));
	if(conversion == 'x')
		chaine = ft_strjoin(chaine, convert_xx(ap, 1));
	if(conversion == '%')
		chaine = ft_strjoin(chaine, convert_pourcent());
	return (chaine);
}
