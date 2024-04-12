#include "./filesystem.h"

/**
 * show_file - desc
 * @params: hls_parameters
 * @path: string
 *
 * Description: List all dir/file
 * Return: errno or 0
*/
int show_file(hls_parameters params, char *path)
{
	DIR *list_of_dir;
	struct dirent *current_file;

    errno = 0;
	list_of_dir = opendir(path);
    if (!list_of_dir)
    {
        error_handler(errno, path);
        return (0);
    }

	while ((current_file = readdir(list_of_dir)) != NULL)
		print_files(params, path, current_file->d_name);
	if (!params.line_by_line && !params.more_details)
		putchar('\n');

	closedir(list_of_dir);
	return (0);
}
