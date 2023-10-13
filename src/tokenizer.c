/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:22:25 by soutin            #+#    #+#             */
/*   Updated: 2023/10/13 14:31:25 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	word_until(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(sep, str[i]))
	{
		if (ft_strchr("\"\'", str[i]))
			i += quotes_until(&str[i], sep);
		i++;	
	}	
	return (i);
}

int	quotes_until(char *str, char *sep)
{
	int	i;

	i = 1;
	while (str[i] && !ft_strchr("\"\'", str[i]))
	{
		i += skip_wspaces(str + i);
		i++;
	}
	if (str[i])
		i += word_until(str + i, sep);
	return (i);
}

int	meta_until(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("|&;()<>", str[i]))
	{
		if (ft_strchr("\"\'", str[i]))
			i += quotes_until(&str[i], sep);
		i++;
	}
	return (i);
}

int	token_until(char *str, char *sep)
{
	int	i;

	i = 0;
	if (ft_strchr("\'\"", str[i]))
		i = quotes_until(str, sep);
	if (!ft_strchr(sep, str[i]))
		i += word_until(str, sep);
	else
		i += meta_until(str, sep);
	return (i);
}

char	*tokenizer(char *str)
{
	static char	*tmp;
	int			i;
	char		*new;

	if (str)
		tmp = str;
	while (*tmp && ft_strchr(" \n", *tmp))
		tmp++;
	i = token_until(tmp,  " \n|&;()<>");
	new = ft_substr(tmp, 0, i);
	if (!new)
		return (NULL);
	while (i--)
		tmp++;
	return (new);
}

