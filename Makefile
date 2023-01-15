# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 13:59:19 by yakhay            #+#    #+#              #
#    Updated: 2023/01/12 16:35:57 by yakhay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  get_next_line.c get_next_line_utils.c main.c check_map.c


OBJS = $(SRCS:.c=.o)


RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= so_long

all:			$(NAME)

$(NAME):	$(OBJS)	
	$(CC) $(SRCS) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)



.PHONY:			all clean fclean re 
