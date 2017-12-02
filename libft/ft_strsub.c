/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 00:36:55 by dhill             #+#    #+#             */
/*   Updated: 2017/06/26 01:03:50 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	newstr = ft_strnew(len);
	i = 0;
	if (!s || !newstr)
		return (NULL);
	while (i < len)
		*(newstr + i++) = *(s + start++);
	return (newstr);
}
