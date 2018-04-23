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
MovingState::MovingState(PlayerCharacter* thePlayerCharacter) :
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
void MovingState::KeyDown(ALLEGRO_EVENT theEvent)
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
      case ALLEGRO_KEY_Z:
      {
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
void MovingState::KeyUp(ALLEGRO_EVENT theEvent)
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

   if (mpPlayerCharacter->IsMovingDirectionEmpty() == true)
   {
      mpPlayerCharacter->GetSprite()->SetAnimationSourceX(0);
      mpPlayerCharacter->GetSprite()->ResetFrames();
      mpPlayerCharacter->ChangeState(new IdleState(mpPlayerCharacter));
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
   PlayerConstants::DIRECTION currentDirection = mpPlayerCharacter->GetFrontOfMovingDirectionVector();

   if (currentDirection == PlayerConstants::DIRECTION::DOWN)
   {
      mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::DOWN);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY(0,
                                                          4);
      mpPlayerCharacter->SetCoordinateY(mpPlayerCharacter->GetCoordinateY() + mpPlayerCharacter->GetVelocity()->GetComponentY());
   } 
   else if (currentDirection == PlayerConstants::DIRECTION::UP)
   {
      mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::UP);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY(64,
                                                          4);
      mpPlayerCharacter->SetCoordinateY(mpPlayerCharacter->GetCoordinateY() - mpPlayerCharacter->GetVelocity()->GetComponentY());
   }
   else if (currentDirection == PlayerConstants::DIRECTION::RIGHT)
   {
      mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::RIGHT);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY(128,
                                                          4);
      mpPlayerCharacter->SetCoordinateX(mpPlayerCharacter->GetCoordinateX() + mpPlayerCharacter->GetVelocity()->GetComponentX());
   }
   else if (currentDirection == PlayerConstants::DIRECTION::LEFT)
   {
      mpPlayerCharacter->SetDirection(PlayerConstants::DIRECTION::LEFT);
      mpPlayerCharacter->GetSprite()->SetAnimationSourceY(192,
                                                          4);
      mpPlayerCharacter->SetCoordinateX(mpPlayerCharacter->GetCoordinateX() - mpPlayerCharacter->GetVelocity()->GetComponentX());
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