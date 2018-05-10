//***************************************************************************************************************************************************
//
// File Name: CircleObject.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef CircleObject_h
#define CircleObject_h

#include "Object.h"

class CircleObject : public Object
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: CircleObject
      //
      // Description:
      //  Constructor that sets default values for member variables.
      //
      // Arguments:
      //  theCoordinateX - The X-Coordinate where the circular object is at.
      //  theCoordinateY - The Y-Coordinate where the circular object is at.
      //  theRadius - The radius of the circular object.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      CircleObject(int theCoordinateX, int theCoordinateY, int theRadius);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetRadius
      //
      // Description:
      //  This method returns the radius of the circular object.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the circular object radius.
      //
      //*********************************************************************************************************************************************
      int GetRadius();

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

      // The radius of the circular object.
      int mRadius;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif