#include "./file_system.h"

/**
 * get_file_info - get file info
 * @fullpath: string
 *
 * Description: get file info
 * Return: 1 or 0
*/
int get_file_info(char *fullpath)
{
	struct stat file_stat;
	struct group *grp;
	struct passwd *pwd;
	struct tm date;
	char formatted_date[40];

	if (!stat(fullpath, &file_stat))
	{
		pwd = getpwuid(file_stat.st_uid);
		grp = getgrgid(file_stat.st_gid);
		gmtime_r(&file_stat.st_mtim.tv_sec, &date);
		strftime(formatted_date, 40, "%b %d %H:%M", &date);

		file_info_print(file_stat, grp, pwd, formatted_date);
	}
	else
	{
		return (1);
	}
	return (0);
}
