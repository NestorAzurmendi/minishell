# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/09/21 20:42:16 by nazurmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   minishell

SRCS    =   src/main.c              \
			src/read_path.c			\
			src/split_line.c			\

LIBFT   =   libft/libft.a

OBJS    =   $(SRCS:.c=.o)

CFLAGS  = -Wall -Wextra -Werror


$(NAME):	$(OBJS)
		gcc ${CFLAGS} $(OBJS) ${LIBFT} -o $(NAME)


$(LIBFT):
		@$(MAKE) -C libft

all		: $(NAME)


clean   :
		rm -rf $(OBJS)
		@$(MAKE) -C libft clean

fclean  :   clean
		rm -rf $(NAME) $(LIBFT)

re      :   fclean
		rm -rf $(NAME)

.PHONY  :   all clean fclean re
