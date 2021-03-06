//***************************************************************************************************************************************************
//
// File Name: RectangleObject.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef RectangleObject_h
#define RectangleObject_h

#include "Object.h"

class RectangleObject : public Object
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: RectangleObject
      //
      // Description:
      //  Constructor that sets default values for member variables.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      RectangleObject(int theCoordinateX, int theCoordinateY, int theWidth, int theHeight);

      //*********************************************************************************************************************************************
      //
      // Method Name: SetWidth
      //
      // Description:
      //  Updates the width of the rectangular object.
      //
      // Arguments:
      //  theWidth - The new width of the rectangular object.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetWidth(int theWidth);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetWidth
      //
      // Description:
      //  This method returns the width of the rectangular object.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the rectangular object width.
      //
      //*********************************************************************************************************************************************
      int GetWidth();

      //*********************************************************************************************************************************************
      //
      // Method Name: SetHeight
      //
      // Description:
      //  Updates the height of the rectangular object.
      //
      // Arguments:
      //  theHeight - The new height of the rectangular object.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetHeight(int theHeight);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetHeight
      //
      // Description:
      //  This method returns the height of the rectangular object.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the rectangular object height.
      //
      //*********************************************************************************************************************************************
      int GetHeight();

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

      // The width of the rectangular object.
      int mWidth;

      // The height of the rectangular object.
      int mHeight;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif