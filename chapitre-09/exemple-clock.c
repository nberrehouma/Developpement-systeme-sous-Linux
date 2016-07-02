// ------------------------------------------------------------------
// exemple-clock.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void    action_a_mesurer        (void);
    
int main (void)
{
	clock_t debut_programme;
	double  duree_ecoulee;

	debut_programme = clock();

	action_a_mesurer();

	duree_ecoulee = clock() - debut_programme;
	duree_ecoulee = duree_ecoulee / CLOCKS_PER_SEC;
	fprintf(stdout, "Duree = %f \n", duree_ecoulee);
	return EXIT_SUCCESS;
}

void action_a_mesurer (void)
{
	int i, j;
	FILE * fp1, * fp2;
	double x = 0.0;

	for (i = 0; i < 30000; i ++)
		for (j = 0; j < 30000; j ++)
			x += i * j;
	for (i = 0; i < 50000; i ++) {
		if ((fp1 = fopen ("exemple_setitimer_2", "r")) != NULL) {
			if ((fp2 = fopen("/dev/null", "w")) != NULL) {
				while (fread(& j, sizeof (int), 1, fp1) == 1)
					fwrite(& j, sizeof (int), 1, fp2);
				fclose(fp2);
			}
			fclose(fp1);
		}
	}
}


