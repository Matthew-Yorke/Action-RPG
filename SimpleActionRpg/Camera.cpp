//***************************************************************************************************************************************************
//
// File Name: Camera.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "Camera.h"
#include "allegro5/allegro.h"
#include "MathConstants.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: Camera
//
// Description:
//  Set member to default values and call to update the camera position.
//
//***************************************************************************************************************************************************
Camera::Camera(RectangleObject* thepBoundaries, Object* thepObject)
{
   mCoordinateX = 0;
   mCoordinateY = 0;
   mpBoundaries = thepBoundaries;
   mpFollowingObject = thepObject;

   Update();
}

//************************************************************************************************************************************************
//
// Method Name: ChangeFollowingObject
//
// Description:
//  Store the new object being tracked and call to update the camera position.
//
//************************************************************************************************************************************************
void Camera::ChangeFollowingObject(Object* thepObject)
{
   mpFollowingObject = thepObject;
   Update();
}

//************************************************************************************************************************************************
//
// Method Name: GetCoordinateX
//
// Description:
//  Return the current X-Coordinate of the camera.
//
//************************************************************************************************************************************************
int Camera::GetCoordinateX()
{
   return mCoordinateX;
}

//************************************************************************************************************************************************
//
// Method Name: GetCoordinateY
//
// Description:
//  Return the current Y-Coordinate of the camera.
//
//************************************************************************************************************************************************
int Camera::GetCoordinateY()
{
   return mCoordinateY;
}

//************************************************************************************************************************************************
//
// Method Name: SetBoundaries
//
// Description:
//  Store the boundary limits of the passed in rectangle.
//
//************************************************************************************************************************************************
void Camera::SetBoundaries(RectangleObject* thepBoundaries)
{
   mpBoundaries = thepBoundaries;
}

//***************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  If an object is being followed, scroll the camera position along with the player at the center of the X-Coordinate and/or Y-Coordinate up to the
//  boundary limits for the camera. If there is not object to be followed then the camera stays at its previous location.
//
//***************************************************************************************************************************************************
void Camera::Update()
{
   // Note: 960 is screen width and 540 is screen height.
   // TODO: Change those values to use constants or have some value passed in.
   // If there is an object being followed, update the camera coordinates to place the followed object center of the camera.
   if (mpFollowingObject != nullptr)
   {
      mCoordinateX = (-960 / MathConstants::HALF) + (mpFollowingObject->GetCoordinateX() + mpFollowingObject->GetWidthCenterPoint()); 
      mCoordinateY = (-540 / MathConstants::HALF) + (mpFollowingObject->GetCoordinateY() + mpFollowingObject->GetHeightCenterPoint()); 
   }

   // Prevent the camera from scrolling past the world coordinate origin point for the left side of the screen.
   if (mCoordinateX < mpBoundaries->GetCoordinateX())
   {
      mCoordinateX = mpBoundaries->GetCoordinateX();
   }
   else if ((mCoordinateX + 960) > mpBoundaries->GetWidth())
   {
      mCoordinateX = mpBoundaries->GetWidth() - 960;
   }

   // Prevent the camera from scrolling past the world coordinate origin point for the top of the screen.
   if (mCoordinateY < mpBoundaries->GetCoordinateY())
   {
      mCoordinateY = mpBoundaries->GetCoordinateY();
   }
   else if ((mCoordinateY + 540) > mpBoundaries->GetHeight())
   {
      mCoordinateY = mpBoundaries->GetHeight() - 540;
   }

   // Have the camera mock follow the object by pushing all other object the opposite direction the object is moving.
   al_identity_transform(&mCamera);
   al_translate_transform(&mCamera,
                          -mCoordinateX,
                          -mCoordinateY);
   al_use_transform(&mCamera);
}

//***************************************************************************************************************************************************
// End Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Protected Method Definitions
//***************************************************************************************************************************************************



//***************************************************************************************************************************************************
// End Protected Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
// Start Private Method Definitions
//***************************************************************************************************************************************************



//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************