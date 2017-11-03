#include "UPDATER.h"

void display_version(float nb1, float nb2, char *name)
{
	fprintf(stdout, "Version installee precedement %s.xp3 : %f\n", nb1, name);
	fprintf(stdout, "Version actuelle %s.xp3              : %f\n\n", nb2, name);
}

void remove_useless_files()
{
	remove("newevimage.ver");
	remove("newdata.ver");
	remove("newimage.ver");
	remove("NUL");
	
}
