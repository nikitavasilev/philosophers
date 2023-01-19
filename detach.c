#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *routine(void *args)
{
	// pthread_detach(pthread_self());

	size_t	i;

	// void *ptr = malloc(1000);
	// (void)ptr;

	i = 0;
	while (i < 100)
	{
		i++;
		// sleep(1);
		dprintf(STDERR_FILENO, "doing threads\n");
		dprintf(STDERR_FILENO, "%s\n", (char *)args);
	}
	return NULL;
}

int	main(void)
{
	pthread_t	id;
	int			ret;

	// create a thread
	ret = pthread_create(&id, NULL, &routine, "hello");
	pthread_detach(id);
	if (!ret)
		dprintf(STDERR_FILENO, "thread created succesfully\n");
	else
		dprintf(STDERR_FILENO, "thread not created.\n");
	// pthread_join(id, NULL);
	dprintf(STDERR_FILENO, "after pthread_create\n");
	// sleep(1);
	return (0);
}
