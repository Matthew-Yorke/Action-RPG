//***************************************************************************************************************************************************
//
// File Name: PlaySubState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "PlaySubState.h"
#include "Map.h"
#include "ShadowLayer.h"
#include "Clock.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: PlaySubState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
PlaySubState::PlaySubState(PlayState* pThePlayState)
{
   mpPlayeState = pThePlayState;
}

//***************************************************************************************************************************************************
// End Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Protected Method Definitions
//***************************************************************************************************************************************************

//************************************************************************************************************************************************
//
// Method Name: CollisionDeterction
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
bool PlaySubState::CollisionDetection(RectangleObject* theRectangleOne, RectangleObject* theRectangleTwo)
{
   bool collisionOccurred = false;

   if (theRectangleOne->GetCoordinateX() < (theRectangleTwo->GetCoordinateX() + theRectangleTwo->GetWidth()) &&
       (theRectangleOne->GetCoordinateX() + theRectangleOne->GetWidth()) > theRectangleTwo->GetCoordinateX() &&
       theRectangleOne->GetCoordinateY() < (theRectangleTwo->GetCoordinateY() + theRectangleTwo->GetHeight()) &&
       (theRectangleOne->GetCoordinateY() + theRectangleOne->GetHeight()) > theRectangleTwo->GetCoordinateY())
   {
      collisionOccurred = true;
   }

   return collisionOccurred;
}

//************************************************************************************************************************************************
//
// Method Name: PlayerAttackCollision
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlaySubState::PlayerAttackCollision()
{
   // Determine if the player is attacking with their weapon.
   if (mpPlayeState->mpPlayer->GetMeleeWeapon()->GetIsWeaponSwinging() == true)
   {
      std::vector<Enemy*> temporaryEnemyList = mpPlayeState->mpCurrentMap->GetEnemyList();
      // Traverse the list of enemy NPCs that can be hit by the player,
      for (auto currentEnemy = temporaryEnemyList.begin();
           currentEnemy != temporaryEnemyList.end();)
      {
         // Check if there is collision between the NPC that is not currently invincible and the weapon.
         if ((*currentEnemy)->GetIsInvincible() == false &&
             CollisionDetection(mpPlayeState->mpPlayer->GetMeleeWeapon()->GetHitBox(), (*currentEnemy)->GetHitBox()) == true)
         {
            (*currentEnemy)->TakeDamage(mpPlayeState->mpPlayer->GetMeleeWeapon()->GetDamage());
            (*currentEnemy)->TemporaryInvincible();
            
            // Check if the enemy NPC has depleted their life
            if ((*currentEnemy)->GetCurrentHealth() <= 0)
            {
               delete (*currentEnemy);
               currentEnemy = temporaryEnemyList.erase(currentEnemy);
               mpPlayeState->mpCurrentMap->UpdateEnemyList(temporaryEnemyList);
            }
            else
            {
               currentEnemy++;
            }
         }
         else
         {
            currentEnemy++;
         }
      }
   }
}

//*********************************************************************************************************************************************
//
// Method Name: MapNonTraverableMapTileCollision
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
void PlaySubState::MapNonTraverableMapTileCollision()
{
   bool nonTraversableTileCollision = mpPlayeState->mpCurrentMap->NonTraverableTileCollision(mpPlayeState->mpPlayer->GetMovementHitBox());

   if (nonTraversableTileCollision)
   {
      switch(mpPlayeState->mpPlayer->GetDirection())
      {
         case PlayerConstants::DIRECTION::DOWN:
         {
            mpPlayeState->mpPlayer->SetCoordinateY(mpPlayeState->mpPlayer->GetCoordinateY() - mpPlayeState->mpPlayer->GetVelocity()->GetComponentY());
            break;
         }
         case PlayerConstants::DIRECTION::UP:
         {
            mpPlayeState->mpPlayer->SetCoordinateY(mpPlayeState->mpPlayer->GetCoordinateY() + mpPlayeState->mpPlayer->GetVelocity()->GetComponentY());
            break;
         }
         case PlayerConstants::DIRECTION::LEFT:
         {
            mpPlayeState->mpPlayer->SetCoordinateX(mpPlayeState->mpPlayer->GetCoordinateX() + mpPlayeState->mpPlayer->GetVelocity()->GetComponentY());
            break;
         }
         case PlayerConstants::DIRECTION::RIGHT:
         {
            mpPlayeState->mpPlayer->SetCoordinateX(mpPlayeState->mpPlayer->GetCoordinateX() - mpPlayeState->mpPlayer->GetVelocity()->GetComponentY());
            break;
         }
      }
   }
}

//************************************************************************************************************************************************
//
// Method Name: MapEventCollision
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void PlaySubState::MapEventCollision()
{
   std::string mapFileLocation = "";
   Map* temporaryMap = nullptr;
   int playerCoordinateX = mpPlayeState->mpPlayer->GetCoordinateX();
   int playerCoordinateY = mpPlayeState->mpPlayer->GetCoordinateY();
   bool changeMap = false;

   std::vector<ChangeMapEvent*> changeMapList = mpPlayeState->mpEventStorage->GetChangeMapEvents();
   for (auto pCurrentChangeMapEvent = changeMapList.begin();
        pCurrentChangeMapEvent != changeMapList.end();
        pCurrentChangeMapEvent++)
   {
      changeMap = CollisionDetection(mpPlayeState->mpPlayer->GetMovementHitBox(), (*pCurrentChangeMapEvent)->GetArea());

      if (changeMap == true)
      {
         playerCoordinateX = (*pCurrentChangeMapEvent)->GetObjectDestinationCoordinateX();
         playerCoordinateY = (*pCurrentChangeMapEvent)->GetObjectDestinationCoordinateY();
         mapFileLocation = (*pCurrentChangeMapEvent)->GetMapFileLocation();
         mpPlayeState->mpEventStorage->ClearEvents();
         temporaryMap = new Map(mpPlayeState->mpGraphics, mapFileLocation);
         break;
      }
   }

   if(changeMap == true)
   {
      delete mpPlayeState->mpCurrentMap;
      mpPlayeState->mpCurrentMap = temporaryMap;

      mpPlayeState->mpPlayer->SetCoordinateX(playerCoordinateX);
      mpPlayeState->mpPlayer->SetCoordinateY(playerCoordinateY);
   }
}

//***************************************************************************************************************************************************
// End Protected Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Private Method Definitions
//***************************************************************************************************************************************************



//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************