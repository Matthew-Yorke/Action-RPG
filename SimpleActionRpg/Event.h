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

      //*********************************************************************************************************************************************
      //
      // Method Name: Event
      //
      // Description:
      //  Constructor that initializes member variables.
      //
      // Arguments:
      //  theCoordinateX - The X-Coordinate where the event exists.
      //  theCoordinateY - The Y-Coordinate where the event exists.
      //  theWidth - The width of the area of the event.
      //  theHeight  - The height of the area of the event.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Event(int theCoordinateX, int theCoordinateY, int theWidth, int theHeight);

      //*********************************************************************************************************************************************
      //
      // Method Name: ~Event
      //
      // Description:
      //  Destructor that cleans up allocated memory.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      ~Event();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetArea
      //
      // Description:
      //  Returns the area where the event resides.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns the rectangular area of where the event resides.
      //
      //*********************************************************************************************************************************************
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

      // Holds the area where the event resides.
      RectangleObject* mpArea;

};

#endif