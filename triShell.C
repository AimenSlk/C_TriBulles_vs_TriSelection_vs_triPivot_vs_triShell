#include "/usr/local/public/BIBLIOC++/chaine.h"
#include "tableau.h"
#include <stdlib.h>
#include <time.h>
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

// tri le tableau t de n entiers par la methode du tri Shell
// necessite 1 <= n <= LG_MAX
void trierShell (Tableau t, const int n, int &nbA, int &nbC) throw (Chaine);


int main()
{
	int nbA=0;
	int nbC=0;
	int moyennenbC=0;
	int moyennenbA=0;
	for (int i=1; i <= 300 ; i++)
	{	
		for (int b=1; b <= 100 ; b++)
			{
    				Tableau t;
				const int LG = i;
    				srandom(time(NULL));
   				 remplirTableau (t, LG);
   				 trierShell (t, LG,nbA,nbC);
				moyennenbA +=nbA;
				moyennenbC +=nbC;
				nbA=0;
				nbC=0;
			}
		moyennenbC =moyennenbC/100;
		moyennenbA =moyennenbA/100;
		ecrire(i);
	ecrire(uneChaine(" "));
	ecrire(moyennenbA);
	ecrire(uneChaine(" "));
	ecrireNL(moyennenbC);
			
	}
}

// tri le tableau t de n entiers par la methode du tri Shell
// necessite 1 <= n <= LG_MAX
void trierShell (Tableau t, const int n, int &nbA, int &nbC) throw (Chaine)
{
    int inc = n / 2;
    int j;

    if (n < 1 || n > LG_MAX)
    {
        throw (uneChaine ("VALEUR_INCORRECTE"));
    }
    while (inc > 0)
    {
        for (int i = inc + 1; i <= n; i++)
        {
            j = i - inc - 1;
            while (j >= 0)
            {
		nbC++;
                if (t[j] > t[j+inc])
                {
                    const int aux = t[j];
                    t[j] = t[j+inc];
                    t[j+inc] = aux;
                    j = j - inc;
		    nbA += 3;
                }
                else
                {
                    j = -1;
                }
            }
        }
        inc = inc / 2;
    }
}
