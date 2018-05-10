//***************************************************************************************************************************************************
//
// File Name: AnimatedSprite.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef AnimatedSprite_H
#define AnimatedSprite_H

#include "Sprite.h"
#include "Graphics.h"

class AnimatedSprite : public Sprite
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: AnimatedSprite
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
      //  theFps - The number of frames that occur in a second.
      //  theNumberFrames - The number of frames in the animation.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      AnimatedSprite(Graphics& theGraphics, const std::string theFilePath, int theSourceX, int theSourceY, int theWidth, int theHeight, float theFps,
                     int theNumberFrames);

      //*********************************************************************************************************************************************
      //
      // Method Name: SetAnimationSourceX
      //
      // Description:
      //  Updates the X-Coordinate of the animation on the sprite(sheet) bitmap.
      //
      // Arguments:
      //  theSourceX - The X-Coordinate on the sprite(sheet) bitmap to update to.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetAnimationSourceX(int theSourcex);

      //*********************************************************************************************************************************************
      //
      // Method Name: SetAnimationSourceY
      //
      // Description:
      //  Updates the Y-Coordinate of the animation on the sprite(sheet) bitmap and the number of frames for the new animation.
      //
      // Arguments:
      //  theSourceY - The Y-Coordinate on the sprite(sheet) bitmap to update to.
      //  theNumberFrames - The number of frames in the animation.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetAnimationSourceY(int theSourceY, int theNumberFrames);

      //*********************************************************************************************************************************************
      //
      // Method Name: ResetFrames
      //
      // Description:
      //  Reset the current frame and the time elapsed.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void ResetFrames();

      //*********************************************************************************************************************************************
      //
      // Method Name: Update
      //
      // Description:
      //  Update to the next frame when enough time has passed.
      //
      // Arguments:
      //  theElapsedTime - The amount of time elapsed since the last update.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Update(float theElapsedTime);

   protected:

      // There are currently no protected methods for this class.

   private:

      // There are currently no private methods for this class.

      //*********************************************************************************************************************************************
      // End Method Declarations
      //*********************************************************************************************************************************************

      //*********************************************************************************************************************************************
      // Start Member Variable Declarations
      //*********************************************************************************************************************************************

   public:

      // There are currently no public member variables for this class.

   protected:

      // There are currently no protected member variables for this class.

   private:

      // Holds the amount of time until a frame should be updated to the next frame.
      float mFrameTime;

      // Holds the number of frames in the current animation.
      int mNumberFrames;

      // Holds the current frame number in the number of frames.
      int mCurrentFrame;

      // Holds the amount of time that has elapsed in total for the current frame.
      float mElapsedTime;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif