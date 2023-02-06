/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:49 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/05 23:57:12 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse(t_data *data, int argc, char **argv)
{
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_philos = ft_atoi(argv[1]);
	if (argc == 6)
		data->number_of_meals = ft_atoi(argv[5]);
	else
		data->number_of_meals = MAX_INT;
}


int		main(int argc, char **argv)
{
	t_data data;

	if(!check_params(argc,argv))
		return (-1);
	parse(&data, argc, argv);
	start_philosophers(&data);
	start_forks(&data);
	create_threads(&data);
	init_spy(&data);
	join_threads(&data);
	free_all(&data);
	return (0);
}
