#include "/usr/local/public/BIBLIOC++/chaine.h"
#include "/home/fln1147a/Dev2/tris/tableau.h"
#include <stdlib.h>
#include <time.h>
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"



void trierSelection (Tableau t, const int n, int &nbA, int &nbC) throw (Chaine);
void position (Tableau t, const int n, int b, int bi, int &nbA, int &nbC, int c);

int main()
{
	int nbA=0;
	int nbC=0;
	int moyennenbC=0;
	int moyennenbA=0;
	for (int i=2; i <= 300; i++)
	{	
		for (int b=1; b <= 100 ; b++)
			{
    				Tableau t;
				const int LG = i;
    				srandom(time(NULL));
   				 remplirTableau (t, LG);
   				 trierSelection (t, LG, nbA, nbC);
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

// tri le tableau t de n entiers par la methode des bulles
// necessite 1 <= n <= LG_MAX
void position (Tableau t, const int n, int b, int bi, int &nbA, int &nbC, int c)
{
	b=t[c];
	bi=c;
	for (int i=c; i <= n; i++, nbC++)
	{
		if (t[i] < b )
		{
			b=t[i];
			bi=i;
			nbA= nbA+2;
		}
	}
}

void trierSelection (Tableau t, const int n, int &nbA, int &nbC) throw (Chaine)
{
	int b=0;
	int bi=0;
    if (n < 1 || n > LG_MAX)
    {
        throw (uneChaine ("VALEUR_INCORRECTE"));
    }
    for (int c=0; c <= n; c++)
	{
		position(t,n,b,bi,nbA,nbC,c);
		if (t[bi] != t[c])
		{
			t[bi]=t[c];
			t[c]=b;
			nbA=nbA+2;
			nbC++;
		}
	}
}


