/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:00:12 by hqannouc          #+#    #+#             */
/*   Updated: 2025/08/15 03:59:21 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct s_philo;

typedef struct s_table
{
    int             num_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_of_meals;
    pthread_mutex_t *all_forks;
    struct s_philo *philo;
} t_table;

typedef struct s_philo
{
    int             id;
    int             count_meals;
    int				full;
    struct s_table         *table;
    pthread_t       thread;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
    pthread_mutex_t *meal_mutex;
    
} t_philo;

int     create_threads(t_table *table);
int   ft_init_table(t_table *table, char **argv);
int ft_init_philo(t_table *table);
#endif