#include "container.h"
//https://cesarvr.github.io/post/2018-05-22-create-containers/
//CLONE_IO,CLONE_NEWIPC, CLONE_NEWNET, CLONE_NEWPID, CLONE_NEWUSER,  and  CLONE_NEWUTS.

void	clone_process(int (*func)(void *), int flags, void *arg)
{
	void	*stack;

	stack = create_stack();
	if (clone(func, stack, flags, arg) == -1)
	{
		perror("[ERROR]\t");
		exit(EXIT_FAILURE);
	}
}


int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	printf("(parent) id => %d\n", getpid());
	clone_process(&jail, CLONE_NEWPID | CLONE_NEWUTS | SIGCHLD, NULL);
	wait(NULL);
	return (EXIT_SUCCESS);
}
