//***************************************************************************************************************************************************
//
// File Name: AnimatedSprite.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#include "AnimatedSprite.h"
#include "Game.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: AnimatedSprite
//
// Description:
//  Set member variables to their default values.
//
//***************************************************************************************************************************************************
AnimatedSprite::AnimatedSprite(Graphics& theGraphics, const std::string theFilePath, int theSourceX, int theSourceY, int theWidth, int theHeight,
                               float theFps, int theNumberFrames) :
   Sprite(theGraphics,
          theFilePath,
          theSourceX,
          theSourceY,
          theWidth,
          theHeight)
{
   mFrameTime = 1.0F / theFps;
   mNumberFrames = theNumberFrames;
   mCurrentFrame = 0;
   mElapsedTime = 0;
}

//***************************************************************************************************************************************************
//
// Method Name: SetAnimationSourceX
//
// Description:
//  Updates the X-Coordinate of the animation on the sprite(sheet) bitmap.
//
//***************************************************************************************************************************************************
void AnimatedSprite::SetAnimationSourceX(int theSourceX)
{
   mSourceX = theSourceX;
}

//***************************************************************************************************************************************************
//
// Method Name: SetAnimationSourceY
//
// Description:
//  Updates the Y-Coordinate of the animation on the sprite(sheet) bitmap and the number of frames for the new animation.
//
//***************************************************************************************************************************************************
void AnimatedSprite::SetAnimationSourceY(int theSourceY, int theNumberFrames)
{
   mSourceY = theSourceY;
   mNumberFrames = theNumberFrames;
}

//***************************************************************************************************************************************************
//
// Method Name: ResetFrames
//
// Description:
//  Reset the current frame and the time elapsed.
//
//***************************************************************************************************************************************************
void AnimatedSprite::ResetFrames()
{
   mCurrentFrame = 0;
   mElapsedTime = 0.0F;
}

//***************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  Update the amount of time that has elapsed for the current frame. If the amount of time exceeds the frame time, update to the next frame and
//  reset the elapsed time.
//
//***************************************************************************************************************************************************
void AnimatedSprite::Update(float theElapsedTime)
{
   // Increase the elapsed time by the amount of time since the last update.
   mElapsedTime += theElapsedTime;

   // Check if elapsed time exceeds the frame time.
   if (mElapsedTime > mFrameTime)
   {
      // Update the next frame and reset the elapsed time.
      mCurrentFrame++;
      mElapsedTime = 0;

      // If the next frame is still within the bounds of the number of frames then increase the X-Coordinate of the sprite(sheet) by the sprite
      // width.
      if (mCurrentFrame < mNumberFrames)
      {
         mSourceX += mWidth;
      }
      // The next frame is past the bounds of the number of frames. Reset the X-coordinate and current frame to the first frame of the animation.
      else
      {
         mSourceX = 0;
         mCurrentFrame = 0;
      }
   }
}

//***************************************************************************************************************************************************
// End Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Protected Method Definitions
//***************************************************************************************************************************************************

// Note: There are no protected methods in this class.

//***************************************************************************************************************************************************
// End Protected Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Private Method Definitions
//***************************************************************************************************************************************************

// Note: There are no private methods in this class.

//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************