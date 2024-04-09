#include "./file_system.h"


/**
 * show_files - list all file in path
 * @params: hls_parameter
 *
 * Description: List file in current dir
 * Return: Success / Failure
*/
int show_files(hls_parameters params)
{
	DIR *list_of_dir;
	struct dirent *current_file;
	char fullpath[256];

	list_of_dir = opendir(params.path);
	errno = 0;
	if (list_of_dir == NULL)
	{
		switch(errno)
		{
			case EACCES:
			      return (2);
			case ENOENT:
			      return (3);
			case ENOTDIR:
			      return (4);
			default:
			      return (1);
		}

	}
	
	while ((current_file = readdir(list_of_dir)) != NULL)
	{

		if (params.almost_all)
		{
			if (strcmp(current_file->d_name, ".") == 0 || strcmp(current_file->d_name, "..") == 0)
			{
				continue;
			}
		}
		else if (!params.hidden_file && current_file->d_name[0] == '.')
		{
			continue;
		}


		if (params.more_info)
		{
			strcpy(fullpath, params.path);
			if (params.path[strlen(params.path)] != '/')
			{
				strcat(fullpath, "/");
			}

			strcat(fullpath, current_file->d_name);

			if (get_file_info(fullpath) == 1)
			{
				return (1);
			}
		 }


		printf("%s", current_file->d_name);
		if (params.by_the_line || params.more_info)
		{
			putchar('\n');
		}
		else
		{
			putchar('\t');
		}
	}
	if (!params.by_the_line && !params.more_info)
	{
		putchar('\n');
	}
	
	closedir(list_of_dir);

	return (0);
}
