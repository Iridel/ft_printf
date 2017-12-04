/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 02:30:12 by dhill             #+#    #+#             */
/*   Updated: 2017/12/03 03:09:36 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_s_indirect(t_info *var, ...)
{
	va_list	ap;

	va_start(ap, var);
	return (handle_s(var, ap));
}

int		handle_lc(t_info *var, va_list ap)
{
	char		u8[5];
	wchar_t		wc;

	u8[4] = '\0';
	wc = va_arg(ap, wchar_t);
	convert_wchar(u8, wc);
	return (handle_s_indirect(var, u8));
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
