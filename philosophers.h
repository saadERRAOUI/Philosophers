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

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3

void    ft_handle_mutex(pthread_mutex_t mutex, int state);
int     ft_atoi_check(const char *str, int *number);

typedef     s_philo
{
    int     id_philo;
    size_t  tt_die;
    size_t  tt_eat;
    size_t  tt_sleep;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *m_write;
}           t_philo;
#endif