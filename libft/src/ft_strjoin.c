/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:46:09 by soutin            #+#    #+#             */
/*   Updated: 2023/09/24 19:44:00 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	t_len;

	if (!s1 || !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	new = ft_calloc((t_len + 1), sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(new, (char *)s2, t_len + 1);
	return (new);
}