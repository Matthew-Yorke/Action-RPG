//***************************************************************************************************************************************************
//
// File Name: CastMagicPlayState.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include <vector>
#include "CastMagicPlayState.h"
#include "PlayerCharacter.h"
#include "RegularPlayState.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: CastMagicPlayState
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
CastMagicPlayState::CastMagicPlayState(PlayState* pThePlayState) :
PlaySubState(pThePlayState)
{
   mpSelector = new Sprite(*pThePlayState->mpGraphics, "../Images/Selector.png", 0, 0, 32, 32);
   mSelectorCenterLocationX = 0;
   mSelectorCenterLocationY = 0;
   mUpdateNeeded = true;
}

//************************************************************************************************************************************************
//
// Method Name: KeyDown
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void CastMagicPlayState::KeyDown(ALLEGRO_EVENT theEvent)
{
   // Track that a key was pressed down and enter that action's state.
   switch (theEvent.keyboard.keycode)
   {
      case ALLEGRO_KEY_DOWN:
      {
         mSelectorCenterLocationY++;
         mUpdateNeeded = true;
         break;
      }
      case ALLEGRO_KEY_UP:
      {
         mSelectorCenterLocationY--;
         mUpdateNeeded = true;
         break;
      }
      case ALLEGRO_KEY_RIGHT:
      {
         mSelectorCenterLocationX++;
         mUpdateNeeded = true;
         break;
      }
      case ALLEGRO_KEY_LEFT:
      {
         mSelectorCenterLocationX--;
         mUpdateNeeded = true;
         break;
      }
      case ALLEGRO_KEY_Z:
      {
         mpPlayeState->ChangeSubState(new RegularPlayState(mpPlayeState));
      }
   }
}

//************************************************************************************************************************************************
//
// Method Name: KeyUp
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void CastMagicPlayState::KeyUp(ALLEGRO_EVENT theEvent)
{
   mpPlayeState->mpPlayer->KeyUp(theEvent);
}

//************************************************************************************************************************************************
//
// Method Name: Update
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void CastMagicPlayState::Update(float theTimeChange)
{
   if (mUpdateNeeded == true)
   {
      for (auto iterator = mMagicArea.begin(); iterator != mMagicArea.end(); iterator++)
      {
         delete *iterator;
      }
      mMagicArea.clear();

      int currentX = 0;
      int currentY = 0;

      // Holds the list of tile locations to investigate from for more moveable spaces.
      std::vector<MagicAreaSquare*> investigateAreas;
      // List of new areas found from the investigate areas container.
      std::vector<MagicAreaSquare*> newInvestigateAreas;

      // Add the ships location as the starting investigate area.
      MagicAreaSquare* startingNode = new MagicAreaSquare();
      startingNode->x = mSelectorCenterLocationX;
      startingNode->y = mSelectorCenterLocationY;
      investigateAreas.push_back(startingNode);

      // Add the ships location as a tile where it can move to.
      mMagicArea.push_back(startingNode);

      // For as many movement spaces that are left, check which tiles are needed in the moveable tile container for the tiles the ship can traverse
      // to.
      for (int currentMovementDistance = 0;
           currentMovementDistance < 3;
           currentMovementDistance++)
      {
         // For each tile that is to be investigated this iteration, search for each adjacent tile to check if it's already added to the moveable
         // tiles container. If they aren't found in the moveable tiles container, then add them to the moveable tiles and new areas to investigate
         // containers so the next iteration will know what tiles are already found and which tiles to check next respectfully.
         for (auto currentInvestigateArea = investigateAreas.begin();
              currentInvestigateArea < investigateAreas.end();
              currentInvestigateArea++)
         {
            // Check the tile above of the investigate tile.
            currentX = (*currentInvestigateArea)->x;
            currentY = (*currentInvestigateArea)->y - 1;
            auto foundMoveableTileIterator = std::find_if(mMagicArea.begin(),
                                                          mMagicArea.end(),
                                                          [currentX, currentY](const MagicAreaSquare* d){return d->x == currentX && d->y == currentY;});
            if (foundMoveableTileIterator == mMagicArea.end())
            {
               MagicAreaSquare* ValidNode = new MagicAreaSquare();
               ValidNode->x = currentX;
               ValidNode->y = currentY;
               mMagicArea.push_back(ValidNode);
               newInvestigateAreas.push_back(ValidNode);
            }

            
            // Check the tile below of the investigate tile.
            currentX = (*currentInvestigateArea)->x;
            currentY = (*currentInvestigateArea)->y + 1;
            foundMoveableTileIterator = std::find_if(mMagicArea.begin(),
                                                     mMagicArea.end(),
                                                     [currentX, currentY](const MagicAreaSquare* d){return d->x == currentX && d->y == currentY;});
            if (foundMoveableTileIterator == mMagicArea.end())
            {
               MagicAreaSquare* ValidNode = new MagicAreaSquare();
               ValidNode->x = currentX;
               ValidNode->y = currentY;
               mMagicArea.push_back(ValidNode);
               newInvestigateAreas.push_back(ValidNode);
            }

            // Check the tile to the left of the investigate tile.
            currentX = (*currentInvestigateArea)->x - 1;
            currentY = (*currentInvestigateArea)->y;
            foundMoveableTileIterator = std::find_if(mMagicArea.begin(),
                                                     mMagicArea.end(),
                                                     [currentX, currentY](const MagicAreaSquare* d){return d->x == currentX && d->y == currentY;});
            if (foundMoveableTileIterator == mMagicArea.end())
            {
               MagicAreaSquare* ValidNode = new MagicAreaSquare();
               ValidNode->x = currentX;
               ValidNode->y = currentY;
               mMagicArea.push_back(ValidNode);
               newInvestigateAreas.push_back(ValidNode);
            }

            // Check the tile to the right of the investigate tile.
            currentX = (*currentInvestigateArea)->x + 1;
            currentY = (*currentInvestigateArea)->y;
            foundMoveableTileIterator = std::find_if(mMagicArea.begin(),
                                                     mMagicArea.end(),
                                                     [currentX, currentY](const MagicAreaSquare* d){return d->x == currentX && d->y == currentY;});
            if (foundMoveableTileIterator == mMagicArea.end())
            {
               MagicAreaSquare* ValidNode = new MagicAreaSquare();
               ValidNode->x = currentX;
               ValidNode->y = currentY;
               mMagicArea.push_back(ValidNode);
               newInvestigateAreas.push_back(ValidNode);
            }
         }

         // Transfer the data from the new investigate areas container to the investigate areas container for the next iteratio to know which tiles
         // to search from.
         investigateAreas.clear();
         investigateAreas = newInvestigateAreas;
         newInvestigateAreas.clear();
      }

      // Clear the investigate area container.
      investigateAreas.clear();

      mUpdateNeeded = false;
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
void CastMagicPlayState::Draw(Graphics& theGraphics)
{
   if (mpPlayeState->mpCurrentMap != nullptr)
   {
      mpPlayeState->mpCurrentMap->Draw();
   }

   std::vector<Enemy*> temporaryEnemyList = mpPlayeState->mpCurrentMap->GetEnemyList();
   for (auto currentEnemy = temporaryEnemyList.begin();
        currentEnemy != temporaryEnemyList.end();
        currentEnemy++)
   {
      (*currentEnemy)->Draw(theGraphics);
   }

   if (mpPlayeState->mpPlayer != nullptr)
   {
      mpPlayeState->mpPlayer->Draw(theGraphics);
   }

   if (mpPlayeState->mpShadowLayer != nullptr)
   {
      mpPlayeState->mpShadowLayer->Draw(theGraphics);
   }

   // Selector
   for (auto iterator = mMagicArea.begin(); iterator != mMagicArea.end(); iterator++)
   {
      mpSelector->Draw(theGraphics, (*iterator)->x * 32, (*iterator)->y * 32);
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