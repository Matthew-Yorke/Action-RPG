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
IdleState::IdleState()
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
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::UP);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 128, 4);
         mpPlayerCharacter->mUpPressed = true;
         mpPlayerCharacter->ChangeState(new MovingState());
         break;
      }
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::DOWN);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 32, 4);
         mpPlayerCharacter->mDownPressed = true;
         mpPlayerCharacter->ChangeState(new MovingState());
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::LEFT);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 64, 4);
         mpPlayerCharacter->mLeftPressed = true;
         mpPlayerCharacter->ChangeState(new MovingState());
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::RIGHT);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 96, 4);
         mpPlayerCharacter->mRightPressed = true;
         mpPlayerCharacter->ChangeState(new MovingState());
         break;
      }
      case ALLEGRO_KEY_Z:
      {
         mpPlayerCharacter->ChangeState(new MeleeAttackState());
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