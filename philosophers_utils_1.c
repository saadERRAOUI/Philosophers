# include "philosophers.h"

void    ft_handle_mutex(pthread_mutex_t *mutex, int state)
{
	if (state == INIT)
		pthread_mutex_init(mutex, NULL);
	if (state == LOCK)
		pthread_mutex_lock(mutex);
	else if (state == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (state == DESTROY)
		pthread_mutex_destroy(mutex);
}

void    ft_handle_philo(t_philo *philo, int state)
{
	long	ts;

	ts = (ft_get_timestamp() - philo->t_start_dinner) / 1000;
	pthread_mutex_lock(philo->m_write);
	if (state == FORK)
		printf("%zu %i has taken a fork\n", ts, philo->id_philo);
	else if (state == EAT)
		printf("%zu %i is eating\n", ts, philo->id_philo);
	else if (state == SLEEP)
		printf("%zu %i is sleeping\n", ts, philo->id_philo);
	else if (state == THINK)
		printf("%zu %i is thinking\n", ts, philo->id_philo);
	else if (state == DIE)
		printf("%zu %i died\n", ts, philo->id_philo);
	pthread_mutex_unlock(philo->m_write);
}

int ft_init_philos(t_pgroup *pgroup)
{
	size_t  i;
	size_t  nbr_philos;
	pthread_mutex_t mutex;

	i = -1;
	nbr_philos = pgroup->nbr_philos;
	ft_handle_mutex(&mutex, INIT);
	pgroup->f_die = -1;
	pgroup->m_died = &mutex;
	pgroup->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * pgroup->nbr_philos);
	while (++i < nbr_philos)
		ft_handle_mutex(&(pgroup->forks[i]), INIT);
	i = -1;
	pgroup->philos = malloc(sizeof(t_philo) * nbr_philos);
	while (++i < nbr_philos)
		ft_init_philo(i, pgroup, &pgroup->philos[i]);
	return (1);
}

void ft_init_philo(int id_philo, t_pgroup *pgroup, t_philo *philo)
{
	philo->id_philo = id_philo;
	philo->tt_die = pgroup->tt_die;
	philo->tt_eat = pgroup->tt_eat;
	philo->tt_sleep = pgroup->tt_sleep;
	philo->nbr_meals = pgroup->nbr_meals;
	philo->f_meals = pgroup->f_meals;
	philo->t_meals_count = 0;
	philo->r_fork = &pgroup->forks[id_philo];
	philo->l_fork = &pgroup->forks[(id_philo + 1) % pgroup->nbr_philos];
	philo->m_write = pgroup->m_write;
	philo->tt_start = 0;
}

long    ft_get_timestamp()
{
	struct timeval  tv;
	int             ret;

	ret = gettimeofday(&tv, NULL);
	if (ret)
		exit (1);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}