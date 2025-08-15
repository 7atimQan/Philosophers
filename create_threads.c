/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:01:35 by hqannouc          #+#    #+#             */
/*   Updated: 2025/08/15 04:01:07 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_a_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
        usleep(1000);
		pthread_mutex_lock(philo->right);
		printf("%d has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->left);
		printf("%d has taken a fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		printf("%d has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->right);
		printf("%d has taken a fork\n", philo->id);
	}

}

void	philo_eat(t_philo *philo)
{
	printf("is eating\n");
	pthread_mutex_lock(philo->meal_mutex);
	philo->count_meals++;
	pthread_mutex_unlock(philo->meal_mutex);
	usleep(philo->table->time_to_eat);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	philo_sleep(t_philo *philo)
{
	printf("is sleeping\n");
	usleep(philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	printf("is thinking\n");
}

void *ft_routine(void *param)
{
    t_philo *philo;

    philo = (t_philo *)param;
    while (1)
    {
        take_a_fork(philo);
        philo_eat(philo);
        put_fork(philo);
        philo_sleep(philo);
        philo_think(philo);
    }
}

int create_threads(t_table *table)
{
    int i;

    i = 0;
    while (i < table->num_philo)
    {
        pthread_create(&table->philo[i].thread, NULL, ft_routine, &table->philo[i]);
        i++;
    }
    return (1);
}