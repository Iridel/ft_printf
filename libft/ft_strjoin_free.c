/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:58:57 by dhill             #+#    #+#             */
/*   Updated: 2017/09/28 23:14:36 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char *s2)
{
	char *newstr;

	newstr = ft_strjoin(s1, (char const *)s2);
	ft_strdel(&s2);
	return (newstr);
}
