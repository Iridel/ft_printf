/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:25:59 by dhill             #+#    #+#             */
/*   Updated: 2017/07/06 21:10:21 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t i;

	if (*find != '\0')
	{
		i = ft_strlen(find);
		while (ft_strncmp(str, find, i) != 0)
		{
			if (*str == '\0')
				return (NULL);
			str++;
		}
	}
	return ((char *)str);
}
