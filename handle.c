/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:11:17 by dhill             #+#    #+#             */
/*   Updated: 2017/12/03 02:04:47 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_c(t_info *var, va_list ap)
{
	char	*str;
	int		arg;
	char	*padding;

	arg = va_arg(ap, int);
	str = ft_strnew(1);
	str[0] = (char)arg;
	var->str_len = 1;
	padding = create_padding(var, str);
	if (var->fl.neg_f == 0)
	{
		ft_putstr(padding);
		ft_putstr(str);
		if (str[0] == '\0')
			ft_putchar('\0');
	}
	else
	{
		ft_putstr(str);
		if (str[0] == '\0')
			ft_putchar('\0');
		ft_putstr(padding);
	}
	free(padding);
	free(str);
	return (var->total_len);
}

int		handle_s(t_info *var, va_list ap)
{
	char	*str;
	char	*arg;
	char	*padding;

	if (var->length == l)
		arg = convert_wstr(va_arg(ap, wchar_t *));
	else
		arg = va_arg(ap, char *);
	str = create_str(var, arg);
	padding = create_padding(var, str);
	if (var->fl.neg_f == 0)
	{
		ft_putstr(padding);
		ft_putstr(str);
		if (str[0] == '\0')
			ft_putchar('\0');
	}
	else
	{
		ft_putstr(str);
		if (str[0] == '\0')
			ft_putchar('\0');
		ft_putstr(padding);
	}
	free(padding);
	free(str);
	return (var->total_len);
}

long long	d_i_help(t_info *var, va_list ap)
{
	if (var->length == ll)
		return (va_arg(ap, long long));
	if (var->length == l)
		return ((long long)va_arg(ap, long));
	if (var->length == hh)
		return ((long long)va_arg(ap, int));
	if (var->length == h)
		return ((long long)va_arg(ap, int));
	if (var->length == j)
		return (va_arg(ap, long long));
	if (var->length == t)
		return (va_arg(ap, long long));
	if (var->length == z)
		return ((long long)va_arg(ap, unsigned long long));
	if (var->length == unset)
		return ((long long)va_arg(ap, int));
	return (0);
}

int		handle_d_i(t_info *var, va_list ap)
{
	char		*padding;
	char		*number;
	long long	val;

	val = d_i_help(var, ap);
	number = create_signed(var, val);
	padding = create_num_padding(var);
	sign_help(var, val, padding, number);
	if (var->fl.neg_f == 0)
	{
		ft_putstr(padding);
		ft_putstr(number);
	}
	else
	{
		ft_putstr(number);
		ft_putstr(padding);
	}
	free(number);
	free(padding);
	return (var->total_len);
}

int		handle_u_x_o_p(t_info *var, va_list ap)
{
	char		*padding;
	char		*number;
	long long	val;

	val = va_arg(ap, unsigned long long);
	number = create_unsigned(var, val);
	padding = create_num_padding(var);
	if (var->fl.neg_f == 0)
	{
		ft_putstr(padding);
		ft_putstr(number);
	}
	else
	{
		ft_putstr(number);
		ft_putstr(padding);
	}
	free(number);
	free(padding);
	return (var->total_len);
}
