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
#include "AnimatedSprite.h"
#include "MeleeWeapon.h"
#include "Character.h"
#include "State.h"
#include "PlayerConstants.h"
#include <vector>
#include <algorithm>
#include "Tile.h"
#include "Magic.h"

class PlayerCharacter : public Character
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
      PlayerCharacter(Graphics& theGraphics, int theCoordianteX, int theCoordinateY);

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
      // Method Name: GetDirection
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
      PlayerConstants::DIRECTION GetDirection();

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
      // Method Name: InsertMovementDirection
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
      void InsertMovementDirection(PlayerConstants::DIRECTION theDirection);

      //************************************************************************************************************************************************
      //
      // Method Name: RemoveMovementDirection
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
      void RemoveMovementDirection(PlayerConstants::DIRECTION theDirection);

      //************************************************************************************************************************************************
      //
      // Method Name: IsMovingDirectionEmpty
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
      bool IsMovingDirectionEmpty();

      //************************************************************************************************************************************************
      //
      // Method Name: IsMovingDirectionEmpty
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
      PlayerConstants::DIRECTION GetFrontOfMovingDirectionVector();

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
      Vector2D* GetVelocity();

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
      MeleeWeapon* GetMeleeWeapon();

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
      void ChangeState(State* theState);

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
      void KeyDown(ALLEGRO_EVENT theEvent);

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
      void KeyUp(ALLEGRO_EVENT theEvent);

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
      void Update(float theTimeChange);

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
      void Draw(Graphics& theGraphics);

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
      Vector2D* mpVelocity;

      // TODO: Add description.
      MeleeWeapon* mpMeleeWeapon;

      // TODO: Add description.
      State* mpCurrentState;

      // TODO: Add description.
      PlayerConstants::DIRECTION mDirection; 

      // TODO: Add description.
      std::vector<PlayerConstants::DIRECTION> mMovingDirectionVector;

      Magic* mpTestDamageSpell;

      bool mIsCharging;

      float mCurrentSpellChargeTime;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif