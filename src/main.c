/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:23:19 by soutin            #+#    #+#             */
/*   Updated: 2023/10/14 19:43:59 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	count_tokens(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (*str)
// 	{
// 		while (ft_strchr(" \n", *str))
// 			str++;
// 		if (*str && (ft_strchr("&|<>()", *str) && !ft_strchr("&|<>()", *(str - 1)))
// 			i++;
// 		if (*str && !ft_strchr("&|<>()", *str) && ft_strchr("&|<>() \n", *(str - 1)))
// 			i++;
// 		str++;
// 	}
// 	return (i);
// }

t_vars	*_vars(void)
{
	static t_vars	vars;
	
	return (&vars);
}

void	printlist(t_token **head)
{
	t_token	*current;

	current = *head;
	while (current != NULL)
	{
		ft_printf("%s : ", current->string);
		if (current->type == 0)
			ft_printf("WORD\n");
		else if (current->type == 1)
			ft_printf("FILEPATH\n");
		else if (current->type == 2)
			ft_printf("LIMITER\n");
		else if (current->type == 3)
			ft_printf("RESERVEDw\n");
		else if (current->type == 4)
			ft_printf("ENVVARIABLE\n");
		else if (current->type == 5)
			ft_printf("GREAT\n");
		else if (current->type == 6)
			ft_printf("GREATGREAT\n");
		else if (current->type == 7)
			ft_printf("LESS\n");
		else if (current->type == 8)
			ft_printf("LESSLESS\n");
		else if (current->type == 9)
			ft_printf("PIPE\n");
		else if (current->type == 10)
			ft_printf("ERRORLEVEL\n");
		current = current->next;
	}
}

int	main(int c, char **v, char **envp)
{
	char *s;

	(void)c;
	(void)envp;
	s = NULL;
	_vars()->tokens = NULL;
	while (1)
	{
		s = readline("minishell> ");
		if (s)
		{
			if (!parse(s))
			{
				if (tokenizer(s) < 0)
					ft_printf("parse error\n");
				else
					printlist(&_vars()->tokens);
				ft_lstclear(&_vars()->tokens, &free);
			}
		}
		free(s);
	}
	return (0);
}