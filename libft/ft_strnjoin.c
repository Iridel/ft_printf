/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:58:55 by dhill             #+#    #+#             */
/*   Updated: 2017/10/01 01:05:57 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strjoin but for n len of s2;
*/

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*newstr;
	size_t	len;
	size_t	i;
	size_t	i2;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + n;
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		newstr[i] = s2[i2];
		i++;
		i2++;
	}
	return (newstr);
}
