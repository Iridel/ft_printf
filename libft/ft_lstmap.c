/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:31:37 by dhill             #+#    #+#             */
/*   Updated: 2017/07/05 20:22:57 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *node))
{
	t_list	*new;
	t_list	*iter;

	if (!list)
		return (NULL);
	iter = f(list);
	new = iter;
	while (list->next)
	{
		list = list->next;
		iter->next = f(list);
		if (!iter->next)
			return (NULL);
		iter = iter->next;
	}
	return (new);
}
