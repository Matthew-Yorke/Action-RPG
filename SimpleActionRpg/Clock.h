//***************************************************************************************************************************************************
//
// File Name: Clock.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Clock_H
#define Clock_H

#include "Graphics.h"
#include <vector>
#include "Light.h"

class Clock
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Clock
      //
      // Description:
      //  Constructor that sets member variables to their default values.
      //
      // Arguments:
      //  theSecondsInMinute - The number of real world seconds that correlate to a clock minute.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Clock(float theSecondsInMinute);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetTimeString
      //
      // Description:
      //  Returns the time string in the HH:MM format.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns a string for the time format as HH:MM.
      //
      //*********************************************************************************************************************************************
      std::string GetTimeString();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetMinute
      //
      // Description:
      //  Returns the current minute of the clock.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns an integer that represent the current minute of the clock.
      //
      //*********************************************************************************************************************************************
      int GetMinute();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetHour
      //
      // Description:
      //  Return the current hour of the clock.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns an integer that represent the current hour of the clock.
      //
      //*********************************************************************************************************************************************
      int GetHour();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetTotalMinutes
      //
      // Description:
      //  Return the current total number of minutes the clock is at.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns an integer that represent the total number of minutes the clock is at.
      //
      //*********************************************************************************************************************************************
      int GetTotalMinutes();

      //*********************************************************************************************************************************************
      //
      // Method Name: Update
      //
      // Description:
      //  Updates the clock when enough time has passed to increment to the next minute of the clock.
      //
      // Arguments:
      //  theTimeChange - The time change since the last update.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Update(float theTimeChange);

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

      // Holds the current minute of clock.
      int mMinute;

      // Holds the current hour of the clock.
      int mHour;

      // Holds the number of real world seconds for a clock minute to occur.
      float mSecondsInMinute;

      // Holds how much time until the next minute occurs for the clock.
      float mTimeUntilTick;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif