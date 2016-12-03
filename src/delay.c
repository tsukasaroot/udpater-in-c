/*
** delay.c for delay in /home/jordan.roucom/updater-in-c
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 14:08:36 2016 Jordan Rouco miguez
** Last update Tue Oct 18 14:11:30 2016 Jordan Rouco miguez
*/

#include <time.h>
#include "../include/main.h"

void    delay(unsigned int ms)
{
  ///Créé un délai, utilisations diverses
  clock_t goal = ms + clock();
  while (goal > clock());
}
