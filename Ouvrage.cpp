/*
 * \file Ouvrage.cpp
 * \brief Classe Ouvrage
 * \author Emile Labrecque
 *
 * Programme qui definit la classe Ouvrage et ses methodes
 *
 */

#include <iostream>
#include "Ouvrage.h"
#include <sstream>
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace biblio;


/*
 * \brief Constructeur de la classe Ouvrage
 * \param[in] p_auteur auteur de l'ouvrage
 * \param[in] p_titre titre de l'ouvrage
 * \param[in] p_ville ville d'edition
 * \param[in] p_editeur editeur de l'ouvrage
 * \param[in] p_annee annee d'edition
 * \param[in] p_identifiant Code ISBN de l'ouvrage
 */
Ouvrage::Ouvrage (const string& p_auteur, const string& p_titre, const string& p_ville, const string& p_editeur, const int& p_annee, const string& p_identifiant) :
Reference (p_auteur, p_titre, p_annee, p_identifiant), m_ville (p_ville), m_editeur (p_editeur)
{

  PRECONDITION (util::validerFormatNom (p_editeur));
  PRECONDITION (util::validerFormatNom (p_ville));
  PRECONDITION (util::validerCodeIsbn (p_identifiant));

  POSTCONDITION (m_ville == p_ville);
  POSTCONDITION (m_editeur == p_editeur);

  INVARIANTS ();
}


/*
 * \brief Requete pour l'editeur
 */
string
Ouvrage::reqEditeur () const
{
  return m_editeur;

}


/*
 * \brief Requete pour la ville
 */
string
Ouvrage::reqVille () const
{
  return m_ville;
}


/*
 * \brief Methode pour affichage de la reference dans un format precis
 * \return string contenant la reference formatee
 */
string
Ouvrage::reqReferenceFormate () const
{
  std::ostringstream oss;

  oss << Reference::reqReferenceFormate ();
  oss << m_ville << " : ";
  oss << m_editeur << ", ";
  oss << Reference::reqAnnee () << ". ";
  oss << Reference::reqIdentifiant () << "." << endl;

  string ref = oss.str ();

  return ref;
}


/*
 * \brief Methode pour cloner un ouvrage
 */
Reference*
Ouvrage::clone () const
{
  return new Ouvrage (*this);
}


/*
 * \brief Methode pour verifier les invariants de la classe Ouvrage
 */
void
Ouvrage::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (reqVille ()));
  INVARIANT (util::validerFormatNom (reqEditeur ()));

}


