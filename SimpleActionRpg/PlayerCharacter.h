//***************************************************************************************************************************************************
//
// File Name: PlayerCharacter.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#ifndef PlayerCharacter_h
#define PlayerCharacter_h

#include <allegro5/allegro_acodec.h>
#include "allegro5\allegro.h"
#include "Vector2D.h"
#include "Sprite.h"
#include "MeleeWeapon.h"
#include "Rectangle.h"
#include "State.h"

class PlayerCharacter
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //************************************************************************************************************************************************
      //
      // Method Name: PlayerCharacter
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
      PlayerCharacter(Graphics& theGraphics);

      //************************************************************************************************************************************************
      //
      // Method Name: ~PlayerCharacter
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
      ~PlayerCharacter();

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
      inline float GetCoordinateX() { return mCoordinateX; };

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
      inline void SetCoordinateX(float theCoordinateX) { mCoordinateX = theCoordinateX; mpMeleeWeapon->SetCoordinateX(theCoordinateX); };

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
      inline float GetCoordinateY() { return mCoordinateY; };

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
      inline void SetCoordinateY(float theCoordinateY) { mCoordinateY = theCoordinateY; mpMeleeWeapon->SetCoordinateY(theCoordinateY); };

      //************************************************************************************************************************************************
      //
      // Method Name: GetVelocity
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
      inline Vector2D* GetVelocity() { return mpVelocity; };

      //************************************************************************************************************************************************
      //
      // Method Name: GetMeleeWeapon
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
      inline MeleeWeapon* GetMeleeWeapon() { return mpMeleeWeapon; };

      //************************************************************************************************************************************************
      //
      // Method Name: ChangeState
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theState - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void ChangeState(State* theState) { delete mpCurrentState; mpCurrentState = theState; mpCurrentState->SetCharacterReference(this); };

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
      inline void KeyDown(ALLEGRO_EVENT theEvent) { mpCurrentState->KeyDown(theEvent); };

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
      inline void KeyUp(ALLEGRO_EVENT theEvent) { mpCurrentState->KeyUp(theEvent); };

      //************************************************************************************************************************************************
      //
      // Method Name: Update
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
      inline void Update(float theTimeChange) { mpCurrentState->Update(theTimeChange); };

      //************************************************************************************************************************************************
      //
      // Method Name: Draw
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
      inline void Draw(Graphics& theGraphics) { mpCurrentState->Draw(theGraphics); };

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
      void DrawSprite(Graphics& theGraphics);

   protected:

   private:

   //************************************************************************************************************************************************
   // End Method Declarations
   //************************************************************************************************************************************************

   //************************************************************************************************************************************************
   // Start Member Variable Declarations
   //************************************************************************************************************************************************

   public:

   protected:

   private:

      // TODO: Add description.
      int mMaxHealth;

      // TODO: Add description.
      int mCurrentHealth;

      // TODO: Add description.
      int mMaxMana;

      // TODO: Add description.
      int mCurrentMana;

      // TODO: Add description.
      float mCoordinateX;
 
      // TODO: Add description.
      float mCoordinateY;

      // TODO: Add description.
      Vector2D* mpVelocity;

      // TODO: Add description.
      Sprite* mpSprite;

      // TODO: Add description.
      Rectangle* mpHitbox;

      // TODO: Add description.
      MeleeWeapon* mpMeleeWeapon;

      State* mpCurrentState;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif