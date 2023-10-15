/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:22:25 by soutin            #+#    #+#             */
/*   Updated: 2023/10/15 16:14:58 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	skip_wspaces(char *str, int *i)
{
	while (str[*i] && ft_strchr(" \t\n\r\v", str[*i]))
		(*i)++;
}

int	quotes_until(char *str, char *sep, int *i)
{
	int	c;

	c = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
	if (!str[*i])
		return (-1);
	(*i)++;
	return (*i);
}

int	token_until(char *str, char *sep, int *i)
{
	int	save;

	save = *i;
	if (!ft_strchr(sep, str[*i]))
		while (str[*i] && !ft_strchr(sep, str[*i]))
		{
			if (ft_strchr("\'\"", str[*i]))
			{
				if (quotes_until(str, sep, i) < 0)
					return (-1);
			}
			else
				(*i)++;
		}
	else
		while (str[*i] && ft_strchr("|&()<>", str[*i]))
			(*i)++;
	return (*i - save);
}

int	check_token_type_error(void)
{
	t_token	*tmp;

	tmp = _vars()->tokens;
	while (tmp)
	{
		if (tmp->type < 0)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	tokenizer(char *str)
{
	int		token_end;
	int		token_start;
	char	*new_str;
	int		token_len;

	token_end = 0;
	while (str[token_end])
	{
		skip_wspaces(str, &token_end);
		token_start = token_end;
		token_len = token_until(str, " \n|&()<>", &token_end);
		if (token_len < 0)
			return (ft_lstclear(&_vars()->tokens, &free), -1);
		else if (!token_len && str[token_end])
			token_end++;
		else
		{
			new_str = ft_substr(str, token_start, token_len);
			if (!new_str)
				return (-1);
			if (ft_lstadd_back(&_vars()->tokens, ft_lstnew(new_str)) < 0)
				return (-1);
		}
	}
	// ft_printf("%d\n", check_token_error());
	if (check_token_type_error() < 0)
		return (ft_lstclear(&_vars()->tokens, &free), -1);
	return (0);
}
