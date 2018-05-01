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
   mpCurrentMap = new Map(&theGraphics, "../Maps/TestMap.txt");

   mpShadowLayer = new ShadowLayer("../Images/ShadowLayer.png");
   
   mpPlayer = new PlayerCharacter(theGraphics, 64, 64);
   
   mpMapAreaBoundary = new Rectangle(0,
                                     0,
                                     mpCurrentMap->GetMapWidth(),
                                     mpCurrentMap->GetMapHeight());
   mpCamera = new Camera(mpMapAreaBoundary, mpPlayer);
   
   mpGameClock = new Clock(6.0F);
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
   mpPlayer->KeyDown(theEvent);
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
   mpPlayer->KeyUp(theEvent);
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
   std::vector<Enemy*> temporaryEnemyList = mpCurrentMap->GetEnemyList();
   for (auto currentEnemy = temporaryEnemyList.begin();
        currentEnemy != temporaryEnemyList.end();
        currentEnemy++)
   {
      (*currentEnemy)->Update(theTimeChange);
   }

   mpPlayer->Update(theTimeChange);
   mpGameClock->Update(theTimeChange);
   mpCamera->Update();
   mpShadowLayer->CameraUpdate(mpCamera);

   if (mpGameClock->GetTotalMinutes() <= (12 * 60)) // Note: 12 * 60 is the total minutes in 12 hours.
   {
      mpShadowLayer->SetIntensity(0.28F * mpGameClock->GetTotalMinutes()); // Note: 202 is max intensity.
   }
   else
   {
      mpShadowLayer->SetIntensity(abs((0.28F * mpGameClock->GetTotalMinutes()) - 404));
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
void PlayState::Draw(Graphics& theGraphics)
{
   if (mpCurrentMap != nullptr)
   {
      mpCurrentMap->Draw();
   }

   std::vector<Enemy*> temporaryEnemyList = mpCurrentMap->GetEnemyList();
   for (auto currentEnemy = temporaryEnemyList.begin();
        currentEnemy != temporaryEnemyList.end();
        currentEnemy++)
   {
      (*currentEnemy)->Draw(theGraphics);
   }

   if (mpPlayer != nullptr)
   {
      mpPlayer->Draw(theGraphics);
   }

   if (mpShadowLayer != nullptr)
   {
      mpShadowLayer->Draw(theGraphics);
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

//************************************************************************************************************************************************
//
// Method Name: CollisionDeterction
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
bool PlayState::CollisionDetection(Rectangle* theRectangleOne, Rectangle* theRectangleTwo)
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
void PlayState::PlayerAttackCollision()
{
   // Determine if the player is attacking with their weapon.
   if (mpPlayer->GetMeleeWeapon()->GetIsWeaponSwinging() == true)
   {
      std::vector<Enemy*> temporaryEnemyList = mpCurrentMap->GetEnemyList();
      // Traverse the list of enemy NPCs that can be hit by the player,
      for (auto currentEnemy = temporaryEnemyList.begin();
           currentEnemy != temporaryEnemyList.end();)
      {
         // Check if there is collision between the NPC that is not currently invincible and the weapon.
         if ((*currentEnemy)->GetIsInvincible() == false &&
             CollisionDetection(mpPlayer->GetMeleeWeapon()->GetHitBox(), (*currentEnemy)->GetHitBox()) == true)
         {
            (*currentEnemy)->TakeDamage(mpPlayer->GetMeleeWeapon()->GetDamage());
            (*currentEnemy)->TemporaryInvincible();
            
            // Check if the enemy NPC has depleted their life
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
void PlayState::MapNonTraverableMapTileCollision()
{
   bool nonTraversableTileCollision = mpCurrentMap->NonTraverableTileCollision(mpPlayer->GetMovementHitBox());

   if (nonTraversableTileCollision)
   {
      switch(mpPlayer->GetDirection())
      {
         case PlayerConstants::DIRECTION::DOWN:
         {
            mpPlayer->SetCoordinateY(mpPlayer->GetCoordinateY() - mpPlayer->GetVelocity()->GetComponentY());
            break;
         }
         case PlayerConstants::DIRECTION::UP:
         {
            mpPlayer->SetCoordinateY(mpPlayer->GetCoordinateY() + mpPlayer->GetVelocity()->GetComponentY());
            break;
         }
         case PlayerConstants::DIRECTION::LEFT:
         {
            mpPlayer->SetCoordinateX(mpPlayer->GetCoordinateX() + mpPlayer->GetVelocity()->GetComponentY());
            break;
         }
         case PlayerConstants::DIRECTION::RIGHT:
         {
            mpPlayer->SetCoordinateX(mpPlayer->GetCoordinateX() - mpPlayer->GetVelocity()->GetComponentY());
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
void PlayState::MapEventCollision()
{
   Map* temporaryMap = nullptr;
   int playerCoordinateX = mpPlayer->GetCoordinateX();
   int playerCoordinateY = mpPlayer->GetCoordinateY();
   bool changeMap = mpCurrentMap->ChangeMapEventCollision(mpPlayer->GetMovementHitBox(),
                                                          temporaryMap,
                                                          playerCoordinateX,
                                                          playerCoordinateY);

   if(changeMap == true)
   {
      delete mpCurrentMap;
      mpCurrentMap = temporaryMap;

      mpPlayer->SetCoordinateX(playerCoordinateX);
      mpPlayer->SetCoordinateY(playerCoordinateY);
   }
}

//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************