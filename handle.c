/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:11:17 by dhill             #+#    #+#             */
/*   Updated: 2017/12/02 17:26:33 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_c(va_list ap)
{
	char	*c;

	c = va_arg(ap, int);
	ft_putstr((char *)c);
	return (1);
}

int		handle_s(t_info *var, va_list ap)
{
	char	*str;
	char	*arg;
	char	*padding;

	arg = va_arg(ap, char *);
	str = create_str(var, arg);
	padding = create_padding(var, str);
	if (var->fl.neg_f == 0)
	{
		ft_putstr(padding);
		ft_putstr(str);
		if (ft_strequ(arg, "") == 0)
			ft_putchar('\0');
	}
	else
	{
		ft_putstr(str);
		if (ft_strequ(arg, "") == 0)
			ft_putchar('\0');
		ft_putstr(padding);
	}
	free(padding);
	free(str);
	return (var->total_len);
}

int		handle_d_i(t_info *var, va_list ap)
{
	char		*padding;
	char		*number;
	long long	val;

	val = va_arg(ap, long long);
	number = create_signed(var, val);
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

//one more left here
