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

   inline int GetCoordinateX() { return mCoordianteX; };

   inline void SetCoordinateX(int theCoordinateX) { mCoordianteX = theCoordinateX; };

   inline int GetCoordinateY() { return mCoordianteY; };

   inline void SetCoordinateY(int theCoordinateY) { mCoordianteY = theCoordinateY; };

   inline int GetWidth() { return mWidth; };

   inline int GetHeight() { return mHeight; };

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