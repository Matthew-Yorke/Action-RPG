//***************************************************************************************************************************************************
//
// File Name: Rectangle.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Rectangle_H
#define Rectangle_H

class Rectangle
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

public:

   //************************************************************************************************************************************************
   //
   // Method Name: Rectangle
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
   Rectangle(int theCoordinateX, int theCoordianteY, int theWidth, int theHeight);

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
   int GetCoordinateX();

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
   void SetCoordinateX(int theCoordinateX);

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
   int GetCoordinateY();

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
   void SetCoordinateY(int theCoordinateY);

   //************************************************************************************************************************************************
   //
   // Method Name: GetWidth
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
   int GetWidth();

   //************************************************************************************************************************************************
   //
   // Method Name: SetWidth
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theWidth - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   void SetWidth(int theWidth);

   //************************************************************************************************************************************************
   //
   // Method Name: GetHeight
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
   int GetHeight();

   //************************************************************************************************************************************************
   //
   // Method Name: SetHeight
   //
   // Description:
   //  TODO: Add description.
   //
   // Arguments:
   //  theHeight - TODO: Add description.
   //
   // Return:
   //  N/A
   //
   //************************************************************************************************************************************************
   void SetHeight(int theHeight);

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
   int mCoordianteX;

   // TODO: Add description.
   int mCoordianteY;

   // TODO: Add description.
   int mWidth;

   // TODO: Add description.
   int mHeight;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************

};

#endif