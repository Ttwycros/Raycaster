/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:51:30 by ttwycros          #+#    #+#             */
/*   Updated: 2021/12/04 00:48:56 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_abs(int val)
{
	if (val >= 0)
		return (val);
	else
		return (-val);
}

int	ft_putnbr_base_non_secure(long long nbr, char *base, int base_size)
{
	int	nbr_final[100];
	int	i;
	int	lenght;

	lenght = 0;
	i = 0;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		lenght++;
	}
	while (nbr)
	{
		nbr_final[i] = ft_abs(nbr % base_size);
		nbr = nbr / base_size;
		i++;
		lenght++;
	}
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (lenght);
}

int	ft_pointer(unsigned long long nbr, char *base, int base_size)
{
	ft_putstr("0x");
	return (ft_putnbr_base_non_secure(nbr, base, base_size) + 2);
}

int	ft_output(const char *s, va_list structura)
{
	if (*s == 'd' || *s == 'i')
		return (ft_putnbr_base_non_secure(va_arg(structura, int),
				"0123456789", 10));
	if (*s == 'X')
		return (ft_putnbr_base_non_secure(va_arg(structura, unsigned int),
				"0123456789ABCDEF", 16));
	if (*s == 'x')
		return (ft_putnbr_base_non_secure(va_arg(structura, unsigned int),
				"0123456789abcdef", 16));
	if (*s == 'u')
		return (ft_putnbr_base_non_secure(va_arg(structura, unsigned int),
				"0123456789", 10));
	if (*s == 'p')
		return (ft_pointer(va_arg(structura, unsigned long long),
				"0123456789abcdef", 16));
	if (*s == 'c')
		return (ft_putchar(va_arg(structura, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(structura, char *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		lenght;
	va_list	structura;
	int		i;
	int		total_lenght;

	va_start(structura, s);
	lenght = 0;
	total_lenght = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			lenght = ft_output(s + i + 1, structura);
			total_lenght += lenght;
			i++;
			if (lenght != 0)
				i++;
		}
		ft_putchar(s[i]);
		i++;
		total_lenght++;
	}
	va_end(structura);
	return (total_lenght);
}
