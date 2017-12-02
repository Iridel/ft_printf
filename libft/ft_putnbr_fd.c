/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:36:24 by dhill             #+#    #+#             */
/*   Updated: 2017/07/01 21:29:16 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		numcheck(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		numcheck(n / 10, fd);
		numcheck(n % 10, fd);
	}
	else
	{
		if (n > 0)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(-n + '0', fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	numcheck(n, fd);
}
