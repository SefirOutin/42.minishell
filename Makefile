# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soutin <soutin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 16:35:15 by soutin            #+#    #+#              #
#    Updated: 2023/10/07 14:55:18 by soutin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			=		src
OBJ_DIR			=		obj
LIBFT_DIR		=		libft

NAME			=		minishell
SRC				=		$(wildcard $(SRC_DIR)/*.c)
OBJ				=		$(SRC:$(SRC)/%.c=$(OBJ_DIR)/%.o)
LIBFT			=		libft/libft.a

CPPFLAGS		=		-I./include -I./libft/include
CFLAGS			=		-Wall -Werror -Werror -g3

$(NAME):				$(OBJ)
							$(MAKE) -C $(LIBFT_DIR)
							cc $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

all:					$(NAME)


clean:
						$(MAKE) fclean -C $(LIBFT_DIR)

fclean:					clean
							rm -f $(NAME)

re:						fclean all

.PHONY:					all clean fclean re
