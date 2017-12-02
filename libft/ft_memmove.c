/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 22:22:34 by dhill             #+#    #+#             */
/*   Updated: 2017/07/05 15:54:43 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*srccpy;
	unsigned char		*destcpy;

	srccpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	if (dest > src && len > 0)
	{
		len--;
		while (len > 0)
		{
			destcpy[len] = srccpy[len];
			len--;
		}
		destcpy[len] = srccpy[len];
		return (dest);
	}
	else
	{
		ft_memcpy(dest, src, len);
		return (dest);
	}
	return (dest);
}
