/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:23:19 by soutin            #+#    #+#             */
/*   Updated: 2023/10/13 15:01:14 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// t_token	*lstlast(t_token *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

// t_token	*lstnew(char *content)
// {
// 	t_token	*c;

// 	c = malloc(sizeof(*c));
// 	if (!c)
// 		return (NULL);
// 	c->string = content;
// 	c->next = NULL;
// 	if (!ft_strchr("|&<>(); \t\n", content[0]))
// 		c->type = WORD;
// 	else
// 		c->type = OPERATOR;
// 	return (c);
// }

// void	lstadd_back(t_token **lst, t_token *new)
// {
// 	if (*lst)
// 		lstlast(*lst)->next = new;
// 	else
// 		*lst = new;
// }





int	choose_type(char *content)
{
	if (!ft_strncmp(content, "<", 2))
		return (LESS);
	else if (!ft_strncmp(content, "<<", 3))
		return (LESSLESS);
	else if (!ft_strncmp(content, ">", 2))
		return (GREAT);
	else if (!ft_strncmp(content, ">>", 3))
		return (GREATGREAT);
	else if (!ft_strncmp(content, "&", 2))
		return (AMPERSAND);
	else if (!ft_strncmp(content, "|", 2))
		return (PIPE);
	else if (!ft_strncmp(content, "$", 2))
		return (DOLLAR);
	else
		return (WORD);
	return (-1);
}



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
			ft_printf("LESS\n");
		else if (current->type == 2)
			ft_printf("GREAT\n");
		else if (current->type == 3)
			ft_printf("GREATGREAT\n");
		else if (current->type == 4)
			ft_printf("LESSLESS\n");
		else if (current->type == 5)
			ft_printf("AMPERSAND\n");
		else if (current->type == 6)
			ft_printf("SEMILICON\n");
		else if (current->type == 7)
			ft_printf("PIPE\n");
		else if (current->type == 8)
			ft_printf("FILEPATH\n");
		else if (current->type == 9)
			ft_printf("DOLLAR\n");
		else if (current->type == 10)
			ft_printf("RESERVEDw\n");
		current = current->next;
	}
	ft_printf("\n");
}

// void	freelist(t_token **head)
// {
// 	t_token *tmp;

// 	tmp = *head;
// 	while (tmp)
// 	{
// 		free(tmp->string);
// 		tmp = tmp->next
// 	}
// }

void	printtab(char **v)
{
	while (*v)
	{
		printf("%s\n", *v);
		v++;
	}
}

int	main(int c, char **v, char **envp)
{
	char *s;
	int i = 0;
	t_vars	vars;

	(void)c;
	(void)envp;
	printtab(v);
	s = v[1];
	ft_printf("%d\n", parse(v[1]));
	vars.tokens = NULL;
	// ft_printf("%d\n", count_tokens("                       time << in sleep                3 | | sleep 2 >> frfrfrout      "));
	ft_lstadd_back(&vars.tokens, ft_lstnew(tokenizer(s)));
	while (i < 10)
	{
		ft_lstadd_back(&vars.tokens, ft_lstnew(tokenizer(NULL)));
		i++;
	}
	printlist(&vars.tokens);
	ft_lstclear(&vars.tokens, &free);
	return (0);
}