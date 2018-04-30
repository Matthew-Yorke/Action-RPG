//***************************************************************************************************************************************************
//
// File Name: Event.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Event_H
#define Event_H

#include "RectangleObject.h"

class Event
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      Event(int theCoordinateX, int theCoordinateY, int theWidth, int theHeight);

      ~Event();

      RectangleObject* GetArea();

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
      RectangleObject* mpArea;

};

#endif