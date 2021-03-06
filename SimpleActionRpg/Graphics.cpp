//***************************************************************************************************************************************************
//
// File Name: Graphics.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add Description.
//
//***************************************************************************************************************************************************

#include "Graphics.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: Graphics
//
// Description:
//  Set member variables to default values using the passed in arguments.
//
//***************************************************************************************************************************************************
Graphics::Graphics(ALLEGRO_DISPLAY* pTheDisplay)
{
   mpDisplay = pTheDisplay;
}

//***************************************************************************************************************************************************
//
// Method Name: ~Graphics
//
// Description:
//  Frees any allocated memory managed by this class.
//
//***************************************************************************************************************************************************
Graphics::~Graphics()
{
   for (auto spriteSheetIterator = mpSpriteSheets.begin();
        spriteSheetIterator != mpSpriteSheets.end();
        spriteSheetIterator++)
   {
      al_destroy_bitmap(spriteSheetIterator->second);
   }
}

//***************************************************************************************************************************************************
//
// Method Name: LoadImage
//
// Description:
//  Check if the image already is loaded and if not load the image. Return the pointer to the bitmap image.
//
//***************************************************************************************************************************************************
ALLEGRO_BITMAP* Graphics::LoadImage(const std::string& theFilePath)
{
   if (mpSpriteSheets.count(theFilePath) == 0)
   {
      mpSpriteSheets[theFilePath] = al_load_bitmap(theFilePath.c_str());
   }

   return mpSpriteSheets[theFilePath];
}

//************************************************************************************************************************************************
//
// Method Name: GetDisplay
//
// Description:
//  Returns the pointer to the display screen.
//
//************************************************************************************************************************************************
ALLEGRO_DISPLAY* Graphics::GetDisplay()
{
   return mpDisplay;
}

//***************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  Draws the bitmap sprite to the screen using the passed in arguments.
//
//***************************************************************************************************************************************************
void Graphics::Draw(ALLEGRO_BITMAP* pTheSource, int theStartPositionX, int theStartPositionY, int theWidth, int theHeight, int theDestinationX,
                    int theDestinationY)
{
   al_draw_bitmap_region(pTheSource,
                         theStartPositionX,
                         theStartPositionY,
                         theWidth,
                         theHeight,
                         theDestinationX,
                         theDestinationY,
                         0);
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