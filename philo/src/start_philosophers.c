/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:44:50 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 01:12:18 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philosophers(t_data *info)
{
	int	i;
    t_philo *philo;

	i = 0;
	info->control = TRUE;
	info->first_to_die = FALSE;
    philo = info->philo;
	philo = ft_calloc(info->number_of_philos, sizeof(t_philo));
	while (i < info->number_of_philos)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].n_eat = 0;
		philo[i].last_meal = get_time_stamp();
		philo[i].pgm_start = get_time_stamp();
		i++;
	}
}