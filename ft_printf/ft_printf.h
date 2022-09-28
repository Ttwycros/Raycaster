/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:45:31 by ttwycros          #+#    #+#             */
/*   Updated: 2021/12/03 20:56:37 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char	*s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base_non_secure(long long nbr, char *base, int base_size);
int		ft_pointer(unsigned long long nbr, char *base, int base_size);
int		ft_output(const char *s, va_list structura);

#endif