//***************************************************************************************************************************************************
//
// File Name: IdleState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "IdleState.h"
#include "MovingState.h"
#include "MeleeAttackState.h"
#include "PlayerConstants.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: IdleState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
IdleState::IdleState(PlayerCharacter* thePlayerCharacter) :
State(thePlayerCharacter)
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
void IdleState::KeyDown(ALLEGRO_EVENT theEvent)
{
   // Track that a key was pressed down and enter that action's state.
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::DOWN);
         mpPlayerCharacter->GetSprite()->SetAnimationSourceY(0,
                                                             4);
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::DOWN);
         mpPlayerCharacter->ChangeState(new MovingState(mpPlayerCharacter));
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::UP);
         mpPlayerCharacter->GetSprite()->SetAnimationSourceY(64,
                                                             4);
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::UP);
         mpPlayerCharacter->ChangeState(new MovingState(mpPlayerCharacter));
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::RIGHT);
         mpPlayerCharacter->GetSprite()->SetAnimationSourceY(128,
                                                             4);
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::RIGHT);
         mpPlayerCharacter->ChangeState(new MovingState(mpPlayerCharacter));
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::LEFT);
         mpPlayerCharacter->GetSprite()->SetAnimationSourceY(192,
                                                             4);
         mpPlayerCharacter->InsertMovementDirection(PlayerConstants::DIRECTION::LEFT);
         mpPlayerCharacter->ChangeState(new MovingState(mpPlayerCharacter));
         break;
      }
      case ALLEGRO_KEY_Z:
      {
         mpPlayerCharacter->GetSprite()->SetAnimationSourceY(256,
                                                             3);
         mpPlayerCharacter->GetSprite()->SetAnimationSourceX(0);
         mpPlayerCharacter->GetMeleeWeapon()->GetSprite()->SetAnimationSourceX(0);
         mpPlayerCharacter->GetSprite()->ResetFrames();
         mpPlayerCharacter->GetMeleeWeapon()->GetSprite()->ResetFrames();
         mpPlayerCharacter->ChangeState(new MeleeAttackState(mpPlayerCharacter));
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
void IdleState::KeyUp(ALLEGRO_EVENT theEvent)
{
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
void IdleState::Draw(Graphics& theGraphics)
{
   mpPlayerCharacter->DrawSprite(theGraphics);
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