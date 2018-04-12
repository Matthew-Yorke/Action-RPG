//***************************************************************************************************************************************************
//
// File Name: DialogImage.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef DialogImage_h
#define DialogImage_h

#include "Sprite.h"
#include "Graphics.h"
#include "Rectangle.h"

class DialogImage
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: DialogImage
      //
      // Description:
      //  Constructor that set the member variables based on the passed in attributes. This loads the sprite image and save the dimensions of the
      // dialog image.
      //
      // Arguments:
      //  theGraphics - Reference to the graphics to draw the image to the screen.
      //  theFilePath - The file path to load the image from.
      //  theCoordinateX - The X-Coordinate to place the dialog image.
      //  theCoordinateY - The Y-Coordinate to place the dialog image.
      //  theWidth - The width of the dialog image.
      //  theHeight - The height of the dialog image.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      DialogImage(Graphics& theGraphics, std::string theFilePath, int theCoordinateX, int theCoordianteY, int theWidth, int theHeight);

      //*********************************************************************************************************************************************
      //
      // Method Name: SetCoordinateX
      //
      // Description:
      //  Update the X-Coordinate with the new passed in value.
      //
      // Arguments:
      //  theCoordianteX - The X-Coordinate to update the dialog image at.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      inline void SetCoordinateX(int theCoordianteX)
      {
         mpDimensions->SetCoordinateX(theCoordianteX);
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: SetCoordinateY
      //
      // Description:
      //  Update the Y-Coordinate with the new passed in value.
      //
      // Arguments:
      //  theCoordianteY - The Y-Coordinate to update the dialog image at.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      inline void SetCoordinateY(int theCoordianteY)
      {
         mpDimensions->SetCoordinateY(theCoordianteY);
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: GetImageWidth
      //
      // Description:
      //  Return the width of the image.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the width of the image.
      //
      //*********************************************************************************************************************************************
      inline int GetImageWidth()
      {
         return mpDimensions->GetWidth();
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
      //
      // Description:
      //  Draw the image at the current x and y coordinates.
      //
      // Arguments:
      //  theGraphics - Reference to the graphics for drawing to the screen.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Draw(Graphics& theGraphics);

   protected:

   // There are currently no protected methods for this class.

   private:

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

      // The pointer to the image sprite.
      Sprite* mpImage;

      // Pointer to the rectangle describing the dimensions including the X-Coordinate, Y-Coordinate, width, and height.
      Rectangle* mpDimensions;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif