/*
 * \file validationFormat.h
 * \brief Header file pourles fonctions util
 * \author: Emile Labrecque
 * \date 21 octobre 2021
 *
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

/*
 * \namespace util
 * \brief namespace incluant les fonctions de verification
 *
 */

namespace util
{

  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string& p_issn);
  bool validerCodeIsbn (const std::string& p_isbn);
}


#endif /* VALIDATIONFORMAT_H */

