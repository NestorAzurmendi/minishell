# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/09/22 19:38:24 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   minishell

SRCS    =   src/main.c              \
			src/read_path.c			\
			src/split_line.c		\
			src/ft_strjoin_sl.c
   
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
