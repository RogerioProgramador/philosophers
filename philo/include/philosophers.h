/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:26 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 01:11:53 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define TRUE 1
# define FALSE 0
# define DIE "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"

typedef struct s_data	t_data;
typedef struct s_philo
{
	int				id;
	long int		n_eat;
	long int		last_meal;
	t_data			*info;
	pthread_t		thread;
	long int		pgm_start;
	pthread_mutex_t	fork;
	pthread_mutex_t	*neighbours_fork;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_n_eat;
}	t_philo;

typedef struct s_data
{
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	int					number_of_philos;
	long int			control;
	long int			time_to_die;
	long int			first_to_die;
	t_philo				*philo;
	pthread_mutex_t		mutex_control;
	pthread_mutex_t		mutex_first_to_die;
	pthread_mutex_t		print_out;
}	t_data;

int	check_params(int argc, char **argv);

void	start_philosophers(t_data *info);
void	start_forks(t_data *info);

void	init_spy(t_data *data);

void	create_threads(t_data *data);
void	join_threads(t_data *data);

void	*actions(void *args);
void	print_action(t_philo *p, char *action);

void		write_var(long int *var, pthread_mutex_t *mutex, long int status);
long int	read_var(long int *var, pthread_mutex_t *mutex);

long int	get_time_stamp(void);
long int	get_current_time(long int ts_baseline);

int	ft_strcmp(const char *s1, const char *s2);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
long int	ft_atol(const char *nptr);
int			ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);

void	free_all(t_data *data);

#endif