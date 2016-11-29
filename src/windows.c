/*
** linux.c for linux  in /home/jordan.roucom/updater-in-c
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Wed Oct 19 10:43:19 2016 Jordan Rouco miguez
** Last update Mon Nov 28 14:43:34 2016 Jordan Rouco miguez
*/

#include "../include/main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*On concatène et copie les chaines afin de pouvoir       
  créer le fichier de version: prototype ->               
  on copie la commande dans un tmp, on                    
  ajoute le type au tmp, puis l'extension,                
  et enfin on copie le tmp dans cmd*/

void    runbatchwindows(char *type)
{
  ///Permet en concaténant les chaines, d'ouvrir le site web et de télécharger la donnée envoyée
  char  cmd1[100] = "wget http://dothackers.fansub.ovh/VERSIONS/",
    cmd2[100] = "MOVE ", *dir = " VERSIONS\\", tmp[100];

  strcpy(tmp, cmd1);
  strcat(tmp, type);
  strcat(tmp, ".ver > NUL");
  strcpy(cmd1, tmp);
  system(cmd1);
  system("MKDIR VERSIONS");
  strcat(cmd2, type);
  strcat(cmd2, ".ver > NUL");
  strcat(cmd2, dir);
  system(cmd2);
}
