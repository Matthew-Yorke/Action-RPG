//***************************************************************************************************************************************************
//
// File Name: MagicAnimationPlayState.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef MagicAnimationPlayState_H
#define MagicAnimationPlayState_H

#include "PlaySubState.h"
#include "Map.h"
#include "ShadowLayer.h"
#include "Clock.h"
#include "Sprite.h"
#include "CircleObject.h"

class MagicAnimationPlayState : public PlaySubState
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: MagicAnimationPlayState
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
      MagicAnimationPlayState(PlayState* pThePlayState, Magic* pTheCastedSpell, std::vector<Character*> theAffectedCharacters);

      //*********************************************************************************************************************************************
      //
      // Method Name: ~MagicAnimationPlayState
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
      ~MagicAnimationPlayState();

      //*********************************************************************************************************************************************
      //
      // Method Name: KeyDown
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theEvent - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void KeyDown(ALLEGRO_EVENT theEvent) {};

      //*********************************************************************************************************************************************
      //
      // Method Name: KeyUp
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theEvent - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void KeyUp(ALLEGRO_EVENT theEvent) {};

      //*********************************************************************************************************************************************
      //
      // Method Name: Update
      //
      // Description:
      //  Nothing is being done during the idle state, so there is no code in the update method.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Update(float theTimeChange);

      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
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
      void Draw(Graphics& theGraphics);

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

      bool mIsUpPressed;
      bool mIsDownPressed;
      bool mIsLeftPressed;
      bool mIsRightPressed;

      CircleObject* mpSpellArea;

      Magic* mpCastedSpell;

      std::vector<Character*> mAffectedCharacters;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif