#include "container.h"

#define STACK_SIZE 65536

char	*create_stack(void)
{
	char	*res;

	res = (char *)calloc(sizeof(char), STACK_SIZE);
	if (!res)
	{
		perror("[ERROR]\t");
		exit(EXIT_FAILURE);
	}
	return ((void *)(res + STACK_SIZE));
}