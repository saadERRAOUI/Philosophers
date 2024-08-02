/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:56:31 by serraoui          #+#    #+#             */
/*   Updated: 2024/08/02 01:03:55 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_check_death(t_pgroup *pgroup)
{
    size_t i;
    t_philo *philos;

    i = -1;
    philos = pgroup->philos;
    while (++i < pgroup->nbr_philos)
    {
        if (philos[i].tt_start == 0 && ft_get_timestamp()
			- pgroup->t_start_dinner >= (long) philos[i].tt_die
			&& philos[i].tt_die > 0)
			pgroup->f_die = philos[i].id_philo;
		else if (philos[i].tt_start && ft_get_timestamp()
			- philos[i].tt_start >= (long) philos[i].tt_die)
			pgroup->f_die = philos[i].id_philo;
    }
}

void ft_supervise_dinner(t_pgroup *pgroup)
{
	while (1)
	{
        ft_check_death(pgroup);
        if (pgroup->f_die != -1)
        {
            ft_handle_philo(&(pgroup->philos[pgroup->f_die]), DIE);
            return ;
        }
        else if (pgroup->f_die == -1 && !ft_dinner_served(pgroup))
            return ;
	}
}

void ft_free_table(t_pgroup *pgroup)
{
    size_t   i;
    pthread_mutex_t  *forks;

    i = -1;
    forks = pgroup->forks;
    while (++i < pgroup->nbr_philos)
        pthread_mutex_destroy(&forks[i]);
    free(pgroup->forks);
    free(pgroup->philos);
    pthread_mutex_destroy(pgroup->m_write);
    free(pgroup);
}

int ft_main(int ac, char **av)
{
    t_pgroup *pgroup = NULL;

    if (ac < 5 || ac > 6)
        return (printf("Invalid number of params !\n"), 1);
    if (!ft_check_params(ac, av, &pgroup))
        return (printf("Invalid params, please recheck your input !\n"));
    ft_init_philos(pgroup);
    ft_simulate_dinner(pgroup);
    ft_supervise_dinner(pgroup);
    ft_free_table(pgroup);
    return (0);
}

int main(int ac, char **av)
{
    ft_main(ac, av);
    // system("leaks philosophers");
    return (0);
}