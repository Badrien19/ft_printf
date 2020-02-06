/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:31:03 by badrien           #+#    #+#             */
/*   Updated: 2020/02/06 15:59:23 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*convert_xx(va_list ap, int o, t_flag flag)
{
	char			*s;
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	s = get_hexa(i, o);
	i = 1;
	if (flag.precison != -1 && flag.precison > (int)ft_strlen(s) - (int)i)
		s = add_zero_front(s, flag.precison);
	if (flag.precison == 0 && s[0] == '0')
		{
			free(s);
			s = ft_strndup("\0", 1);
		}
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

char	*convert_pourcent(t_flag flag)
{
	char	*c;

	if (!(c = malloc(sizeof(2) * 2)))
		{
			flag.error = 1;
			return (0);
		}
	c[0] = '%';
	c[1] = '\0';
	if (flag.after > (int)ft_strlen(c) && flag.after != -1)
		c = add_space_back(c, flag.after, ' ');
	if (flag.before > (int)ft_strlen(c) && flag.before != -1)
		c = add_space_before(c, flag.before, ' ');
	if (flag.zero != -1 && flag.zero > (int)ft_strlen(c) && flag.precison == -1)
		c = add_zero_front_zero(c, flag.zero);
	return (c);
}
