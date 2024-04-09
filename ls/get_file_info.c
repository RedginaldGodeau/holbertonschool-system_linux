#include "./file_system.h"


int get_file_info(char *fullpath)
{
	struct stat file_stat;
	struct group *grp;
	struct passwd *pwd;
	struct tm date;
	char formatted_date[40];

	if (!stat(fullpath, &file_stat))
	{
		printf((S_ISDIR(file_stat.st_mode))  ? "d" : "-");
		printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
		printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
		printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
		printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
		printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
		printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
		printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
		printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
		printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
		putchar(' ');
		
		printf("%ld ", file_stat.st_nlink);

		pwd = getpwuid(file_stat.st_uid);
		printf("%s ", pwd->pw_name);

		grp = getgrgid(file_stat.st_gid);
		printf("%s ", grp->gr_name);

		printf("%6ld ", file_stat.st_size);
		
		gmtime_r(&file_stat.st_mtim.tv_sec, &date);
		strftime(formatted_date, 40, "%b %d %H:%M", &date);

		printf("%s ", formatted_date);
	}
	else
	{
		return (1);
	}

	return (0);
}
