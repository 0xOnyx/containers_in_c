#include "container.h"
//https://cesarvr.github.io/post/2018-05-22-create-containers/

int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	void	*stack;

	stack = create_stack();
	printf("(parent)\n");
	clone(&jail, stack, CLONE_NEWUTS | CLONE_NEWPID | SIGCHLD, 0);
	wait(NULL);
	return (EXIT_SUCCESS);
}
