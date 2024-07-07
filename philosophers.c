/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:56:31 by serraoui          #+#    #+#             */
/*   Updated: 2024/05/14 20:34:47 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_init_pgroup(t_pgroup *pgroup, int ac, int number)
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

int ft_check_params(int ac, char **av, t_pgroup **pgroup)
{
    int number;

    (*pgroup) = malloc(sizeof(t_pgroup));
    (*pgroup)->f_meals = 0;
    while (ac != 1)
    {
        if (!ft_atoi_check(av[ac - 1], &number))
            return (free(*pgroup), 0);
		if ((ac == 6 && number < 0) || (ac != 6 && number <= 0))
            return (free(*pgroup), 0);
        printf("AC___ %i %i\n", ac, number);
        ft_init_pgroup((*pgroup), ac, number);
        ac--;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_pgroup *pgroup = NULL;

    if (ac < 5 || ac > 6)
        return (printf("Invalid number of params !\n"), 1);
    if (!ft_check_params(ac, av, &pgroup))
        return (printf("Invalid params, please recheck your input !\n"));
    printf("OK \n");
    printf("PGROUP__ %zu\n", pgroup->tt_eat);
    printf("PGROUP__ %zu\n", pgroup->nbr_philos);
    printf("PGROUP__ %zu\n", pgroup->tt_sleep);
    printf("PGROUP__ %zu\n", pgroup->tt_die);
    printf("PGROUP__ %zu\n", pgroup->nbr_meals);
    printf("PGROUP__ %i\n", pgroup->f_meals);
    ft_init_philos(pgroup);
    return (0);
}