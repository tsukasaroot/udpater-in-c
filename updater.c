#include "include/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	openingfiles(FILE* newpatch, FILE* actualpatch, char *newtype, char *type, char *typedata, char os)
{
  ///Ouvre les fichiers en concaténant les variables, les envoies dans la fonction runbatch, puis fait les opé nécessaires
  char	*VERSIONS = "VERSIONS/", tmp[100];
  int	newver, actualver;

  if (os == 'L')
    runbatchlinux(newtype);
  else
    runbatchwindows(newtype);

  strcat(typedata, ".xp3");
  conc_new(newtype);
  conc_old(type);
  newpatch = fopen(newtype, "r+");
  printf("\n\n%s\n\n", newtype);
  if (newpatch != NULL)   //On ouvre le .ver téléchargé
    {
      actualpatch = fopen(type, "rw+");
      if (actualpatch != NULL)    //On ouvre le .ver actuellement valable
	{
	  fscanf(newpatch, "%d", &newver);    //On récupère les chiffres sous forme integer afin de pouvoir les comparer
	  fscanf(actualpatch, "%d", &actualver);
	  printf("Nouvelle version : %d \nVersion actuelle : %d\n\n", newver, actualver);
	  if (newver > actualver)
	    {
	      char	cmd[100] = "wget http://dothackers.fansub.ovh/update/";
	      strcat(cmd, typedata);
	      remove(typedata);
	      if (system(cmd) == 1)
		printf("Erreur du téléchargement de la nouvelle version");
	      delay(9000);
	    }
	  else if (newver == actualver)
	    {
	      printf("   %s est a jour", typedata);
	    }
	  else
	    printf("   %s est maintenant a jour", typedata);
	  fclose(actualpatch);
	}
      else        //On créée une version à 1 et on télécharge le fichier concerné
	{
	  actualpatch = fopen(type, "w+");
	  fputs("1", actualpatch);
	  char	cmd[100] = "wget http://dothackers.fansub.ovh/update/";
	  strcat(cmd, typedata);
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
      rename(newtype, type);
    }
  else
    printf("Erreur d'ouverture du fichier de version.\nVerifiez vos parametres internet.");
}

int	main()
{
  ///On ouvre les différents fichiers un par un

  FILE	*newpatch = NULL;
  FILE	*actualpatch = NULL;
  char	newtype1[100] = "newGsen", type1[100] = "Gsen", typedata[100] = "data", newtype2[100] = "newImage", type2[100] = "Image", typedata2[100] = "image", newtype3[100] = "newEvimage", type3[100] = "Evimage", typedata3[100] = "evimage";
  char	os;

  if (system("lsb_release -a") == 0)
    os = 'L';
  else
    {
      printf("WINDOWS\n\n");
      os = 'W';
    }
  openingfiles(newpatch, actualpatch, newtype1, type1, typedata, os);
  printf("\n\n");
  delay(2);
  openingfiles(newpatch, actualpatch, newtype2, type2, typedata2, os);
  printf("\n\n");
  delay(2);
  openingfiles(newpatch, actualpatch, newtype3, type3, typedata3, os);
  printf("\n\n");
  delay(2);
  if (os == 'W')
    system("START gstring.exe");    //Démarre le jeu puis quitte la console
  else
    system("wine gstring.exe");
  return (0);
}
