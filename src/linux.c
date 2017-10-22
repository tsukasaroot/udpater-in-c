#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void runbatchlinux(char *type)
{
	char cmd1[100] = "wget http://dothackers-fansub.fr/VERSIONS/",
		cmd2[100] = "mv ", *dir = " VERSIONS\\", tmp[100];

	strcpy(tmp, cmd1);
	strcat(tmp, type);
	strcat(tmp, ".ver &>./tmp");
	strcpy(cmd1, tmp);
	system(cmd1);
	system("mkdir VERSIONS &>./tmp");
	strcat(cmd2, type);
	strcat(cmd2, ".ver &>./tmp");
	strcat(cmd2, dir);
	system(cmd2);
}
