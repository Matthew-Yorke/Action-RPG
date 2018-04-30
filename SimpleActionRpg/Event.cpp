//***************************************************************************************************************************************************
//
// File Name: Event.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#include "Event.h"

Event::Event(int theCoordinateX, int theCoordinateY, int theWidth, int theHeight)
{
   mpArea = new RectangleObject(theCoordinateX,
                                theCoordinateY,
                                theWidth,
                                theHeight);
}

Event::~Event()
{
   delete mpArea;
}

RectangleObject* Event::GetArea()
{
   return mpArea;
}