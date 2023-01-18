#ifndef CONTAINER_H
# define _GNU_SOURCE
# include <sched.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

int		jail(void *args);
char	*create_stack(void);

#endif