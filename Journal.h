/*
 * \file Journal.h
 * \brief Header file classe Journal
 * \author Emile Labrecque
 *
 */

#ifndef JOURNAL_H
#define JOURNAL_H
#include "Reference.h"

namespace biblio
{

  /**
   * \class Journal
   * \brief Cette classe sert a la creation de reference de journal
   *
   * Attributs : m_nom nom de la revue
   *             m_volume volume
   *             m_numero numero
   *             m_page page ou commence la reference
   *
   */

  class Journal : public biblio::Reference
  {
  public:
    Journal (const std::string& p_auteur, const std::string& p_titre, const std::string& p_nom, const int& p_volume, const int& p_numero, const int& p_page, const int& p_annee, const std::string& p_identifiant);

    std::string reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;
    virtual std::string reqReferenceFormate () const;

    virtual Reference* clone () const;

  private:
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;
    void verifieInvariant () const;
  };

}
#endif /* JOURNAL_H */

