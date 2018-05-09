//***************************************************************************************************************************************************
//
// File Name: Pathfinding.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#ifndef Pathfinding_h
#define Pathfinding_h

#include <vector>
#include "Tile.h"

class Pathfinding
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: Pathfinding
      //
      // Description:
      //  Constructor that sets member variables with the passed in argument.
      //
      // Arguments:
      //  theMap - A vector of tiles for map.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      Pathfinding(std::vector<TileInformation*> theMap);

      //*********************************************************************************************************************************************
      //
      // Method Name: FindPath
      //
      // Description:
      //  Return the list of tiles that connect the starting point tile to the ending point tile.
      //
      // Arguments:
      //  pTheStart - Pointer to the starting tile location.
      //  pTheEnd - Pointer to the ending tile location.
      //
      // Return:
      //  Returns a vector of tiles ordered from the starting tile to the ending tile. If a path does not exist, the vector will be empty.
      //
      //*********************************************************************************************************************************************
      std::vector<TileInformation*> FindPath(TileInformation* pTheStart, TileInformation* pTheEnd);

   protected:

      // There are currently no protected methods for this class.

   private:

      //*********************************************************************************************************************************************
      //
      // Method Name: DetermineNeighborsCost
      //
      // Description:
      //  Determine if the cost from the current tile to the neighbor tile is less then a previous calculation to the neighbor. If so update the
      //  neighbor tile with the new path.
      //
      // Arguments:
      //  pTheCurrentTile - Pointer to the current tile being examined.
      //  pTheNeighborTile - Pointer to neighbor of the current tile being examined.
      //  pTheEndTile - Pointer to the ending tile of the path.
      //  mTheOpenList - Reference to the open list vector.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void DetermineNeighborMovementCost(TileInformation* pTheCurrentTile, TileInformation* pTheNeighborTile, TileInformation* pTheEndTile,
                                         std::priority_queue<TileInformation*, std::vector<TileInformation*>, CompareGlobalGoal>& theOpenList);

      //*********************************************************************************************************************************************
      //
      // Method Name: Distance
      //
      // Description:
      //  Return the distance from the starting to the ending tile location.
      //
      // Arguments:
      //  pTheStart - Pointer to the starting tile location.
      //  pTheEnd - Pointer to the ending tile location.
      //
      // Return:
      //  Returns the floating point value of the distance from the starting to the ending tile location.
      //
      //*********************************************************************************************************************************************
      float Distance(TileInformation* pTheStart, TileInformation* pTheEnd);

      //*********************************************************************************************************************************************
      //
      // Method Name: Heuristic
      //
      // Description:
      //  Return the distance from the starting to the ending tile location.
      //
      // Arguments:
      //  pTheStart - Pointer to the starting tile location.
      //  pTheEnd - Pointer to the ending tile location.
      //
      // Return:
      //  Returns the floating point value of the distance from the starting to the ending tile location.
      //
      //*********************************************************************************************************************************************
      float Heuristic(TileInformation* pTeStart, TileInformation* pTheEnd);

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

      // Holds a vector of tiles of the map.
      std::vector<TileInformation*> mMap;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif

