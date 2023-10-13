/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:48:14 by soutin            #+#    #+#             */
/*   Updated: 2023/10/11 17:05:22 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_token **lst, void (*del)(void*))
{
	t_token	*t;
	t_token	*buf;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		buf = t->next;
		ft_lstdelone(t, del);
		t = buf;
	}
	*lst = NULL;
}
