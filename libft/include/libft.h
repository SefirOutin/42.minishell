/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:52:51 by soutin            #+#    #+#             */
/*   Updated: 2023/10/14 14:25:42 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../../include/minishell.h"
# include <bsd/string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_token
{
	char			*string;
	int				len;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_gnl
{
	char			*line;
	long			nb_bytes;
}					t_gnl;

int	choose_type(char *content);


int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
unsigned int		ft_strlen(const char *c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *p, int v, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t count);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_token				*ft_lstnew(void *content);
void				ft_lstadd_front(t_token **lst, t_token *new);
int					ft_lstsize(t_token *lst);
t_token				*ft_lstlast(t_token *lst);
int					ft_lstadd_back(t_token **lst, t_token *new);
void				ft_lstdelone(t_token *lst, void (*del)(void *));
void				ft_lstclear(t_token **lst, void (*del)(void *));
void				ft_lstiter(t_token *lst, void (*f)(void *));
t_token				*ft_lstmap(t_token *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_printf(const char *str, ...);
size_t				pf_putchar(int c);
size_t				pf_putstr(char *s);
void				pf_putnbr(int nb, size_t *len);
void				pf_convert_base(unsigned long nb, char index, size_t *len);

char				*get_next_line(int fd);

#endif