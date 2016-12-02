/*
** main.h for main_H in /home/jordan.roucom/updater-in-c
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 14:21:02 2016 Jordan Rouco miguez
** Last update Wed Nov 30 14:12:48 2016 Jordan Rouco miguez
*/

#ifndef DEL_H_
# define DEL_H_

void	delay(unsigned int ms);
void	runbatchlinux(char *type);
void	runbatchwindows(char *type);
char	conc_new(char *newtype);
char	conc_old(char *type);

#endif /* !DEL_H_ */
