#ifndef FILE_SYSTEM_H_
#define FILE_SYSTEM_H_

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "./hls.h"

void file_info_print(struct stat, struct group *, struct passwd *, char *);
int get_file_info(char *);
int print_files(hls_parameters, char *);
int show_files(hls_parameters);

#endif
