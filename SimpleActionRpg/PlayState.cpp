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
   mpCurrentMap = new Map("../Maps/TestMap.txt");

   mpShadowLayer = new ShadowLayer("../Images/ShadowLayer.png");
   
   mpPlayer = new PlayerCharacter(theGraphics, 0, 0);
   
   mpMapAreaBoundary = new Rectangle(0,
                                     0,
                                     mpCurrentMap->GetMapWidth(),
                                     mpCurrentMap->GetMapHeight());
   mpCamera = new Camera(mpMapAreaBoundary, mpPlayer);
   
   mpGameClock = new Clock(6.0F);

   mpTestEnemy = new Enemy(theGraphics, 50, 50);
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
   if (mpTestEnemy != nullptr)
   {
      mpTestEnemy->Update(theTimeChange);
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

   //Check player weapon collision
   if (mpPlayer->GetMeleeWeapon()->GetIsWeaponSwinging() == true)
   {
      if (mpTestEnemy != nullptr &&
          mpPlayer->GetMeleeWeapon()->GetHitBox()->GetCoordinateX() < (mpTestEnemy->GetCoordinateX() + mpTestEnemy->GetWidth()) &&
          (mpPlayer->GetMeleeWeapon()->GetHitBox()->GetCoordinateX() + mpPlayer->GetMeleeWeapon()->GetHitBox()->GetWidth()) > mpTestEnemy->GetCoordinateX() &&
          mpPlayer->GetMeleeWeapon()->GetHitBox()->GetCoordinateY() < (mpTestEnemy->GetCoordinateY() + mpTestEnemy->GetHeight()) &&
          (mpPlayer->GetMeleeWeapon()->GetHitBox()->GetCoordinateY() + mpPlayer->GetMeleeWeapon()->GetHitBox()->GetHeight()) > mpTestEnemy->GetCoordinateY())
      {
          // collision detected!
         if (mpTestEnemy->GetIsInvincible() == false)
         {
            mpTestEnemy->TakeDamage(mpPlayer->GetMeleeWeapon()->GetDamage());
            mpTestEnemy->TemporaryInvincible();
            std::cout << "hit\n";

            if (mpTestEnemy->GetCurrentHealth() <= 0)
            {
               delete mpTestEnemy;
               mpTestEnemy = nullptr;
            }
         }
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
   if (mpCurrentMap != nullptr)
   {
      mpCurrentMap->Draw();
   }

   if (mpTestEnemy != nullptr)
   {
      mpTestEnemy->Draw(theGraphics);
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



//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************