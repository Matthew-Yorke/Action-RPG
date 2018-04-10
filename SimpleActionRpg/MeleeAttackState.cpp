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
   mAttackTimeRemaining = 0.5F;
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
      if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::DOWN)
      {
         mpPlayerCharacter->GetSprite()->SetNewAnimation(32, 32, 1);
      }
      else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
      {
         mpPlayerCharacter->GetSprite()->SetNewAnimation(32, 128, 1);
      }
      else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
      {
         mpPlayerCharacter->GetSprite()->SetNewAnimation(32, 64, 1);
      }
      else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
      {
         mpPlayerCharacter->GetSprite()->SetNewAnimation(32, 96, 1);
      }

      mpPlayerCharacter->ChangeState(new IdleState());
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
      mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 160, 1);
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics, mpPlayerCharacter->GetCoordinateX(), mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::LEFT)
   {
      mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 224, 1);
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics, mpPlayerCharacter->GetCoordinateX(), mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::RIGHT)
   {
      mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 256, 1);
      mpPlayerCharacter->DrawSprite(theGraphics);
      mpPlayerCharacter->GetMeleeWeapon()->DrawSprite(theGraphics, mpPlayerCharacter->GetCoordinateX(), mpPlayerCharacter->GetCoordinateY());
   }
   else if (mpPlayerCharacter->GetDirection() == PlayerConstants::DIRECTION::UP)
   {
      mpPlayerCharacter->GetSprite()->SetNewAnimation(0, 192, 1);
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