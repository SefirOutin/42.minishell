/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:23:57 by soutin            #+#    #+#             */
/*   Updated: 2023/10/14 20:03:38 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vars
{
	struct s_token	*tokens;
	int				nb_cmds;
}					t_vars;

enum				e_token_type
{
	WORD,
	FILEPATH,
	LIMITER,
	RESERVEDW,
	ENVVARIABLE,
	GREAT,
	GREATGREAT,
	LESS,
	LESSLESS,
	PIPE,
	ERRORLEVEL,
};

t_vars				*_vars(void);
int					parse(char *str);
int					word_until(char *str, char *sep, int *i);
int					quotes_until(char *str, char *sep, int *i);
int					tokenizer(char *str);
void				skip_wspaces(char *str, int *i);
void				printlist(struct s_token **head);
int	pwd(void);

#endif