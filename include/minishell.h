/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:23:57 by soutin            #+#    #+#             */
/*   Updated: 2023/10/13 23:47:13 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vars
{
	t_token	*tokens;
	int		nb_cmds;
	int		nb_sq;
	int		nb_dq;
	t_token	*commands;
}			t_vars;

enum		e_token_type
{
	WORD,
	LESS,
	GREAT,
	GREATGREAT,
	LESSLESS,
	AMPERSAND,
	SEMILICON,
	PIPE,
	FILEPATH,
	DOLLAR,
	RESERVEDW,

};

int			parse(char *str);
int			word_until(char *str, char *sep, int *i);
int			quotes_until(char *str, char *sep, int *i);
int			tokenizer(t_vars *vars, char *str);
void			skip_wspaces(char *str, int *i);

#endif