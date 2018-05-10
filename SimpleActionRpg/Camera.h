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

#include "allegro5/allegro.h"
#include "Object.h"
#include "RectangleObject.h"

class Camera
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Camera
      //
      // Description:
      //  Constructor that sets member variables to default values.
      //
      // Arguments:
      //  pTheBoundaries - Pointer to a rectangle depicting the world coordinate boundary limits of the camera.
      //  pTheObject - Pointer to the initial object for the camera to follow.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Camera(RectangleObject* pTheBoundaries, Object* pTheObject);

      //*********************************************************************************************************************************************
      //
      // Method Name: ChangeFollowingObject
      //
      // Description:
      //  This method changes what object to point at for the camera to follow.
      //
      // Arguments:
      //  pTheObject - Pointer to the object for the camera to follow.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void ChangeFollowingObject(Object* pTheObject);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetCoordinateX
      //
      // Description:
      //  This method returns the current X-Coordinate of the camera.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the current X-Coordinate of the camera.
      //
      //*********************************************************************************************************************************************
      int GetCoordinateX();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetCoordinateY
      //
      // Description:
      //  This method returns the current Y-Coordinate of the camera.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the current Y-Coordinate of the camera.
      //
      //*********************************************************************************************************************************************
      int GetCoordinateY();

      //*********************************************************************************************************************************************
      //
      // Method Name: SetBoundaries
      //
      // Description:
      //  This method changes the boundary limits with the passed in rectangle.
      //
      // Arguments:
      //  pTheBoundaries - Pointer to the rectangle containing the boundary limits for the camera.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetBoundaries(RectangleObject* pTheBoundaries);

      //*********************************************************************************************************************************************
      //
      // Method Name: Update
      //
      // Description:
      //  Update the camera position based on the object that is being followed, but staying within its bounds.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Update();

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

      // The camera object to transform where on the screen object are displayed.
      ALLEGRO_TRANSFORM mCamera;

      // The X-Coordinate where the camera is top most on the world coordinate system.
      int mCoordinateX;

      // The Y-Coordinate where the camera is left most on the world coordinate system.
      int mCoordinateY;

      // Holds the world boundary values for area that the camera be within.
      RectangleObject* mpBoundaries;

      // The object the camera follows.
      Object* mpFollowingObject;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif