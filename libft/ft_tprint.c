/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:41:44 by dhill             #+#    #+#             */
/*   Updated: 2017/07/05 23:56:11 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tprint(void *toprint, char *type)
{
	if (ft_strequ(type, "int") == 1)
		ft_putnbr((int)toprint);
	if (ft_strequ(type, "char*") == 1)
		ft_putstr((char *)toprint);
	if (ft_strequ(type, "char") == 1)
		ft_putchar((char)toprint);
	ft_putchar('\n');
}
