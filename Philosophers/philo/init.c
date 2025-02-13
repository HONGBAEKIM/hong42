/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:26:40 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/20 19:26:41 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_alloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->num_philo);
	if (!data->tid)
		return (ft_error(ALLOCATING_THREADS_IDS_ERROR, data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (ft_error(ALLOCATING_FORKS_ERROR, data));
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (ft_error(ALLOCATING_PHILOS_ERROR, data));
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].leftfork = &data->forks[0];
	data->philos[0].rightfork = &data->forks[data->num_philo - 1];
	i = 1;
	while (i < data->num_philo)
	{
		data->philos[i].leftfork = &data->forks[i];
		data->philos[i].rightfork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->time_die;
		data->philos[i].eat_cont = 0;
		data->philos[i].eating = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int	init_data(t_data *data, char **av)
{
	data->num_philo = (int) ft_atoi(av[1]);
	data->time_die = (unsigned int) ft_atoi(av[2]);
	data->time_eat = (unsigned int) ft_atoi(av[3]);
	data->time_sleep = (unsigned int) ft_atoi(av[4]);
	if (av[5])
		data->num_meals = (int) ft_atoi(av[5]);
	else
		data->num_meals = -1;
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	init(t_data *data, char **av)
{
	if (ft_av_check(av))
	{
		ft_error(INPUT_IS_OUT_OF_RANGE, NULL);
		return (1);
	}
	if (init_data(data, av))
		return (1);
	if (ft_alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (0);
}

/* if (data->num_philo <= 0 || 200 < data->num_philo 
		|| data->time_die < 0 || data->time_eat < 0 || 
		data->time_sleep < 0 || data->num_meals <= 0)
	
		
void	ft_av_check(char **str)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	c = ft_atoi(str[3]);
	d = ft_atoi(str[4]);
	if (str[5])
		e = ft_atoi(str[5]);
	else
		e = 1;
	if (a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0)
		ft_error(INPUT_IS_OUT_OF_RANGE, NULL);
}

 */