# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 16:46:30 by anggonza          #+#    #+#              #
#    Updated: 2021/11/09 17:39:45 by anggonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c \
ft_checkflag.c \
ft_printhexa.c \
ft_putchar_count.c \
utils.c \
ft_printptr_count.c \
ft_printunsigned_count.c \

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $<

all: $(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean bonus re
