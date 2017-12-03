/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 02:30:12 by dhill             #+#    #+#             */
/*   Updated: 2017/12/03 03:59:14 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wctype.h>

#include "ft_printf.h"

int		handle_lc(t_info *var, va_list ap)
{
	char		u8[4];
	wchar_t		wc;
	int			len;

	(void)var;
	ft_bzero(u8, 4);
	wc = va_arg(ap, wint_t);
	len = convert_wchar(u8, wc);
	write(1, u8, 1);
	//write(1, u8 + 1, 1);
	//write(1, u8 + 2, 1);
	//write(1, u8 + 3, 1);
	return (len);
}

int		check_type(char c)
{
	return (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'i'
			|| c == 'd' || c == 'D' || c == 'o' || c == 'O' || c == 'u' ||
			c == 'U' || c == 'x' || c == 'X');
}

int		check_flag(char c)
{
	return (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0');
}
