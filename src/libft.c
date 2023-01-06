/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:47 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/12/27 18:14:23 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_string(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int	string_to_int(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\f') || (*str == '\r')
		|| (*str == ' ') || (*str == '\n'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && str[i] >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
