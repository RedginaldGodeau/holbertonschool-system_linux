#include "./filesystem.h"

/**
 * error_handler - handle errors
 * @err: errno
 * @path: string
 *
 * Description: error handler
 */
void error_handler(int err, char *path)
{
	switch (err)
	{
		case EACCES:
			fprintf(stderr,
					"./hls: connot access %s: Permission denied\n",
					path);
			exit(2);
		case ENOENT:
			fprintf(stderr,
					"./hls: cannot access %s: No such file or directory\n",
					path);
			exit(2);
        case ENOTDIR:
			fprintf(stderr, "./hls: cannot access %s: %s is not a directory\n",
					path, path);
			exit(1);
        default:
            exit(1);
	}
}
