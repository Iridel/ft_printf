/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:17:59 by dhill             #+#    #+#             */
/*   Updated: 2017/07/01 22:52:23 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		dothething(long n, char *str)
{
	long	i;

	i = ft_intlen(n);
	if (!n)
	{
		str[0] = '0';
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
}

char			*ft_itoa(int n)
{
	long	num;
	char	*newstr;
	int		len;

	num = (long)n;
	len = ft_intlen(num);
	newstr = ft_strnew(len);
	if (!newstr || !len)
		return (NULL);
	dothething(num, newstr);
	return (newstr);
}
