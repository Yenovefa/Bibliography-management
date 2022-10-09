/*
 * \file Bibliographie.cpp
 * \brief Classe Bibliographie
 * \author Emile Labrecque
 *
 * Programme qui definit la classe Bibliographie et ses methodes
 *
 */

#include <iostream>
#include "Bibliographie.h"
#include "Reference.h"
#include <vector>
#include <sstream>
#include <string>
#include "ContratException.h"

#include <string.h>
#include <stdio.h>

using namespace std;
using namespace biblio;


/*
 * \brief Constructeur de la classe bibliographie
 * \param[in] p_nomBiblio nom de la bibliographie
 */
Bibliographie::Bibliographie (const std::string p_nomBiblio) : m_nomBiblio (p_nomBiblio)
{
  PRECONDITION (!m_nomBiblio.empty ());
  POSTCONDITION (m_nomBiblio == p_nomBiblio);
  INVARIANTS ();
}


/*
 * \brief Destructeur de la classe Bibliographie
 */
Bibliographie::~Bibliographie ()
{

  for (int i = m_vReferences.size (); i >= 0; i--)
    {
      delete (m_vReferences[i]);
    }
  m_vReferences.clear ();
  m_nomBiblio.clear ();
}


/*
 * \brief Constructeur Copie pour la classe Bibliographie
 */

Bibliographie::Bibliographie (const Bibliographie& source) : m_nomBiblio (0)
{
  PRECONDITION (m_vReferences.empty ());

  for (int i = 0; i < source.m_vReferences.size (); i++)
    {
      Bibliographie::ajouterReference (*source.m_vReferences[i]); //source.m_vReferences[i] est un pointeur
      ;
    }
};


/*
 * \brief Operateur d'assignation pour la classe Bibliographie
 */

Bibliographie& Bibliographie::operator= (const Bibliographie& source)
{
  PRECONDITION (m_vReferences.empty ());
  if (this != &source)
    {
      //supprime
      Bibliographie::~Bibliographie ();

      //copier
      for (int i = 0; i < source.m_vReferences.size (); i++)
        {
          Bibliographie::ajouterReference (*source.m_vReferences[i]); //source.m_vReferences[i] est un pointeur
          ;
        }
    }
  //return
  return *this;
}


/*
 * \brief Requete pour le nom de la bibliographie
 */
std::string
Bibliographie::reqNomBiblio ()
{
  return m_nomBiblio;
}


/*
 * \brief Methode pour ajouter une reference dans le vecteur de  la bibliographie
 * \param[in] p_nouvelleReference Nouvelle reference a ajouter
 */
void
Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
{
  if (!Bibliographie::referenceEstDejaPresente (p_nouvelleReference.reqIdentifiant ()))
    {
      m_vReferences.push_back (p_nouvelleReference.clone ());
    }
}


/*
 * \brief Methode pour affichage de la bibliographie dans un format precis
 * \return string contenant la bibliographie formatee
 */
std::string
Bibliographie::reqBibliographieFormate () const
{
  ostringstream oss;

  oss << m_nomBiblio << endl;
  oss << "===============================" << endl;

  for (int i = 0; i < m_vReferences.size (); i++)
    {
      oss << "[" << i + 1 << "] ";
      oss << m_vReferences[i]->reqReferenceFormate ();
    }


  return oss.str ();

}


/*
 * \brief Methode pour verifier si l'identifiant est deja present dans le vecteur de la bibliographie
 * \param[in] p_identifiant Identifiant ISBN ou ISSN a verifier
 * \return True si l'identifiant est present, sinon False
 */
bool
Bibliographie::referenceEstDejaPresente (const string & p_identifiant) const
{
  bool verif = false;

  string str = Bibliographie::reqBibliographieFormate ();

  if (str.find (p_identifiant) != string::npos)
    {
      verif = true;
    }

  return verif;
}


/*
 * \brief Methode pour verifier les invariants dans la classe Bibliographie
 */
void
Bibliographie::verifieInvariant () const
{
  INVARIANT (!m_nomBiblio.empty ());
}