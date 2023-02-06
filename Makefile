# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 13:20:43 by rsiqueir          #+#    #+#              #
#    Updated: 2023/02/06 01:13:52 by rsiqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CC = cc -Wall -Werror -Wextra
CFLAGS = -lreadline
RM = rm -f

SRCS =	philo/src/actions.c	\
		philo/src/action_utils.c	\
		philo/src/check_params.c \
		philo/src/main.c	\
		philo/src/spy.c	\
		philo/src/start_forks.c \
		philo/src/start_philosophers.c \
		philo/src/threads.c	\
		philo/src/free.c \
		philo/src/utils.c	
		
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -I./philo/include -c $< -o $@

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME) 

re: fclean all

.PHONY:	all clean fclean re