/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:33:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/06/01 11:55:01 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    //printf("%13.4da", 42);
    ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
    //ft_printf
    //ft_printf("%.9d", 42);
    //ft_printf("%-5d", 42);
    //ft_putstr("\n");
    return(0);
}