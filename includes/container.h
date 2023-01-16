#ifndef CONTAINER_H
# define _GNU_SOURCE
# include <sched.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int		jail(void *args);
void	*create_stack(void);

#endif