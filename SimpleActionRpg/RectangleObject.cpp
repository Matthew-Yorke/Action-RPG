//***************************************************************************************************************************************************
//
// File Name: RectangleObject.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "RectangleObject.h"
#include "MathConstants.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: RectangleObject
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
RectangleObject::RectangleObject(int theCoordinateX, int theCoordinateY, int theWidth, int theHeight) :
Object(theCoordinateX,
       theCoordinateY,
       (theWidth / MathConstants::HALF),
       (theWidth / MathConstants::HALF))
{
   mWidth = theWidth;
   mHeight = theHeight;
}

//*********************************************************************************************************************************************
//
// Method Name: GetWidth
//
// Description:
//  Returns the width of the rectangular object.
//
//*********************************************************************************************************************************************
int RectangleObject::GetWidth()
{
   return mWidth;
}


//*********************************************************************************************************************************************
//
// Method Name: GetHeight
//
// Description:
//  Returns the height of the rectangular object.
//
//*********************************************************************************************************************************************
int RectangleObject::GetHeight()
{
   return mHeight;
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