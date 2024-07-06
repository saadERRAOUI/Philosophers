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

int ft_check_params(int ac, char **av)
{
    int number;

    while (ac != 1)
    {
        if (!ft_atoi_check(av[ac - 1], &number))
            return (0);
		if ((ac == 5 && number < 0) || (ac != 5 && number <= 0))
            return (0);
        ac--;
    }
    return (1);
}

int main(int ac, char **av)
{
    //Todo : check if the params are valid
    if (ac < 5 || ac > 6)
        return (printf("Invalid number of params !\n"), 1);
    if (!ft_check_params(ac, av))
        return (printf("Invalid params, please recheck your input !\n"));
    printf("OK \n");
    //ft_init_philos()
    return (0);
}