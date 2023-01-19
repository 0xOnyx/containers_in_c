#ifndef CONTAINER_H
# define NAME "container"
# define _GNU_SOURCE
# include <sched.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/mount.h>
# include <sys/stat.h>
# include <fcntl.h>

# define CGROUP_FOLDER "/sys/fs/cgroup/pids/"

int		jail(void *args);
char	*create_stack(void);
void	clone_process(int (*func)(void *), int flags, void *arg);

#endif