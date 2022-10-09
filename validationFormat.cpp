/*
 * \file validationFormat.cpp
 * \brief programme pour demander les infos a l'utilisateur et creer l'objet Reference
 * \author Emile Labrecque
 * \date 21 octobre 2021
 *
 */

#include <cstdlib>
#include <iostream>
#include "validationFormat.h"
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


namespace util
{

  //-----------------------------------------Fonction 1 ------------------------


  bool
  validerFormatNom (const string& p_nom)
  {

    bool valide = false;
    int longueur = p_nom.size ();


    for (int i = 0; i <= longueur - 1; i++)
      {
        if (isalpha (p_nom[i]))
          {
            valide = true;
          }
        else if (p_nom[i] == ' ' & p_nom[i + 1] != ' ')
          {
            if (p_nom[i + 1] == '-')
              {
                valide = false;
                break;
              }
            else
              {
                valide = true;
              }
          }
        else if (p_nom[i] == '-' & p_nom[i + 1] != '-' )
          {
            if (p_nom[i + 1] == ' ')
              {
                valide = false;
                break;
              }
            else
              {
                valide = true;
              }
          }

        else
          {
            valide = false;
            break;
          }

      }
    return valide;
  }

  //------------------------------------------------------------ fonction 2


  bool
  validerCodeIssn (const string& p_issn)
  {
    bool valide = false;

    if (p_issn.substr (0, 5) == "ISSN ")
      {

        if (isdigit (p_issn[5]) & isdigit (p_issn[6]) & isdigit (p_issn[7]) & isdigit (p_issn[8]))
          {
            if (p_issn[9] == '-')
              {
                if (isdigit (p_issn[10]) & isdigit (p_issn[11]) & isdigit (p_issn[12]))
                  {
                    string sub1 = p_issn.substr (5, 4);
                    string sub2 = p_issn.substr (10, 3);
                    string issnNombres = sub1 + sub2;
                    int issnInt = atoi (issnNombres.c_str ());
                    int nb1 = issnInt / 1000000 % 10;
                    int nb2 = issnInt / 100000 % 10;
                    int nb3 = issnInt / 10000 % 10;               // Extract each number from the Issn to an int
                    int nb4 = issnInt / 1000 % 10;
                    int nb5 = issnInt / 100 % 10;
                    int nb6 = issnInt / 10 % 10;
                    int nb7 = issnInt % 10;


                    int temp = (nb1 * 8 + nb2 * 7 + nb3 * 6 + nb4 * 5 + nb5 * 4 + nb6 * 3 + nb7 * 2) % 11;
                    int cleControle = 11 - temp;


                    if ( atoi (p_issn.substr (13).c_str ()) == cleControle)
                      {
                        valide = true;
                      }
                  }
              }

          }

      }
    return valide;
  }

  //------------------------------------------------------------ fonction 3


  bool
  validerCodeIsbn (const string& p_isbn)
  {
    bool valide = false;

    if (p_isbn.substr (0, 9) == "ISBN 978-" | p_isbn.substr (0, 9) == "ISBN 979-")
      {
        int n = (p_isbn.substr (9, p_isbn.size () - 9)).find ("-");  // position du deuxieme tiret et fin du domaine
        string domaine = p_isbn.substr (9, n);

        if (domaine[0] == '7' |  (atoi (domaine.c_str ()) <= 5 | (atoi (domaine.c_str ()) <= 649 && atoi (domaine.c_str ()) >= 600) ) | (atoi (domaine.c_str ()) <= 94 && atoi (domaine.c_str ()) >= 80) | (atoi (domaine.c_str ()) <= 989 && atoi (domaine.c_str ()) >= 950) | (atoi (domaine.c_str ()) <= 9989 && atoi (domaine.c_str ()) >= 9900) | (atoi (domaine.c_str ()) <= 99999 && atoi (domaine.c_str ()) >= 99900))
          {
            string partie2 = p_isbn.substr (5, p_isbn.size () - 6);

            partie2.erase (remove (partie2.begin (), partie2.end (), '-'), partie2.end ());

            int somme_pairs = 0;
            int somme_impairs = 0;

            for (int i = 0; i < partie2.size (); i++)
              {
                if ((i + 1) % 2 == 0)
                  {
                    somme_pairs = somme_pairs + (partie2[i] - 48 ); //-48 car les nombres commencent a 48 en ASCII
                  }
                else
                  {
                    somme_impairs = somme_impairs + (partie2[i] - 48 );
                  }
              }
            int somme_partielle = (3 * somme_pairs) + somme_impairs;
            int cle = 10 - (somme_partielle % 10);

            if (p_isbn[p_isbn.size () - 1] == cle + 48)
              {
                valide = true;
              }

          }

      }
    return valide;
  }

}