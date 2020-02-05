/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:23:28 by badrien           #+#    #+#             */
/*   Updated: 2020/02/05 15:25:38 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		get_text(const char *next, int *cpy_i)
{
	int i;

	i = 0;
	while (next[i] != '%' && next[i] != '\0')
		i++;
	write(1, next, i);
	*cpy_i = *cpy_i + i;
	return (i);
}

/*
** REMONTER TOUS LES MALLOCS avec flag.error
*/

int				ft_printf(const char *template, ...)
{
	va_list		ap;
	t_flag		flag;
	int			i;
	int			taille;

	taille = 0;
	i = 0;
	va_start(ap, template);
	while (template[i] != '\0')
		if (template[i] != '%')
			taille += get_text(&template[i], &i);
		else if (template[i] == '%')
		{
			flag = make_flag(&template[i++], ap, flag, 1);
			taille += get_conversion(ap, flag);
			if (flag.type == '\0' || flag.error != -1)
				return (-1);
			while (is_conversion(template[i]) == 0)
				i++;
			i++;
		}
	return (taille);
}

int				get_conversion(va_list ap, t_flag flag)
{
	int i;

	i = 0;
	if (flag.type == 'c')
		i += convert_c(ap, flag);
	if (flag.type == 's')
		i += putstr_len(convert_s(ap, flag));
	if (flag.type == 'p')
		i += putstr_len(convert_p(ap, flag));
	if (flag.type == 'd' || flag.type == 'i')
		i += putstr_len(convert_di(ap, flag));
	if (flag.type == 'u')
		i += putstr_len(convert_u(ap, flag));
	if (flag.type == 'X')
		i += putstr_len(convert_xx(ap, 0, flag));
	if (flag.type == 'x')
		i += putstr_len(convert_xx(ap, 1, flag));
	if (flag.type == '%')
		i += putstr_len(convert_pourcent(flag));
	return (i);
}
