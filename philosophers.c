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

int ft_isdigit(int c)
{
    return (c <= '9' && c >= '0');
}

int	ft_atoi_check(const char *str, int *number)
{
	int		i;
	int		sign;
	size_t	n;

	i = 0;
	sign = 1;
	(*number) = 0;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = n * 10 + str[i++] - '0';
	}
	if ((n > INT_MAX && sign == 1) || (n > 2147483648 && sign == -1))
		return (0);
	return ((*number) = n * sign, 1);
}

int ft_check_params(int ac, char **av)
{
    int number;

    while (ac != 2)
    {
        if (!ft_atoi_check(av[ac -1], &number) ||
            (ft_atoi_check(av[ac -1], &number) && number < 0))
            return (0);
        ac--;
    }
    return (1);
}

int main(int ac, char **av)
{
    //Todo : check if the params are valid
    if (ac < 6 || ac > 7)
        return (printf("Invalid number of params !\n"), 1);
    if (!ft_check_params(ac, av))
        return (printf("Invalid params, please recheck your input !\n"));
    //printf("OK \n");
    ft_init_philos()
    return (0);
}