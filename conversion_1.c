/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:37:33 by badrien           #+#    #+#             */
/*   Updated: 2020/02/05 16:13:50 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_c(va_list ap, t_flag flag)
{
	char	c;
	int		i;

	i = 1;
	c = va_arg(ap, int);
	if (flag.before != -1)
	{
		i = 1 + flag.before;
		while (--flag.before > 0)
			write(1, " ", 1);
	}
	write(1, &c, 1);
	if (flag.after != -1)
	{
		i = 1 + flag.after;
		while (--flag.after > 0)
			write(1, " ", 1);
	}
	return (i);
}

char	*convert_s(va_list ap, t_flag flag)
{
	char	*temp;
	int		i;
	char	*s;

	temp = va_arg(ap, char*);
	i = -1;
	if (temp == NULL)
		s = ft_strndup("(null)", 6);
	else
		s = ft_strndup(temp, ft_strlen(temp));
	if (flag.precison < (int)ft_strlen(s) && flag.precison != -1)
		s = ft_strndup(s, flag.precison);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	if (flag.before > (int)ft_strlen(s) && flag.before != -1)
		s = add_space_before(s, flag.before, ' ');
	if (s == NULL)
		flag.error = 1;
	return (s);
}

char	*convert_p(va_list ap, t_flag flag)
{
	unsigned long long	adress;
	char				*s;

	adress = (unsigned long long)va_arg(ap, void*);
	s = get_adress(adress);
	if (flag.precison > (int)ft_strlen(s) && flag.precison != -1)
		s = add_zero_front(s, flag.precison);
	if (flag.precison == 0 && s[0] == '0')
		s = ft_strndup("\0", 1);
	s = ft_strjoin("0x", s);
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	if (flag.before > (int)ft_strlen(s) && flag.before != -1)
		s = add_space_before(s, flag.before, ' ');
	if (s == NULL)
		flag.error = 1;
	return (s);
}

char	*convert_di(va_list ap, t_flag flag)
{
	int		i;
	char	*s;

	i = va_arg(ap, int);
	s = get_int(i);
	if (flag.precison != -1 && flag.precison > (int)ft_strlen(s) - 1)
		s = add_zero_front(s, flag.precison);
	if (flag.precison == 0 && s[0] == '0')
		s = ft_strndup("\0", 1);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison != -1)
		s = add_space_before(s, flag.zero, ' ');
	if (flag.before != -1 && flag.before > (int)ft_strlen(s))
		s = add_space_before(s, flag.before, ' ');
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	if (s == NULL)
		flag.error = 1;
	return (s);
}

char	*convert_u(va_list ap, t_flag flag)
{
	unsigned int	i;
	char			*s;

	i = va_arg(ap, unsigned int);
	s = get_unsigned_int(i);
	if (flag.precison != -1 && flag.precison > (int)ft_strlen(s))
		s = add_zero_front(s, flag.precison);
	if (flag.precison == 0 && s[0] == '0')
		s = ft_strndup("\0", 1);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison != -1)
		s = add_space_before(s, flag.zero, ' ');
	if (flag.before != -1 && flag.before > (int)ft_strlen(s))
		s = add_space_before(s, flag.before, ' ');
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	if (s == NULL)
		flag.error = 1;
	return (s);
}
