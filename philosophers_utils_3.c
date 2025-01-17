/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:59:38 by serraoui          #+#    #+#             */
/*   Updated: 2024/08/05 22:48:37 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_pgroup(t_pgroup *pgroup, int ac, int number)
{
	if (ac == 6)
	{
		pgroup->nbr_meals = (size_t)number;
		pgroup->f_meals = 1;
	}
	if (ac == 5)
		pgroup->tt_sleep = (size_t)number;
	if (ac == 4)
		pgroup->tt_eat = (size_t)number;
	if (ac == 3)
		pgroup->tt_die = (size_t)number;
	if (ac == 2)
		pgroup->nbr_philos = (size_t)number;
}

int	ft_check_params(int ac, char **av, t_pgroup **pgroup)
{
	int	number;

	(*pgroup) = malloc(sizeof(t_pgroup));
	(*pgroup)->f_meals = 0;
	while (ac != 1)
	{
		if (!ft_atoi_check(av[ac - 1], &number))
			return (free(*pgroup), 0);
		if ((ac == 6 && number < 0) || (ac != 6 && number <= 0))
			return (free(*pgroup), 0);
		ft_init_pgroup((*pgroup), ac, number);
		ac--;
	}
	return (1);
}

void	*ft_philo_lifecycle(void *philo)
{
	t_philo	*p;
	long tmp;

	p = (t_philo *)philo;
	while (1)
	{
		if (p->f_meals && p->t_meals_count == p->nbr_meals)
			return (NULL);
		pthread_mutex_lock(p->r_fork);
		ft_handle_philo(p, FORK);
		pthread_mutex_lock(p->l_fork);
		ft_handle_philo(p, FORK);
		tmp = ft_get_timestamp();
		ft_handle_philo(p, EAT);
		usleep((p->tt_eat) * 1000);
		pthread_mutex_unlock(p->r_fork);
		pthread_mutex_unlock(p->l_fork);
		p->tt_start = tmp;
		p->t_meals_count += 1;
		ft_handle_philo(p, SLEEP);
		usleep((p->tt_sleep) * 1000);
		ft_handle_philo(p, THINK);
	}
}

int	ft_simulate_dinner(t_pgroup *pgroup)
{
	size_t	i;

	i = -1;
	pgroup->t_start_dinner = ft_get_timestamp();
	while (++i < pgroup->nbr_philos)
	{
		(pgroup->philos[i]).t_start_dinner = pgroup->t_start_dinner;
		if (pthread_create(&pgroup->philos[i].th_philo, NULL,
				ft_philo_lifecycle, (void *)(&pgroup->philos[i])))
			return (1);
		usleep(1000);
	}
	return (0);
}

int	ft_dinner_served(t_pgroup *pgroup)
{
	size_t	i;
	int		flag;

	i = -1;
	flag = 0;
	while (++i < pgroup->nbr_philos)
	{
		if (pgroup->philos[i].t_meals_count < pgroup->nbr_meals)
		{
			flag = 1;
			break ;
		}
	}
	return (flag);
}
