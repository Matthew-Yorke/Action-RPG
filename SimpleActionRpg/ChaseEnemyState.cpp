//***************************************************************************************************************************************************
//
// File Name: ChaseEnemyState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "ChaseEnemyState.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: ChaseEnemyState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
ChaseEnemyState::ChaseEnemyState(Enemy* theEnemy) :
EnemyState(theEnemy)
{
   mpNextTile = nullptr;
   mTravelingToNextTile = false;
}

//************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  Nothing is being done during the idle state, so there is no code in the update method.
//
//************************************************************************************************************************************************
void ChaseEnemyState::Update(float theTimeChange)
{
   if (mTravelingToNextTile == false)
   {
      mpNextTile = mpEnemy->GetNextPathTile();
      mTravelingToNextTile = true;
   }

   if (mpNextTile != nullptr)
   {
      // Tile is left of player
      if ((mpNextTile->TileCoordinateX * mpNextTile->TileWidth) + (mpNextTile->TileWidth / 2) < 
          (mpEnemy->GetMovementHitBox()->GetCoordinateX() + mpEnemy->GetMovementHitBox()->GetWidthCenterPoint()))
      {
         mpEnemy->SetCoordinateX(mpEnemy->GetCoordinateX() - 1);
      }
      // Tile is right of player
      else if ((mpNextTile->TileCoordinateX * mpNextTile->TileWidth) + (mpNextTile->TileWidth / 2) > 
               (mpEnemy->GetMovementHitBox()->GetCoordinateX() + mpEnemy->GetMovementHitBox()->GetWidthCenterPoint()))
      {
         mpEnemy->SetCoordinateX(mpEnemy->GetCoordinateX() + 1);
      }
      // Tile is above player
      else if ((mpNextTile->TileCoordinateY * mpNextTile->TileHeight) + (mpNextTile->TileHeight / 2) <
                (mpEnemy->GetMovementHitBox()->GetCoordinateY() + mpEnemy->GetMovementHitBox()->GetHeightCenterPoint()))
      {
         mpEnemy->SetCoordinateY(mpEnemy->GetCoordinateY() - 1);
      }
      // Tile is below player
      else if ((mpNextTile->TileCoordinateY * mpNextTile->TileHeight) + (mpNextTile->TileHeight / 2) >
               (mpEnemy->GetMovementHitBox()->GetCoordinateY() + mpEnemy->GetMovementHitBox()->GetHeightCenterPoint()))
      {
         mpEnemy->SetCoordinateY(mpEnemy->GetCoordinateY() + 1);
      }
      // At tile
      else
      {
         //mpEnemy->RemoveTopPathTile();
         mTravelingToNextTile = false;
      }
   }
   else
   {
      // Destination Reached.
      mTravelingToNextTile = false;
   }
}

//************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  N/A
//
// Return:
//  N/A
//
//************************************************************************************************************************************************
void ChaseEnemyState::Draw(Graphics& theGraphics)
{
   mpEnemy->DrawSprite(theGraphics);
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