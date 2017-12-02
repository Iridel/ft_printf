/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 23:49:23 by dhill             #+#    #+#             */
/*   Updated: 2017/10/07 23:55:11 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_null(char const *s1, char const *s2)
{
	char	*newstr;

	if (!s1 && s2)
	{
		newstr = ft_strsub(s2, 0, ft_strlen(s2));
		return (newstr);
	}
	else
		return (ft_strjoin(s1, s2));
	return (NULL);
}
