#include "./get_paths.h"

/**
 * get_paths - find all path in args
 * @argc: count of args
 * @argv: list of args
 * @paths: table of string
 *
 * Description: find all path
 * Return: number of path
 */
int get_paths(int argc, char **argv, char **paths)
{
	int i = 0;
	int path_i = 0;

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] != '-')
			paths[path_i++] = argv[i];
	}
	return (path_i);
}
