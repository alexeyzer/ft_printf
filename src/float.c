#include "ft_printf.h"

int       ft_pow(int nbr, int n)
{
    int tmp;

    tmp = nbr;
    while (n > 1)
    {
        nbr *= tmp;
        n--;
    }
    if (n == 0)
        return 1;
    return nbr;
}

int leng(int nbr)
{
    int len;
    int n;

    len = 0;
    n = nbr;
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    if (nbr == 0)
        return 1;
    return len;
}

void    width(char c, int w)
{
    int i;

    i = 0;
    while (i < w)
    {
        ft_putchar(c);
        i++;
    }
}

void    ft_putfloat(double nbr, t_print *print)
{
    int         br;
    int         n;
    
    n = (int)nbr;
    nbr = nbr - n;
    nbr = nbr * ft_pow(10, print->precision + 1);
    br = (int)nbr;
    if (br % 10 > 4) 
        br += (br % 10 != 9) ? 11 : 1;
    br /= 10;
    if (br / ft_pow(10, print->precision) != 0)
    {
        br %= ft_pow(10, print->precision);
        n++;
    }
    ft_putnbr(n);
    if (print->helper == 0)
    {
    ft_putchar('.');
    width('0', print->precision - leng(br));
    if (br != 0) ft_putnbr(br);
    }
}

void	work_with_float(t_print *print, va_list list, int *count)//works with different nbrs & prs
{
    double      nbr;
    int         n;
    int         l;

    if (print->precision < 0)
        print->precision = 6;
    if (print->precision == 0)
        print->helper = 1;
    nbr = va_arg(list, double);
    n = (nbr > 0) ? (int)nbr : (int)(-nbr);
    l = (nbr > 0 && print->flag->plus == 1) ? leng(n) + 1 : leng(n);
    if (nbr < 0)
    {
        print->minus = 1;
        l = l + 1;
        nbr = -nbr;
    }
    else
        print->minus = 0;
    *count = *count + print->precision + l + ((print->helper == 1) ? 0 : 1);
    look_at_width(print->precision + l + ((print->helper == 1) ? 0 : 1), print->width, print, &nbr);
}
