/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:17:14 by hqannouc          #+#    #+#             */
/*   Updated: 2025/08/15 04:03:06 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int is_digit(int argc, char **argv)
// {
//     ;
// }

// int check_args(int argc, char **argv)
// {
//     if (argc != 5 || argc != 6)
//         return (-1);
//     if (!is_digit(argc, argv))
//         return (-1);

// }
int ft_destroy(t_table *table)
{
    int i;

    i = 0;
    while (i < table->num_philo)
    {
        pthread_join(table->philo[i].thread, NULL);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_table table;

    // if (!check_args(argc, argv))
    //     return (1);
    ft_init_table(&table, argv);
    ft_init_philo(&table);
    create_threads(&table);
    ft_destroy(&table);
    return (0);
}