#include "/usr/local/public/BIBLIOC++/chaine.h"
#include "/home/fln1147a/Dev2/tris/tableau.h"
#include <stdlib.h>
#include <time.h>
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"



void trierSelection (Tableau t, const int n) throw (Chaine);

int main()
{
    Tableau t;
    const int LG = 50;

    // initialisation du generateur de nombres aleatoires avec l'heure courante
    srandom(time(NULL));
    // initialisation du tableau avec des valeurs aleatoires
    remplirTableau (t, LG);
    // affichage du tableau initial
    ecrireTableau (t, LG);
    // tri du tableau
    trierSelection (t, LG);
    // affichage du tableau trie
    ecrireTableau (t, LG);
}

// tri le tableau t de n entiers par la methode des bulles
// necessite 1 <= n <= LG_MAX
void trierSelection (Tableau t, const int n) throw (Chaine)
{
	int b;
    if (n < 1 || n > LG_MAX)
    {
        throw (uneChaine ("VALEUR_INCORRECTE"));
    }
    for (int i=0; i < n; i++)
	{
	for (int a=1; a< n; a++)
		{
			if (t[i]>t[a])
				{
					b=t[i];
					t[i]=t[a];
					t[a]=b;
				}
		}
	}
}

