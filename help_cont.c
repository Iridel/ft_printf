/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 02:30:12 by dhill             #+#    #+#             */
/*   Updated: 2017/12/04 15:52:40 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(char c)
{
	return (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'i'
			|| c == 'd' || c == 'D' || c == 'o' || c == 'O' || c == 'u' ||
			c == 'U' || c == 'x' || c == 'X');
}

int		check_flag(char c)
{
	return (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0');
}