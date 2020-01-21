/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:23:29 by badrien           #+#    #+#             */
/*   Updated: 2020/01/06 09:51:54 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flag reset_flag(t_flag flag)
{
	flag.type = '\0';
	flag.precison = -1;
	flag.before = -1;
	flag.after = -1;
	flag.error = -1;
	flag.zero = -1;
	return (flag);
}

t_flag make_flag(const char *str, va_list ap, t_flag flag) //%d %.1d %1d %-d
{
	int i;
	int tmp;

	i = 1;
	while (is_conversion(str[i]) == 0) // si va_arg est negatif mettre en positif
	{	
		if(str[i] == '0') //%01d
		{
			flag.zero = atoi(&str[i]); // FT
			while(str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else if(str[i] >= '1' && str[i] <= '9') //%1d
		{
			flag.before = atoi(&str[i]); // FT
			while(str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else if(str[i] == '*' && flag.precison != 0)
		{
			tmp = va_arg(ap, int);
			(tmp >= 0) ? (flag.before = tmp) : (flag.after = tmp * -1);
			i++;
		}
		else if(str[i] == '.') // %.1d
		{
			i++;
			if(str[i] == '*')
				{
					tmp = va_arg(ap, int);
					(tmp >= 0) ? (flag.precison = tmp) : (flag.precison = -1);
				}
			else
				flag.precison = atoi(&str[i]); //FT
			while((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
				i++;
		}
		else if(str[i] == '-') // %-1d
		{
			i++;
			if(str[i] == '*')
				{	
					tmp = va_arg(ap, int);
					(tmp >= 0) ? (flag.after = tmp) : (flag.after = -1);
				}
			else
				flag.after = atoi(&str[i]); //FT
			while((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
				i++;
		}
		else if(str[i] == '\0')
			flag.error = 1;
		else
			i++;
	}
	flag.type = str[i];
	return(flag);
}

int is_conversion(char c)
{
	char conversion[10];
	int i;

	i = 0;
	ft_memcpy(conversion, "cspdiuxX%\0", 9);
	while(conversion[i])
	{
		if(c == conversion[i])
			return (1);
		i++;
	}
	return (0);
}