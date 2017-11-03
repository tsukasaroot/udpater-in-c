#include "UPDATER.h"

int get_ver(char *path, datas *datas)
{
	FILE *fd = NULL;
	char version_path[100] = "VERSIONS/";
	char cmd[100] = "MOVE ";
	char cmd2[100] = "wget.exe ";

	strcat(version_path, path);
	strcat(version_path, ".ver");
	fd = fopen(version_path, "r+");
	if (fd != NULL) {
		fscanf(fd, "%f", &datas->version);
		get_file(path, datas);
		strcat(cmd, "new");
		strcat(cmd, path);
		strcat(cmd, ".ver ");
		strcat(cmd, version_path);
		system(cmd);
		fclose(fd);
	} else {
		get_patch(path, datas);
		strcat(cmd2, datas->site);
		strcat(cmd2, "/VERSIONS/");
		strcat(cmd2, "new");
		strcat(cmd2, path);
		strcat(cmd2, ".ver");
		system(cmd2);
		strcat(cmd, "new");
		strcat(cmd, path);
		strcat(cmd, ".ver ");
		strcat(cmd, version_path);
		system(cmd);
	}
	return (0);
}
