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

      //*********************************************************************************************************************************************
      //
      // Method Name: Sprite
      //
      // Description:
      //  Constructor that sets default values for member variables.
      //
      // Arguments:
      //  theGraphics - Reference to the graphics object for drawing to the screen.
      //  theFilePath - The file path where the sprite(sheet) is located.
      //  theSourceX - The X-Coordinate where the sprite image on the bitmap is located.
      //  theSourceY - The Y-Coordinate where the sprite image on the bitmap is located.
      //  theWidth - The width of the sprite image.
      //  theHeight - The height of the sprite image.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Sprite(Graphics& theGraphics, const std::string theFilePath, int theSourceX, int theSourceY, int theWidth, int theHeight);

      //*********************************************************************************************************************************************
      //
      // Method Name: SetNewSprite
      //
      // Description:
      //  Sets a new sprite image from the sprite(sheet) bitmap.
      //
      // Arguments:
      //  theSourceX - The X-Coordinate where the new sprite image is on the sprite(sheet) bitmap.
      //  theSourceY - The Y-Coordinate where the new sprite image is on the sprite(sheet) bitmap.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetNewSprite(int theSourceX, int theSourceY);

      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
      //
      // Description:
      //  Draws the sprite image to the screen.
      //
      // Arguments:
      //  theGraphics - Reference to the graphics object for drawing to the screen.
      //  theDestinationX - The X-Coordinate on the screen where to draw the sprite image.
      //  theDestinationY - The Y-Coordinate on the screen where to draw the sprite image.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Draw(Graphics& theGraphics, int theDestinationX, int theDestinationY);

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

      // Holds the X-Coordinate where the sprite image resides in the sprite(sheet) bitmap.
      int mSourceX;

      // Holds the Y-Coordinate where the sprite image resides in the sprite(sheet) bitmap.
      int mSourceY;

      // Holds the width of the sprite image.
      int mWidth;

      // Holds the height of the sprite image.
      int mHeight;

   private:

      // Holds the bitmap of the sprite(sheet) containing the image(s) of sprites.
      ALLEGRO_BITMAP* mpSpriteSheet;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif