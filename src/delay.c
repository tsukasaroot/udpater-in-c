#include <time.h>

void delay(unsigned int ms)
{
	clock_t goal = ms + clock();
	while (goal > clock());
}
