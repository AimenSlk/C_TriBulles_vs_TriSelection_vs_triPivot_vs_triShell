#include "/usr/local/public/BIBLIOC++/chaine.h"
#include "tableau.h"
#include <stdlib.h>
#include <time.h>
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

// tri le tableau t de n entiers par la methode du tri rapide
// necessite 1 <= n <= LG_MAX
void trierPivot (Tableau t, const int n, int &nbA, int &nbC) throw (Chaine);

// tri recursif de la tranche iDeb..iFin du tableau t
void trierTranche (Tableau t, const int iDeb, const int iFin, int &nbA, int &nbC);

int main()
{
	int nbA=0;
	int nbC=0;
	int moyennenbC=0;
	int moyennenbA=0;
	for (int i=1; i <= 300
 ; i++)
	{	
		for (int b=1; b <= 100 ; b++)
			{
    				Tableau t;
				const int LG = i;
    				srandom(time(NULL));
   				 remplirTableau (t, LG);
   				 trierPivot (t, LG,nbA,nbC);
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
// tri le tableau t de n entiers par la methode du tri rapide
// necessite 1 <= n <= LG_MAX
void trierPivot (Tableau t, const int n, int &nbA, int &nbC) throw (Chaine)
{
    if (n < 1 || n > LG_MAX)
    {
        throw (uneChaine ("VALEUR_INCORRECTE"));
    }
    trierTranche (t, 0, n-1,nbA,nbC);
}

// tri recursif de la tranche iDeb..iFin du tableau t
void trierTranche (Tableau t, const int iDeb, const int iFin, int &nbA, int &nbC)
{
    int i = iDeb;
    int j = iFin;
    int pivot;
    if (i < j)
    {
        pivot = t[i];
	nbA++;
        while (i < j)
        {
	nbC++;
            if (t[j] >= pivot)
            {
                j--;
            }
            else
            {
                if (t[i+1] < pivot)
                {
                    t[i] = t[i+1];
                    i++;
			nbA++;
                }
                else
                {
                    t[i] = t[j];
                    t[j] = t[i+1];
                    i++;
                    j--;
			nbA=nbA+2;
                }
            }
        }
        t[i] = pivot;
        trierTranche (t, iDeb, i-1, nbA, nbC);
        trierTranche (t, i+1, iFin, nbA, nbC);
    }
}
