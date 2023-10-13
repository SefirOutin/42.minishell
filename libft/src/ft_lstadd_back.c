/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:56:54 by soutin            #+#    #+#             */
/*   Updated: 2023/10/11 17:02:22 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
