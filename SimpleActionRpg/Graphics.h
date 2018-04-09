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

   //************************************************************************************************************************************************
   //
   // Method Name: Graphics
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theDisplay - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   Graphics(ALLEGRO_DISPLAY* theDisplay);

   //************************************************************************************************************************************************
   //
   // Method Name: ~Graphics
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
   ~Graphics();

   //************************************************************************************************************************************************
   //
   // Method Name: Draw
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  thepSource - TODO: Add description.
   //  theStartPositionX - TODO: Add description.
   //  theStartPositionY - TODO: Add description.
   //  theWidth - TODO: Add description.
   //  theHeight - TODO: Add description.
   //  theDestinationX - TODO: Add description.
   //  theDestinationY - TODO: Add description.
   //  theAngle - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   void Draw(ALLEGRO_BITMAP* thepSource, int theStartPositionX, int theStartPositionY, int theWidth, int theHeight, int theDestinationX,
             int theDestinationY, float theAngle);

   //************************************************************************************************************************************************
   //
   // Method Name: LoadImage
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theFilePath - TODO: Add description.
   //
   // Return:
   //  TODO: Add description.
   //
   //************************************************************************************************************************************************
   ALLEGRO_BITMAP* LoadImage(const std::string& theFilePath);

   //************************************************************************************************************************************************
   //
   // Method Name: GetDisplay
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
   inline ALLEGRO_DISPLAY* GetDisplay() { return mpDisplay; };

protected:

   //************************************************************************************************************************************************
   //
   // Method Name: SetAngleInRadians
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
   void SetAngleInRadians(float theAngle);

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