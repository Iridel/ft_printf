/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 02:30:12 by dhill             #+#    #+#             */
/*   Updated: 2017/12/03 02:33:05 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     handle_s_indirect(t_info *var, ...)
{
    va_list     ap;

    va_start(ap, var);
    return (handle_s(var, ap));
}

int     handle_C(t_info *var, va_list ap)
{
    char    u8[5];
    wchar_t wc;

    u8[4] = '\0';
    wc = va_arg(ap, wchar_t);
    convert_wchar(u8, wc);
    return (handle_s_indirect(var, u8));
}
