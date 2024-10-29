/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:04:42 by antimit           #+#    #+#             */
/*   Updated: 2024/10/29 15:08:37 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <stdarg.h>
#include <unistd.h>


int	print_num(int n)
{
	long	nlong;
	int		count;
	char	c;

	count = 0;
	nlong = n;
	if (nlong < 0)
	{
		nlong = -nlong;
		count += write(1, "-", 1);
	}
	if (nlong >= 10)
	{
		count += print_num(nlong / 10);
	}
	c = nlong % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	print_str(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i++])
	{
		count += write(1, &str[i], 1);
	}
	return (count);
}

int	print_hex(unsigned n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n >= 16)
	{
		count += print_hex(n / 16);
	}
	count += write(1, &symbols[n % 16], 1);
	return (count);
}
int	print_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'd')
	{
		count = print_num(va_arg(ap, int));
	}
	else if (c == 's')
	{
		count = print_str(va_arg(ap, char *));
	}
	else if (c == 'x')
	{
		count = print_hex(va_arg(ap, unsigned int));
	}
	else
	{
		count = write(1, &c, 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += print_format(*(++format), ap);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	return (count);
}

// int	main(void)
// {
// 	int count;
// 	count = ft_printf("Hello World\n");
// 	ft_printf("%d\n", count);
// }
