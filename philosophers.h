/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:56:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/05/14 16:56:29 by serraoui         ###   ########.fr       */
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

void    ft_handle_mutex(pthread_mutex_t mutex, int state);
int     ft_atoi_check(const char *str, int *number);

#endif