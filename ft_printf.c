/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 01:32:45 by dhill             #+#    #+#             */
/*   Updated: 2017/12/04 15:53:21 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(t_info *var, char *s)
{
	int count;

	count = 0;
	count += parse_flags(var, s + count);
	count += parse_width(var, s + count);
	count += parse_precision(var, s + count);
	count += parse_length(var, s + count);
	count += parse_type(var, s + count);
	return (count);
}

int		print(t_info *var, char *s)
{
	int i;

	i = 0;
	while ((s[i] != '\0' && s[i] != '%') || (s[i] == '%' && s[i + 1] == '%'))
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i++;
		ft_putchar(s[i]);
		i++;
	}
	var->total_len += i;
	return (i);
}

int		route(t_info *var, va_list ap)
{
	if (var->type == 'c')
		return (handle_c(var, ap));
	if (var->type == 's')
		return (handle_s(var, ap));
	if (var->type == 'd')
		return (handle_d_i(var, ap));
	if (var->type == 'u')
		return (handle_u_x_o_p(var, ap));
	return (0);
}

int		ft_printf(char *statement, ...)
{
	t_info	*var;
	va_list	ap;
	int		total;
	int		offset;

	total = 0;
	var = (t_info *)ft_memalloc(sizeof(t_info));
	va_start(ap, statement);
	while (*statement)
	{
		offset = print(var, statement);
		total += offset;
		statement += offset;
		if (*statement == '\0')
			break ;
		offset = parse(var, statement);
		statement += offset;
		total += route(var, ap);
		ft_bzero(var, sizeof(t_info));
	}
	va_end(ap);
	free(var);
	return (total);
}
