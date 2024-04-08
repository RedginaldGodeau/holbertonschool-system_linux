#include "./hls.h"


/**
 * show_files - list all file in path
 * @path: string
 *
 * Description: List file in current dir
 * Return: Success / Failure
*/
int show_files(char *path)
{
	DIR *list_of_dir;
	struct dirent *current_file;

	list_of_dir = opendir(path);
	if (list_of_dir == NULL)
	{
		return (1);
	}

	while ((current_file = readdir(list_of_dir)) != NULL)
	{
		printf("%s\t", current_file->d_name);
	}
	putchar('\n');

	closedir(list_of_dir);

	return (0);
}
