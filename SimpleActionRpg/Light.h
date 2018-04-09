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

class Light
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
      Light(int theCoordinateX, int theCoordinateY, int theRaidus, int theIntensity);

      //************************************************************************************************************************************************
      //
      // Method Name: GetCoordinateX
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
      inline float GetCoordinateX() { return mCoordinateX; };

      //************************************************************************************************************************************************
      //
      // Method Name: SetCoordinateX
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theCoordinateX - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void SetCoordinateX(float theCoordinateX) { mCoordinateX = theCoordinateX; };

      //************************************************************************************************************************************************
      //
      // Method Name: GetCoordinateY
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
      inline float GetCoordinateY() { return mCoordinateY; };

      //************************************************************************************************************************************************
      //
      // Method Name: SetCoordinateY
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theCoordinateY - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      inline void SetCoordinateY(float theCoordinateY) { mCoordinateY = theCoordinateY; };

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
      int mCoordinateX;

      // TODO: Add description.
      int mCoordinateY;

      // TODO: Add description.
      int mRaidus;

      // TODO: Add description.
      int mIntensity;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif