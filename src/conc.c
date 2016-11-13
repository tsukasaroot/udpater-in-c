/*
** conc_xp3.c for conc_xp3 in /home/jordan.roucom/updater-in-c
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Wed Oct 19 10:58:17 2016 Jordan Rouco miguez
** Last update Sun Nov 13 15:03:44 2016 Jordan Rouco miguez
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	conc_old(char *type)
{
  char	*VERSIONS = "VERSIONS/", tmp[100], *cpy = NULL;

  strcat(type, ".ver");       //On créée le chemin pour le fichier .ver actuellement installée
  strcpy(tmp, VERSIONS);
  strcat(tmp, type);
  strcpy(type, tmp);
  cpy = malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(cpy, type);
}

void	conc_new(char *newtype)
{
  char	*VERSIONS = "VERSIONS/", tmp[100], *cpy = NULL;

  strcpy(tmp, VERSIONS);      //On créée le chemin pour le fichier .ver téléchargé
  strcat(newtype, ".ver");
  strcat(tmp, newtype);
  strcpy(newtype, tmp);
  cpy = malloc(sizeof(char) * (strlen(newtype) + 1));
  strcpy(cpy, newtype);
}
