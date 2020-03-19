/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:36:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/03/19 13:19:22 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int checkforextra(char a, char **format, t_print *print)
{
	if (a == 't')
	{
		print->type = **format;
		(*format)++;
		return (0);
	}
	if (a == 'f')
	{
		print->flag = **format;
		if (**format == '%')
			return (0);
		(*format)++;
		if(**format == '+' || **format == '-' || **format == ' ' 
    	|| **format == '#' || **format == '0')
			exits("format\n", print); 
		else
			return (1);
	}
	return	(secondcheck(a, format, print));
}

int secondcheck(char a, char **format, t_print *print)
{
	if (a == 'w')
	{
		if (**format == '*')
            print->width = '*';
        else
            print->width = (char)(ft_atoi(*format));
		return (checklast(format, 'w', print));
	}
	if (a == 'p')
	{
		(*format)++;
        if (**format == '*')
        {
            print->precision = '*';
        }
        else
			print->precision = (char)(ft_atoi(*format));
        return (checklast(format, 'p', print));
	}
	return (exits("invalid letter", print));
}

int checklast(char **f, char a, t_print *print)
{
	while ((**f >= '0' && **f <= '9') || **f == '*')
		(*f)++;
	if (a == 'w')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' 
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p' || **f == '.')
			return (1);
	}
	if (a == 'p')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' 
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p')
			return (1);
	}
	return (exits("format\n", print));
}

t_print    *print_init(t_print *new_print)
{

	new_print = (t_print*)malloc(sizeof(t_print));
    new_print->flag = 0;
    new_print->type = 0;
    new_print->width = 0;
    new_print->precision = 0;
    return (new_print);
}

int exits(char *strerr, t_print *end_print)
{
	ft_putstr("something wrong in ");
	ft_putstr(strerr);
	free(end_print);
	exit(0);
	return (0);
}