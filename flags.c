/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:23:29 by badrien           #+#    #+#             */
/*   Updated: 2020/02/06 16:33:05 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flag	reset_flag(t_flag flag)
{
	flag.type = '\0';
	flag.precison = -1;
	flag.before = -1;
	flag.after = -1;
	flag.error = -1;
	flag.zero = -1;
	return (flag);
}

int		flag_dot_minus(int *i, const char *str, va_list ap)
{
	int ret;
	int tmp;

	(*i)++;
	if (str[*i] == '*')
	{
		tmp = va_arg(ap, int);
		ret = (tmp >= 0) ? (tmp) : (-1);
	}
	else
		ret = ft_atoi(&str[*i]);
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
		(*i)++;
	return (ret);
}

int		flag_zero_number(int *i, const char *str)
{
	int ret;

	ret = ft_atoi(&str[*i]);
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	return (ret);
}

t_flag	make_flag(const char *str, va_list ap, t_flag flag, int i)
{
	int tmp;

	flag = reset_flag(flag);
	while (is_conversion(str[i]) == 0)
		if (str[i] == '0')
			flag.zero = flag_zero_number(&i, str);
		else if (str[i] >= '1' && str[i] <= '9')
			flag.before = flag_zero_number(&i, str);
		else if (str[i] == '*' && flag.precison != 0)
		{
			tmp = va_arg(ap, int);
			if (tmp >= 0)
				flag.before = tmp;
			else
				flag.after = tmp * -1;
			i++;
		}
		else if (str[i] == '.')
			flag.precison = flag_dot_minus(&i, str, ap);
		else if (str[i] == '-')
			flag.after = flag_dot_minus(&i, str, ap);
		else
			i++;
	flag.type = str[i];
	return (flag);
}

int		is_conversion(char c)
{
	char	conversion[10];
	int		i;

	i = 0;
	if (c == '\0')
		return (1);
	ft_memcpy(conversion, "cspdiuxX%\0", 9);
	while (conversion[i] != '\0')
	{
		if (c == conversion[i])
			return (1);
		i++;
	}
	return (0);
}
