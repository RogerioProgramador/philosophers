/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:27:47 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 00:58:16 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_and_return(char *msg, int return_value)
{
	printf("%s\n", msg);
	return (return_value);
}

int	validate_number(char **argv, int i)
{
	long int	j;
	int			index;
	int			arg_size;

	j = 0;
	index = 0;
	arg_size = ft_strlen(argv[i]);
	if (argv[i][index] == '-')
		return (1);
	while (index < arg_size)
	{
		if (!ft_isdigit(argv[i][index]))
			return (1);
		index++;
	}
	j = ft_atol(argv[i]);
	if (j > MAX_INT || j < MIN_INT)
		print_and_return("Invalid number!", FALSE);
	return (0);
}

int	check_params(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (print_and_return("At least 4 arguments is required.", FALSE));
	while (i < argc)
	{
		if (validate_number(argv, i) != 0)
			return (print_and_return("All arguments must be numbers "
					"with positive values!", FALSE));
		i++;
	}
	return (TRUE);
}
