/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:32:11 by hqannouc          #+#    #+#             */
/*   Updated: 2025/08/15 03:55:28 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *nptr)
{
	char	*ptr;
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	ptr = (char *)nptr;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (sign * result);
}

int   ft_init_table(t_table *table, char **argv)
{
    table->num_philo = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        table->num_of_meals = ft_atoi(argv[5]);
    else
        table->num_of_meals = -1;
    table->all_forks = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!table->all_forks)
	{
		// ft_putstr_fd("failed to allocate\n", 2);
		return (0);
	}
	return (1);
}

int ft_init_philo(t_table *table)
{
	int	i;

    table->philo = malloc(table->num_philo * sizeof(t_philo));
    if (!table->philo)
        return (-1);
	i = -1;
	while (++i < table->num_philo)
	{
		table->philo[i].id = i;
		table->philo[i].left = &table->all_forks[i];
		if (i == table->num_philo - 1)
			table->philo[i].right = &table->all_forks[0];
		else
			table->philo[i].right = &table->all_forks[i + 1];
		table->philo[i].full = 0;
		// table->philo[i].last_time_eat = get_time_now(table);
		table->philo[i].table = table;
	}
	return (1);
}