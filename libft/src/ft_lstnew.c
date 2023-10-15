/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:53:58 by soutin            #+#    #+#             */
/*   Updated: 2023/10/14 19:45:23 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	reserved_word(char *content)
{
	if (!strncmp(content, "echo", 5))
		return (1);
	if (!strncmp(content, "cd", 3))
		return (1);
	if (!strncmp(content, "pwd", 4))
		return (1);
	if (!strncmp(content, "export", 7))
		return (1);
	if (!strncmp(content, "unset", 6))
		return (1);
	if (!strncmp(content, "env", 4))
		return (1);
	if (!strncmp(content, "exit", 5))
		return (1);
	return (0);
}

int	choose_type_next(char *content, int last_type)
{
	int	type;
	
	if (reserved_word(content))
		type = RESERVEDW;
	else if (!ft_strchr("<>|$", content[0]))
	{
		type = WORD;
		if (last_type == LESS || last_type == GREAT || last_type == GREATGREAT)
			type = FILEPATH;
		else if (last_type == LESSLESS)
			type = LIMITER;
	}
	else
		return (-1);
	return (type);
}

int	choose_type(char *content)
{
	int	type;
	int	last_type;
	
	last_type = -1;
	if (_vars()->tokens)
		last_type = ft_lstlast(_vars()->tokens)->type;
	if (!ft_strncmp(content, "<", 7))
		type = LESS;
	else if (!ft_strncmp(content, "<<", 3))
		type = LESSLESS;
	else if (!ft_strncmp(content, ">", 2))
		type = GREAT;
	else if (!ft_strncmp(content, ">>", 3))
		type = GREATGREAT;
	else if (!ft_strncmp(content, "$?", 3))
		type = ERRORLEVEL;
	else if (!ft_strncmp(content, "|", 2))
		type = PIPE;
	else if (!ft_strncmp(content, "$", 2))
		type = ENVVARIABLE;
	else
		type = choose_type_next(content, last_type);
	return (type);
		
}

t_token	*ft_lstnew(void *content)
{
	t_token	*c;

	c = (t_token *)ft_calloc(1, sizeof(*c));
	if (!c)
		return (NULL);
	c->string = content;
	c->type = choose_type((char *)content);
	c->next = NULL;
	return (c);
}
