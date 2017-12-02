/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:20:19 by dhill             #+#    #+#             */
/*   Updated: 2017/10/04 20:19:46 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** finds the first occurrence of the char find in str up to n bytes.
** it returns the index not a pointer
*/

int		compare(char x, char y)
{
	if (x == y)
		return (0);
	else
		return (-1);
}

int		ft_findchr(const char *str, const char find, size_t n)
{
	size_t	i;

	i = 0;
	if (find)
	{
		while (compare(str[i], find) != 0 && i <= n)
		{
			if (i == n)
				return (-1);
			i++;
		}
		return (i);
	}
	else
		return (-1);
}
