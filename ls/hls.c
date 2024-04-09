#include "./hls.h"

/**
 * hls_create - Create hls struct
 * @path: bool
 * @by_the_line: bool
 * @more_info: bool
 * @hidden_file: bool
 * @almost_all: bool
 *
 * Description: List file in current dir
 * Return: Success / Failure
 */
hls_parameters hls_create(
		char *path,
		int by_the_line,
		int more_info,
		int hidden_file,
		int almost_all
		)
{
	hls_parameters param;

	param.path = path;
	param.more_info = more_info;
	param.by_the_line = by_the_line;
	param.hidden_file = hidden_file;
	param.almost_all = almost_all;

	return (param);
}
