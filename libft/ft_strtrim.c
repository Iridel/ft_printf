/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:46:55 by dhill             #+#    #+#             */
/*   Updated: 2017/07/06 21:11:31 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *str)
{
	int		i;
	int		i2;
	int		len;
	char	*new;

	i = 0;
	i2 = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str) - 1;
	while (ft_iswhitespace(str[i]))
		i++;
	while (ft_iswhitespace(str[len]))
		len--;
	new = ft_strnew((len - i) + 1);
	if (!new)
		return (new = ft_memalloc(ft_strlen(str)));
	while (i <= len)
	{
		new[i2] = str[i];
		i++;
		i2++;
	}
	return (new);
}
