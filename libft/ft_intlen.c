/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:10:52 by dhill             #+#    #+#             */
/*   Updated: 2017/09/25 18:17:49 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tries to find the length of the number inputed
** and returns it as an int; takes longs
*/

int		ft_intlen(long n)
{
	int i;
	int len;

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
