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
		if (argv[i][0] == '-')
			switch (argv[i][1])
			{
				case '1':
					params.line_by_line = 1;
					break;
				case 'a':
					params.hidden_files = 1;
					break;
				case 'A':
					params.almost_all = 1;
					break;
				case 'l':
					params.more_details = 1;
					break;
			}
	}
	return (params);
}
