/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:23:26 by badrien           #+#    #+#             */
/*   Updated: 2019/11/27 17:40:10 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
//# include <cstdarg>

typedef struct	s_list
{
	char type;
	int precison;
	int before;
	int after;
	int error;
}				t_flag;
// ft_printf
int	ft_printf(const char *template, ...);
int is_flag(const char *s);
char *get_text(const char *next);
char *get_conversion(va_list ap, char *chaine, char conversion);

// conversion.c
char *convert_c(va_list ap);
char *convert_s(va_list ap);
char *convert_p(va_list ap);
char *convert_di(va_list ap);
char *convert_u(va_list ap);
char *convert_xx(va_list ap, int o);
char *convert_pourcent();

//conversion utils.c
char	*fill_number(int i, unsigned int nb, int signe);
char	*get_int(int n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_adress(char *pt, int i);
char	*get_hexa(int nbr, int i);
char	*get_unsigned_int(unsigned int nb);

// printf_utils
size_t	ft_strlen(const char *chaine);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

// flags.c

t_flag reset_flag(t_flag flag);
t_flag make_flag(char *str, va_list ap, t_flag flag);
int is_conversion(char c);

#endif

// je peux passer ap a un eautre fonction pour faire les va_arg dans d'autre fonction