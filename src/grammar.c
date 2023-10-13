/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:13:51 by soutin            #+#    #+#             */
/*   Updated: 2023/10/13 23:28:54 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	error(t_token *head)
// {
// 	t_token *tmp;

// 	tmp = head;
// 	while (tmp)
// 	{
// 		if (ft_strchr("|", tmp->string[0]))
// 			return (-1);
// 		if (ft_strchr("<>|", ft_lstlast(head)->string[0]))
// 			return (-1);
// 		if (ft_strchr("<>|", tmp->string[0]) && ft_strchr("<>|", tmp->next->string[0]))
// 			return (-1);
// 		if (ft_strchr("|", tmp->string[0]) && ft_strchr)
// 	}
// }

int	meta_after_meta(char *str, int *j, int *i)
{
	*j = *i;
	while (ft_strchr("&|<>", str[*i]) && str[*i])
		i++;
	skip_wspaces(str + *i, i);
	// ft_printf("%c", str[i]);
	if (ft_strchr("<>|", str[*i]) && ft_strchr("<>", str[*j]))
		return (-1);
	if (str[*i] == '|' && str[*j] == '|')
		return (-1);
	return (0);
}

int	parse(char *str)
{
	int	i;
	int	j;

	skip_wspaces(str, &i);
	if (str[i] == '|')
		return (-1);
	while (str[i])
	{
		skip_wspaces(str, &i);
		if (str[i] && ft_strchr("<>|&", str[i]))
		{
			meta_after_meta(str, &j, &i);
			return (-1);
		}
		else if (!ft_strchr(" \n\t\r\v", str[i]))
		{
			j = i;
			while (!ft_strchr("&|<>() \n\t\r\v", str[i]) && str[i])
				i++;
		}
		if (!str[i])
			break;
	}
	if (ft_strchr("<>|", str[j]))
		return (-1);
	return (0);
}
