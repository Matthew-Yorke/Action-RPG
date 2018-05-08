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
   bool operator()(TileInformation*  lhs, TileInformation* rhs)
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
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
Pathfinding::Pathfinding(std::vector<TileInformation*> theMap)
{
   mpMap = theMap;
}

//***************************************************************************************************************************************************
//
// Method Name: ~Pathfinding
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
Pathfinding::~Pathfinding()
{
}

//***************************************************************************************************************************************************
//
// Method Name: FindPath
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
std::vector<TileInformation*> Pathfinding::FindPath(TileInformation* theStart, TileInformation* theEnd)
{
   std::vector<TileInformation*> mpShortestPath;
   std::priority_queue<TileInformation*, std::vector<TileInformation*>, CompareGlobalGoal> mOpenList;

   for (auto iterator = mpMap.begin(); iterator != mpMap.end(); iterator++)
   {
      (*iterator)->Visited = false;
      (*iterator)->GlobalGoal = INFINITY;
      (*iterator)->LocalGoal = INFINITY;
      (*iterator)->pParent = nullptr;
   }

   TileInformation* currentTile = theStart;
   theStart->LocalGoal = 0.0F;
   theStart->GlobalGoal = Heuristic(theStart, theEnd);

   mOpenList.push(theStart);

   while (mOpenList.empty() == false && currentTile != theEnd)
   {
      while (mOpenList.empty() == false && mOpenList.top()->Visited == true)
      {
         mOpenList.pop();
      }

      if (mOpenList.empty() == true)
      {
         break;
      }

      currentTile = mOpenList.top();
      currentTile->Visited = true;

      float possibleLowerGoal = 0.0F;
      if (currentTile->pTopNeighbor != nullptr && currentTile->pTopNeighbor->Visited == false && currentTile->pTopNeighbor->Traversable == true)
      {
         mOpenList.push(currentTile->pTopNeighbor);
         possibleLowerGoal = currentTile->LocalGoal + Distance(currentTile, currentTile->pTopNeighbor);

         if (possibleLowerGoal < currentTile->pTopNeighbor->LocalGoal)
         {
            currentTile->pTopNeighbor->pParent = currentTile;
            currentTile->pTopNeighbor->LocalGoal = possibleLowerGoal;
            currentTile->pTopNeighbor->GlobalGoal = currentTile->pTopNeighbor->LocalGoal + Heuristic(currentTile->pTopNeighbor, theEnd);
         }
      }
      if (currentTile->pBottomNeighbor != nullptr && currentTile->pBottomNeighbor->Visited == false && currentTile->pBottomNeighbor->Traversable == true)
      {
         mOpenList.push(currentTile->pBottomNeighbor);

         possibleLowerGoal = currentTile->LocalGoal + Distance(currentTile, currentTile->pBottomNeighbor);

         if (possibleLowerGoal < currentTile->pBottomNeighbor->LocalGoal)
         {
            currentTile->pBottomNeighbor->pParent = currentTile;
            currentTile->pBottomNeighbor->LocalGoal = possibleLowerGoal;
            currentTile->pBottomNeighbor->GlobalGoal = currentTile->pBottomNeighbor->LocalGoal + Heuristic(currentTile->pBottomNeighbor, theEnd);
         }
      }
      if (currentTile->pLeftNeighbor != nullptr && currentTile->pLeftNeighbor->Visited == false && currentTile->pLeftNeighbor->Traversable == true)
      {
         mOpenList.push(currentTile->pLeftNeighbor);

         possibleLowerGoal = currentTile->LocalGoal + Distance(currentTile, currentTile->pLeftNeighbor);

         if (possibleLowerGoal < currentTile->pLeftNeighbor->LocalGoal)
         {
            currentTile->pLeftNeighbor->pParent = currentTile;
            currentTile->pLeftNeighbor->LocalGoal = possibleLowerGoal;
            currentTile->pLeftNeighbor->GlobalGoal = currentTile->pLeftNeighbor->LocalGoal + Heuristic(currentTile->pLeftNeighbor, theEnd);
         }
      }
      if (currentTile->pRightNeighbor != nullptr && currentTile->pRightNeighbor->Visited == false && currentTile->pRightNeighbor->Traversable == true)
      {
         mOpenList.push(currentTile->pRightNeighbor);

         possibleLowerGoal = currentTile->LocalGoal + Distance(currentTile, currentTile->pRightNeighbor);

         if (possibleLowerGoal < currentTile->pRightNeighbor->LocalGoal)
         {
            currentTile->pRightNeighbor->pParent = currentTile;
            currentTile->pRightNeighbor->LocalGoal = possibleLowerGoal;
            currentTile->pRightNeighbor->GlobalGoal = currentTile->pRightNeighbor->LocalGoal + Heuristic(currentTile->pRightNeighbor, theEnd);
         }
      }
   }

   TileInformation* temporary = theEnd;
   while (temporary->pParent != nullptr)
   {
      mpShortestPath.insert(mpShortestPath.begin(), temporary);
      temporary = temporary->pParent;
   }

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
// Method Name: Distance
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
float Pathfinding::Distance(TileInformation* theStart, TileInformation* theEnd)
{
   return sqrtf((theStart->TileCoordinateX - theEnd->TileCoordinateX)*(theStart->TileCoordinateX - theEnd->TileCoordinateX) +
                (theStart->TileCoordinateY - theEnd->TileCoordinateY)* (theStart->TileCoordinateY - theEnd->TileCoordinateY));
}

//***************************************************************************************************************************************************
//
// Method Name: Heuristic
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
float Pathfinding::Heuristic(TileInformation* theStart, TileInformation* theEnd)
{
   return Distance(theStart, theEnd);
}

//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************