/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:07:22 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 01:09:44 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		pthread_mutex_destroy(&((data->philo)[i].fork));
		pthread_mutex_destroy(&(data->philo)[i].mutex_last_meal);
		pthread_mutex_destroy(&(data->philo)[i].mutex_n_eat);
	}
	pthread_mutex_destroy(&(data->mutex_control));
	pthread_mutex_destroy(&(data->mutex_first_to_die));
	pthread_mutex_destroy(&(data->print_out));
	ft_free_ptr((void *)&data->philo);
}