//***************************************************************************************************************************************************
//
// File Name: RegularPlayState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include <vector>
#include "RegularPlayState.h"
#include "CastMagicPlayState.h"
#include "PlayerCharacter.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: RegularPlayState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
RegularPlayState::RegularPlayState(PlayState* pThePlayState) :
PlaySubState(pThePlayState)
{
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
void RegularPlayState::KeyDown(ALLEGRO_EVENT theEvent)
{
   mpPlayeState->mpPlayer->KeyDown(theEvent);

   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_X:
      {
         mpPlayeState->ChangeSubState(new CastMagicPlayState(mpPlayeState, mpPlayeState->mpPlayer->GetCurrentSpell()));
      }
   }
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
void RegularPlayState::KeyUp(ALLEGRO_EVENT theEvent)
{
   mpPlayeState->mpPlayer->KeyUp(theEvent);
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
void RegularPlayState::Update(float theTimeChange)
{
   std::vector<Enemy*> temporaryEnemyList = mpPlayeState->mpCurrentMap->GetEnemyList();
   for (auto currentEnemy = temporaryEnemyList.begin();
        currentEnemy != temporaryEnemyList.end();
        currentEnemy++)
   {
      (*currentEnemy)->Update(theTimeChange);
   }

   mpPlayeState->mpPlayer->Update(theTimeChange);
   mpPlayeState->mpPlayer->SetCurrentTile(mpPlayeState->mpCurrentMap->GetClosestTile(mpPlayeState->mpPlayer->GetMovementHitBox()->GetCoordinateX() + mpPlayeState->mpPlayer->GetMovementHitBox()->GetWidthCenterPoint(),
                                                                                     mpPlayeState->mpPlayer->GetMovementHitBox()->GetCoordinateY() + mpPlayeState->mpPlayer->GetMovementHitBox()->GetHeightCenterPoint()));

   auto enemyList = mpPlayeState->mpCurrentMap->GetEnemyList();
   for (auto iterator = enemyList.begin(); iterator != enemyList.end(); iterator++)
   {
      (*iterator)->SetCurrentTile(mpPlayeState->mpCurrentMap->GetClosestTile((*iterator)->GetMovementHitBox()->GetCoordinateX() + (*iterator)->GetMovementHitBox()->GetWidthCenterPoint(),
                                                                             (*iterator)->GetMovementHitBox()->GetCoordinateY() + (*iterator)->GetMovementHitBox()->GetHeightCenterPoint()));
   }

   mpPlayeState->mpGameClock->Update(theTimeChange);
   mpPlayeState->mpCamera->Update();
   mpPlayeState->mpShadowLayer->CameraUpdate(mpPlayeState->mpCamera);

   if (mpPlayeState->mpGameClock->GetTotalMinutes() <= (12 * 60)) // Note: 12 * 60 is the total minutes in 12 hours.
   {
      mpPlayeState->mpShadowLayer->SetOpacity(0.28F * mpPlayeState->mpGameClock->GetTotalMinutes()); // Note: 202 is max intensity.
   }
   else
   {
      mpPlayeState->mpShadowLayer->SetOpacity(abs((0.28F * mpPlayeState->mpGameClock->GetTotalMinutes()) - 404));
   }

   mpPlayeState->PathUpdateTime -= theTimeChange;
   if (mpPlayeState->mpCurrentMap != nullptr && mpPlayeState->PathUpdateTime < 0)
   {
      mpPlayeState->mpCurrentMap->FindPaths(mpPlayeState->mpPlayer->GetCurrentTile());
      mpPlayeState->PathUpdateTime = 0.2F;
   }

   PlayerAttackCollision();
   MapEventCollision();
   MapNonTraverableMapTileCollision();
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
void RegularPlayState::Draw(Graphics& theGraphics)
{
   if (mpPlayeState->mpCurrentMap != nullptr)
   {
      mpPlayeState->mpCurrentMap->Draw();
   }

   std::vector<Enemy*> temporaryEnemyList = mpPlayeState->mpCurrentMap->GetEnemyList();
   for (auto currentEnemy = temporaryEnemyList.begin();
        currentEnemy != temporaryEnemyList.end();
        currentEnemy++)
   {
      (*currentEnemy)->Draw(theGraphics);
   }

   if (mpPlayeState->mpPlayer != nullptr)
   {
      mpPlayeState->mpPlayer->Draw(theGraphics);
   }

   if (mpPlayeState->mpShadowLayer != nullptr)
   {
      mpPlayeState->mpShadowLayer->Draw(theGraphics);
   }
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