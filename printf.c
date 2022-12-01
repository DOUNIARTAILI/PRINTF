/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:35:16 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/01 23:44:29 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int    ft_putchar(char c)
{
    return (write(1, &c, 1));
}
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
    int ret;

    ret = 0;
	nb = (unsigned int)n;
	if (n < 0)
	{
		ret += ft_putchar('-');
		nb = n * -1;
	}
	if (nb <= 9)
		ret += ft_putchar(nb + 48);
	else
	{
		ret += ft_putnbr(nb / 10);
		ret += ft_putchar(((nb % 10) + 48));
	}
    return (ret);
}

int	ft_putstr(char *s)
{
	if (!s)
		return 0;
	return write(1, s, ft_strlen(s));
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    size_t  i;
    int ret;
    

    va_start(ap, format);
    ret = 0;
    i = 0;
    while (format[i])
    {
        
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                ret += ft_putchar(va_arg(ap, int)); 
            else if (format[i] == 's')
                ret += ft_putstr(va_arg(ap, char *));
            else if (format[i] == 'd' || format[i] == 'i')
                ret += ft_putnbr(va_arg(ap, int));
            else if (format[i] == '%')
                ret += ft_putchar('%');
            else
                ret += ft_putchar(format[i]);
        }
        else
        {
            ret += ft_putchar(format[i]);
        }
            // elseif (format[i + 1] == 'p')
            //     print_p();
            // elseif (format[i + 1] == 'u')
            //     print_u();
            // elseif (format[i + 1] == 'x')
            //     print_x();
            // elseif (format[i + 1] == 'X')
            //     print_X();
        i++;
    }
    va_end(ap);
    return (ret);
}
int main ()
{
    int x = ft_printf("my name is %s i'm %d%c %a\n", "dounia", -2147483648, '!', 1337);
    printf("%d\n", x);
}
