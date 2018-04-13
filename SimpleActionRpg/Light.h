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

      //************************************************************************************************************************************************
      //
      // Method Name: Light
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theCoordinateX - TODO: Add description.
      //  theCoordinateY - TODO: Add description.
      //  theRaidus - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      Light(int theCoordinateX, int theCoordinateY, int theRaidus, ALLEGRO_COLOR theColor, int theIntensity);

      //*********************************************************************************************************************************************
      //
      // Method Name: CameraUpdate
      //
      // Description:
      //  Update the message box screen location based upon the camera location.
      //
      // Arguments:
      //  theCamera - Pointer to the camera object used to update the X and Y coordinates relative to the camera.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void CameraUpdate(Camera* theCamera);

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

      // TODO: Add description.
      int mIntensity;

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