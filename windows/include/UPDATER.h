#ifndef UPDATER_H
# define UPDATER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "color.h"

typedef struct datas
{
	float version;
	float nversion;
	char *site;
}	datas;

void display_version(float nb1, float nb2, char *name);
void remove_useless_files();
int get_ver(char *path, datas *datas);
int get_patch(char *path, datas *datas);
int get_file(char *path, datas *datas);

#endif
