/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:56:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/08/02 01:03:20 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define INIT 0
# define LOCK 1
# define UNLOCK 2
# define DESTROY 3

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4


typedef struct   s_philo
{
    int     id_philo;
    size_t  f_meals;
    size_t  t_meals_count;
    size_t  nbr_meals;
    size_t  tt_die;
    size_t  tt_eat;
    size_t  tt_sleep;
    long    tt_start;
    long    t_start_dinner;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *m_write;
    pthread_t       th_philo;
}           t_philo;

typedef struct   s_pgroup
{
    long            t_start_dinner;
    size_t          tt_die;
    size_t          tt_eat;
    size_t          tt_sleep;
    size_t          nbr_philos;
    size_t          nbr_meals;
    int             f_meals; 
    int             f_die;
    int             f_done;
    pthread_mutex_t *m_write;
    // pthread_mutex_t *m_meals;
    pthread_mutex_t *m_died;
    pthread_mutex_t *forks;
    t_philo         *philos;
}           t_pgroup;

void    ft_handle_mutex(pthread_mutex_t *mutex, int state);
void    ft_init_philo(int id_philo, t_pgroup *pgroup, t_philo *philo);
void    ft_handle_philo(t_philo *philo, int state);
void    *ft_philo_lifecycle(void *philo);
void ft_init_pgroup(t_pgroup *pgroup, int ac, int number);
void    *ft_philo_lifecycle(void *philo);
long     ft_get_timestamp();
int     ft_atoi_check(const char *str, int *number);
int     ft_init_philos(t_pgroup *pgroup);
int ft_simulate_dinner(t_pgroup *pgroup);
int ft_dinner_served(t_pgroup *pgroup);
int ft_check_params(int ac, char **av, t_pgroup **pgroup);
// int     ft_get_timestamp(long *ts);
// t_philo *ft_init_philo(int id_philo, t_pgroup *pgroup);

#endif