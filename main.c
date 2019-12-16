/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badrien <badrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:48:59 by badrien           #+#    #+#             */
/*   Updated: 2019/12/16 13:28:57 by badrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	int i;
	char *oui = "%0100d";
	i = -1;
	t_flag flag;
	va_list ap;
	
	//printf("<%s>\n", get_adress(oui));
	ft_printf("<%p>\n", &oui); // - nb flag 0
	printf("<%p>\n",&oui); // nb -nb 0 .
	/*
	flag = reset_flag(flag);
	flag = make_flag(oui, ap, flag);

	printf("Flag:\n");
	printf("flag.type: %c\n", flag.type);
	printf("flag.precision: %d\n", flag.precison);
	printf("flag.before: %d\n", flag.before);
	printf("flag.after: %d\n", flag.after);
	printf("flag.zero %d\n", flag.zero);
	*/
	/*
	ft_printf("s1= <%s>\ns2= <%s> \ns3= <%s>\n", oui, oui2, oui3);
	printf("s1= <%s>\ns2= <%s> \ns3= <%s>\n", oui, oui2, oui3);
	*/
	/*
	ft_printf("ceci est un caractere: <%20c>\n", 'A');
	printf("ceci est un caractere: <%20c>\n", 'A');

	ft_printf("ceci est un pointeur: <%20p>\n", &oui);
	printf("ceci est un pointeur: <%20p>\n", &oui);

	ft_printf("ceci est un int: <%d>\n", i);
	printf("ceci est un int: <%d>\n", i);


	ft_printf("ceci est un nombre en hexa: <%x>\n", i);
	printf("ceci est un nombre en hexa: <%x>\n", i);


	ft_printf("ceci est un nombre en HEXA: <%X>\n", i);
	printf("ceci est un nombre en HEXA: <%X>\n", i);
	
	ft_printf("Ceci est un unsigned int: <%u>\n",i);
	printf("Ceci est un unsigned int: <%u>\n",i);
	*/
	//printf("%s", get_unsigned_int(4294967295));
	//oui = get_adress(oui, 0);
	//oui = get_adress(oui, 1);
	//printf("ma fonction:     %s\n", oui);
	//printf("printf original: %p\n",&i);
	
    return (0);
}