//***************************************************************************************************************************************************
//
// File Name: Vector2D.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#ifndef Vector2D_h
#define Vector2D_h

class Vector2D
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Vector2D
      //
      // Description:
      //  Constructor that sets default values for member variables.
      //
      // Arguments:
      //  theComponentX - The X-Component of the vector.
      //  theComponentY - The Y-Component of the vector.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Vector2D(float theComponentX, float theComponentY);

      //*********************************************************************************************************************************************
      //
      // Method Name: SetComponentX
      //
      // Description:
      //  Updates the X-Component of the vector.
      //
      // Arguments:
      //  theComponentX - The new X-Component of the vector.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetComponentX(float theComponentX);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetComponentX
      //
      // Description:
      //  This method returns the X-Component of the vector.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns a float depicting the X-Component of the vector.
      //
      //*********************************************************************************************************************************************
      float GetComponentX();

      //*********************************************************************************************************************************************
      //
      // Method Name: SetComponentY
      //
      // Description:
      //  Updates the Y-Component of the vector.
      //
      // Arguments:
      //  theComponentY - The new Y-Component of the vector.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void SetComponentY(float theComponentY);

      //*********************************************************************************************************************************************
      //
      // Method Name: GetComponentY
      //
      // Description:
      //  This method returns the Y-Component of the vector.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns a float depicting the Y-Component of the vector.
      //
      //*********************************************************************************************************************************************
      float GetComponentY();

      //*********************************************************************************************************************************************
      //
      // Method Name: GetLength
      //
      // Description:
      //  Returns the length (based on both the X and Y components) of the vector.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Returns a float depicting the length of the vector.
      //
      //*********************************************************************************************************************************************
      float GetLength();

   protected:

      // There are currently no protected methods for this class.

   private:

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
      void CalculateLength();

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

      // Holds the X-Component of the vector.
      float mComponentX;

      // Holds the Y-Component of the vector.
      float mComponentY;

      // Holds the length of the vector ((based on both the X and Y components).
      float mLength;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif