/*
** linux.c for linux  in /home/jordan.roucom/updater-in-c
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Wed Oct 19 10:43:19 2016 Jordan Rouco miguez
** Last update Thu Oct 19 16:49:04 2017 Tsukasa
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/main.h"

/*
** On concatène et copie les chaines afin de pouvoir
** créer le fichier de version: prototype ->
** on copie la commande dans un tmp, on
** ajoute le type au tmp, puis l'extension,
** et enfin on copie le tmp dans cmd
*/

void    runbatchwindows(char *type)
{
  ///Permet en concaténant les chaines, d'ouvrir le site web et de télécharger la donnée envoyée
  char  cmd1[100] = "wget http://dothackers-fansub.fr/VERSIONS/",
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
