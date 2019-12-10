/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:23:29 by badrien           #+#    #+#             */
/*   Updated: 2019/12/09 19:05:01 by badrien          ###   ########.fr       */
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

	i = 1;
	while (is_conversion(str[i]) == 0)
	{
		//printf("Boucle: %c\n", str[i]);
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
		else if(str[i] == '.') // %.1d
		{
			if(str[i + 1] == '*')
				flag.precison = va_arg(ap, int);
			else
				flag.precison = atoi(&str[i + 1]); //FT
			i++;
			while(str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else if(str[i] == '-') // %-1d
		{
			if(str[i + 1] == '*')
				flag.after = va_arg(ap, int);
			else
				flag.after = atoi(&str[i + 1]); //FT
			i++;
			while(str[i] >= '0' && str[i] <= '9')
				i++;
		}
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