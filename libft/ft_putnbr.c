/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 01:50:04 by dhill             #+#    #+#             */
/*   Updated: 2017/07/01 21:28:46 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		numcheck(int n)
{
	if (n >= 10 || n <= -10)
	{
		numcheck(n / 10);
		numcheck(n % 10);
	}
	else
	{
		if (n > 0)
			ft_putchar(n + '0');
		else
			ft_putchar(-n + '0');
	}
}

void			ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	numcheck(n);
}
