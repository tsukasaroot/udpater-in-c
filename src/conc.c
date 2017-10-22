#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
** On récupère le type de l'ancienne version et le nouveau
** type qu'on concatène avec les différents 's'
*/

void conc_old(char *type)
{
	char *VERSIONS = "VERSIONS/", tmp[100];

	strcat(type, ".ver");
	strcpy(tmp, VERSIONS);
	strcat(tmp, type);
	strcpy(type, tmp);
}

void conc_new(char *newtype)
{
	char *VERSIONS = "VERSIONS/", tmp[100];

	strcpy(tmp, VERSIONS);
	strcat(newtype, ".ver");
	strcat(tmp, newtype);
	strcpy(newtype, tmp);
}
