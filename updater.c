#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(unsigned int ms)
{
    ///Créé un délai, utilisations diverses

    clock_t goal = ms + clock();
    while (goal > clock());
}

void runbatch(char *type)
{
    ///Permet en concaténant les chaines, d'ouvrir le site web et de télécharger la donnée envoyée

    char cmd1[100] = "wget http://dothackers.fansub.ovh/VERSIONS/", cmd2[100] = "MOVE ", *dir = " VERSIONS\\";
    char tmp[100];

    //On concatène et copie les chaines afin de pouvoir créer le fichier de version: prototype -> on copie la commande dans un tmp, on ajoute le type au tmp, puis l'extension, et enfin on copie le tmp dans cmd

    strcpy(tmp, cmd1);
    strcat(tmp, type);
    strcat(tmp, ".ver");
    strcpy(cmd1, tmp);

    printf("\n%s\n", cmd1);
    system(cmd1);



    system("MKDIR VERSIONS");

    strcat(cmd2, type);
    strcat(cmd2, ".ver");
    strcat(cmd2, dir);

    printf("%s", cmd2);
    system(cmd2);

    //Quasiment le même principe qu'au dessus
}

void OpeningFiles(FILE* newpatch, FILE* actualpatch, char *newtype, char *type, char *typedata)
{
    ///Ouvre les fichiers en concaténant les variables, les envoies dans la fonction runbatch, puis fait les opé nécessaires

    char *VERSIONS = "VERSIONS/", tmp[100];
    int newver, actualver;

    runbatch(newtype);

    strcat(typedata, ".xp3");

    printf("   %s\n", typedata);

    strcpy(tmp, VERSIONS);      //On créée le chemin pour le fichier .ver téléchargé
    strcat(newtype, ".ver");
    strcat(tmp, newtype);
    strcpy(newtype, tmp);

    printf("   %s\n", newtype);

    strcat(type, ".ver");       //On créée le chemin pour le fichier .ver actuellement installée
    strcpy(tmp, VERSIONS);
    strcat(tmp, type);
    strcpy(type, tmp);

    printf("   %s\n", type);

    newpatch = fopen(newtype, "r+");

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
                char cmd[100] = "wget http://dothackers.fansub.ovh/update/";

                strcat(cmd, typedata);

                remove(typedata);

                if (system(cmd) == 1)
                {
                    printf("Erreur du téléchargement de la nouvelle version");
                    delay(9000);
                }
            }
            else if (newver == actualver)
            {
                printf("   %s est a jour", typedata);
            }
            else
            {
                printf("   %s est maintenant a jour", typedata);
            }

            fclose(actualpatch);
        }
        else        //On créée une version à 1 et on télécharge le fichier concerné
        {
            actualpatch = fopen(type, "w+");
            fputs("1", actualpatch);

            char cmd[100] = "wget http://dothackers.fansub.ovh/update/";

                strcat(cmd, typedata);

                printf("%s", cmd);

                remove(typedata);
                if (system(cmd) == 1)
                {
                    printf("Erreur du téléchargement de la nouvelle version");
                }
            else
            {
                printf("   %s est maintenant a jour\n", typedata);
            }

            fclose(actualpatch);
        }
        fclose(newpatch);

        remove(type);
        rename(newtype, type);
    }
    else
    {
        printf("Erreur d'ouverture du fichier de version. \nVérifiez vos paramètres internet.");
    }

}

int main()
{
    ///On ouvre les différents fichiers un par un

    FILE* newpatch = NULL;
    FILE* actualpatch = NULL;

    char newtype1[100] = "newGsen", type1[100] = "Gsen", typedata[100] = "data", newtype2[100] = "newImage", type2[100] = "Image", typedata2[100] = "image", newtype3[100] = "newEvimage", type3[100] = "Evimage", typedata3[100] = "evimage";

    OpeningFiles(newpatch, actualpatch, newtype1, type1, typedata);

    printf("\n\n");
    delay(2);

    OpeningFiles(newpatch, actualpatch, newtype2, type2, typedata2);

    printf("\n\n");
    delay(2);

    OpeningFiles(newpatch, actualpatch, newtype3, type3, typedata3);

    printf("\n\n");
    delay(2);

    system("START gstring.exe");    //Démarre le jeu puis quitte la console
    return 0;
}
