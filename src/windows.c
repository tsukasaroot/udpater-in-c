#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void runbatchwindows(char *type)
{
	char cmd1[100] = "wget http://dothackers-fansub.fr/VERSIONS/",
		cmd2[100] = "MOVE ", *dir = " VERSIONS\\", tmp[100];

	strcpy(tmp, cmd1);
	strcat(tmp, type);
	strcat(tmp, ".ver 2> NUL");
	strcpy(cmd1, tmp);
	strcat(cmd1, " --no-check-certificate");
	system(cmd1);
	system("MKDIR VERSIONS 2> NUL");
	strcat(cmd2, type);
	strcat(cmd2, ".ver 2> NUL");
	strcat(cmd2, dir);
	system(cmd2);
}
