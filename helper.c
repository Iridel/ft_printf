/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:08:20 by dhill             #+#    #+#             */
/*   Updated: 2017/12/02 22:08:31 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_str(t_info *var, char *str)
{
	char	*new;
	int		len;

	len = var->fl.pre_f ? MIN(ft_strlen(str), var->pre) : ft_strlen(str);
	new = ft_strnew(len);
	new = ft_strncpy(new, str, len);
	var->str_len = len;
	return (new);
}

char	*create_padding(t_info *var, char *str)
{
	char	*new;
	int		len;

	len = 0;
	if (var->fl.width_f)
	{
		if (var->fl.pre_f)
			len = var->width - MIN(ft_strlen(str), var->pre);
		else
			len = var->width - ft_strlen(str);
	}
	len < 0 ? len = 0 : 0;
	new = ft_strnew(len);
	var->fl.zero_f ? ft_memset(new, '0', len) : ft_memset(new, ' ', len);
	var->total_len = len + var->str_len; 
	return (new);
}

char	*create_signed(t_info *var, long long num)
{
	char	*new;

	var->num_len = var->fl.pre_f == 1 && var->pre == 0 && num == 0 ? 0 : ll_len(num);
	var->num_len = MAX(var->num_len, var->pre) + prefix_len(var, num);
	new = ft_strnew(var->num_len);
	new = itoa_helper(var, num, new, var->num_len - 1);
	return (new);
}

char	*create_unsigned(t_info *var, unsigned long long num)
{
	char	*new;

	var->num_len = var->fl.pre_f == 1 && var->pre == 0 && num == 0 ? 0 : ll_u_len(var, num);
	var->num_len = MAX(var->num_len, var->pre) + u_prefix_len(var, num);
	new = ft_strnew(var->num_len);
	new = itoa_u_helper(var, num, new, var->num_len - 1);
	return (new);
}

char	*create_num_padding(t_info *var)
{
	char	*new;
	int		len;

	len = var->width > var->num_len ? var->width - var->num_len : 0 ;
	new = ft_strnew(len);
	if (var->fl.neg_f == 0 && var->fl.pre_f == 1 && var->fl.zero_f == 1)
		ft_memset(new, '0', len);
	else
		ft_memset(new, ' ', len);
	var->total_len = var->num_len + len;
	return (new);
}
