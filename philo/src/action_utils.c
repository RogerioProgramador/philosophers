/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:20:52 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 00:42:22 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_alive(t_philo *philo)
{
	if ((philo->info->time_to_die - get_current_time(philo->last_meal)) > 0)
		return (TRUE);
	else
		return (FALSE);
}

int	has_enough_time(t_philo *philo, int action)
{
	long int	in_ms;

	in_ms = get_current_time(philo->last_meal);
	if ((philo->info->time_to_die - in_ms)
		> action)
		return (TRUE);
	else
		return (FALSE);
}

void	print_action(t_philo *p, char *action)
{
	long int	t;

	pthread_mutex_lock(&p->info->print_out);
	t = get_current_time(p->pgm_start);
	if (ft_strcmp(action, FORK) == 0
		&& read_var(&p->info->control, &p->info->mutex_control))
		printf("%ld %i %s\n", t, p->id, FORK);
	if (ft_strcmp(action, EAT) == 0
		&& read_var(&p->info->control, &p->info->mutex_control))
		printf("%ld %i %s\n", t, p->id, EAT);
	if (ft_strcmp(action, THINK) == 0
		&& read_var(&p->info->control, &p->info->mutex_control))
		printf("%ld %i %s\n", t, p->id, THINK);
	if (ft_strcmp(action, SLEEP) == 0
		&& read_var(&p->info->control, &p->info->mutex_control))
		printf("%ld %i %s\n", t, p->id, SLEEP);
	if (ft_strcmp(action, DIE) == 0
		&& read_var(&p->info->first_to_die,
			&p->info->mutex_first_to_die) == 0)
	{
		write_var(&p->info->first_to_die,
			&p->info->mutex_first_to_die, 1);
		printf("%ld %i %s\n", t, p->id, DIE);
	}
	pthread_mutex_unlock(&p->info->print_out);
}
