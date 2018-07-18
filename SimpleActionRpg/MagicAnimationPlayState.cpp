//***************************************************************************************************************************************************
//
// File Name: MagicAnimationPlayState.cpp
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
#include "MagicAnimationPlayState.h"
#include "PlayerCharacter.h"
#include "RegularPlayState.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: MagicAnimationPlayState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
MagicAnimationPlayState::MagicAnimationPlayState(PlayState* pThePlayState, Magic* theCastedSpell, std::vector<Character*> theAffectedCharacters) :
PlaySubState(pThePlayState)
{
   mpCastedSpell = theCastedSpell;
   mAffectedCharacters = theAffectedCharacters;
}

//************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void MagicAnimationPlayState::Update(float theTimeChange)
{
   // Update magic animation.
   for (auto iterator = mAffectedCharacters.begin();
        iterator != mAffectedCharacters.end();
        iterator++)
   {
      mpCastedSpell->ExecuteSpell(*iterator);
   }
   mpPlayeState->ChangeSubState(new RegularPlayState(mpPlayeState));
}

//************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void MagicAnimationPlayState::Draw(Graphics& theGraphics)
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

   // Magic animation.
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