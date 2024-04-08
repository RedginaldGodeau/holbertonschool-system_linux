#include "./hls.h"

/**
 * main - Main function
 *
 * Description: List file in current dir
 * Return: Success / Failure
*/
int main(void)
{
	char *default_path = "./";

	if (show_files(default_path) == 1)
	{
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
