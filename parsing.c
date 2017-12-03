/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:15:01 by dhill             #+#    #+#             */
/*   Updated: 2017/12/03 03:22:46 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_info *var, char *s)
{
	int			i;
	int			ck;

	i = 1;
	ck = s[i];
	while (s[i] != '\0' && check_flag(s[i]) == 1)
	{
		s[i] == '-' ? var->fl.neg_f = 1 && i++ : 0;
		s[i] == '+' ? var->fl.plus_f = 1 && i++ : 0;
		s[i] == ' ' ? var->fl.sp_f = 1 && i++ : 0;
		s[i] == '0' ? var->fl.zero_f = 1 && i++ : 0;
		s[i] == '#' ? var->fl.pound_f = 1 && i++ : 0;
		ck = s[i];
	}
	return (i);
}

int		parse_width(t_info *var, char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0' && ft_isdigit(s[i]) == 1)
	{
		var->fl.width_f = 1;
		var->width = var->width * 10 + s[i] - '0';
		i++;
	}
	return (i);
}

int		parse_precision(t_info *var, char *s)
{
	int			i;

	i = 0;
	if (s[i] != '.')
		return (0);
	var->fl.pre_f = 1;
	while (s[i] != '\0' && ft_isdigit(s[i]) == 0)
		i++;
	while (s[i] != '\0' && ft_isdigit(s[i]) == 1)
	{
		var->pre = var->pre * 10 + s[i] - '0';
		i++;
	}
	return (i);
}

int		parse_length(t_info *var, char *s)
{
	if ((s[0] == 'h' && s[1] == 'h') || (s[0] == 'l' && s[1] == 'l'))
	{
		s[0] == 'l' && s[1] == 'l' ? var->length = ll : 0;
		s[0] == 'h' && s[1] == 'h' ? var->length = hh : 0;
		return (2);
	}
	s[0] == 'h' ? var->length = h : 0;
	s[0] == 'l' ? var->length = l : 0;
	s[0] == 'j' ? var->length = j : 0;
	s[0] == 't' ? var->length = t : 0;
	s[0] == 'z' ? var->length = z : 0;
	if (s[0] == 'h' || s[0] == 'l' || s[0] == 'j' || s[0] == 't' || s[0] == 'z')
		return (1);
	return (0);
}

int		parse_type(t_info *var, char *s)
{
	if (check_type(s[0]))
	{
		s[0] == 'c' || s[0] == 'C' ? var->type = 'c' : 0;
		s[0] == 's' || s[0] == 'S' ? var->type = 's' : 0;
		s[0] == 'd' || s[0] == 'D' || s[0] == 'i' ? var->type = 'd' : 0;
		s[0] == 'u' || s[0] == 'U' || s[0] == 'o' || s[0] == 'O' ||
			s[0] == 'x' || s[0] == 'X' || s[0] == 'p' ? var->type = 'u' : 0;
		var->fl.upper_f = ft_isupper(s[0]);
		var->base = 10;
		s[0] == 'x' || s[0] == 'X' || s[0] == 'p' ? var->base = 16 : 0;
		s[0] == 'o' || s[0] == 'O' ? var->base = 8 : 0;
		s[0] == 'p' ? var->fl.p_prefix_f = 1 : 0;
		s[0] == 'D' || s[0] == 'S' || s[0] == 'C' ? var->length = l : 0;
	}
	else
		return (0);
	return (1);
}
