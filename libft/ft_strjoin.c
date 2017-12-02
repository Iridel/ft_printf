/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:38:12 by dhill             #+#    #+#             */
/*   Updated: 2017/10/04 22:01:07 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len;
	size_t	i;
	size_t	i2;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	i = 0;
	i2 = i;
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
