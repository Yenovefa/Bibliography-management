/*
 * \file BibliographieTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Bibliographie
 * \author Emile Labrecque
 */

#include <iostream>
#include <gtest/gtest.h>
#include "ContratException.h"
#include "Ouvrage.h"
#include "Bibliographie.h"
#include "Journal.h"


/**
 * \brief Test du constructeur avec paramètres
 *
 *        cas valide :
 *          Création d'une bibliographie valide : ParametresValides
 *
 *        cas invalides : p_nom invalide
 */
TEST (Ouvrage, ParametresValides)
{
  biblio::Bibliographie bibliographieTest ("Bibliographie");
  ASSERT_EQ ("Bibliographie", bibliographieTest.reqNomBiblio ());
}

//p_nom invalide


TEST (Ouvrage, ParametreNomBiblioInvalide)
{
  ASSERT_THROW (biblio::Bibliographie b1 (""), PreconditionException);
}


/**
 * \brief Test de la methode void ajouterReference
 *        cas valide : La reference est ajoutee au vecteur m_vReferences
 */

TEST (Bibliographie, ajouterReference)
{
  biblio::Bibliographie b ("Bibliographie");
  biblio::Ouvrage o ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Springer", 2011, "ISBN 978-0-387-77591-3");
  b.ajouterReference (o);
  ASSERT_EQ ("Bibliographie\n===============================\n[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.\n", b.reqBibliographieFormate ());
}


/*
 * \brief Test de la methode std::string Bibliographie::reqBibliographieFormate
 *        Cas valide reqBibliographieFormate: Retour du vecteur m_vReferences selon le bon format
 */

TEST (Bibliographie, reqBibliographieFormate)
{
  biblio::Bibliographie b1 ("Bibliographie");
  biblio::Ouvrage o1 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Springer", 2011, "ISBN 978-0-387-77591-3");
  biblio::Journal j1 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, 6, 113, 2009, "ISSN 1937-4771");
  b1.ajouterReference (o1);
  b1.ajouterReference (j1);

  ASSERT_EQ ("Bibliographie\n===============================\n[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.\n[2] Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.\n", b1.reqBibliographieFormate ());
}


/*
 * \brief Test de la privee bool Bibliographie::referenceEstDejaPresente (const std::string)
 *        Cas valide : Le programme rejette la reference deja presente. On teste donc la methode publique reqReferenceFormate avec une reference ajoute en double
 */

TEST (Bibliographie, referenceEstDejaPresente)
{
  biblio::Bibliographie b1 ("Bibliographie");
  biblio::Ouvrage o1 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Springer", 2011, "ISBN 978-0-387-77591-3");
  biblio::Journal j1 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, 6, 113, 2009, "ISSN 1937-4771");
  b1.ajouterReference (o1);
  b1.ajouterReference (o1);
  b1.ajouterReference (j1);

  ASSERT_EQ ("Bibliographie\n===============================\n[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.\n[2] Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.\n", b1.reqBibliographieFormate ());
}

/**
 * \class BibliographieTest
 * \brief Fixture pour les tests sur une bibliographie
 */

class BibliographieTest : public ::testing::Test
{

public:


  BibliographieTest () :
  f_BibliographieTest ("Bibliographie") { }
  ;

  biblio::Bibliographie f_BibliographieTest;

} ;


/*
 * \brief Test de la methode std::string Bibliographie::reqNomBiblio()
 *        Cas valide reqNomBiblio: Creation Bibliographie connue valide et test nom
 */
TEST_F (BibliographieTest, reqNomBiblio)
{
  ASSERT_EQ ("Bibliographie", f_BibliographieTest.reqNomBiblio ());
}

