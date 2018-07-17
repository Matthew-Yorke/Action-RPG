//***************************************************************************************************************************************************
//
// File Name: Magic.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Magic_H
#define Magic_H

#include <vector>
#include "AnimatedSprite.h"
#include "WorldConstants.h"
#include "Effect.h"

class Magic
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Magic
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Magic(Effect* theEffect, int theRaidus, int theManaCost, float theChargeTime);

      //*********************************************************************************************************************************************
      //
      // Method Name: ~Magic
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      ~Magic();

   protected:

      // There are currently no protected methods for this class.

   private:

      // There are currently no private methods for this class.

   //************************************************************************************************************************************************
   // End Method Declarations
   //************************************************************************************************************************************************

   //************************************************************************************************************************************************
   // Start Member Variable Declarations
   //************************************************************************************************************************************************

   public:

      // There are currently no public member variables for this class.

   protected:

      // There are currently no protected member variables for this class.

   private:

      // The animation of the spell.
      AnimatedSprite* mpSpellAnimation;

      // The type of effect the spell will do to the target(s).
      Effect* mpEffect;

      // The elemental type of the spell which can reduce, increase, or have no difference int he spells power.
      std::vector<WorldConstants::ELEMENTS> mElements;

      // Radius of the spells area of effect.
      int mRadius;

      // The mana cost to cast the spell.
      int mManaCost;

      // Time to charge a level of the spell.
      float mChargeTime;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif