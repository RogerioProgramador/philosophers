/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:40:47 by rsiqueir          #+#    #+#             */
/*   Updated: 2023/02/06 00:58:47 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*s;

	s = b;
	while (n--)
	{
		*s++ = (unsigned char)c;
	}
	return (b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s_s1;
	unsigned char	*s_s2;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	while (s_s1[i] || s_s2[i])
	{
		if (s_s1[i] != s_s2[i])
			return (s_s1[i] - s_s2[i]);
		i++;
	}
	return (0);
}


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atol(const char *nptr)
{
	long int	s;
	long int	res;

	s = 1;
	res = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			s *= -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
	{
		res = (res * 10) + (*nptr - 48);
		nptr++;
	}
	return (res * s);
}

int	ft_atoi(const char *nptr)
{
	int	s;
	int	res;

	s = 1;
	res = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			s *= -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
	{
		res = (res * 10) + (*nptr - 48);
		nptr++;
	}
	return (res * s);
}


size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		s++;
		n++;
	}
	return (n);
}


long int	read_var(long int *var, pthread_mutex_t *mutex)
{
	long int	temp;

	pthread_mutex_lock(mutex);
	temp = *var;
	pthread_mutex_unlock(mutex);
	return (temp);
}

void	write_var(long int *var, pthread_mutex_t *mutex, long int status)
{
	pthread_mutex_lock(mutex);
	*var = status;
	pthread_mutex_unlock(mutex);
}

long int	get_time_stamp(void)
{
	struct timeval	tv;
	long int		ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000000 + tv.tv_usec) / 1000;
	return (ms);
}

long int	get_current_time(long int ts_baseline)
{
	long int	time_now;

	time_now = get_time_stamp() - ts_baseline;
	return (time_now);
}