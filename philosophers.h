/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:56:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/07/06 18:50:41 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>

# define INIT 0
# define LOCK 1
# define UNLOCK 2
# define DESTROY 3

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

void    ft_handle_mutex(pthread_mutex_t mutex, int state);
int     ft_atoi_check(const char *str, int *number);

typedef struct   s_philo
{
    int     id_philo;
    size_t  tt_die;
    size_t  tt_eat;
    size_t  tt_sleep;
    size_t  nbr_meals;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *m_write;
}           t_philo;

typedef struct   s_pgroup
{
    size_t  tt_die;
    size_t  tt_eat;
    size_t  tt_sleep;
    size_t  nbr_philos;
    size_t  nbr_meals;
    int     f_meals;
    t_philo     *philos;
}           t_pgroup;

#endif