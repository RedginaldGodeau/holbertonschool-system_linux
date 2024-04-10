#include "./filesystem.h"

/**
 * function_name - print details
 * @sta: stat
 * @grp: group
 * @pwd: passwd
 * @date: string
 *
 * Description: print details
*/
void print_more_details(struct stat sta, struct group *grp, struct passwd *pwd,
		char *date
		)
{
	printf((S_ISDIR(sta.st_mode))  ? "d" : "-");
	printf((sta.st_mode & S_IRUSR) ? "r" : "-");
	printf((sta.st_mode & S_IWUSR) ? "w" : "-");
	printf((sta.st_mode & S_IXUSR) ? "x" : "-");
	printf((sta.st_mode & S_IRGRP) ? "r" : "-");
	printf((sta.st_mode & S_IWGRP) ? "w" : "-");
	printf((sta.st_mode & S_IXGRP) ? "x" : "-");
	printf((sta.st_mode & S_IROTH) ? "r" : "-");
	printf((sta.st_mode & S_IWOTH) ? "w" : "-");
	printf((sta.st_mode & S_IXOTH) ? "x" : "-");
	putchar(' ');
	printf("%ld ", sta.st_nlink);
	printf("%s ", pwd->pw_name);
	printf("%s ", grp->gr_name);
	printf("%6ld ", sta.st_size);
	printf("%s ", date);
}
