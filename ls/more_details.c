#include "./filesystem.h"

/**
 * more_details - get values for print details
 * @path: string
 * @file_name: string
 *
 * Description: get values for print details
 * Return: 0 or 1
 */
int more_details(char *path, char *file_name)
{
	char *fullpath = malloc(strlen(path) + strlen(file_name));
	struct stat f_stat;
	struct group *grp;
	struct passwd *pwd;
	struct tm date;
	char formatted_date[40];

	strcpy(fullpath, path);
	if (path[strlen(path)] != '/')
		strcat(fullpath, "/");
	strcat(fullpath, file_name);
	if (!stat(fullpath, &f_stat))
	{
		pwd = getpwuid(f_stat.st_uid);
		grp = getgrgid(f_stat.st_gid);
		gmtime_r(&f_stat.st_mtim.tv_nsec, &date);
		strftime(formatted_date, 40, "%b %d %H:%M", &date);
		print_more_details(f_stat, grp, pwd, formatted_date);
	}
	else
	{
		free(fullpath);
		return (1);
	}
	free(fullpath);
	return (0);
}
