/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:41:54 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 18:41:54 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_nbr(int nb)
{
	int	lenght;

	lenght = 0;
	if (nb == -2147483648)
		return (print_str("-2147483648"));
	if (nb < 0)
	{
		lenght += print_char('-');
		nb = -nb;
	}
	if (nb > 9)
		lenght += print_nbr(nb / 10);
	lenght += print_char(nb % 10 + '0');
	return (lenght);
}

int	print_str(const char *str)
{
	int	lenght;

	lenght = 0;
	if (!str)
	{
		lenght += write(1, "(null)", 6);
		return (lenght);
	}
	while (*str)
	{
		lenght += print_char(*str);
		str++;
	}
	return (lenght);
}

static int	print_format(va_list ap, char format)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		lenght += print_char(va_arg(ap, int));
	else if (format == 's')
		lenght += print_str(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		lenght += print_nbr(va_arg(ap, int));
	return (lenght);
}

int	ft_printf(const char *format, ...)
{
	int		text_lenght;
	va_list	ap;

	text_lenght = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			text_lenght += print_format(ap, *format);
		}
		else
			text_lenght += print_char(*format);
		format++;
	}
	return (text_lenght);
}
