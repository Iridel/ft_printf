/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:59 by dhill             #+#    #+#             */
/*   Updated: 2017/12/02 01:00:33 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ll_len(long long n)
{
	long long	i;
	int			len;

	i = n;
	len = 0;
	if (!ft_ispositive(n))
		len++;
	while (i >= 10 || i <= -10)
	{
		i = i / 10;
		len++;
	}
	if (n == 0 || i > -9 || i < 9)
		len++;
	return (len);
}

int		prefix_len(t_info *var, long long num)
{
	if (num < 0 || var->fl.sp_f == 1 || var->fl.plus_f == 1)
		return (1);
	return (0);
}

char	*itoa_helper(t_info *var, long long n, char *new, int num_len)
{
	while (n)
	{
		new[num_len] = '0' + n % 10;
		n /= 10;
		num_len--;
	}
	while (num_len >= 0)
	{
		new[num_len] = '0';
		num_len--;
	}
	if (n < 0)
		new[0] = '-';
	else if (var->fl.plus_f == 1)
		new[0] = '+';
	else if (var->fl.sp_f == 1)
		new[0] = ' ';
	return (new);
}
