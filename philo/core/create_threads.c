#include <pthread.h>
#include "core.h"

// function to create threads
void	create_threads(t_philo_args *args, t_data *philos)
{
	int			i;
	pthread_t	id;

	i = 0;
	while (i < args->nb_philos)
	{
		pthread_create(&id, NULL, &routine, &philos[i]);
		pthread_join(id, NULL);
		i++;
	}
}
