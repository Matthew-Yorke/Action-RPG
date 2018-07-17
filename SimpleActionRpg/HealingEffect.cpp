//***************************************************************************************************************************************************
//
// File Name: HealingEffect.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "HealingEffect.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: HealingEffect
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
HealingEffect::HealingEffect(int theMinimumEffect, int theMaximumEffect, std::vector<WorldConstants::STATUS_EFFECTS> theStatusEffectsHealed) :
Effect(theMinimumEffect, theMaximumEffect)
{
   mStatusEffectsHealed = theStatusEffectsHealed;
}

//*********************************************************************************************************************************************
//
// Method Name: Execute
//
// Description:
//  TODO: Add description.
//
//*********************************************************************************************************************************************
void HealingEffect::Execute(/*Target Objects*/)
{
   // Determine spell effect value.

   // Increase target health (up to maximum by final spell effect value).

   // Remove status effects from list of status effects healed.
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