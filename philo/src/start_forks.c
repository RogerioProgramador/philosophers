/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:54:38 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 00:27:27 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_forks(t_data *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->mutex_control, NULL);
	pthread_mutex_init(&info->mutex_first_to_die, NULL);
	pthread_mutex_init(&info->print_out, NULL);
	while (i < info->number_of_philos)
	{
		pthread_mutex_init(&(info->philo)[i].fork, NULL);
		(info->philo)[i].neighbours_fork = &((info->philo)[(i + 1)
				% info->number_of_philos].fork);
		pthread_mutex_init(&(info->philo)[i].mutex_last_meal, NULL);
		pthread_mutex_init(&(info->philo)[i].mutex_n_eat, NULL);
		if ((info->philo)[i].id % 2)
		{
			(info->philo)[i].first_fork = (info->philo)[i].neighbours_fork;
			(info->philo)[i].second_fork = &(info->philo)[i].fork;
		}
		else
		{
			(info->philo)[i].first_fork = &(info->philo)[i].fork;
			(info->philo)[i].second_fork = (info->philo)[i].neighbours_fork;
		}
		i++;
	}
}