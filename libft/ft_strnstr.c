/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:15:50 by dhill             #+#    #+#             */
/*   Updated: 2017/07/06 20:57:11 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(find);
	if (*find == '\0')
		return ((char *)str);
	while (i < n && str[i] != '\0')
	{
		if (ft_strncmp((char *)&str[i], find, len) == 0)
		{
			if (i + len > n)
				return (NULL);
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
