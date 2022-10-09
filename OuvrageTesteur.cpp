/*
 * \file OuvrageTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Ouvrage
 * \author Emile Labrecque
 */

#include <iostream>
#include <gtest/gtest.h>
#include "Ouvrage.h"
#include "ContratException.h"

using namespace std;


/**
 * \brief Test du constructeur avec paramètres
 *
 *        cas valide :
 *          Création d'un ouvrage valide : ParametresValides
 *
 *        cas invalides :
 *        	ville invalide -> ParametreVilleInvalide,
 *        	editeur invalide : ParametreEditeurInvalide,
 */
TEST (Ouvrage, ParametresValides)
{
  biblio::Ouvrage ouvrageTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Springer", 2011, "ISBN 978-0-387-77591-3");
  ASSERT_EQ ("New York", ouvrageTest.reqVille ());
  ASSERT_EQ ("Springer", ouvrageTest.reqEditeur ());
}

//ville invalide


TEST (Ouvrage, ParametreVilleInvalide)
{
  ASSERT_THROW (biblio::Ouvrage o1 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New  York", "Springer", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o2 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New--York", "Springer", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o3 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New- York", "Springer", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o4 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New -York", "Springer", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o4 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "", "Springer", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);


}

//editeur invalide


TEST (Ouvrage, ParametreEditeurInvalide)
{
  ASSERT_THROW (biblio::Ouvrage o1 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Spr  inger", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o2 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Spr--inger", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o3 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Spr- inger", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o4 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Spr -inger", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (biblio::Ouvrage o4 ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
}

/**
 * \class OuvrageTest
 * \brief Fixture pour les tests sur un ouvrage
 */

class OuvrageTest : public ::testing::Test
{

public:


  OuvrageTest () :
  f_OuvrageTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "New York", "Springer", 2011, "ISBN 978-0-387-77591-3") { }
  ;

  biblio::Ouvrage f_OuvrageTest;
} ;


/*
 * \brief Test de la methode std::string Ouvrage::reqEditeur()
 *        Cas valide reqEditeur: Creation ouvrage valide connu et test editeur
 */
TEST_F (OuvrageTest, reqEditeur)
{
  ASSERT_EQ ("Springer", f_OuvrageTest.reqEditeur ());
}


/*
 * \brief Test de la methode std::string Ouvrage::reqVille()
 *        Cas valide reqVille: Creation ouvrage valide connu et test ville
 */
TEST_F (OuvrageTest, reqVille)
{
  ASSERT_EQ ("New York", f_OuvrageTest.reqVille ());
}


/*
 * \brief Test de la methode virtual std::string Ouvrage::reqReferenceFormate()
 *        Cas valide: Retour de l'ouvrage formate connu
 */
TEST_F (OuvrageTest, reqReferenceFormate)
{
  ASSERT_EQ ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.\n", f_OuvrageTest.reqReferenceFormate ());

}