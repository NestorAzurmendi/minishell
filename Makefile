# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazurmen <nazurmen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 18:30:24 by hellnhell         #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2020/09/24 20:22:10 by nazurmen         ###   ########.fr        #
=======
#    Updated: 2020/09/24 19:06:17 by nazurmen         ###   ########.fr        #
>>>>>>> 8992fef... pwd cd echo
#                                                                              #
# **************************************************************************** #

NAME    =   minishell

SRCS    =   src/main.c              \
			src/read_path.c			\
			src/split_line.c		\
			src/echo.c				\
			src/pwd.c				\
<<<<<<< HEAD
			src/ft_strjoin_sl.c

GCC         =   @gcc -Wall -Wextra -Werror -g3
OBJS        =   $(SRCS:.c=.o)
LIBFT       = libft/libft.a
INCLUDES    =   ./

all: $(NAME)
$(NAME):    $(OBJS)
        @$(MAKE) -C libft
        @$(GCC) -I$(INCLUDES) $(LIBFT) $(OBJS) -o $(NAME)
clean:
            -@$(RM) $(OBJS)
            @$(MAKE) -C libft clean
fclean:     clean
            -@$(RM) $(NAME) $(LIBFT)
re:         fclean all
.PHONY:     all clean fclean re bonus
=======
			src/cd.c				\

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
>>>>>>> 8992fef... pwd cd echo
