# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 13:59:19 by yakhay            #+#    #+#              #
#    Updated: 2023/01/14 19:32:53 by yakhay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_bzero.c		\
		ft_strlen.c		\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_substr.c		\
		ft_split.c		\
		ft_strdup.c


OBJS = $(SRCS:.c=.o)


RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):	$(OBJS)	
	ar -rc $(NAME) $?

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)



.PHONY:			all clean fclean re 
