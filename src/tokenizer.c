/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:22:25 by soutin            #+#    #+#             */
/*   Updated: 2023/10/13 23:49:00 by soutin           ###   ########.fr       */
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
	(*i)++;
	return (*i);
}

int	token_until(t_vars *vars, char *str, char *sep, int *i)
{
	vars->nb_sq = 0;
	vars->nb_dq = 0;
	if (!ft_strchr(sep, str[*i]))
		while (str[*i] && !ft_strchr(sep, str[*i]))
		{
			if (ft_strchr("\'\"", str[*i]))
			{
				quotes_until(str, sep, i);
				
			}
			else
				(*i)++;
		}
	else
		while (str[*i] && ft_strchr("|&()<>", str[*i]))
			(*i)++;
	return (*i);
}

int	tokenizer(t_vars *vars, char *str)
{
	int		i;
	int		token_start;
	char	*new_str;
	t_token	*new_token;

	i = 0;
	while (str[i])
	{
		skip_wspaces(str, &i);
		token_start = i;
		if (token_until(vars, str,  " \n|&()<>", &i) - token_start)
		{
			new_str = ft_substr(str, token_start, i - token_start);
			if (!new_str)
				return (-1);
			new_token = ft_lstnew(new_str);
			if (!new_token)
				return (-1);
			ft_lstadd_back(&vars->tokens, new_token);
		}
		else if (str[i])
			i++;
	}
	return (0);
}

