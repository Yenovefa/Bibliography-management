/*
 * \file Reference.cpp
 * \brief Classe Reference
 * \author Emile Labrecque
 * \date 21 octobre 2021
 *
 * Programme qui definit la classe Reference et ses methodes
 *
 */

#include <cstdlib>
#include <iostream>
#include "Reference.h"
#include <sstream>
#include "ContratException.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace biblio;


/*
 * \fn Reference::Reference (const string& p_auteur, const string& p_titre, const int& p_annee, const string& p_identifiant )
 * \brief Constructeur de la classe Reference
 *
 * \param[in] m_auteurs Auteur principal (string).
 * \param[in] m_titre Titre (string).
 * \param[in] m_annee Annee d'edition (int).
 * \param[in] m_identifiant Code ISBN ou ISSN (string).
 *
 */
Reference::Reference (const string& p_auteur, const string& p_titre, const int& p_annee, const string& p_identifiant ) : m_auteurs (p_auteur), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
{
  PRECONDITION (util::validerFormatNom (p_auteur));
  PRECONDITION (!p_titre.empty ());
  PRECONDITION (p_annee > 0);
  PRECONDITION (util::validerCodeIssn (p_identifiant) | util::validerCodeIsbn (p_identifiant));

  POSTCONDITION (m_auteurs == p_auteur);
  POSTCONDITION (m_titre == p_titre);
  POSTCONDITION (m_annee == p_annee);
  POSTCONDITION (m_identifiant == p_identifiant);

  INVARIANTS ();

}


Reference::~Reference () { }


/*
 * \brief Requete pour l'auteur de l'objet
 * \return Retour m_auteurs
 *
 */
string
Reference::reqAuteur () const
{
  return m_auteurs;
}


/*
 * \brief Requete pour le titre de l'objet
 * \return Retour m_titre
 */
string
Reference::reqTitre () const
{
  return m_titre;
}


/*
 * \brief Requete pour l'annee d'edition de l'objet
 * \return Retour m_annee
 */
int
Reference::reqAnnee () const
{
  return m_annee;
}


/*
 * \brief Requete pour l'identifiant (ISBN ou ISSN) de l'objet
 * \return Retour m_identifiant
 */
string
Reference::reqIdentifiant () const
{
  return m_identifiant;
}


/*
 * \brief Methode pour modifier l'annee d'edition
 * \param[in] p_annee nouvelle annee d'edition (int)
 */
void
Reference::modifierAnnee (const int& p_annee)
{
  PRECONDITION (p_annee > 0);

  m_annee = p_annee;

  POSTCONDITION (m_annee == p_annee);
}


/*
 * \brief Methode pour retourner la reference complete formatee
 * \return Reference formatee en format <auteur>, <titre>, <annee>, <identifiant>.
 */
string
Reference::reqReferenceFormate () const
{
  ostringstream oss;
  oss << m_auteurs << ". ";
  oss << m_titre << ". ";
  ;

  string ref = oss.str ();

  return ref;
}


/*
 * \brief Methode pour verifier si 2 objets Reference sont identiques
 * \param[in] reference a comparer
 * \return  booleen montrant si les 2 objets sont identiques
 */
bool Reference::operator== (const Reference& ref) const
{
  bool validation = false;

  if (ref.reqReferenceFormate () == reqReferenceFormate ())
    {
      validation = true ;
    }

  return validation;
}


/*
 * \brief Methode pour verifier les invariants de la classe Reference
 */

void
Reference::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (m_auteurs));
  INVARIANT (util::validerCodeIssn (m_identifiant) | util::validerCodeIsbn (m_identifiant) );
}