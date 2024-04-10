#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include "./hls_parameters.h"

int show_file(hls_parameters, char *);
int print_files(hls_parameters, char *, char *);
int more_details(char *, char *);
void print_more_details(struct stat, struct group *, struct passwd *, char *);
#endif
