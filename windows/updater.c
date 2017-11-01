#include "UPDATER.h"

int get_patch(char *path, datas *datas)
{
	char cmd[100] = "wget ";
	char tpe[50];

	strcat(tpe, path);
	strcat(tpe, ".xp3");
	remove(tpe);
	strcat(cmd, datas->site);
	strcat(cmd, "/update/");
	strcat(cmd, path);
	strcat(cmd, ".xp3 --no-check-certificate");
	system(cmd);
	return (0);
}

int check_newver(char *path, datas *datas)
{
	FILE *fd = NULL;
	char type[100] = "new";

	strcat(type, path);
	strcat(type, ".ver");
	fd = fopen(type, "r");
	if (fd != NULL) {
		fscanf(fd, "%f", &datas->nversion);
		fprintf(stdout, "%s -> \n		Version actuelle : %f\n\n", path, datas->version);
		fprintf(stdout, "		Version en ligne : %f\n\n", datas->nversion);
		if (datas->version < datas->nversion)
			return (1);
		else
			return (0);
	} else {
		fprintf(stdout, "Fichier telecharge introuvable\n");
		return (-1);
	}
	return (0);
}

int get_file(char *path, datas *datas)
{
	char cmd[100] = "wget ";

	strcat(cmd, datas->site);
	strcat(cmd, "/VERSIONS/");
	strcat(cmd, "new");
	strcat(cmd, path);
	strcat(cmd, ".ver");
	system(cmd);
	if (check_newver(path, datas) == 1)
		get_patch(path, datas);
	else
		return (0);
	return (0);
}

int get_ver(float *version, char *path, datas *datas)
{
	FILE *fd = NULL;
	char version_path[100] = "VERSIONS/";
	char cmd[100] = "MOVE ";
	char cmd2[100] = "wget ";

	strcat(version_path, path);
	strcat(version_path, ".ver");
	fd = fopen(version_path, "r+");
	if (fd != NULL) {
		fscanf(fd, "%f", version);
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

void check_dir()
{
	if (access("VERSIONS", 0) == -1)
		system("MD VERSIONS");
}

int main()
{
	datas datas;

	datas.site = malloc(sizeof(char) * (32 + 1));
	datas.site = "https://www.dothackers-fansub.fr";
	if (system("ping -n 1 www.dothackers-fansub.fr 2> NUL") != 0) {
		fprintf(stdout, "Erreur reseau !\n Verifiez que vous soyez connectes et retentez.\n \
Si après un nouveau test, vous avez de nouveau ce message d'erreur, \nle site est en maintenance ou rencontre \
des problemes de connection.\n");
		return (-1);
	}
	fprintf(stdout, "-----------------------------------------------------------------\n\n");
	get_ver(&datas.version, "evimage", &datas);
	get_ver(&datas.version, "data", &datas);
	get_ver(&datas.version, "image", &datas);
	remove("newevimage.ver");
	remove("newdata.ver");
	remove("newimage.ver");
	remove("NUL");
	return (0);
}
