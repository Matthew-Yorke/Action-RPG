//***************************************************************************************************************************************************
//
// File Name: GameState.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef GameState_H
#define GameState_H

#include <allegro5/allegro_acodec.h>
#include "Graphics.h"

class GameState
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //************************************************************************************************************************************************
      //
      // Method Name: GameState
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
      //************************************************************************************************************************************************
      GameState();

      //************************************************************************************************************************************************
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
      //************************************************************************************************************************************************
      virtual void KeyDown(ALLEGRO_EVENT theEvent) = 0;

      //************************************************************************************************************************************************
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
      //************************************************************************************************************************************************
      virtual void KeyUp(ALLEGRO_EVENT theEvent) = 0;

      //************************************************************************************************************************************************
      //
      // Method Name: Update
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
      //************************************************************************************************************************************************
      virtual void Update(float theTimeChange) = 0;

      //************************************************************************************************************************************************
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
      //************************************************************************************************************************************************
      virtual void Draw(Graphics& theGraphics) = 0;

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

      // There are currently no protected member variables for this class.

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif