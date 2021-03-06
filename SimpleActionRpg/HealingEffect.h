//***************************************************************************************************************************************************
//
// File Name: HealingEffect.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef HealingEffect_H
#define HealingEffect_H

#include <vector>
#include "Effect.h"
#include "WorldConstants.h"
#include "Character.h"

class HealingEffect : public Effect
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: HealingEffect
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
      HealingEffect(int theMinimumEffect, int theMaximumEffect, std::vector<WorldConstants::STATUS_EFFECTS> theStatusEffectsHealed);

      //*********************************************************************************************************************************************
      //
      // Method Name: Execute
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
      void Execute(Character* theAffectedCharacter);

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

      std::vector<WorldConstants::STATUS_EFFECTS> mStatusEffectsHealed;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif