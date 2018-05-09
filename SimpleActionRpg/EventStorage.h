//***************************************************************************************************************************************************
//
// File Name: EventStorage.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef EventStorage_H
#define EventStorage_H

#include <vector>
#include "ChangeMapEvent.h"

// Forward Declarations
class ChangeMapEvent;

class EventStorage
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: GetInstance
      //
      // Description:
      //  Get an instance of the event manager.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns an instance of the event manager class.
      //
      //*********************************************************************************************************************************************
      static EventStorage* GetInstance();

      //*********************************************************************************************************************************************
      //
      // Method Name: ReleaseInstance
      //
      // Description:
      //  Release an instance of the event manager.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      static void ReleaseInstance(); 

      //*********************************************************************************************************************************************
      //
      // Method Name: AddChangeMapEvent
      //
      // Description:
      //  Adds a change map event to the vector of change map events.
      //
      // Arguments:
      //  thepChangeMapEvent - The change map event to add to the vector.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void AddChangeMapEvent(ChangeMapEvent* thepChangeMapEvent);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetChangeMapEvents
      //
      // Description:
      //  Returns the vector of change maps events.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Return the vector of change map events.
      //
      //*********************************************************************************************************************************************
      std::vector<ChangeMapEvent*> GetChangeMapEvents();

      //*********************************************************************************************************************************************
      //
      // Method Name: ClearEvents
      //
      // Description:
      //  Clear all the events being managed by the event manager.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void ClearEvents();

   protected:

      // There are currently no protected methods for this class.

   private:

      //*********************************************************************************************************************************************
      //
      // Method Name: EventStorage
      //
      // Description:
      //  Constructor of the event manager that sets member variables to default values.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      EventStorage();

      //*********************************************************************************************************************************************
      //
      // Method Name: ~EventStorage
      //
      // Description:
      //  Destructor of the event manager that cleans up any allocated memory being managed by this class.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      ~EventStorage();

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

      // Tracks the single instance of this event manager class.
      static EventStorage* mpInstance;

      // Tracks the number of references to the instance of this event manager class.
      static int mNumberOfReferences;

      // Tracks the change map events.
      std::vector<ChangeMapEvent*> mChangeMapEvents;
};

#endif