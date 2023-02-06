/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:53:32 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/05 23:56:39 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philos_ate_enough(t_data *data)
{
	int	i;
	int	full_philos;

	i = -1;
	full_philos = 0;
	while (++i < data->number_of_philos)
	{
		if (read_var(&(data->philo)[i].n_eat,
			&(data->philo)[i].mutex_n_eat) >= data->number_of_meals)
			full_philos++;
	}
	if (full_philos == data->number_of_philos)
		return (TRUE);
	else
		return (FALSE);
}

void	init_spy(t_data *data)
{
	int				i;

	i = -1;
	while (1)
	{
		i = (i + 1) % data->number_of_philos;
		if (data->number_of_meals != MAX_INT)
		{
			if (philos_ate_enough(data))
				break ;
		}
		if (read_var(&(data->philo)[i].n_eat,
			&(data->philo)[i].mutex_n_eat) < data->number_of_meals
				&& get_current_time(read_var(&(data->philo)[i].last_meal,
					&(data->philo)[i].mutex_last_meal)) > data->time_to_die)
		{
			write_var(&data->control, &data->mutex_control, FALSE);
			print_action(&(data->philo)[i], DIE);
			break ;
		}
		usleep(450);
	}
}