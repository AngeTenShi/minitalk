# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 16:46:30 by anggonza          #+#    #+#              #
#    Updated: 2021/12/14 19:52:35 by anggonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk

SRCS	=  utils.c \
client.c \
server.c \

CLIENT = client
SERVER = server

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -I./ft_printf -o $@ $<

all: $(NAME)

$(NAME):	printf ${OBJS} $(CLIENT) $(SERVER)

$(CLIENT): printf
	$(CC) $(CLIENT).c utils.c -L./ft_printf -l:libftprintf.a -I./ft_printf -o $(CLIENT)

$(SERVER): printf
	$(CC) $(SERVER).c utils.c -L./ft_printf -l:libftprintf.a -I./ft_printf -o $(SERVER)

printf:
	$(MAKE) -C ./ft_printf

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean bonus re
