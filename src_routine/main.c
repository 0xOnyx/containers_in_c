#include "container.h"
//https://cesarvr.github.io/post/2018-05-22-create-containers/

int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	printf("(parent)");
	clone(&jail, create_stack(), SIGCHLD, 0);
	return (0);
}
