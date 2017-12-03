/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 11:59:00 by dhill             #+#    #+#             */
/*   Updated: 2017/12/02 17:34:26 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    parse(t_info *var, char *s)
{
	int count;

	count = 0;
	count += parse_flags(var, s + count);
	count += parse_width(var, s + count);
	count += parse_precision(var, s + count);
	count += skip_length(s + count);
	count += parse_type(var, s + count);
	return (count);
}

int     print(t_info *var, char *s)
{
    int i;

    i = 0;
    while ((s[i] != '\0' && s[i] != '%') || (s[i] == '%' && s[i + 1] == '%'))
    {
        if (s[i + 1] == '%')
            i++;
        ft_putchar(s[i]);
        i++;
    }
	var->total_len += i;
    return (i);
}  

void	route(t_info *var, va_list ap)
{
	var->type == 'c' ? handle_c(var, ap) : 0;
	var->type == 's' ? handle_s(var, ap) : 0;
	var->type == 'd' ? handle_d_i(var, ap) : 0;
	var->type == 'u' ? handle_u_x_o_p(var, ap) : 0;
}

int		ft_printf(char *statement, ...)
{
	t_info	*var;
	va_list	ap;
	int		total;
	int		offset;

	var = (t_info *)ft_memalloc(sizeof(t_info));
	va_start(ap, statement);
	while (*statement)
	{
		offset = print(var, statement);
		statement += offset;
		offset = parse(var, statement);
		statement += offset;
		route(var, ap);
		ft_bzero(var, sizeof(t_info));
	}
	va_end(ap);
	total = var->total_len;
	free(var);
	return(total);
}
