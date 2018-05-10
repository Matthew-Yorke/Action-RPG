//***************************************************************************************************************************************************
//
// File Name: ChangeMapEvent.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef ChangeMapEvent_H
#define ChangeMapEvent_H

#include <string>
#include "Event.h"

class ChangeMapEvent : public Event
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: ChangeMapEvent
      //
      // Description:
      //  Constructor of the change map event to retain the event location and the event execution parameters.
      //
      // Arguments:
      //  theCoordinateX - The X-Coordinate where the event exists.
      //  theCoordinateY - The Y-Coordinate where the event exists.
      //  theWidth - The width of the area of the event.
      //  theHeight - The height of the area of the event.
      //  theMapFileLocation - The string containing the file path of the map to load when the event activates.
      //  theObjectDestinationCoordinateX - The X-Coordinate the object will be placed when the event occurs.
      //  theObjectDestinationCoordinateY - The Y-Coordinate the object will be placed when the event occurs.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      ChangeMapEvent(int theCoordinateX, int theCoordianteY, int theWidth, int theHeight, std::string theMapFileLocation,
                     int theObjectDestinationCoordinateX, int theObjectDestinationCoordinateY);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetObjectDestinationCoordinateX
      //
      // Description:
      //  Returns the X-Coordinate the object is to be placed at when the event occurs.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Return an integer value depicting the X-Coordinate the object is to be placed when the event occurs.
      //
      //*********************************************************************************************************************************************
      int GetObjectDestinationCoordinateX();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetObjectDestinationCoordinateY
      //
      // Description:
      //  Returns the Y-Coordinate the object is to be placed at when the event occurs.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Return an integer value depicting the Y-Coordinate the object is to be placed when the event occurs.
      //
      //*********************************************************************************************************************************************
      int GetObjectDestinationCoordinateY();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetMapFileLocation
      //
      // Description:
      //  Returns the file location of the map to load when the event occurs.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns a string value depicting the file location of the map to load when the event occurs.
      //
      //*********************************************************************************************************************************************
      std::string GetMapFileLocation();

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

      // Holds the map file location to load when the event occurs.
      std::string mMapFileLocation;

      // Holds the X-Coordinate the player is moved to when the event occurs.
      int mObjectDestinationCoordinateX;

      // Holds the Y-Coordinate the player is moved to when the event occurs.
      int mObjectDestinationCoordinateY;
};

#endif