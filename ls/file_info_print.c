#include "./file_system.h"

/**
 * file_info_print - print info of file
 * @file_stat: stat
 * @grp: group
 * @pwd: passwd
 * @formatted_date: string
 *
 * Description: print info of file
*/
void file_info_print(
		struct stat file_stat,
		struct group *grp, struct passwd *pwd,
		char *formatted_date
)
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
		printf("%s ", pwd->pw_name);
		printf("%s ", grp->gr_name);
		printf("%6ld ", file_stat.st_size);
		printf("%s ", formatted_date);
}
