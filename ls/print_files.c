#include "./file_system.h"

/**
 * print_files - write files
 * @params: hls_parameters
 * @filename: string
 *
 * Description: write file in console
 * Return: 1 or 0
 */
int print_files(hls_parameters params, char *filename)
{
	char fullpath[256];

	if (params.almost_all)
	{
		if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0)
			return (0);
	}
	else if (!params.hidden_file && filename[0] == '.')
		return (0);

	if (params.more_info)
	{
		strcpy(fullpath, params.path);

		if (params.path[strlen(params.path)] != '/')
			strcat(fullpath, "/");

		strcat(fullpath, filename);

		if (get_file_info(fullpath) == 1)
			return (1);
	}
	printf("%s", filename);
	if (params.by_the_line || params.more_info)
		putchar('\n');
	else
		putchar('\t');

	return (0);
}
