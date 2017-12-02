/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:24:06 by dhill             #+#    #+#             */
/*   Updated: 2017/09/25 18:14:49 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** it is supposed to reallocate the memory of src to the newsize and return
** a newstr
*/

void	*ft_realloc(void *src, size_t srcsize, size_t newsize)
{
	void *new;

	if (!src)
		return (NULL);
	new = ft_memalloc(newsize);
	if (newsize < srcsize)
		ft_memcpy(new, src, newsize);
	else
		ft_memcpy(new, src, srcsize);
	free(src);
	return (new);
}
