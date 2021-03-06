//***************************************************************************************************************************************************
//
// File Name: PlayState.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef PlayState_H
#define PlayState_H

#include "GameState.h"
#include "PlaySubState.h"
#include "Map.h"
#include "ShadowLayer.h"
#include "PlayerCharacter.h"
#include "Camera.h"
#include "Clock.h"
#include "Enemy.h"
#include "EventStorage.h"

class PlaySubState;

class PlayState : public GameState
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: PlayState
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
      PlayState(Graphics& theGraphics);

      //*********************************************************************************************************************************************
      //
      // Method Name: ~PlayState
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
      ~PlayState();

      //************************************************************************************************************************************************
      //
      // Method Name: ChangeSubState
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theState - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void ChangeSubState(PlaySubState* theState);

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
      void KeyDown(ALLEGRO_EVENT theEvent);

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
      void KeyUp(ALLEGRO_EVENT theEvent);

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

      Graphics* mpGraphics;

      Map* mpCurrentMap;

      ShadowLayer* mpShadowLayer;

      PlayerCharacter* mpPlayer;

      RectangleObject* mpMapAreaBoundary;

      Camera* mpCamera;

      Clock* mpGameClock;

      float PathUpdateTime; 

      EventStorage* mpEventStorage;

      // TODO: Add description.
      PlaySubState* mpCurrentSubState;

   protected:

      // There are currently no protected member variables for this class.

   private:

      

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif