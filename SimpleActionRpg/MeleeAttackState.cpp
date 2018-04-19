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
#include <algorithm>

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
MeleeAttackState::MeleeAttackState(PlayerCharacter* thePlayerCharacter) :
State(thePlayerCharacter)
{
   mAttackTimeRemaining = 0.45F;
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
   // Track that an additional movement key was pressed
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::DOWN);
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::LEFT);
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::RIGHT);
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::UP);
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
   // Track that a movement key was let go.
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->RemoveMovementDirection(PlayerConstants::DIRECTION::DOWN);
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->RemoveMovementDirection(PlayerConstants::DIRECTION::LEFT);
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->RemoveMovementDirection(PlayerConstants::DIRECTION::RIGHT);
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->RemoveMovementDirection(PlayerConstants::DIRECTION::UP);
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
   //mpPlayerCharacter->GetSprite()->SetAnimationSourceY(256,
   //                                                    3);
   mpPlayerCharacter->GetSprite()->Update(theTimeChange);
   mpPlayerCharacter->GetMeleeWeapon()->GetSprite()->Update(theTimeChange);

   if (mAttackTimeRemaining < 0.0F)
   {
      if (mpPlayerCharacter->IsMovingDirectionEmpty() == false)
      {
         if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::DOWN)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(0,
                                                                4);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(64,
                                                                4);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(128,
                                                                4);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(192,
                                                                4);
         }

         mpPlayerCharacter->ChangeState(new MovingState(mpPlayerCharacter));
      }
      else
      {
         if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::DOWN)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(0,
                                                                1);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(64,
                                                                1);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(128,
                                                                1);
         }
         else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
         {
            mpPlayerCharacter->GetSprite()->SetAnimationSourceY(192,
                                                                1);
         }

         mpPlayerCharacter->ChangeState(new IdleState(mpPlayerCharacter));
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
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics,
                                                      mpPlayerCharacter->GetCoordinateX() - 10,
                                                      mpPlayerCharacter->GetCoordinateY() - 21);
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
   {
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics,
                                                      mpPlayerCharacter->GetCoordinateX(),
                                                      mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
   {
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics,
                                                      mpPlayerCharacter->GetCoordinateX(),
                                                      mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
   {
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics,
                                                      mpPlayerCharacter->GetCoordinateX(),
                                                      mpPlayerCharacter->GetCoordinateY());
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