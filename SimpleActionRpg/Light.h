//***************************************************************************************************************************************************
//
// File Name: Light.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Light_H
#define Light_H

#include "Graphics.h"
#include "CircleObject.h"
#include "Camera.h"

class Light : public CircleObject
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Light
      //
      // Description:
      //  Constructor that sets default values for member variables.
      //
      // Arguments:
      //  theCoordinateX - The X-Coordinate where the light resides.
      //  theCoordinateY - The Y-Coordinate where the light resides.
      //  theRaidus - The radius of the light from the center point.
      //  theColor - The color of the light.
      //  theOpacity - The opacity of the light.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Light(int theCoordinateX, int theCoordinateY, int theRaidus, ALLEGRO_COLOR theColor, int theOpacity);

      //*********************************************************************************************************************************************
      //
      // Method Name: CameraUpdate
      //
      // Description:
      //  Updates the light positions based on the camera position.
      //
      // Arguments:
      //  theCamera - Pointer to the camera object used to update the X-Coordinate and Y-Coordinate relative to the camera.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void CameraUpdate(Camera* theCamera);

      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
      //
      // Description:
      //  Draws the light.
      //
      // Arguments:
      //  theGraphics - Reference to the graphics object for drawing to the screen.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Draw(Graphics& theGraphics);

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

      // Th
      int mOpacity;

      // TODO: Add description.
      ALLEGRO_COLOR mColor;

      // The X-Coordinate of the light based on world coordinates.
      int mWorldCoordinateX;

      // The Y-Coordinate of the light based on world coordinates.
      int mWorldCoordinateY;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif