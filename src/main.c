/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:33:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/06/02 16:27:28 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    //printf("%13.4da", 42);
    printf("%.2sa\n", "hello");
    ft_printf("@moulitest: %s", NULL);
    //ft_printf("%.9d", 42);
    //ft_printf("%-5d", 42);
    //ft_putstr("\n");
    return(0);
}