//***************************************************************************************************************************************************
//
// File Name: Object.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Object_h
#define Object_h

class Object
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Object
      //
      // Description:
      //  Constructor that sets member variables to default values.
      //
      // Arguments:
      //  theCoorindateX - The X-Coordinate to place the object upon creation.
      //  theCoorindateY - The Y-Coordinate to place the object upon creation.
      //  mWidthCenterPoint - The center point of the width of the object.
      //  mHeightCenterPoint - The center point of the height of the object.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Object(int theCoorindateX, int theCoordianteY, int mWidthCenterPoint, int mHeightCenterPoint);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetCoordinateX
      //
      // Description:
      //  This method returns the current X-Coordinate of the object.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the current X-Coordinate of the object.
      //
      //*********************************************************************************************************************************************
      inline int GetCoordinateX()
      {
         return mCoordinateX;
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: SetCoordinateX
      //
      // Description:
      //  This method updates the X-Coordinate of the object based on the passed in value.
      //
      // Arguments:
      //  theCoordianteX - The updated X-Coordinate to place the object at.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      inline void SetCoordinateX(int theCoordianteX)
      {
         mCoordinateX = theCoordianteX;
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: GetCoordinateY
      //
      // Description:
      //  This method returns the current Y-Coordinate of the object.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the current Y-Coordinate of the object.
      //
      //*********************************************************************************************************************************************
      inline int GetCoordinateY()
      {
         return mCoordinateY;
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: SetCoordinateY
      //
      // Description:
      //  This method updates the Y-Coordinate of the object based on the passed in value.
      //
      // Arguments:
      //  theCoordianteY - The updated Y-Coordinate to place the object at.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      inline void SetCoordinateY(int theCoordianteY)
      {
         mCoordinateY = theCoordianteY;
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: GetWidthCenterPoint
      //
      // Description:
      //  This method returns the current width of the object.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the current width center point of the object.
      //
      //*********************************************************************************************************************************************
      inline int GetWidthCenterPoint()
      {
         return mWidthCenterPoint;
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: SetWidth
      //
      // Description:
      //  This method updates the width center point of the object based on the passed in value.
      //
      // Arguments:
      //  theWidthCenterPoint - The updated width center point of the object.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      inline void SetWidth(int theWidthCenterPoint)
      {
         mWidthCenterPoint = theWidthCenterPoint;
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: GetHeightCenterPoint
      //
      // Description:
      //  This method returns the current height center point of the object.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the current height center of the object.
      //
      //*********************************************************************************************************************************************
      inline int GetHeightCenterPoint()
      {
         return mHeightCenterPoint;
      };

      //*********************************************************************************************************************************************
      //
      // Method Name: SetHeightCenterPoint
      //
      // Description:
      //  This method updates the height center of the object based on the passed in value.
      //
      // Arguments:
      //  theHeightCenterPoint - The updated height center point of the object.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      inline void SetHeightCenterPoint(int theHeightCenterPoint)
      {
         mHeightCenterPoint = theHeightCenterPoint;
      };

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

      // The X-Coordinate that the object is placed at based on world coordinates.
      int mCoordinateX;

      // The Y-Coordinate that the object is placed at based on world coordinates.
      int mCoordinateY;

      // The center point along the width of an object.
      int mWidthCenterPoint;

      // The center point along the height of an object.
      int mHeightCenterPoint;

   private:

      // There are currently no private member variables for this class.

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif