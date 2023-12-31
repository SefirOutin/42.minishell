/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:56:54 by soutin            #+#    #+#             */
/*   Updated: 2023/10/14 14:18:44 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstadd_back(t_token **lst, t_token *new)
{
	if (!new)
		return (-1);
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
	return (0);
}
