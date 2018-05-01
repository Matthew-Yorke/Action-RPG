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
#include "Map.h"

class Map;
class Graphics;

class ChangeMapEvent : public Event
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      ChangeMapEvent(Graphics* theGraphics, int theCoordinateX, int theCoordianteY, int theWidth, int theHeight, std::string theMapFileLocation, int thePlayerCoordinateX, int thePlayerCoordinateY);

      ~ChangeMapEvent();

      int GetPlayerCoordinateX();

      int GetPlayerCoordinateY();

      Map* Execute();

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

      std::string mMapFileLocation;

      int mPlayerCoordinateX;

      int mPlayerCoordinateY;

      Graphics* mpGraphics;
};

#endif