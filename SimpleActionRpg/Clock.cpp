//***************************************************************************************************************************************************
//
// File Name: Clock.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "Clock.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: Clock
//
// Description:
//  Sets member variables their default values.
//
//***************************************************************************************************************************************************
Clock::Clock(float theSecondsInMinute)
{
   mTimeUntilTick = mSecondsInMinute = theSecondsInMinute;
   mMinute = 0;
   mHour = 0;
}

//***************************************************************************************************************************************************
//
// Method Name: GetTimeString
//
// Description:
//  Return a time string the format of HH:MM
//
//***************************************************************************************************************************************************
std::string Clock::GetTimeString()
{
   // Holds the time string in format of HH:MM
   std::string returnString = "";

   // Check if the hour is below 10 and append a 0 to the front of the string if so.
   if (mHour < 10)
   {
      returnString += "0";
   }

   // Append the hour to the time string and a colon for the hour/minute separator.
   returnString += std::to_string(mHour) + ":";

   // Check if the minute is below 10 and append a 0 to the front of the string if so.
   if (mMinute < 10)
   {
      returnString += "0";
   }

   // Append the minute to the time string.
   returnString += std::to_string(mMinute);

   // Return the time string now in the HH:MM format.
   return returnString;
}

//***************************************************************************************************************************************************
//
// Method Name: GetMinute
//
// Description:
//  Returns the current minute.
//
//***************************************************************************************************************************************************
int Clock::GetMinute()
{
   return mMinute;
}

//***************************************************************************************************************************************************
//
// Method Name: GetHour
//
// Description:
//  Returns the current hour.
//
//***************************************************************************************************************************************************
int Clock::GetHour()
{
   return mHour;
}

//***************************************************************************************************************************************************
//
// Method Name: GetTotalMinutes
//
// Description:
//  Returns the total number minutes from the combined hours and minutes.
//
//***************************************************************************************************************************************************
int Clock::GetTotalMinutes()
{
   return (mHour * 60) + mMinute;
}

//***************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  Decrement the time until next tick. When the time until next tick reaches below the threshold update to the next minute. If the minute reaches
//  minute number 60, minutes are reset to 0 and the hour is incremented. If the hour increments to 24 then hour is reset back to 0.
//
//***************************************************************************************************************************************************
void Clock::Update(float theTimeChange)
{
   // Decrement the time until next tick.
   mTimeUntilTick -= theTimeChange;

   // Check if a time update should occur.
   if (mTimeUntilTick < 0.0F)
   {
      // Reset the time until next tick.
      mTimeUntilTick = mSecondsInMinute;

      // Increment to the next minute.
      mMinute++;

      // Check if the next hour has been reached.
      if (mMinute == 60)
      {
         // Reset the minute count and increment to the next hour.
         mMinute = 0;
         mHour++;

         // Check if the Clock has reached the end of a 24 hour cycle.
         if (mHour == 24)
         {
            // Reset the hour count.
            mHour = 0;
         }
      }
   }
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