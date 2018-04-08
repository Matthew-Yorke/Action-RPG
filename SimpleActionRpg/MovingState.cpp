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
         mpPlayerCharacter->GetVelocity()->SetComponentY(-1.0F);
         break;
      }
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->GetVelocity()->SetComponentY(1.0F);
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->GetVelocity()->SetComponentX(-1.0F);
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->GetVelocity()->SetComponentX(1.0F);
         break;
      }
      case ALLEGRO_KEY_Z:
      {
         //mpPlayerCharacter->ChangeState(new MovingState());
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
         mpPlayerCharacter->GetVelocity()->SetComponentY(0.0F);
         mpPlayerCharacter->ChangeState(new IdleState());
         break;
      }
      case ALLEGRO_KEY_DOWN:
      {
         mpPlayerCharacter->GetVelocity()->SetComponentY(0.0F);
         mpPlayerCharacter->ChangeState(new IdleState());
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mpPlayerCharacter->GetVelocity()->SetComponentX(0.0F);
         mpPlayerCharacter->ChangeState(new IdleState());
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mpPlayerCharacter->GetVelocity()->SetComponentX(0.0F);
         mpPlayerCharacter->ChangeState(new IdleState());
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
void MovingState::Update(float theTimeChange)
{
   mpPlayerCharacter->SetCoordinateX(mpPlayerCharacter->GetCoordinateX() + mpPlayerCharacter->GetVelocity()->GetComponentX());
   mpPlayerCharacter->SetCoordinateY(mpPlayerCharacter->GetCoordinateY() + mpPlayerCharacter->GetVelocity()->GetComponentY());
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