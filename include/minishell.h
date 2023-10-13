/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:23:57 by soutin            #+#    #+#             */
/*   Updated: 2023/10/13 14:30:56 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_vars
{
	t_token			*tokens;
	int				nb_cmds;
	t_token			*commands;
}					t_vars;

enum				e_token_type
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

int	parse(char *str);
int	word_until(char *str, char *sep);
int	quotes_until(char *str, char *sep);
char	*tokenizer(char *str);
int	skip_wspaces(char *str);

#endif