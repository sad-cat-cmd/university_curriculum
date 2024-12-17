#include <stdlib.h>
#include <time.h>

int random(int n)
{
	return (rand()*n/(RAND_MAX+1));
}
void main()
{ 
	int A;	
	srand(time(0));
	A=random(19);
	printf(" %d", A);
        getch();
}