#ifndef HLS_H_
#define HLS_H_

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

#define DEFAULT_PATH "./"

/**
 * struct hls_parameters - struct for ls parameters 
 * @path: char *
 * @by_the_line: bool
 * @more_info: bool
 * @hidden_file: bool
 * @almost_all: bool
 *
 * Description: Longer description
*/

typedef struct hls_parameters_t
{
	char *path;
	int by_the_line;
	int more_info;
	int hidden_file;
	int almost_all;
} hls_parameters;
hls_parameters hls_create(char *, int, int, int, int);

#endif
