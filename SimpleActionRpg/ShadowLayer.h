//***************************************************************************************************************************************************
//
// File Name: ShadowLayer.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef ShadowLayer_H
#define ShadowLayer_H

#include "Graphics.h"
#include <vector>
#include "Light.h"
#include "Camera.h"

class ShadowLayer
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: ShadowLayer
      //
      // Description:
      //  Constructor that sets default values for member variables.
      //
      // Arguments:
      //  theFileLocation - The file location of the shadow layer image.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      ShadowLayer(std::string theFileLocation);

      //*********************************************************************************************************************************************
      //
      // Method Name: ~ShadowLayer
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
      ~ShadowLayer();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetOpacity
      //
      // Description:
      //  Returns the current opacity of the shadow layer.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns an integer representing the current opacity of the shadow layer.
      //
      //*********************************************************************************************************************************************
      int GetOpacity();

      //*********************************************************************************************************************************************
      //
      // Method Name: SetOpacity
      //
      // Description:
      //  Update the opacity of the shadow layer.
      //
      // Arguments:
      //  theOpacity - The new opacity of the shadow layer.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetOpacity(int theOpacity);

      //*********************************************************************************************************************************************
      //
      // Method Name: AddLight
      //
      // Description:
      //  Adds a light object to the list of lights blended over the shadow layer.
      //
      // Arguments:
      //  pTheLight - Pointer to the light object to be added.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void AddLight(Light* pTheLight);

      //*********************************************************************************************************************************************
      //
      // Method Name: RemoveLight
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
      //*********************************************************************************************************************************************
      void RemoveLight();

      //*********************************************************************************************************************************************
      //
      // Method Name: CameraUpdate
      //
      // Description:
      //  Updates the shadow layer positions based on the camera position.
      //
      // Arguments:
      //  pTheCamera - Pointer to the camera object used to update the X-Coordinate and Y-Coordinate relative to the camera.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void CameraUpdate(Camera* pTheCamera);

      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
      //
      // Description:
      //  Draws the shadow layer to the screen.
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

      // A Bitmap of the shadow box blended onto the screen.
      ALLEGRO_BITMAP* mpShadowBitmap;

      // The opacity of the shadow layer.
      int mOpacity;

      // Vector containing all the lights to be blended over the shadow layer.
      std::vector<Light*> mLightList;

      // The dimensions of the shadow layer.
      RectangleObject* mpDimensions;

      // The X-Coordinate where the shadow layer resides.
      float mCoordinateX;

      // The Y-Coordinate where the shadow layer resides.
      float mCoordinateY;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif