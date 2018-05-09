//***************************************************************************************************************************************************
//
// File Name: Pathfinding.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "Pathfinding.h"
#include <list>
#include <queue>

struct CompareGlobalGoal
{
   bool operator()(TileInformation* lhs, TileInformation* rhs)
   {
      return lhs->GlobalGoal > rhs->GlobalGoal;
   }
};

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: Pathfinding
//
// Description:
//  Retain the list of tiles in the map.
//
//***************************************************************************************************************************************************
Pathfinding::Pathfinding(std::vector<TileInformation*> theMap)
{
   mMap = theMap;
}

//***************************************************************************************************************************************************
//
// Method Name: FindPath
//
// Description:
//  Using the A* pathfinding algorithm, determines the shortest path from the starting tile to the ending tile. The path is determined by defining
//  the local and global cost between tiles. The lowest cost to another tile will be the parent tile. The path retraces the parent tiles from the
//  ending tile to determine the shortest path. The path is returned.
//
//***************************************************************************************************************************************************
std::vector<TileInformation*> Pathfinding::FindPath(TileInformation* pTheStart, TileInformation* pTheEnd)
{
   // The vector of the shortest path from the start to end tile.
   std::vector<TileInformation*> mpShortestPath;
   // Holds an open list of tiles to check ordered by lowest to highest global goal values.
   std::priority_queue<TileInformation*, std::vector<TileInformation*>, CompareGlobalGoal> mOpenList;;
   // Holds the possible goal value that may be lower then a previous goal value.
   float possibleLowerGoal = 0.0F;

   // Reset all tile pathfinding parameters.
   for (auto iterator = mMap.begin();
        iterator != mMap.end();
        iterator++)
   {
      (*iterator)->Visited = false;
      (*iterator)->GlobalGoal = INFINITY;
      (*iterator)->LocalGoal = INFINITY;
      (*iterator)->pParent = nullptr;
   }

   // Determine the starting tile as the first current tile to look at.
   TileInformation* currentTile = pTheStart;
   // Set the local goal to be 0 as there is no cost to move into itself.
   pTheStart->LocalGoal = 0.0F;
   // Determine the global goal by checking the heuristic between the start and end tile.
   pTheStart->GlobalGoal = Heuristic(pTheStart,
                                     pTheEnd);
   // Add the start tile as the first tile in the open list
   mOpenList.push(pTheStart);

   // Keep calculating the path until there is no more items in the open list or the current tile is the end tile.
   while (mOpenList.empty() == false &&
          currentTile != pTheEnd)
   {
      // Remove any top items in the open list that have already been visited.
      while (mOpenList.empty() == false &&
             mOpenList.top()->Visited == true)
      {
         mOpenList.pop();
      }

      // If the open list is empty after removing already visited tile, then break out as there is no more calculating to do.
      if (mOpenList.empty() == true)
      {
         break;
      }

      // Set the current tile as the top item in the open list and set that tile to have been visited.
      currentTile = mOpenList.top();
      currentTile->Visited = true;


      // Determine for each neighbor if the movement cost to it is lower to move to it from the current tile.
      DetermineNeighborMovementCost(currentTile, currentTile->pTopNeighbor, pTheEnd, mOpenList);
      DetermineNeighborMovementCost(currentTile, currentTile->pBottomNeighbor, pTheEnd, mOpenList);
      DetermineNeighborMovementCost(currentTile, currentTile->pLeftNeighbor, pTheEnd, mOpenList);
      DetermineNeighborMovementCost(currentTile, currentTile->pRightNeighbor, pTheEnd, mOpenList);
   }

   // Calculate the path from the end tile to the start tile by iterating the parent tile and adding that tile to the beginning of the shortest path
   // vector.
   TileInformation* temporary = pTheEnd;
   while (temporary->pParent != nullptr)
   {
      mpShortestPath.insert(mpShortestPath.begin(),
                            temporary);
      temporary = temporary->pParent;
   }

   // Return the vector for the shortest path.
   return mpShortestPath;
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
//
// Method Name: DetermineNeighborMovementCost
//
// Description:
//  Determine if the neighbor can be traversed to if it hasn't already. Add the neighbor to the open list if it can be visited. Determine the cost
//  from the current tile to the neighbor tile. If the cost is lower then a previous cost to the neighbor then the current tile is now the shortest
//  path to that neighbor. Calculate the global cost from the neighbor to the end tile that the neighbor has been updated.
//
//***************************************************************************************************************************************************
void Pathfinding::DetermineNeighborMovementCost(TileInformation* pTheCurrentTile, TileInformation* pTheNeighborTile, TileInformation* pTheEndTile,
                                                std::priority_queue<TileInformation*, std::vector<TileInformation*>, CompareGlobalGoal>& theOpenList)
{
   // Determines the possible lower cost from the current tile to the neighbor tile.
   float possibleLowerGoal = 0.0F;
   
   // Make sure the neighbor tile hasn't been visited and can be traveled to.
   if (pTheNeighborTile != nullptr &&
       pTheNeighborTile->Visited == false &&
       pTheNeighborTile->Traversable == true)
   {
      // Add the neighbor tile into the open list to be examined on another loop.
      theOpenList.push(pTheNeighborTile);
      
      // Determine the total cost (current tile total cost plus the cost to the next tile) from the current tile to the neighbor tile.
      possibleLowerGoal = pTheCurrentTile->LocalGoal + Distance(pTheCurrentTile,
                                                                pTheNeighborTile);
      
      // If the cost is lower then a previous cost to the neighbor tile.
      if (possibleLowerGoal < pTheNeighborTile->LocalGoal)
      {
         // Update the neighbors parent to be the current tile as it is now the shortest path.
         pTheNeighborTile->pParent = pTheCurrentTile;
         // Updated the neighbors local goal as the total cost calculated above.
         pTheNeighborTile->LocalGoal = possibleLowerGoal;
         // Recalculate the global goal from the neighbor tile to the end tile.
         pTheNeighborTile->GlobalGoal = pTheNeighborTile->LocalGoal + Heuristic(pTheNeighborTile,
                                                                                pTheEndTile);
      }
   }
}

//***************************************************************************************************************************************************
//
// Method Name: Distance
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
float Pathfinding::Distance(TileInformation* pTheStart, TileInformation* pTheEnd)
{
   return sqrtf((pTheStart->TileCoordinateX - pTheEnd->TileCoordinateX) * (pTheStart->TileCoordinateX - pTheEnd->TileCoordinateX) +
                (pTheStart->TileCoordinateY - pTheEnd->TileCoordinateY) * (pTheStart->TileCoordinateY - pTheEnd->TileCoordinateY));
}

//***************************************************************************************************************************************************
//
// Method Name: Heuristic
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
float Pathfinding::Heuristic(TileInformation* pTheStart, TileInformation* pTheEnd)
{
   return Distance(pTheStart,
                   pTheEnd);
}

//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************