#include "./hls_parameters.h"
/**
 * function_name - desc
 * @argc: count of args
 * @argv: list of args
 *
 * Description: create param by args
 * Return: hls_parameters
 */
hls_parameters create_hls_by_args(int argc, char **argv)
{
	hls_parameters params = create_hls_parameters(0, 0, 0, 0);
	int i = 0;

	for (i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-1") == 0)
			params.line_by_line = 1;
		else if (strcmp(argv[i], "-a") == 0)
			params.hidden_files = 1;
		else if (strcmp(argv[i], "-A") == 0)
			params.almost_all = 1;
		else if (strcmp(argv[i], "-l") == 0)
			params.more_details = 1;
	}

	return (params);
}
