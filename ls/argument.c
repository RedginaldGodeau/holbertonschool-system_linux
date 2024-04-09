#include "./main.h"
#include <string.h>

hls_parameters get_arguments(int argc, char **argv)
{
	hls_parameters params = hls_create(DEFAULT_PATH, 0, 0, 0, 0);
	int i = 1;

	for (i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-1") == 0)
		{
			params.by_the_line = 1;
		}
		else if (strcmp(argv[i], "-a") == 0)
		{
			params.hidden_file = 1;
		}
		else if (strcmp(argv[i], "-l") == 0)
		{
			params.more_info = 1;
		}
		else if (strcmp(argv[i], "-A") == 0)
		{
			params.almost_all = 1;
		}
		else
		{
			params.path = argv[i];
		}
	}
	return (params);
}
