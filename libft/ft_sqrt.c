/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:13:27 by dhill             #+#    #+#             */
/*   Updated: 2017/07/18 20:16:42 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double num)
{
	double	root;
	double	square;
	size_t	i;

	if (num <= 0)
		return (0);
	root = num / 2;
	square = root * root;
	i = 0;
	while ((i < 20 && square < num - 1E-5) || square > num + 1E-5)
	{
		square = root * root;
		root -= ((square - num) / 2) / root;
		i++;
	}
	return (root);
}
