# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
#    Updated: 2020/10/08 18:43:38 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   minishell

SRCS	=   src/main.c              \
			src/read_path.c			\
			src/split_line.c		\
			src/echo.c				\
			src/pwd.c				\
			src/cd.c				\
			src/utils.c		\
			src/check_our_implement.c		

GCC			=   @gcc -Wall -Wextra -Werror -g3
OBJS		=   $(SRCS:.c=.o)
LIBFT		= libft/libft.a
INCLUDES	=   ./

all: $(NAME)
$(NAME):	$(OBJS)
		@$(MAKE) -C libft
		@$(GCC) -I$(INCLUDES) $(LIBFT) $(OBJS) -o $(NAME)
clean:
			-@$(RM) $(OBJS)
			@$(MAKE) -C libft clean
fclean:		clean
			-@$(RM) $(NAME) $(LIBFT)
re:			fclean all
.PHONY:		all clean fclean re bonus
