/*
 * \file Journal.cpp
 * \brief Classe Journal
 * \author Emile Labrecque
 *
 * Programme qui definit la classe Journal et ses methodes
 *
 */

#include <iostream>
#include "Journal.h"
#include <sstream>
#include "ContratException.h"
#include "validationFormat.h"

using namespace std;
using namespace biblio;


/*
 * \brief Constructeur de la classe Journal
 * \param[in] p_auteur Auteur
 * \param[in] p_titre Titre
 * \param[in] p_nom Nom de la revue
 * \param[in] p_volume Volume
 * \param[in] p_numero Numero
 * \param[in] p_page Page ou commence la reference
 * \param[in] p_annee Annee d'edition
 * \param[in] p_identifiant Code ISSN
 */

Journal::Journal (const string& p_auteur, const string& p_titre, const string& p_nom, const int& p_volume, const int& p_numero, const int& p_page, const int& p_annee, const string& p_identifiant) : Reference (p_auteur, p_titre, p_annee, p_identifiant), m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
{

  PRECONDITION (!p_nom.empty ());
  PRECONDITION (util::validerCodeIssn (p_identifiant));
  PRECONDITION (p_volume > 0);
  PRECONDITION (p_numero > 0);
  PRECONDITION (p_page > 0);

  POSTCONDITION (m_nom == p_nom);
  POSTCONDITION (m_volume == p_volume);
  POSTCONDITION (m_numero == p_numero);
  POSTCONDITION (m_page == p_page);

  INVARIANTS ();
}


/*
 * \brief Requete pour le nom de la revue
 */
string
Journal::reqNom () const
{
  return m_nom;
}


/*
 * \brief Requete pour le volume
 */
int
Journal::reqVolume () const
{
  return m_volume;
}


/*
 * \brief Requete pour le numero
 */
int
Journal::reqNumero () const
{
  return m_numero;
}


/*
 * \brief Requete pour la page ou commence la reference
 */
int
Journal::reqPage () const
{
  return m_page;
}


/*
 * \brief Methode pour afficher la reference selon un format defini
 * \return string contenant la reference formatee
 */
string
Journal::reqReferenceFormate () const
{
  std::ostringstream oss;

  oss << Reference::reqReferenceFormate ();
  oss << m_nom << ", ";
  oss << "vol. " << m_volume << ", ";
  oss << "no. " << m_numero << ", ";
  oss << "pp. " << m_page << ", ";
  oss << Reference::reqAnnee () << ". ";
  oss << Reference::reqIdentifiant () << "." << endl;

  string ref = oss.str ();
  return ref;
}


/*
 * \brief Methode pour verifier les invariants de la classe Journal
 */
void
Journal::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (reqNom ()));
  INVARIANT (reqVolume () > 0);
  INVARIANT (reqNumero () > 0);
  INVARIANT (reqPage () > 0);

}


/*
 * \brief Methode pour cloner un Journal
 */
Reference*
Journal::clone () const
{
  return new Journal (*this); // Appel du constructeur copie
}


