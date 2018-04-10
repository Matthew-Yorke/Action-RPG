//***************************************************************************************************************************************************
//
// File Name: MeleeAttackState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "MeleeAttackState.h"
#include "IdleState.h"
#include "MovingState.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: MovingState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
MeleeAttackState::MeleeAttackState()
{
   mAttackTimeRemaining = 0.3F;
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
void MeleeAttackState::KeyDown(ALLEGRO_EVENT theEvent)
{
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->mDownPressed = true;
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->mLeftPressed = true;
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->mRightPressed = true;
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->mUpPressed = true;
         break;
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
void MeleeAttackState::KeyUp(ALLEGRO_EVENT theEvent)
{
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->mDownPressed = false;
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->mLeftPressed = false;
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->mRightPressed = false;
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->mUpPressed = false;
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
// Arguments:
//  N/A
//
// Return:
//  N/A
//
//************************************************************************************************************************************************
void MeleeAttackState::Update(float theTimeChange)
{
   mAttackTimeRemaining -= theTimeChange;

   if (mAttackTimeRemaining < 0.0F)
   {
      
      
      if (mpPlayerCharacter->mDownPressed == true ||
          mpPlayerCharacter->mLeftPressed == true ||
          mpPlayerCharacter->mRightPressed == true ||
          mpPlayerCharacter->mUpPressed == true)
      {
         if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::DOWN)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(32, 4);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(64, 4);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(96, 4);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(128, 4);
         }

         mpPlayerCharacter->ChangeState(new MovingState());
      }
      else
      {
         if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::DOWN)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(32, 1);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(64, 1);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(96, 1);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(128, 1);
         }

         mpPlayerCharacter->ChangeState(new IdleState());
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
void MeleeAttackState::Draw(Graphics& theGraphics)
{
   if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::DOWN)
   {
      mpPlayerCharacter->GetSprite()->SetAnimationSourceX(0);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY(160, 1);
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics, mpPlayerCharacter->GetCoordinateX(), mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
   {
      mpPlayerCharacter->GetSprite()->SetAnimationSourceX(0);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY(224, 1);
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics, mpPlayerCharacter->GetCoordinateX(), mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
   {
      mpPlayerCharacter->GetSprite()->SetAnimationSourceX(0);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY( 256, 1);
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics, mpPlayerCharacter->GetCoordinateX(), mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
   {
      mpPlayerCharacter->GetSprite()->SetAnimationSourceX(0);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY(192, 1);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics, mpPlayerCharacter->GetCoordinateX(), mpPlayerCharacter->GetCoordinateY());
      mpPlayerCharacter->DrawSprite(theGraphics);
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