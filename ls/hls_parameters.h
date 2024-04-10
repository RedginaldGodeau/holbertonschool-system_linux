#ifndef HLS_PARAMETERS_H_
#define HLS_PARAMETERS_H_

#include <string.h>

/**
 * struct hls_parameters_t - ls parameters
 * @line_by_line: bool
 * @hidden_files: bool
 * @almost_all: bool
 * @more_details: bool
 *
 * Description: Longer description
 */
typedef struct hls_parameters_t
{
	int line_by_line;
	int hidden_files;
	int almost_all;
	int more_details;
} hls_parameters;

hls_parameters create_hls_parameters(int, int, int, int);
hls_parameters create_hls_by_args(int, char **);

#endif
