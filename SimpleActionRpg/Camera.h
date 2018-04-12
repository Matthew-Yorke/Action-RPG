//***************************************************************************************************************************************************
//
// File Name: Camera.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Camera_h
#define Camera_h

class Camera
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //************************************************************************************************************************************************
      //
      // Method Name: Camera
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
      Camera();

      inline float GetCoordinateX() { return mCoordinateX; };

      inline float GetCoordinateY() { return mCoordinateY; };

      //************************************************************************************************************************************************
      //
      // Method Name: Update
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  thePlayerCoordinateX - TODO: Add description.
      //  thePlayerCoordinateX - TODO: Add description.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void Update(float thePlayerCoordinateX, float thePlayerCoordianteY);

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
      float mCoordinateX;

      // TODO: Add description.
      float mCoordinateY;

      ALLEGRO_TRANSFORM mCamera;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif