#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *routine(void *args)
{
	dprintf(STDERR_FILENO, "doing threads\n");
	dprintf(STDERR_FILENO, "%s\n", (char *)args);
	return NULL;
}

int	main(void)
{
	pthread_t	id;
	int			ret;
	// size_t		i;

	ret = pthread_create(&id, NULL, &routine, NULL);
	if (!ret)
		dprintf(STDERR_FILENO, "thread created succesfully\n");
	else
		dprintf(STDERR_FILENO, "thread not created.\n");
	dprintf(STDERR_FILENO, "after pthread_create\n");
	// i = 0;
	// while (i < 1000000000)
	// 	i++;
	pthread_join(id, NULL);
	dprintf(STDERR_FILENO, "after pthread_join\n");
	return (0);
}
