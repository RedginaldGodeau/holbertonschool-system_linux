#include "./file_system.h"
#include "./hls.h"
#include "./main.h"


/**
 * main - Main function
 * @argc: number of args
 * @argv: list of args
 *
 * Description: List file in current dir
 * Return: Success / Failure
 */
int main(int argc, char **argv)
{

	hls_parameters params = get_arguments(argc, argv);

	switch (show_files(params))
	{
		case 2:
			fprintf(stderr, "Permission denied\n");
			exit(2);
			break;
		case 3:
			fprintf(stderr, "Directory does exist\n");
			exit(2);
			break;
		case 4:
			fprintf(stderr, "%s is not a directory\n", params.path);
			exit(1);
			break;
	}

	exit(EXIT_SUCCESS);

}
