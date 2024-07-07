# include "philosophers.h"

void    ft_handle_mutex(pthread_mutex_t mutex, int state)
{
    if (state == INIT)
        pthread_mutex_init(&mutex, NULL);
    else if (state == LOCK)
        pthread_mutex_lock(&mutex);
    else if (state == UNLOCK)
        pthread_mutex_unlock(&mutex);
    else if (state == DESTROY)
        pthread_mutex_destroy(&mutex);
}

//TODO :  write a function that takes the current time in milliseconds
//TODO : replace the 0 timestamp with the current time in ms
void    ft_handle_philo(int id_philo, int state)
{
    if (state == FORK)
        printf("%zu %i has taken a fork", 0, id_philo);
    else if (state == EAT)
        printf("%zu %i is eating", 0, id_philo);
    else if (state == SLEEP)
        printf("%zu %i is sleeping", 0, id_philo);
    else if (state == THINK)
        printf("%zu %i is thinking", 0, id_philo);
    else if (state == DIE)
        printf("%zu %i died", 0, id_philo);
}

int ft_init_philos(t_pgroup *pgroup)
{
    size_t nbr_philos;

    pgroup->philos = malloc(sizeof(t_philo) * pgroup->nbr_philos);

    printf("ADDR __ %p\n", pgroup->philos[pgroup->nbr_philos + 1]);
    return (1);
}