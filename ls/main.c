#include "./main.h"

/**
 * main - main func
 * @argc: count args
 * @argv: list of args
 *
 * Description: main
 * Return: 0
 */
int main(int argc, char **argv)
{
	hls_parameters params =
		create_hls_by_args(argc, argv);

	char **paths = malloc(100 * sizeof(char *));
	int n_path = get_paths(argc, argv, paths);
	int i = 0;

	for (i = 0; i < n_path; i++)
	{
		if (n_path > 1)
			printf("%s:\n", paths[i]);
		show_file(params, paths[i]);
		if (n_path > 1)
			putchar('\n');
	}
	if (n_path == 0)
		show_file(params, ".");

	free(paths);
	exit(EXIT_SUCCESS);
}
