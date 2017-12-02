/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:25:28 by dhill             #+#    #+#             */
/*   Updated: 2017/09/28 22:46:33 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies bytes from src to dest until n bytes are copied or c is found in src.
** if c is found, it will copy & return a pointer to the byte after (in dest).
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*srccpy;
	unsigned char	*destcpy;
	size_t			i;

	srccpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		if (destcpy[i] == (unsigned char)c)
			return (&destcpy[i + 1]);
		i++;
	}
	return (NULL);
}
