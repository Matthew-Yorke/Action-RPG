//***************************************************************************************************************************************************
//
// File Name: Vector2D.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include <math.h>
#include "Vector2D.h"

//************************************************************************************************************************************************
//
// Method Name: Vector2D
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  theComponentX - TODO: Add description.
//  theComponentY - TODO: Add description.
//
// Return:
//  N/A
//
//************************************************************************************************************************************************
Vector2D::Vector2D(float theComponentX, float theComponentY)
{
   mComponentX = theComponentX;
   mComponentY = theComponentY;
}

//*********************************************************************************************************************************************
//
// Method Name: SetComponentX
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  theComponentX - TODO: Add description.
//
// Return:
//  N/A
//
//*********************************************************************************************************************************************
void Vector2D::SetComponentX(float theComponentX)
{
   mComponentX = theComponentX;
   CalculateLength();
}

//*********************************************************************************************************************************************
//
// Method Name: GetComponentX
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
//*********************************************************************************************************************************************
float Vector2D::GetComponentX()
{
   return mComponentX;
}

//*********************************************************************************************************************************************
//
// Method Name: SetComponentY
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  theComponentY - TODO: Add description.
//
// Return:
//  N/A
//
//*********************************************************************************************************************************************
void Vector2D::SetComponentY(float theComponentY)
{
   mComponentY = theComponentY;
   CalculateLength();
}

//*********************************************************************************************************************************************
//
// Method Name: GetComponentY
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
//*********************************************************************************************************************************************
float Vector2D::GetComponentY()
{
   return mComponentY;
}

//*********************************************************************************************************************************************
//
// Method Name: GetLength
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
//*********************************************************************************************************************************************
float Vector2D::GetLength()
{
   return mLength;
}

//*********************************************************************************************************************************************
//
// Method Name: CalculateLength
//
// Description:
//  Calculate the length of the vector based on the X and Y components of the vector.
//
// Arguments:
//  N/A
//
// Return:
//  N/A
//
//*********************************************************************************************************************************************
void Vector2D::CalculateLength()
{
   mLength = sqrtf(powf(fabsf(mComponentX), 2.0F) + powf(fabsf(mComponentY), 2.0F));
}