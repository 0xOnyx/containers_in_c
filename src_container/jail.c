#include "container.h"

static int	run(void *name)
{
	char	*_arg[] = {(char *)name, NULL};

	if (execvp((char *)name, _arg) == -1)
	{
		perror("[ERROR]\t");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	setup_variable()
{
	clearenv();
	setenv("TERM", "xterm-256color", 0);
	setenv("PATH", "/bin/:/sbin/:usr/bin:/usr/sbin", 0);
}

static void	setup_root(const char *folder)
{
	chroot(folder);
	chdir("/");
}

static void	write_rules(char *path, int value)
{
	int fd;

	fd = open(path, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (perror("[ERROR]\t"));
	if (dprintf(fd, "%d", value) < 0)
	{
		close(fd);
		perror("[ERROR]\t");
	}
	close(fd);
}

static void	limitProcessCreation()
{
	int		len;
	char 	buff[255];

	mkdir(CGROUP_FOLDER NAME, S_IRUSR | S_IWUSR);
	len = sprintf(buff, "%s/%s", CGROUP_FOLDER NAME, "cgroup.procs");
	buff[len] = '\0';
	write_rules(buff, getpid());

	len = sprintf(buff, "%s/%s", CGROUP_FOLDER NAME, "notify_on_release");
	buff[len] = '\0';
	write_rules(buff, 1);

	len = sprintf(buff, "%s/%s", CGROUP_FOLDER NAME, "pids.max");
	buff[len] = '\0';
	write_rules(buff, 5);
}

int	jail(void *args)
{
	int	status;

	(void)args;
	limitProcessCreation();
	setup_variable();
	setup_root("./root");
	mount("proc", "/proc", "proc", 0, 0);
	clone_process(&run, SIGCHLD, "/bin/sh");
	wait(&status);
	umount("/proc");
	return (EXIT_SUCCESS);
}