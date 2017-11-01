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
	strcat(cmd, ".xp3 > NUL");
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
		if (datas->version < datas->nversion)
			return (1);
		else
			return (0);
	} else {
		fprintf(stdout, "Fichier téléchargé introuvable\n");
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
	strcat(cmd, ".ver > NUL");
	system(cmd);
	if (check_newver(path, datas) == 1)
		get_patch(path, datas);
	else
		return (0);
	return (0);
}

void check_dir()
{
	if (access("VERSIONS", 0) == -1)
		system("mkdir VERSIONS");
}

int main()
{
	datas datas;
	float v1;
	float v1_1;
	float v2;
	float v2_1;

	datas.site = malloc(sizeof(char) * (32 + 1));
	datas.site = "https://www.dothackers-fansub.fr";
	if (system("ping -c 2 www.dothackers-fansub.fr > NUL") != 0) {
		fprintf(stdout, "Erreur reseau !\n Verifiez que vous soyez connectes et retentez.\n \
Si apres un nouveau test, vous avez de nouveau ce message d'erreur, \nle site est en maintenance ou rencontre \
des problemes de connection.\n");
		return (-1);
	}
	fprintf(stdout, "-----------------------------------------------------------------\n\n");
	check_dir();
	get_ver("evimage", &datas);
	clrscr();
	v1 = datas.version;
	v1_1 = datas.nversion;
	get_ver("data", &datas);
	clrscr();
	v2 = datas.version;
	v2_1 = datas.nversion;
	get_ver("image", &datas);
	clrscr();
	display_version(v1, v1_1, "evimage");
	display_version(v2, v2_1, "image");
	display_version(datas.version, datas.nversion, "data");
	remove_useless_files();
	system("wine gsen.exe");
	return (0);
}
