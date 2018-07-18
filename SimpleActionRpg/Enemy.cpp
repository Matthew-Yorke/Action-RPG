//***************************************************************************************************************************************************
//
// File Name: Enemy.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include <allegro5/allegro_primitives.h>
#include "Enemy.h"
#include "ChaseEnemyState.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: Enemy
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
Enemy::Enemy(Graphics& theGraphics, int theCoordinateX, int theCoordinateY) :
Character(theGraphics, theCoordinateX, theCoordinateY)
{
   mCurrentHealth = mMaxHealth = 1;
   mpSprite = new AnimatedSprite(theGraphics,
                                 "../Images/TestEnemy.png",
                                 0,
                                 0,
                                 64,
                                 64,
                                 6,
                                 1);
   mpHitbox = new RectangleObject(theCoordinateX + 20,
                                  theCoordinateY + 1,
                                  25,
                                  63);
   mpMovementHitbox = new RectangleObject(theCoordinateX + 20,
                                          theCoordinateY + 33,
                                          25,
                                          31);
   PathReachedRange = new CircleObject(theCoordinateX + 32,
                                       theCoordinateY + 32,
                                       64);
   mInvincible = false;
   mInvincibleTime = 0.0F;
   mpState = new ChaseEnemyState(this);
}

//************************************************************************************************************************************************
//
// Method Name: GetPathReachedRange
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
CircleObject* Enemy::GetPathReachedRange()
{
   return PathReachedRange;
}

//************************************************************************************************************************************************
 //
 // Method Name: ChangeState
 //
 // Description:
 //  TODO: Add description.
 //
 //************************************************************************************************************************************************
 void Enemy::ChangeState(EnemyState* theState)
{
   delete mpState;
   mpState = theState;
}

//************************************************************************************************************************************************
//
// Method Name: TemporaryInvincible
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Enemy::TemporaryInvincible()
{
   mInvincible = true;
   mInvincibleTime = 0.6F;
}

//************************************************************************************************************************************************
//
// Method Name: GetIsInvincible
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
bool Enemy::GetIsInvincible()
{
   return mInvincible;
}

//************************************************************************************************************************************************
//
// Method Name: GetCurrentHealth
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
int Enemy::GetCurrentHealth()
{
   return mCurrentHealth;
}

//************************************************************************************************************************************************
//
// Method Name: SetPath
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Enemy::SetPath(std::vector<TileInformation*> thePath)
{
   mpPath = thePath;
}

//************************************************************************************************************************************************
//
// Method Name: GetNextPathTile
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
TileInformation* Enemy::GetNextPathTile()
{
   TileInformation* nextPathTile = nullptr;
   if (mpPath.empty() == false)
   {
      nextPathTile = *mpPath.begin();
   }
   return nextPathTile;
}

//************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Enemy::Update(float theTimeChange)
{
   mpState->Update(theTimeChange);

   mpHitbox->SetCoordinateX(GetCoordinateX() + 20);
   mpHitbox->SetCoordinateY(GetCoordinateY() + 1);
   mpMovementHitbox->SetCoordinateX(GetCoordinateX() + 20);
   mpMovementHitbox->SetCoordinateY(GetCoordinateY() + 33);
   PathReachedRange->SetCoordinateX(GetCoordinateX() + 32);
   PathReachedRange->SetCoordinateY(GetCoordinateY() + 32);

   if (mInvincible == true)
   {
      mInvincibleTime -= theTimeChange;

      if (mInvincibleTime < 0.0F)
      {
         mInvincible = false;
      }
   }
}

//************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Enemy::Draw(Graphics& theGraphics)
{
   DrawSprite(theGraphics);
   al_draw_rectangle(mpHitbox->GetCoordinateX(), mpHitbox->GetCoordinateY(), mpHitbox->GetCoordinateX() + mpHitbox->GetWidth(), mpHitbox->GetCoordinateY()+ mpHitbox->GetHeight(), al_map_rgb(255,0,0), 1);
   al_draw_rectangle(mpMovementHitbox->GetCoordinateX(), mpMovementHitbox->GetCoordinateY(), mpMovementHitbox->GetCoordinateX() + mpMovementHitbox->GetWidth(), mpMovementHitbox->GetCoordinateY()+ mpMovementHitbox->GetHeight(), al_map_rgb(0,0,255), 1);
   al_draw_circle(PathReachedRange->GetCoordinateX(), PathReachedRange->GetCoordinateY(), PathReachedRange->GetRadius(), al_map_rgb(0,255,255), 1);

   if (mpCurrentTile != nullptr)
   {
      al_draw_rectangle(mpCurrentTile->TileCoordinateX * 32,
                        mpCurrentTile->TileCoordinateY * 32,
                        (mpCurrentTile->TileCoordinateX * 32) + 32,
                        (mpCurrentTile->TileCoordinateY * 32) + 32,
                        al_map_rgb(255, 255, 0),
                        1);
   }
}

//************************************************************************************************************************************************
//
// Method Name: DrawSprite
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  theGraphics - TODO: Add description.
//
// Return:
//  N/A
//
//************************************************************************************************************************************************
void Enemy::DrawSprite(Graphics& theGraphics)
{
   mpSprite->Draw(theGraphics,
                  GetCoordinateX(),
                  GetCoordinateY());

   for (auto iterator = mpPath.begin(); iterator != mpPath.end(); iterator++)
   {
      al_draw_rectangle((*iterator)->TileCoordinateX * 32,
                        (*iterator)->TileCoordinateY * 32,
                        ((*iterator)->TileCoordinateX * 32) + 32,
                        ((*iterator)->TileCoordinateY * 32) + 32,
                        al_map_rgb(255, 0, 255),
                        1);
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