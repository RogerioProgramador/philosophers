# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2022/12/28 21:17:04 by rsiqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc -Wall -Werror -Wextra
CFLAGS = -lreadline
RM = rm -f

SRCS =	src/main.c	\
		src/libft.c	\
		src/validate.c \
		src/run.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -I./include -c $< -o $@

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME) 

re: fclean all

.PHONY:	all clean fclean re