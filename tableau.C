#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "tableau.h"
#include <stdlib.h>

// ecrit les n premiers elements du tableau t
// necessite 1 <= n <= LG_MAX
void ecrireTableau (const Tableau t, const int n) throw (Chaine)
{
    if (n < 1 || n > LG_MAX)
    {
        throw (uneChaine ("VALEUR_INCORRECTE"));
    }
    ecrire (t[0]);
    for (int i = 1; i < n; i++)
    {
        ecrire (uneChaine (", "));
        ecrire (t[i]);
    }
    ecrireNL();
}

// remplit les n premiers elements du tableau t avec des valeurs aleatoires
// necessite 1 <= n <= LG_MAX
void remplirTableau (Tableau t, const int n) throw (Chaine)
{
    if (n < 1 || n > LG_MAX)
    {
        throw (uneChaine ("VALEUR_INCORRECTE"));
    }
    for (int i = 0; i < n; i++)
    {
        t[i] = random();
    }
}

