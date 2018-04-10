//***************************************************************************************************************************************************
//
// File Name: MeleeWeapon.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include <allegro5/allegro_primitives.h>
#include "MeleeWeapon.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: MeleeWeapon
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
MeleeWeapon::MeleeWeapon(Graphics& theGraphics, int theDamage, int theCoordinateX, int theCoordinateY, int theWidth, int theHeight)
{
   mDamage = theDamage;
   mCoordinateX = theCoordinateX;
   mCoordinateY = theCoordinateY;
   mpSprite = new Sprite(theGraphics,
                         "../Images/TestSword.png",
                         theCoordinateX,
                         theCoordinateY,
                         theWidth,
                         theHeight);
   mpHitbox = new Rectangle(theCoordinateX,
                            theCoordinateY,
                            theWidth,
                            theHeight);
   mDirection = PlayerConstants::DIRECTION::DOWN;
}

//************************************************************************************************************************************************
//
// Method Name: DrawSprite
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  theGraphics - TODO: Add description.
//
// Return:
//  N/A
//
//************************************************************************************************************************************************
void MeleeWeapon::DrawSprite(Graphics& theGraphics, int theCoordianteX, int theCoordinateY)
{
   if (mDirection == PlayerConstants::DIRECTION::DOWN)
   {
      mpSprite->SetAngle(0);
      mpSprite->Draw(theGraphics,
                     theCoordianteX + 10 - 3,
                     theCoordinateY + 25);
   }
   else if (mDirection == PlayerConstants::DIRECTION::UP)
   {
      mpSprite->SetAngle(180 * (3.14/180));
      mpSprite->Draw(theGraphics,
                     theCoordianteX + 20 - 3,
                     theCoordinateY + 5 - 16);
   }
   else if (mDirection == PlayerConstants::DIRECTION::LEFT)
   {
      mpSprite->SetAngle(90 * (3.14/180));
      mpSprite->Draw(theGraphics,
                     theCoordianteX + 2 - 8,
                     theCoordinateY + 14 - 7);
   }
   else if (mDirection == PlayerConstants::DIRECTION::RIGHT)
   {
      mpSprite->SetAngle(270 * (3.14/180));
      mpSprite->Draw(theGraphics,
                     theCoordianteX + 29,
                     theCoordinateY + 14 - 7);
   }
   else
   {
      mpSprite->Draw(theGraphics,
                     static_cast<int>(mCoordinateX),
                     static_cast<int>(mCoordinateY));
      al_draw_rectangle(mCoordinateX + 10, mCoordinateY, mCoordinateX + 10 + 12, mCoordinateY + 32, al_map_rgb(255,0,0), 1.0F);
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