#include "container.h"

static int	run(char *name)
{
	char	*_arg[] = {name, NULL};

	return (execvp(name, _arg));
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

int	jail(void *args)
{
	(void)args;
	setup_variable();
	setup_root("./root");
	mount("proc", "/proc", "proc", 0, 0);

	if (run("bash") == -1)
	{
		perror("[ERROR]\t");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}