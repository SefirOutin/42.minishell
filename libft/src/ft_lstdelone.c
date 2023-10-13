/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:39:30 by soutin            #+#    #+#             */
/*   Updated: 2023/10/11 17:05:51 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_token *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst->string);
	free(lst);
}
