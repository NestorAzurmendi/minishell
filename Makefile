# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/10/23 20:32:21 by hellnhell        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   minishell

SRCS	=   src/main.c              \
			src/read_path.c			\
			src/split_line.c		\
			src/echo.c				\
			src/pwd.c				\
			src/cd.c				\
			src/ft_strjoin_sl.c		\
			src/check_our_implement.c	\
			src/split_dc.c	\
			src/create_lelemnts.c \
			src/list_add_elements.c \
			src/list_pop_elements.c \
			src/list_utils.c

GCC			=   -g3 -Wall -Wextra -Werror -I
OBJS		=   $(SRCS:.c=.o)
LIBFT		= 	libft/libft.a

INCLUDES	=   ./
$(NAME):	$(OBJS)
		gcc ${CFLAGS} $(OBJS) ${LIBFT} -I$(INCLUDES) -o $(NAME) 

$(LIBFT):
			@$(MAKE) -C libft
		
clean:
			@$(RM) $(OBJS)
			@$(MAKE) -C libft clean
			
fclean:		clean
			$(RM) $(NAME) $(LIBFT)
re:			fclean all
.PHONY:		all clean fclean re bonus
