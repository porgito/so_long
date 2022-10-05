# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 15:46:17 by jlaurent          #+#    #+#              #
#    Updated: 2022/01/24 17:50:32 by jlaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c xpm.c mapscan.c hook.c utils.c grab.c enemies.c

OBJS	= ${SRCS:.c=.o}

GCC		= gcc -Wall -Werror -Wextra -I./mlx -Lmlx -lmlx

FW		= -framework OpenGL -framework AppKit

RM		= rm -f

NAME	= so_long


all:		${NAME}

${NAME}:	${OBJS}
						${GCC} ${FW} -o ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:		clean
						${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
