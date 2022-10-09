/*
 * \file Ouvrage.h
 * \brief Header file classe Ouvrage
 * \author Emile Labrecque
 *
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include "Reference.h"

namespace biblio
{

  /**
   * \class Ouvrage
   * \brief Cette classe sert a la creation de reference d'ouvrage
   *
   * Attributs : m_editeur editeur de l'ouvrage
   *             m_ville ville d'edition de l'ouvrage
   *
   */

  class Ouvrage : public biblio::Reference
  {
  public:
    Ouvrage (const std::string& p_auteur, const std::string& p_titre, const std::string& p_ville, const std::string& p_editeur, const int& p_annee, const std::string& p_identifiant);

    std::string reqEditeur () const;
    std::string reqVille () const;
    virtual std::string reqReferenceFormate () const;

    virtual Reference* clone () const;


  private:
    std::string m_editeur;
    std::string m_ville;
    void verifieInvariant () const;
  };
}
#endif /* OUVRAGE_H */

