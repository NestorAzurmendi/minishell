# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/09/20 19:02:05 by hellnhell        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   minishell

SRCS    =   src/main.c              \
   
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
