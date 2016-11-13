/*
** main.h for main_H in /home/jordan.roucom/updater-in-c
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 14:21:02 2016 Jordan Rouco miguez
** Last update Wed Oct 19 13:14:03 2016 Jordan Rouco miguez
*/

#ifndef DELAY_H_
#define DELAY_H_

void	delay(unsigned int ms);
void	runbatchlinux(char *type);
void	runbatchwindows(char *type);
char	conc_new(char *newtype);
char	conc_old(char *type);

#endif
