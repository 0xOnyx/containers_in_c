#include "container.h"
//https://cesarvr.github.io/post/2018-05-22-create-containers/

int	main(int argc, char **argv)
{
	void	*stack;

	(void)argv;
	(void)argc;
	stack = create_stack();
	printf("(parent) id => %d\n", getpid());
	clone(&jail, stack, CLONE_NEWUTS | CLONE_NEWPID | SIGCHLD, 0);
	wait(NULL);
	return (EXIT_SUCCESS);
}
