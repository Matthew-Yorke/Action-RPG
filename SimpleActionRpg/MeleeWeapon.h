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
#include "AnimatedSprite.h"
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
      MeleeWeapon(Graphics& theGraphics, int theDamage);

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

      void SetHitBoxCoordinateX(int theCoordianteX) { mpHitBox->SetCoordinateX(theCoordianteX); };

      void SetHitBoxCoordinateY(int theCoordianteY) { mpHitBox->SetCoordinateY(theCoordianteY); };

      void SetHitBoxWidth(int theWidth) { mpHitBox->SetWidth(theWidth); };

      void SetHitBoxHeight(int theHeight) { mpHitBox->SetHeight(theHeight); };

      int GetWeaponWidth() { return mWeaponWidth; };

      int GetWeaponHeight() { return mWeaponHeight; };

      //************************************************************************************************************************************************
      //
      // Method Name: GetSprite
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
      AnimatedSprite* GetSprite();

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
      AnimatedSprite* mpSprite;

      // TODO: Add description.
      PlayerConstants::DIRECTION mDirection;

      int mWeaponWidth;

      int mWeaponHeight;

      Rectangle* mpHitBox;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif