/*
 * \file JournalTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Journal
 * \author Emile Labrecque
 */

#include <iostream>
#include <gtest/gtest.h>
#include "ContratException.h"
#include "Journal.h"

using namespace std;


/**
 * \brief Test du constructeur avec paramètres
 *
 *        cas valide :
 *          Création d'un journal valide : ParametresValides
 *
 *        cas invalides :
 *        	Nom invalide : ParametreNomInvalide
 *              Volume invalide : ParametreVolumeInvalide
 *        	Numero invalide : ParametreNumeroInvalide
 *              Page invalide : ParametrePageInvalide
 */
TEST (Journal, ParametresValides)
{
  biblio::Journal journalTest ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, 6, 113, 2009, "ISSN 1937-4771");
  ASSERT_EQ ("Journal of Computing Sciences in Colleges", journalTest.reqNom ());
  ASSERT_EQ (24, journalTest.reqVolume ());
  ASSERT_EQ (6, journalTest.reqNumero ());
  ASSERT_EQ (113, journalTest.reqPage ());
}

//Nom invalide


TEST (Journal, ParametreNomInvalide)
{
  ASSERT_THROW (biblio::Journal j1 ("Hart", "A survey of source code management tools for programming courses", "", 24, 6, 113, 2009, "ISSN 1937-4771"), PreconditionException);
}

//Volume invalide


TEST (Journal, ParametreVolumeInvalide)
{
  ASSERT_THROW (biblio::Journal j2 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 0, 6, 113, 2009, "ISSN 1937-4771"), PreconditionException);
  ASSERT_THROW (biblio::Journal j2 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", -12, 6, 113, 2009, "ISSN 1937-4771"), PreconditionException);
}

//Numero invalide


TEST (Journal, ParametreNumeroInvalide)
{
  ASSERT_THROW (biblio::Journal j3 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, 0, 113, 2009, "ISSN 1937-4771"), PreconditionException);
  ASSERT_THROW (biblio::Journal j3 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, -12, 113, 2009, "ISSN 1937-4771"), PreconditionException);
}


//Page invalide


TEST (Journal, ParametrePageInvalide)
{
  ASSERT_THROW (biblio::Journal j4 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, 6, 0, 2009, "ISSN 1937-4771"), PreconditionException);
  ASSERT_THROW (biblio::Journal j4 ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, 6, -12, 2009, "ISSN 1937-4771"), PreconditionException);
}

/**
 * \class JournalTest
 * \brief Fixture pour les tests sur un journal
 */

class JournalTest : public ::testing::Test
{

public:


  JournalTest () :
  f_JournalTest ("Hart", "A survey of source code management tools for programming courses", "Journal of Computing Sciences in Colleges", 24, 6, 113, 2009, "ISSN 1937-4771") { }
  ;

  biblio::Journal f_JournalTest;
} ;


/*
 * \brief Test de la methode std::string Journal::reqNom()
 *        Cas valide reqNom: Creation journal connu valide et test nom
 */
TEST_F (JournalTest, reqNom)
{
  ASSERT_EQ ("Journal of Computing Sciences in Colleges", f_JournalTest.reqNom ());
}


/*
 * \brief Test de la methode int Journal::reqVolume()
 *        Cas valide reqVolume: Creation journal connu valide et test volume
 */
TEST_F (JournalTest, reqVolume)
{
  ASSERT_EQ (24, f_JournalTest.reqVolume ());
}


/*
 * \brief Test de la methode int Journal::reqNumero()
 *        Cas valide reqNumero: Creation journal connu valide et test numero
 */
TEST_F (JournalTest, reqNumero)
{
  ASSERT_EQ (6, f_JournalTest.reqNumero ());
}


/*
 * \brief Test de la methode int Journal::reqPage()
 *        Cas valide reqPage: Creation journal connu valide et test page
 */
TEST_F (JournalTest, reqPage)
{
  ASSERT_EQ (113, f_JournalTest.reqPage ());
}


/*
 * \brief Test de la methode std::string Journal::reqreferenceFormate()
 *        Cas valide reqReferenceFormate: Return d'une reference formatee valide selon un format precis
 */

TEST_F (JournalTest, reqReferenceFormate)
{
  ASSERT_EQ ("Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.\n", f_JournalTest.reqReferenceFormate ());
}

/*
 * \brief Test de la methode Reference* Journal::clone()
 *        Cas valide clone : clone d'un journal valide
 */