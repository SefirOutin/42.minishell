/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:53:58 by soutin            #+#    #+#             */
/*   Updated: 2023/10/13 14:25:42 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_token	*ft_lstnew(void *content)
{
	t_token	*c;

	c = ft_calloc(1, sizeof(*c));
	if (!c)
		return (NULL);
	c->string = content;
	c->type = choose_type((char *)content);
	c->next = NULL;
	return (c);
}
