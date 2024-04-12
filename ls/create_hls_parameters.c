#include "./hls_parameters.h"

/**
 * create_hls_parameters - func
 * @line_by_line: bool
 * @hidden_files: bool
 * @almost_all: bool
 * @more_details: bool
 *
 * Description: create hls_parameters
 * Return: hls_parameters
 */
hls_parameters create_hls_parameters(
		int line_by_line,
		int hidden_files,
		int almost_all,
		int more_details
		)
{
	hls_parameters params;
	params.line_by_line = line_by_line;
	params.hidden_files = hidden_files;
	params.almost_all = almost_all;
	params.more_details = more_details;

	return (params);
}
