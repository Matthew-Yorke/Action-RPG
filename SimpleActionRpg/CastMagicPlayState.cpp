//***************************************************************************************************************************************************
//
// File Name: CastMagicPlayState.cpp
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
#include "CastMagicPlayState.h"
#include "PlayerCharacter.h"
#include "MagicAnimationPlayState.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: CastMagicPlayState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
CastMagicPlayState::CastMagicPlayState(PlayState* pThePlayState) :
PlaySubState(pThePlayState)
{
   mpSpellArea = new CircleObject(pThePlayState->mpPlayer->GetCoordinateX() + pThePlayState->mpPlayer->GetWidthCenterPoint(),
                                  pThePlayState->mpPlayer->GetCoordinateY() + pThePlayState->mpPlayer->GetHeightCenterPoint(),
                                  50.0F);

   mIsUpPressed = false;
   mIsDownPressed = false;
   mIsLeftPressed = false;
   mIsRightPressed = false;
}

//************************************************************************************************************************************************
//
// Method Name: KeyDown
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void CastMagicPlayState::KeyDown(ALLEGRO_EVENT theEvent)
{
   // Track that a key was pressed down and enter that action's state.
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mIsDownPressed = true;
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mIsUpPressed = true;
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mIsRightPressed = true;
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mIsLeftPressed = true;
         break;
      }
      case ALLEGRO_KEY_Z:
      {
         mpPlayeState->ChangeSubState(new MagicAnimationPlayState(mpPlayeState));
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
//************************************************************************************************************************************************
void CastMagicPlayState::KeyUp(ALLEGRO_EVENT theEvent)
{
   // Track that a key was pressed down and enter that action's state.
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mIsDownPressed = false;
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mIsUpPressed = false;
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mIsRightPressed = false;
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mIsLeftPressed = false;
         break;
      }
   }
}

//************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void CastMagicPlayState::Update(float theTimeChange)
{
   // Vertical direction.
   if (mIsDownPressed == true)
   {
      mpSpellArea->SetCoordinateY(mpSpellArea->GetCoordinateY() + 1);
   }
   else if (mIsUpPressed == true)
   {
      mpSpellArea->SetCoordinateY(mpSpellArea->GetCoordinateY() - 1);
   }
   
   // Horizontal direction.
   if (mIsRightPressed == true)
   {
      mpSpellArea->SetCoordinateX(mpSpellArea->GetCoordinateX() + 1);
   }
   else if (mIsLeftPressed == true)
   {
      mpSpellArea->SetCoordinateX(mpSpellArea->GetCoordinateX() - 1);
   }
}

//************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void CastMagicPlayState::Draw(Graphics& theGraphics)
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

   // Selector
   al_draw_filled_circle(mpSpellArea->GetCoordinateX(), mpSpellArea->GetCoordinateY(), mpSpellArea->GetRadius(), al_map_rgba(255, 0, 0, 100));
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