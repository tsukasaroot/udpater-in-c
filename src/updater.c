#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UPDATER.h"

void openingfiles(FILE* newpatch, FILE* actualpatch, char *newtype, char *type, char *typedata, char os)
{
	///Ouvre les fichiers en concaténant les variables, les envoies dans la fonction runbatch, puis fait les opé nécessaires
	int newver, actualver;

	if (os == 'L')
		runbatchlinux(newtype);
	else
		runbatchwindows(newtype);
	strcat(typedata, ".xp3");
	conc_new(newtype);
	conc_old(type);
	newpatch = fopen(newtype, "r+");
	if (newpatch != NULL) {
		actualpatch = fopen(type, "rw+");
		if (actualpatch != NULL) {
			fscanf(newpatch, "%d", &newver);
			fscanf(actualpatch, "%d", &actualver);
			printf("Nouvelle version : %d \nVersion actuelle : %d\n\n", newver, actualver);
			if (newver > actualver) {
				char cmd[100] = "wget http://dothackers-fansub.fr/update/";
				strcat(cmd, typedata);
				strcat(cmd, " --no-check-certificate");
				remove(typedata);
				if (system(cmd) == 1)
					printf("Erreur du téléchargement de la nouvelle version");
			}
			else if (newver == actualver) {
				printf("   %s est a jour", typedata);
			}
			else
				printf("   %s est maintenant a jour", typedata);
			fclose(actualpatch);
		}
		else {
			//On créée une version à 1 et on télécharge le fichier concerné
			actualpatch = fopen(type, "w+");
			fputs("1", actualpatch);
			char cmd[100] = "wget http://dothackers-fansub.fr/update/";
			strcat(cmd, typedata);
			strcat(cmd, " --no-check-certificate");
			printf("%s", cmd);
			remove(typedata);
			if (system(cmd) == 1)
				printf("Erreur du telechargement de la nouvelle version");
			else
				printf("   %s est maintenant a jour\n", typedata);
			fclose(actualpatch);
		}
		fclose(newpatch);
		remove(type);
		remove("newGsen.ver.1");
		rename(newtype, type);
	}
	else
		printf("Erreur d'ouverture du fichier de version.\nVerifiez vos parametres internet.");
}

/*
** Ouverture des fichiers puis traintement, enfin on lance le jeu.
** Si traitement impossible, on lance le jeu.
*/

int main()
{
	///On ouvre les différents fichiers un par un

	FILE *newpatch = NULL;
	FILE *actualpatch = NULL;
	char newtype1[100] = "newGsen", type1[100] = "Gsen", typedata[100] = "data", newtype2[100] = "newImage", type2[100] = "Image", typedata2[100] = "image", newtype3[100] = "newEvimage", type3[100] = "Evimage", typedata3[100] = "evimage";
	char	os;

	system("wget http://dothackers-fansub.fr/VERSIONS/newGsen.ver --no-check-certificate");
	if (system("lsb_release -a") == 0) {
		if (system("sudo ping -c 1 www.dothackers-fansub.fr\n") != 0) {
			printf("Erreur réseau !");
			system("wine gstring.exe");
			return (0);
		}
		os = 'L';
	}
	else {
		if (system("ping -n 1 www.dothackers-fansub.fr\n 2> NUL") != 0) {
			printf("Erreur reseau !\n");
			system("START gstring.exe");
			return (0);
		}
		os = 'W';
	}
	openingfiles(newpatch, actualpatch, newtype1, type1, typedata, os);
	printf("\n\n");
	openingfiles(newpatch, actualpatch, newtype2, type2, typedata2, os);
	printf("\n\n");
	openingfiles(newpatch, actualpatch, newtype3, type3, typedata3, os);
	printf("\n\n");
	if (os == 'W')
		system("START gstring.exe");
	else
		system("wine gstring.exe");
	return (0);
}
