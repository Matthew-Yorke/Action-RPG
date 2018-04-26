//***************************************************************************************************************************************************
//
// File Name: Game.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#ifndef Game_h
#define Game_h

#include "GameState.h"
#include "PlayerCharacter.h" // TODO: Remove
#include "Light.h" // TODO: Remove
#include "ShadowLayer.h" // TODO: Remove
#include "Clock.h" // TODO: Remove
#include "Camera.h" // TODO: Remove
#include "DialogBox.h" // TODO: Remove
#include "DialogImage.h" // TODO: Remove
#include "Rectangle.h" // TODO: Remove
#include "Map.h" // TODO: Remove

class Game
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

public:

   //************************************************************************************************************************************************
   //
   // Method Name: Game
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
   Game();

   //************************************************************************************************************************************************
   //
   // Method Name: Initialize
   //
   // Description:
   //  Initialize the game class by starting up necessary allegro routines and timers.
   //
   // Arguments:
   //  N/A
   //
   // Return:
   //  True  - Initialization is successful.
   //  False - Initialization unsuccessful.
   //
   //************************************************************************************************************************************************
   bool Initialize();

   //************************************************************************************************************************************************
   //
   // Method Name: ChangeState
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
   void ChangeState(GameState* theState);

   //************************************************************************************************************************************************
   //
   // Method Name: GameLoop
   //
   // Description:
   //  TODO: Add method description.
   //
   // Arguments:
   //  N/A
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   void GameLoop();

   //************************************************************************************************************************************************
   //
   // Method Name: Terminate
   //
   // Description:
   //  TODO: Add method description.
   //
   // Arguments:
   //  N/A
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   void Terminate();

protected:

private:

   //************************************************************************************************************************************************
   // End Method Declarations
   //************************************************************************************************************************************************

   //************************************************************************************************************************************************
   // Start Member Variable Declarations
   //************************************************************************************************************************************************

public:

protected:

private:

   // TODO: Add member variable description.
   ALLEGRO_DISPLAY * mpDisplay;

   // TODO: Add member variable description.
   ALLEGRO_TIMER* mpTimer;

   // TODO: Add member variable description.
   ALLEGRO_EVENT_QUEUE* mpEventQueue;

   // TODO: Add member variable description.
   bool mIsGameDone;

   // TODO: Add member variable description.
   // TODO: Move to somewhere more appropriate.
   const int mScreenWidth = 960;

   // TODO: Add member variable description.
   // TODO: Move to somewhere more appropriate.
   const int mScreenHeight = 540;

   // TODO: Add description.
   GameState* mpCurrentState;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif