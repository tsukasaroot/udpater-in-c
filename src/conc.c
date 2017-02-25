/*
** conc_xp3.c for conc_xp3 in /home/jordan.roucom/updater-in-c
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Wed Oct 19 10:58:17 2016 Jordan Rouco miguez
** Last update Fri Nov 25 16:42:39 2016 Jordan Rouco miguez
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/main.h"

/*
** On récupère le type de l'ancienne version et le nouveau
** type qu'on concatène avec les différents 's'
*/

void	conc_old(char *type)
{
  char	*VERSIONS = "VERSIONS/", tmp[100];

  strcat(type, ".ver");
  strcpy(tmp, VERSIONS);
  strcat(tmp, type);
  strcpy(type, tmp);
}

void	conc_new(char *newtype)
{
  char	*VERSIONS = "VERSIONS/", tmp[100];

  strcpy(tmp, VERSIONS);
  strcat(newtype, ".ver");
  strcat(tmp, newtype);
  strcpy(newtype, tmp);
}
