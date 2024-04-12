#include "./filesystem.h"

/**
 * print_files - print_files
 * @params: hls_parameters
 * @file_name: string
 * @path: string
 *
 * Description: print files
 * Return: 0 or 1
 */
int print_files(
		hls_parameters params,
		char *path,
		char *file_name
	       )
{

	if (params.almost_all &&
			(strcmp(file_name, ".") == 0 || strcmp(file_name, "..") == 0))
		return (0);
	else if (!params.hidden_files && file_name[0] == '.')
		return (0);

	if (params.more_details)
		more_details(path, file_name);

	printf("%s%s",
			file_name,
			(params.line_by_line || params.more_details) ? "\n" : "\t");

	return (0);
}
