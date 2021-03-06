/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:23:26 by badrien           #+#    #+#             */
/*   Updated: 2020/02/06 15:24:03 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char	type;
	int		precison;
	int		before;
	int		after;
	int		zero;
	int		error;
}				t_flag;

/*
** ft_printf
*/

int				ft_printf(const char *template, ...);
int				get_conversion(va_list ap, t_flag flag);
int				putstr_len(char *s);

/*
**conversion
*/

int				convert_c(va_list ap, t_flag flag);
char			*convert_s(va_list ap, t_flag flag);
char			*convert_p(va_list ap, t_flag flag);
char			*convert_di(va_list ap, t_flag flag);
char			*convert_u(va_list ap, t_flag flag);
char			*convert_xx(va_list ap, int o, t_flag flag);
char			*convert_pourcent(t_flag flag);

/*
** conversion utils
*/

char			*fill_number(int i, unsigned int nb, int signe);
char			*get_int(int n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*get_adress(unsigned long long pt);
char			*get_hexa(unsigned int nbr, int i);
char			*get_unsigned_int(unsigned int nb);
char			*ft_strndup(char *s, int size);
char			*add_space_back(char *s, int size, char c);
char			*add_space_before(char *s, int size, char c);
char			*add_zero_front(char *s, int size);
char			*add_zero_front_zero(char *s, int size);
char			*ft_strndup_free(char *s, int size);

/*
** printf_utils
*/

size_t			ft_strlen(const char *chaine);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoin_size(char *s1, int size1, char *s2, int size2);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
int				ft_atoi(const char *str);

/*
** flags.c
*/

t_flag			reset_flag(t_flag flag);
t_flag			make_flag(const char *str, va_list ap, t_flag flag, int i);
int				is_conversion(char c);

#endif
