#ifndef UPDATER_H
# define UPDATER_H

/*
** On récupère les types qu'on concatène selon le fichier reçu en param
 */

void conc_old(char *);
void conc_new(char *);

/*
** Concatène des chaines pour télécharger le fichier de version concerné
** L'une des fonctions est pour linux l'autre pour windows
*/

void runbatchlinux(char *);
void runbatchwindows(char *);

#endif
