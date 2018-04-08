//***************************************************************************************************************************************************
//
// File Name: Sprite.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Sprite_H
#define Sprite_H

#include <iostream>
#include "Graphics.h"

class Sprite
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

public:

   //************************************************************************************************************************************************
   //
   // Method Name: Sprite
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theGraphics - TODO: Add description.
   //  theFilePath - TODO: Add description.
   //  theSourceX - TODO: Add description.
   //  theSourceY - TODO: Add description.
   //  theWidth - TODO: Add description.
   //  theHeight - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   Sprite(Graphics& theGraphics, const std::string theFilePath, int theSourceX, int theSourceY, int theWidth, int theHeight);

   //************************************************************************************************************************************************
   //
   // Method Name: ~Sprite
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
   virtual ~Sprite();

   //************************************************************************************************************************************************
   //
   // Method Name: Draw
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theGraphics - TODO: Add description.
   //  theDestinationX - TODO: Add description.
   //  theDestinationY - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   void Draw(Graphics& theGraphics, int theDestinationX, int theDestinationY);

   //************************************************************************************************************************************************
   //
   // Method Name: Update
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theElapsedTime - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   virtual void Update(float theElapsedTime) {};

   //************************************************************************************************************************************************
   //
   // Method Name: SetAngle
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theAngle - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   inline virtual void SetAngle(float theAngle) { mAngle = theAngle; };

   //************************************************************************************************************************************************
   //
   // Method Name: GetAngle
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
   inline float GetAngle() { return mAngle; };

   //************************************************************************************************************************************************
   //
   // Method Name: GetBitmap
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theElapsedTime - TODO: Add description.
   //
   // Return:
   //  TODO: Add description.
   //
   //************************************************************************************************************************************************
   inline ALLEGRO_BITMAP* GetBitmap() { return mpSpriteSheet; };

protected:



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

   // TODO: Add description.
   int mHeight;

   // TODO: Add description.
   int mSourceX;

   // TODO: Add description.
   int mSourceY;

   // TODO: Add description.
   int mWidth;

   // TODO: Add description.
   float mAngle;

private:

   // TODO: Add description.
   ALLEGRO_BITMAP* mpSpriteSheet;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif