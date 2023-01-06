/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:49 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/12/28 17:55:59 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void set_params(t_params *params,int args_number, char **args)
{
	params->number_of_philosophers = string_to_int(args[1]);
	params->time_to_die = string_to_int(args[2]);
	params->time_to_eat = string_to_int(args[3]);
	params->time_to_sleep = string_to_int(args[4]);
	if (args_number == 6)
		params->philosopher_must_eat = string_to_int(args[5]);
	else
		params->philosopher_must_eat = -1;
}


int	main(int argc, char **argv)
{
	t_params params;

	if (is_valid(argc, argv))
	{
		set_params(&params, argc, argv);
		run(&params);
	}
	else
		print_string("Error: Wrong Usage.\n");
}
