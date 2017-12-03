/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 01:43:05 by dhill             #+#    #+#             */
/*   Updated: 2017/12/03 03:48:47 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wchar_size(wchar_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x10FFFF)
		return (4);
	return (0);
}

int		convert_wchar(char *u8, wchar_t wc)
{
	if (wc <= 0x7F)
		u8[0] = wc;
	else if (wc <= 0x7FF)
	{
		u8[0] = 0xC0 | (wc >> 6);
		u8[1] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0xFFFF)
	{
		u8[0] = 0xE0 | (wc >> 12);
		u8[1] = 0x80 | ((wc >> 6) & 0x3F) + 0x80;
		u8[2] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0x10FFFF)
	{
		u8[0] = 0xF0 | (wc >> 18);
		u8[1] = 0x80 | ((wc >> 12) & 0x3F);
		u8[2] = 0x80 | ((wc >> 6) & 0x3F);
		u8[3] = 0x80 | (wc & 0x3F);
	}
	return (wchar_size(wc));
}

int		wstr_len(wchar_t *wstr)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (wstr[i] != '\0')
	{
		len += wchar_size(wstr[i]);
		i++;
	}
	return (len);
}

char	*convert_wstr(wchar_t *wstr)
{
	char	*u8;
	int		len;
	int		i;

	len = wstr_len(wstr);
	i = 0;
	u8 = ft_strnew(len);
	while (*wstr != '\0')
		i += convert_wchar(u8 + i, *wstr++);
	return (u8);
}
