//***************************************************************************************************************************************************
//
// File Name: PlayState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "PlayState.h"
#include "RegularPlayState.h"
#include "CastMagicPlayState.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: PlayState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
PlayState::PlayState(Graphics& theGraphics)
{
   mpGraphics = &theGraphics;

   mpCurrentMap = new Map(&theGraphics, "../Maps/TestMap.txt");

   mpShadowLayer = new ShadowLayer("../Images/ShadowLayer.png");
   
   mpPlayer = new PlayerCharacter(theGraphics, 64, 64);
   
   mpMapAreaBoundary = new RectangleObject(0,
                                           0,
                                           mpCurrentMap->GetMapWidth(),
                                           mpCurrentMap->GetMapHeight());
   mpCamera = new Camera(mpMapAreaBoundary, mpPlayer);
   
   mpGameClock = new Clock(6.0F);

   PathUpdateTime = 0.2F;

   mpEventStorage = mpEventStorage->GetInstance();

   mpCurrentSubState = new RegularPlayState(this);
}

//***************************************************************************************************************************************************
//
// Method Name: ~PlayState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
PlayState::~PlayState()
{
   delete mpCurrentMap;
   delete mpShadowLayer;
   delete mpPlayer;
   delete mpMapAreaBoundary;
   delete mpCamera;
   delete mpGameClock;
   mpEventStorage->ReleaseInstance();
}

//************************************************************************************************************************************************
//
// Method Name: ChangeSubState
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlayState::ChangeSubState(PlaySubState* theState)
{
   delete mpCurrentSubState;
   mpCurrentSubState = theState;
}

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
void PlayState::KeyDown(ALLEGRO_EVENT theEvent)
{
   mpCurrentSubState->KeyDown(theEvent);
}

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
void PlayState::KeyUp(ALLEGRO_EVENT theEvent)
{
   mpCurrentSubState->KeyUp(theEvent);
}

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
void PlayState::Update(float theTimeChange)
{
   mpCurrentSubState->Update(theTimeChange);

   // Check if the enemy NPC has depleted their life
   std::vector<Enemy*> temporaryEnemyList = mpCurrentMap->GetEnemyList();
   for(auto currentEnemy = temporaryEnemyList.begin();
       currentEnemy != temporaryEnemyList.end();)
   {
      if ((*currentEnemy)->GetCurrentHealth() <= 0)
      {
         delete (*currentEnemy);
         currentEnemy = temporaryEnemyList.erase(currentEnemy);
         mpCurrentMap->UpdateEnemyList(temporaryEnemyList);
      }
      else
      {
         currentEnemy++;
      }
   }
}

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
void PlayState::Draw(Graphics& theGraphics)
{
   mpCurrentSubState->Draw(theGraphics);
}

//***************************************************************************************************************************************************
// End Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Protected Method Definitions
//***************************************************************************************************************************************************



//***************************************************************************************************************************************************
// End Protected Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Private Method Definitions
//***************************************************************************************************************************************************



//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************