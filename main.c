#include <stdlib.h>
#include <stdio.h>

int	main()
{
  if(system("ping -c 1 www.google.com &>/dev/null") == 0)
    printf("C'est bon");
  else
    printf("C'est pas bon");
  return (0);
}
