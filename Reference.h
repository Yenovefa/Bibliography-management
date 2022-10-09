/*
 * \file Reference.h
 * \brief Header file classe Reference
 * \author Emile Labrecque
 * \date 21 octobre 2021
 *
 */

#ifndef REFERENCE_H
#define REFERENCE_H

/*
 * \namespace biblio
 * \brief namespace contenant les classes Reference, Ouvrage, Journal et Bibliographie
 *
 */

namespace biblio
{

  /*
   * \class Reference
   * \brief Creation d'un objet Reference
   *
   * Attributs : m_auteurs Auteur principal
   *             m_titre Titre
   *             m_annee Annee d'edition
   *             m_identifiant Identifiant ISBN ou ISSN
   *
   */
  class Reference
  {
  public:
    Reference (const std::string&, const std::string&, const int&, const std::string&);
    virtual ~Reference ();

    std::string reqAuteur () const;
    std::string reqTitre () const;
    int reqAnnee () const;
    std::string reqIdentifiant () const;

    void modifierAnnee (const int&);

    virtual std::string reqReferenceFormate () const = 0;

    bool operator== (const Reference&) const;

    virtual Reference* clone () const = 0;

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
    void verifieInvariant () const;

  };

}
#endif /* REFERENCE_H */

