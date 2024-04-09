#include "./file_system.h"

/**
 * show_files - list all file in path
 * @params: hls_parameter
 *
 * Description: List file in current dir
 * Return: Success / Failure
*/
int show_files(hls_parameters params)
{
	DIR *list_of_dir;
	struct dirent *current_file;

	list_of_dir = opendir(params.path);
	errno = 0;
	if (list_of_dir == NULL)
	{
		return (errno);
	}

	while ((current_file = readdir(list_of_dir)) != NULL)
	{
		print_files(params, current_file->d_name);
	}
	if (!params.by_the_line && !params.more_info)
		putchar('\n');

	closedir(list_of_dir);
	return (0);
}
