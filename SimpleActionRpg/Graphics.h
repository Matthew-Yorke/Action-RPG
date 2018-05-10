//***************************************************************************************************************************************************
//
// File Name: Graphics.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Graphics_H
#define Graphics_H

#include <string>
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Graphics
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Graphics
      //
      // Description:
      //  Constructor that sets default values for member variables.
      //
      // Arguments:
      //  pTheDisplay - Pointer to the display screen.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Graphics(ALLEGRO_DISPLAY* pTheDisplay);
      
      //*********************************************************************************************************************************************
      //
      // Method Name: ~Graphics
      //
      // Description:
      //  Deconstructor that frees any allocated memory managed by this class.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      ~Graphics();
      
      //*********************************************************************************************************************************************
      //
      // Method Name: LoadImage
      //
      // Description:
      //  Load an image.
      //
      // Arguments:
      //  theFilePath - The file path of the image.
      //
      // Return:
      //  Returns the bitmap pointer to the image.
      //
      //*********************************************************************************************************************************************
      ALLEGRO_BITMAP* LoadImage(const std::string& theFilePath);
      
      //*********************************************************************************************************************************************
      //
      // Method Name: GetDisplay
      //
      // Description:
      //  Returns the display screen.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns pointer to the display screen.
      //
      //*********************************************************************************************************************************************
      ALLEGRO_DISPLAY* GetDisplay();
      
      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
      //
      // Description:
      //  Draws the bitmap image to the screen.
      //
      // Arguments:
      //  pTheSource - Pointer to the bitmap image sheet to draw from.
      //  theStartPositionX - The X-Coordinate on the bitmap image to start drawing from.
      //  theStartPositionY - The Y-Coordinate on the bitmap image to start drawing from.
      //  theWidth - The width of the sprite image.
      //  theHeight - The height of the sprite image.
      //  theDestinationX - The X-Coordinate on the screen to draw to.
      //  theDestinationY - The Y-Coordinate on the screen to draw to.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Draw(ALLEGRO_BITMAP* pTheSource, int theStartPositionX, int theStartPositionY, int theWidth, int theHeight, int theDestinationX,
                int theDestinationY);

   protected:

      // There are currently no private methods for this class.

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
      std::map<std::string, ALLEGRO_BITMAP*> mpSpriteSheets;

      // TODO: Add description.
      ALLEGRO_DISPLAY* mpDisplay;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif