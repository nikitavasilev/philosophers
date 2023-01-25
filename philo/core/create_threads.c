#include <pthread.h>
#include <stdlib.h>
#include "core.h"

// function to create threads
void	create_threads(t_philo *philos, t_data *data)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * data->nb_philos);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&threads[i], NULL, &routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}
