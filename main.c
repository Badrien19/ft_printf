/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:48:59 by badrien           #+#    #+#             */
/*   Updated: 2020/02/06 16:20:54 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	int i;
	char *oui = "test";
	i = -1;
	t_flag flag;
	va_list ap;
	
	int o;

	ft_printf("%x\n", 15456);
	ft_printf("%d\n", -2372);
	ft_printf("%i\n", 4154);
	ft_printf("%s\n", "oui");
	ft_printf("%p\n", &i);
	ft_printf("%u\n", 2372);
	ft_printf("%X\n", 2372);

	ft_printf("%-5x\n", 15456);
	ft_printf("%-5d\n", -2372);
	ft_printf("%-5i\n", 4154);
	ft_printf("%-5s\n", "oui");
	ft_printf("%-5p\n", &i);
	ft_printf("%-5u\n", 2372);
	ft_printf("%-5X\n", 2372);

	ft_printf("%.10x\n", 15456);
	ft_printf("%.10d\n", -2372);
	ft_printf("%.10i\n", 4154);
	ft_printf("%.10s\n", "oui");
	ft_printf("%.10p\n", &i);
	ft_printf("%.10u\n", 2372);
	ft_printf("%.10X\n", 2372);

	ft_printf("%10x\n", 15456);
	ft_printf("%10d\n", -2372);
	ft_printf("%10i\n", 4154);
	ft_printf("%10s\n", "oui");
	ft_printf("%10p\n", &i);
	ft_printf("%10u\n", 2372);
	ft_printf("%10X\n", 2372);

	ft_printf("%07x\n", 15456);
	ft_printf("%07d\n", -2372);
	ft_printf("%07i\n", 4154);
	ft_printf("%07s\n", "oui");
	ft_printf("%07p\n", &i);
	ft_printf("%07u\n", 2372);
	ft_printf("%07X\n", 2372);

    return (0);
}