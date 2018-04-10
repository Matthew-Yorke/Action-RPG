//***************************************************************************************************************************************************
//
// File Name: MovingState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "MovingState.h"
#include "IdleState.h"
#include "MeleeAttackState.h"

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
MovingState::MovingState()
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
void MovingState::KeyDown(ALLEGRO_EVENT theEvent)
{
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::UP);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 128, 4);
         mpPlayerCharacter->mUpPressed = false;
         break;
      }
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::DOWN);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 32, 4);
         mpPlayerCharacter->mDownPressed = false;
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::LEFT);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 64, 4);
         mpPlayerCharacter->mLeftPressed = false;
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::RIGHT);
         mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 96, 4);
         mpPlayerCharacter->mRightPressed = false;
         break;
      }
      case ALLEGRO_KEY_Z:
      {
         mpPlayerCharacter->mUpPressed = false;
         mpPlayerCharacter->mDownPressed = false;
         mpPlayerCharacter->mLeftPressed = false;
         mpPlayerCharacter->mRightPressed = false;
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
void MovingState::KeyUp(ALLEGRO_EVENT theEvent)
{
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_UP:
      {
         mpPlayerCharacter->mUpPressed = false;
         break;
      }
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
   }

   if (mpPlayerCharacter->mUpPressed == false &&
       mpPlayerCharacter->mDownPressed == false &&
       mpPlayerCharacter->mLeftPressed == false &&
       mpPlayerCharacter->mRightPressed == false)
   {
      mpPlayerCharacter->ChangeState(new IdleState());
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
void MovingState::Update(float theTimeChange)
{
   if (mpPlayerCharacter->mUpPressed == true)
   {
      mpPlayerCharacter->SetCoordinateY(mpPlayerCharacter->GetCoordinateY() - mpPlayerCharacter->GetVelocity()->GetComponentY());
   }
   else if (mpPlayerCharacter->mDownPressed == true)
   {
      mpPlayerCharacter->SetCoordinateY(mpPlayerCharacter->GetCoordinateY() + mpPlayerCharacter->GetVelocity()->GetComponentY());
   }
   else if (mpPlayerCharacter->mLeftPressed == true)
   {
      mpPlayerCharacter->SetCoordinateX(mpPlayerCharacter->GetCoordinateX() - mpPlayerCharacter->GetVelocity()->GetComponentX());
   }
   else if (mpPlayerCharacter->mRightPressed == true)
   {
      mpPlayerCharacter->SetCoordinateX(mpPlayerCharacter->GetCoordinateX() + mpPlayerCharacter->GetVelocity()->GetComponentX());
   }
   
   mpPlayerCharacter->GetSprite()->Update(theTimeChange);
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
void MovingState::Draw(Graphics& theGraphics)
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