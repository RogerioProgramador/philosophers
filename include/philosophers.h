/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:26 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/12/28 21:16:55 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

#define EATING 1
#define SLEEPING 2
#define THINKING 3

typedef struct	s_philo
{
	int left_hand;
	int right_hand;
	int status;
	int status_time;
}				t_philo;

typedef struct	s_params
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int philosopher_must_eat;
}				t_params;


//LIB
void	print_string(char *s);
int		string_to_int(const char *str);

//Validate
int is_valid(int argc, char **argv);

void run(t_params *params);

#endif