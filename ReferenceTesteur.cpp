/*
 * \file ReferenceTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Reference
 * \author Emile Labrecque
 */

#include <iostream>
#include <gtest/gtest.h>
#include "Reference.h"
#include "ContratException.h"

using namespace std;

/*
 * \class ReferenceDeTest
 * \brief classe de test permettant de tester la classe abstraite Reference
 **/


class ReferenceDeTest : public biblio::Reference
{

public:


  ReferenceDeTest (const string& p_auteur, const string& p_titre, const int& p_annee, const string& p_identifiant ) : Reference (p_auteur, p_titre, p_annee, p_identifiant) { }
  ;


  virtual
  ~ReferenceDeTest () { };


  virtual std::string
  reqReferenceFormate () const
  {
    return biblio::Reference::reqReferenceFormate ();
  };


  virtual Reference*
  clone () const
  {
    return new ReferenceDeTest (*this); // Appel du constructeur copie
  };

} ;


/**
 * \brief Test du constructeur de Reference avec paramètres
 *
 *        cas valide :
 *          Création d'une reference valide : ParametresValides
 *
 *        cas invalides :
 *        	Auteur invalide : ParametreAuteurInvalide,
 *        	Titre invalide : ParametreTitreInvalide,
 *              Annee invalide : ParametreAnneeInvalide
 *              Identifiant invalide : ParametreIdentifiantInvalide
 */


TEST (ReferenceDeTest, ParametresValides)
{
  ReferenceDeTest referenceTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");
  ASSERT_EQ ("Homayoon Beigi", referenceTest.reqAuteur ());
  ASSERT_EQ ("Fundamentals of Speaker Recognition", referenceTest.reqTitre ());
  ASSERT_EQ (2011, referenceTest.reqAnnee ());
  ASSERT_EQ ("ISBN 978-0-387-77591-3", referenceTest.reqIdentifiant ());

}

// Auteur invalide


TEST (ReferenceDeTest, ParametreAuteurInvalide)
{
  ASSERT_THROW (ReferenceDeTest r ("Homayoon  Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (ReferenceDeTest r ("Homayoon -Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (ReferenceDeTest r ("Homayoon- Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (ReferenceDeTest r ("Homayoon--Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);
}

// Titre invalide


TEST (ReferenceDeTest, ParametreTitreInvalide)
{
  ASSERT_THROW (ReferenceDeTest r ("Homayoon Beigi", "", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);

}

// Annee invalide


TEST (ReferenceDeTest, ParametreAnneeInvalide)
{
  ASSERT_THROW (ReferenceDeTest r ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 0, "ISBN 978-0-387-77591-3"), PreconditionException);
  ASSERT_THROW (ReferenceDeTest r ("Homayoon Beigi", "Fundamentals of Speaker Recognition", -20, "ISBN 978-0-387-77591-3"), PreconditionException);
}

// Identifiant invalide


TEST (ReferenceDeTest, ParametreIdentifiantInvalide)
{
  ASSERT_THROW (ReferenceDeTest r ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, ""), PreconditionException);
  ASSERT_THROW (ReferenceDeTest r ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-5"), PreconditionException);
  ASSERT_THROW (ReferenceDeTest r ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "978-0-387-77591-3"), PreconditionException);
}

/**
 * \class ReferenceTest
 * \brief Fixture pour les tests sur une reference
 */

class ReferenceTest : public ::testing::Test
{

public:


  ReferenceTest () :
  f_ReferenceTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3") { }
  ;

  ReferenceDeTest f_ReferenceTest;
} ;


/*
 * \brief Test de la methode std::string Reference::reqAuteur()
 *        Cas valide reqAuteur: Creation reference valide connue et test auteur
 */
TEST_F (ReferenceTest, reqAuteur)
{
  ASSERT_EQ ("Homayoon Beigi", f_ReferenceTest.reqAuteur ());
}


/*
 * \brief Test de la methode std::string Reference::reqTitre()
 *        Cas valide reqTitre: Creation reference valide connue et test titre
 */
TEST_F (ReferenceTest, reqTitre)
{
  ASSERT_EQ ("Fundamentals of Speaker Recognition", f_ReferenceTest.reqTitre ());
}


/*
 * \brief Test de la methode int Reference::reqAnnee()
 *        Cas valide reqAnnee: Creation reference valide connue et test annee
 */
TEST_F (ReferenceTest, reqAnnee)
{
  ASSERT_EQ (2011, f_ReferenceTest.reqAnnee ());
}


/*
 * \brief Test de la methode std::string Reference::reqIdentifiant()
 *        Cas valide reqIdentifiant: Creation reference valide connue et test identifiant
 */
TEST_F (ReferenceTest, reqIdentifiant)
{
  ASSERT_EQ ("ISBN 978-0-387-77591-3", f_ReferenceTest.reqIdentifiant ());
}


/*
 * \brief Test de la methode virtual void Reference::modifierAnnee(const int&)
 *        Cas valide: Modification de l'annee avec la valeur passee
 *        Cas invalide: Annee passee en parametre invalide : ParametreAnneeModifieeInvalide
 */
TEST_F (ReferenceTest, modifierAnnee)
{
  f_ReferenceTest.modifierAnnee (2016);
  ASSERT_EQ (2016, f_ReferenceTest.reqAnnee ());
  ;
}

//Annee modifiee invalide


TEST (ReferenceDeTest, ParametreAnneeModifieeInvalide)
{
  ReferenceDeTest refTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");
  ASSERT_THROW (refTest.modifierAnnee (0), PreconditionException);
  ASSERT_THROW (refTest.modifierAnnee (-20), PreconditionException);
}


/*
 * \brief Test de la methode virtual std::string Reference::reqReferenceFormate()
 *        Cas valide: Retour d'une reference formate connue
 */
TEST_F (ReferenceTest, reqReferenceFormate)
{
  ASSERT_EQ ("Homayoon Beigi. Fundamentals of Speaker Recognition. ", f_ReferenceTest.reqReferenceFormate ());

}


/*
 * \brief Test de la methode bool Reference::operator== (const Reference&) const
 *        Cas valide: l'operateur retourne true si les deux references sont identiquess
 *                    l'operateur retourne false si les deux references ne sont pas identiques
 */

TEST_F (ReferenceTest, operatorEgalEgal)
{
  ReferenceDeTest RefTrue ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");
  ASSERT_EQ (true, f_ReferenceTest.operator== (RefTrue)) ;
  ReferenceDeTest RefFalse ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2010, "ISBN 978-0-387-77591-3");
  ASSERT_EQ (true, f_ReferenceTest.operator== (RefFalse)) ;
}


/*
 * \brief Test de la methode virtual Reference* clone ()
 *        Cas valide: clone d'une reference connue
 */

TEST_F (ReferenceTest, clone)
{
  ReferenceDeTest Ref ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");
  ASSERT_EQ (Ref.reqReferenceFormate (), f_ReferenceTest.clone ()->reqReferenceFormate ());
}