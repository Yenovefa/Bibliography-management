
#include <cstdlib>
#include <iostream>

#include "Ouvrage.h"
#include "Journal.h"
#include "Bibliographie.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;


int
main ()
{

  cout << "Bienvenue dans l'outil de gestion de references bibliographiques" << endl;
  cout << "================================================================" << endl;

  // ------------------------------------OUVRAGE ----------------------------

  cout << "-------------------------------------------------------" << endl;
  cout << "Ajoutez un ouvrage" << endl;
  cout << "-------------------------------------------------------" << endl;

  string p_auteur;
  while (true)
    {
      cout << "Entrez le nom du ou des auteurs :" << endl;
      getline (cin, p_auteur);

      if (util::validerFormatNom (p_auteur))
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Nom du ou des auteurs invalide" << endl;
        }


    }


  string p_titre;
  while (true)
    {
      cout << "Entrez le titre :" << endl;
      getline (cin, p_titre);
      if (!p_titre.empty ())
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Titre invalide" << endl;
        }
    }

  string p_ville;
  while (true)
    {
      cout << "Entrez la ville d'edition :" << endl;
      getline (cin, p_ville);
      if (util::validerFormatNom (p_ville))
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Ville d'edition invalide" << endl;
        }
    }

  string p_editeur;
  while (true)
    {
      cout << "Entrez l'editeur :" << endl;
      getline (cin, p_editeur);
      if (util::validerFormatNom (p_editeur))
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Editeur invalide" << endl;
        }
    }

  int p_annee;
  while (true)
    {
      cout << "Entrez l'annee d'edition :" << endl;
      cin >> p_annee;
      if (p_annee > 0)
        {
          cout << endl;
          cin.clear ();
          cin.sync ();
          cin.ignore ();
          break;
        }
      else
        {
          cout << "Annee invalide" << endl;
          p_annee = 0;
          cin.clear ();
          cin.ignore ();
        }
    }

  string p_identifiant;
  while (true)
    {
      cout << "Entrez le code ISBN :" << endl;
      getline (cin, p_identifiant);

      if (util::validerCodeIsbn (p_identifiant))
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Code ISBN invalide" << endl;
        }
    }

  //--------------------------------------------Gestion des erreurs de contrat-------------------
  try
    {
      biblio::Ouvrage ouvrage (p_auteur, p_titre, p_ville, p_editeur, p_annee, p_identifiant);
    }
  catch (ContratException &e)
    {
      cout << e.reqTexteException () << endl;
      throw;
    }

  biblio::Ouvrage ouvrage (p_auteur, p_titre, p_ville, p_editeur, p_annee, p_identifiant);

  // --------------------------------JOURNAL----------------------------------

  cout << "-------------------------------------------------------" << endl;
  cout << "Ajoutez une reference de type article de journal" << endl;
  cout << "-------------------------------------------------------" << endl;

  while (true)
    {
      cout << "Entrez le nom du ou des auteurs :" << endl;
      getline (cin, p_auteur);

      if (util::validerFormatNom (p_auteur))
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Nom du ou des auteurs invalide" << endl;
        }
    }

  while (true)
    {
      cout << "Entrez le titre :" << endl;
      getline (cin, p_titre);
      if (!p_titre.empty ())
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Titre invalide" << endl;
        }
    }


  string p_nom;
  while (true)
    {
      cout << "Entrez le nom de la revue dans laquelle a ete publiee la reference :" << endl;
      getline (cin, p_nom);
      if (!p_nom.empty ())
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Nom de la revue invalide" << endl;
        }
    }

  int p_volume;
  while (true)
    {
      cout << "Entrez le volume :" << endl;
      cin >> p_volume;
      if (p_volume > 0)
        {
          cout << endl;
          cin.clear ();
          cin.sync ();
          cin.ignore ();
          break;
        }
      else
        {
          cout << "Numero de volume invalide" << endl;
          cin.clear ();
          cin.ignore ();
        }
    }

  int p_numero;
  while (true)
    {
      cout << "Entrez le numero :" << endl;
      cin >> p_numero;
      if (p_numero > 0)
        {
          cout << endl;
          cin.clear ();
          cin.sync ();
          cin.ignore ();
          break;
        }
      else
        {
          cout << "Numero invalide" << endl;
          cin.clear ();
          cin.ignore ();
        }
    }

  int p_page;
  while (true)
    {
      cout << "Entrez la page ou commence la reference :" << endl;
      cin >> p_page;
      if (p_page > 0)
        {
          cout << endl;
          cin.clear ();
          cin.sync ();
          cin.ignore ();
          break;
        }
      else
        {
          cout << "Page invalide" << endl;
          cin.clear ();
          cin.ignore ();
        }
    }

  while (true)
    {
      cout << "Entrez l'annee d'edition :" << endl;
      cin >> p_annee;
      if (p_annee > 0)
        {
          cout << endl;
          cin.clear ();
          cin.sync ();
          cin.ignore ();
          break;
        }
      else
        {
          cout << "Annee invalide" << endl;
          cin.clear ();
          cin.ignore ();
        }
    }

  while (true)
    {
      cout << "Entrez le code ISSN :" << endl;
      getline (cin, p_identifiant);
      if (util::validerCodeIssn (p_identifiant))
        {
          cout << endl;
          break;
        }
      else
        {
          cout << "Code ISSN invalide" << endl;
        }
    }


  //--------------------------------------------Gestion des erreurs de contrat-------------------
  try
    {
      biblio::Journal journal (p_auteur, p_titre, p_nom, p_volume, p_numero, p_page, p_annee, p_identifiant);
    }
  catch (ContratException &e)
    {
      cout << e.reqTexteException () << endl;
      throw;
    }

  biblio::Journal journal (p_auteur, p_titre, p_nom, p_volume, p_numero, p_page, p_annee, p_identifiant);


  //--------------------------------------AFFICHER BIBLIOGRAPHIE----------------

  cout << "References bibliographiques enregistrees" << endl;
  biblio::Bibliographie bibliographie ("Bibliographie");
  bibliographie.ajouterReference (ouvrage);
  bibliographie.ajouterReference (journal);
  cout << bibliographie.reqBibliographieFormate () << endl;

}

