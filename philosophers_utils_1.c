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

void    ft_handle_philo(int id_philo, int state)
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