/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:24:32 by soutin            #+#    #+#             */
/*   Updated: 2023/10/11 17:06:06 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_token	*ft_lstmap(t_token *lst, void *(*f)(void *), void (*del)(void *))
{
	t_token	*tmp;
	t_token	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	tmp = ft_lstnew(f(lst->string));
	if (!tmp)
		return (NULL);
	ptr = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->string));
		if (!tmp->next)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (ptr);
}
