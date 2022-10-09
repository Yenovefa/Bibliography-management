/*
 * \file Bibliographie.h
 * \brief Header file classe Bibliographie
 * \author Emile Labrecque
 *
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include "Reference.h"
#include <vector>

namespace biblio
{

  class Bibliographie
  {
  public:
    Bibliographie (const std::string);
    Bibliographie (const Bibliographie&);
    Bibliographie& operator= (const Bibliographie &);
    ~Bibliographie ();

    std::string reqNomBiblio ();
    void ajouterReference (const Reference& p_nouvelleReference);
    std::string reqBibliographieFormate () const;

  private:
    std::vector<Reference*> m_vReferences;
    std::string m_nomBiblio;
    bool referenceEstDejaPresente (const std::string& p_identifiant) const;
    void verifieInvariant () const;
  };
}



#endif /* BIBLIOGRAPHIE_H */

