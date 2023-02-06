/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:58:56 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 00:37:15 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	think(t_philo *philo)
{
	print_action(philo, THINK);
	usleep(50);
	return ;
}

static void	to_sleep(t_philo *philo)
{
	print_action(philo, SLEEP);
	usleep(philo->info->time_to_sleep * 1000);
	return ;
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_action(philo, FORK);
	pthread_mutex_lock(philo->second_fork);
	print_action(philo, FORK);
	write_var(&philo->last_meal, &philo->mutex_last_meal, get_time_stamp());
	print_action(philo, EAT);
	usleep(philo->info->time_to_eat * 1000);
	write_var(&philo->n_eat, &philo->mutex_n_eat,
		read_var(&philo->n_eat, &philo->mutex_n_eat) + 1);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return ;
}

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_action(philo, FORK);
	usleep(philo->info->time_to_die * 1000);
	print_action(philo, DIE);
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}

void	*actions(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->info->number_of_philos == 1)
		return (one_philo(philo));
	while (philo->n_eat < philo->info->number_of_meals
		&& !read_var(&philo->info->first_to_die,
			&philo->info->mutex_first_to_die))
	{
		usleep(50);
		eat(philo);
		to_sleep(philo);
		think(philo);
	}
	return (0);
}