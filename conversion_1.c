/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:37:33 by badrien           #+#    #+#             */
/*   Updated: 2020/02/03 16:31:13 by badrien          ###   ########.fr       */
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
	i = 0;
	if (temp == NULL)
		s = ft_strndup("(null)", 6);
	else
	{
		if (!(s = malloc(sizeof(char) * (ft_strlen(temp) + 1))))
			return (0);
		while (temp[i] != '\0')
		{
			s[i] = temp[i];
			i++;
		}
		s[i] = '\0';
	}
	if (flag.precison < (int)ft_strlen(s) && flag.precison != -1)
		s = ft_strndup(s, flag.precison);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	if (flag.before > (int)ft_strlen(s) && flag.before != -1)
		s = add_space_before(s, flag.before, ' ');
	return (s);
}

char	*convert_p(va_list ap, t_flag flag)
{
	unsigned long long	adress;
	char				*s;
	char				*new;

	adress = (unsigned long long)va_arg(ap, void*);
	s = get_adress(adress);
	if (flag.precison > (int)ft_strlen(s) && flag.precison != -1)
		s = add_zero_front(s, flag.precison);
	if (flag.precison == 0 && s[0] == '0')
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (0);
		new[0] = '\0';
		s = new;
	}
	s = ft_strjoin("0x", s);
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	if (flag.before > (int)ft_strlen(s) && flag.before != -1)
		s = add_space_before(s, flag.before, ' ');
	return (s);
}

char	*convert_di(va_list ap, t_flag flag)
{
	int		i;
	char	*s;
	char	*new;

	i = va_arg(ap, int);
	s = get_int(i);
	if (flag.precison != -1 && flag.precison > (int)ft_strlen(s) - 1)
		s = add_zero_front(s, flag.precison);
	if (flag.precison == 0 && s[0] == '0')
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (0);
		new[0] = '\0';
		s = new;
	}
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison != -1)
		s = add_space_before(s, flag.zero, ' ');
	if (flag.before != -1 && flag.before > (int)ft_strlen(s))
		s = add_space_before(s, flag.before, ' ');
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	return (s);
}

char	*convert_u(va_list ap, t_flag flag)
{
	unsigned int	i;
	char			*s;
	char			*new;

	i = va_arg(ap, unsigned int);
	s = get_unsigned_int(i);
	if (flag.precison != -1 && flag.precison > (int)ft_strlen(s))
		s = add_zero_front(s, flag.precison);
	if (flag.precison == 0 && s[0] == '0')
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (0);
		new[0] = '\0';
		s = new;
	}
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison == -1)
		s = add_zero_front_zero(s, flag.zero);
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(s) && flag.precison != -1)
		s = add_space_before(s, flag.zero, ' ');
	if (flag.before != -1 && flag.before > (int)ft_strlen(s))
		s = add_space_before(s, flag.before, ' ');
	if (flag.after > (int)ft_strlen(s) && flag.after != -1)
		s = add_space_back(s, flag.after, ' ');
	return (s);
}
