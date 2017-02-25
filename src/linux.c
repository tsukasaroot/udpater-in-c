/*
** linux.c for linux in /home/jordan.roucom/updater-in-c
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Wed Oct 19 10:45:29 2016 Jordan Rouco miguez
** Last update Fri Dec  2 15:46:33 2016 Jordan Rouco miguez
*/

#include "../include/main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
** On concatène et copie les chaines afin de pouvoir créer le fichier de version: prototype ->
** on copie la commande dans un tmp, on ajoute le type au tmp, puis l'extension,
** et enfin on copie le tmp dans cmd
*/

void    runbatchlinux(char *type)
{
  ///Permet en concaténant les chaines, d'ouvrir le site web et de télécharger la donnée envoyée
  char  cmd1[100] = "wget http://dothackers-fansub.xyz/VERSIONS/",
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
