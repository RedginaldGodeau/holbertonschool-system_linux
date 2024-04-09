#include "./file_system.h"
#include "./hls.h"
#include "./main.h"
#include <string.h>

/**
 * main - Main function
 *
 * Description: List file in current dir
 * Return: Success / Failure
*/
int main(int argc, char **argv)
{
	hls_parameters params = hls_create(DEFAULT_PATH, 0, 0, 0, 0);
	
	int i = 1;
	for (i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "-1") == 0)
		{
			params.by_the_line = 1;
		}
		else if(strcmp(argv[i], "-a") == 0)
		{
			params.hidden_file = 1;
		}
		else if(strcmp(argv[i], "-l") == 0)
		{
			params.more_info = 1;
		}
		else if(strcmp(argv[i], "-A") == 0)
		{
			params.almost_all = 1;
		}
		else
		{
			params.path = argv[i];
		}
	}


	switch(show_files(params))
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
