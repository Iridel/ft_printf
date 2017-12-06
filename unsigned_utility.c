/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:50:44 by dhill             #+#    #+#             */
/*   Updated: 2017/12/06 13:41:21 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ll_u_len(t_info *var, unsigned long long n)
{
	unsigned long long	i;
	int					len;

	i = n;
	len = 0;
	while (i >= (unsigned long long)var->base)
	{
		i = i / (unsigned long long)var->base;
		len++;
	}
	if (n == 0 || i < (unsigned long long)var->base)
		len++;
	return (len);
}

int		u_prefix_len(t_info *var, unsigned long long num)
{
	if ((var->fl.pound_f == 0 || num == 0) && var->fl.p_prefix_f == 0)
		return (0);
	if (var->base == 8)
		return (1);
	if (var->base == 16)
		return (2);
	return (0);
}

char	*itoa_u_helper(t_info *var, unsigned long long n, char *new,
						int num_len)
{
	const char			*hex_lower = "0123456789abcdef";
	const char			*hex_upper = "0123456789ABCDEF";
	unsigned long long	o;

	o = n;
	while (n)
	{
		new[num_len] = var->fl.upper_f == 1 ? hex_upper[n % var->base] :
											hex_lower[n % var->base];
		n /= var->base;
		num_len--;
	}
	while (num_len >= 0)
	{
		new[num_len] = '0';
		num_len--;
	}
	if (var->fl.p_prefix_f == 0 && (o == 0 || var->fl.pound_f == 0))
		return (new);
	if ((var->base == 8 || var->base == 16) && var->fl.pound_f == 1)
		new[0] = '0';
	if (var->base == 16 && var->fl.pound_f == 1)
		new[1] = var->fl.upper_f == 1 ? 'X' : 'x';
	return (new);
}
