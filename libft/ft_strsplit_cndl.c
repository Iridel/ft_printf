/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_cndl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 01:48:28 by dhill             #+#    #+#             */
/*   Updated: 2017/10/11 00:43:01 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strct(char const *str, char delim)
{
	int i;

	i = 0;
	while (*str)
	{
		while (*str == delim && *str)
			str++;
		if (*str != delim && *str)
		{
			i++;
			while (*str != delim && *str)
				str++;
		}
	}
	return (i);
}

static void		allohelp(int *tmp, char **str, int n)
{
	int i;

	i = 0;
	while (i <= n && tmp[i] != '\0')
	{
		str[i] = ft_strnew(tmp[i]);
		i++;
	}
	ft_memdel((void *)&tmp);
}

static char		**allocation(char const *s, char **str, char delim, int n)
{
	int		i;
	int		len;
	int		*tmp;

	i = 0;
	tmp = (int *)ft_memalloc(n * sizeof(int));
	if (!tmp)
		return (NULL);
	while (i <= n)
	{
		len = 0;
		while (*s == delim && *s != '\0')
			s++;
		while (*s != delim && *s != '\0')
		{
			len++;
			s++;
		}
		tmp[i] = len;
		i++;
	}
	allohelp(tmp, str, n);
	return (str);
}

static char		**split(char const *s, char **new, char delim, int strnbr)
{
	int i;
	int i2;
	int iter;

	i = 0;
	i2 = 0;
	iter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == delim)
			i++;
		while (iter < (strnbr + 1) && s[i] != delim && s[i] != '\0')
		{
			new[iter][i2] = s[i];
			i++;
			i2++;
		}
		i2 = 0;
		iter++;
	}
	return (new);
}

char			**ft_strsplit_cndl(char const *s, char c, int *n)
{
	int		strnbr;
	char	**new;

	if (!s || !c)
		return (NULL);
	if (c == '\0')
	{
		new = (char **)ft_memalloc(2 * sizeof(char *));
		new[0] = ft_strdup(s);
		new[1] = "\0";
		return (new);
	}
	strnbr = strct(s, c);
	*n = strnbr;
	new = (char **)ft_memalloc((strnbr + 1) * sizeof(char *));
	new = allocation(s, new, c, strnbr);
	if (!new)
		return (NULL);
	split(s, new, c, strnbr);
	return (new);
}
