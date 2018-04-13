//***************************************************************************************************************************************************
//
// File Name: MeleeWeapon.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef MeleeWeapon_H
#define MeleeWeapon_H

#include "PlayerConstants.h"
#include "Sprite.h"
#include "Rectangle.h"

class MeleeWeapon
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //************************************************************************************************************************************************
      //
      // Method Name: MeleeWeapons
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
      MeleeWeapon(Graphics& theGraphics, int theDamage, int theCoordinateX, int theCoordinateY, int theWidth, int theHeight);

      //************************************************************************************************************************************************
      //
      // Method Name: GetCoordinateX
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      float GetCoordinateX();

      //************************************************************************************************************************************************
      //
      // Method Name: SetCoordinateX
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theCoordinateX - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void SetCoordinateX(float theCoordinateX);

      //************************************************************************************************************************************************
      //
      // Method Name: GetCoordinateY
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      float GetCoordinateY();

      //************************************************************************************************************************************************
      //
      // Method Name: SetCoordinateY
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theCoordinateY - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void SetCoordinateY(float theCoordinateY);

      //************************************************************************************************************************************************
      //
      // Method Name: SetDirection
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theDirection - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void SetDirection(PlayerConstants::DIRECTION theDirection);

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
      void DrawSprite(Graphics& theGraphics, int theCoordianteX, int theCoordinateY);

   protected:

      // There are currently no protected methods for this class.

   private:

      // There are currently no private methods for this class.

   //************************************************************************************************************************************************
   // End Method Declarations
   //************************************************************************************************************************************************

   //************************************************************************************************************************************************
   // Start Member Variable Declarations
   //************************************************************************************************************************************************

   public:

      // There are currently no public member variables for this class.

   protected:

      // There are currently no protected member variables for this class.

   private:

      // TODO: Add description.
      int mDamage;

      // TODO: Add description.
      float mCoordinateX;

      // TODO: Add description.
      float mCoordinateY;

      // TODO: Add description.
      Sprite* mpSprite;

      // TODO: Add description.
      Rectangle* mpHitbox;

      // TODO: Add description.
      PlayerConstants::DIRECTION mDirection;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif