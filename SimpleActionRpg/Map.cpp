//***************************************************************************************************************************************************
//
// File Name: Map.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <sstream>

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: Map
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
Map::Map(Graphics* theGraphics, std::string theSpriteSheetFilePath)
{
   mpTileSheet = nullptr;
   mTileWidth = 0;
   mTileHeight = 0;
   mMapWidth = 0;
   mMapHeight = 0;
   mpGraphics = theGraphics;
   mEventsLoaded = false;
   mpEventStorage = mpEventStorage->GetInstance();
   LoadMap(theSpriteSheetFilePath);

   mpPathfinder = new Pathfinding(mpMap);
}

//************************************************************************************************************************************************
//
// Method Name: ~Map
//
// Description:
//  TODO: Add description/A
//
//************************************************************************************************************************************************
Map::~Map()
{
   al_destroy_bitmap(mpTileSheet);

   for(auto currentTile = mpMap.begin(); currentTile != mpMap.end(); currentTile++)
   {
       delete *currentTile;
   } 
   mpMap.clear();

   for(auto currentEnemy = mpEnemyList.begin(); currentEnemy != mpEnemyList.end(); currentEnemy++)
   {
       delete *currentEnemy;
   } 
   mpEnemyList.clear();

   mpEventStorage->ReleaseInstance();
}

//************************************************************************************************************************************************
//
// Method Name: GetMapWidth
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
int Map::GetMapWidth()
{
   return mMapWidth;
}

//************************************************************************************************************************************************
//
// Method Name: GetMapHeight
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
int Map::GetMapHeight()
{
   return mMapHeight;
}

//************************************************************************************************************************************************
//
// Method Name: GetClosestTile
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
TileInformation* Map::GetClosestTile(int theCoordinateX, int theCoordinateY)
{
   TileInformation* closestTile = nullptr;

   for (auto iterator = mpMap.begin(); iterator != mpMap.end(); iterator++)
   {
      if (theCoordinateX >= ((*iterator)->TileCoordinateX * mTileWidth) &&
          theCoordinateX <= (((*iterator)->TileCoordinateX * mTileWidth) + mTileWidth) &&
          theCoordinateY >= ((*iterator)->TileCoordinateY * mTileHeight) &&
          theCoordinateY <= (((*iterator)->TileCoordinateY * mTileHeight) + mTileHeight))
      {
         closestTile = *iterator;
         break;
      }
   }

   return closestTile;
}

//************************************************************************************************************************************************
//
// Method Name: GetEnemyList
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
std::vector<Enemy*> Map::GetEnemyList()
{
   return mpEnemyList;
}

 //************************************************************************************************************************************************
//
// Method Name: UpdateEnemyList
//
// Description:
//  TODO: Add description.
//

//************************************************************************************************************************************************
void Map::UpdateEnemyList(std::vector<Enemy*> theNewList)
{
   mpEnemyList = theNewList;
}

//************************************************************************************************************************************************
//
// Method Name: FindPaths
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Map::FindPaths(TileInformation* theEnd)
{
   for (auto iterator = mpEnemyList.begin(); iterator != mpEnemyList.end(); iterator++)
   {
      (*iterator)->SetPath(mpPathfinder->FindPath((*iterator)->GetCurrentTile(), theEnd));
   }
}

//************************************************************************************************************************************************
//
// Method Name: NonTraverableTileCollision
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
bool Map::NonTraverableTileCollision(RectangleObject* theObject)
{
   bool collisionHappened = false;

   for (auto iterator = mpMap.begin(); iterator != mpMap.end(); iterator++)
   {
      if ((*iterator)->Traversable == false)
      {
         if (theObject->GetCoordinateX() < (((*iterator)->TileCoordinateX * mTileWidth) + mTileWidth) &&
             (theObject->GetCoordinateX() + theObject->GetWidth()) > ((*iterator)->TileCoordinateX * mTileWidth) &&
             theObject->GetCoordinateY() < (((*iterator)->TileCoordinateY * mTileHeight) + mTileHeight) &&
             (theObject->GetCoordinateY() + theObject->GetHeight()) > ((*iterator)->TileCoordinateY * mTileHeight))
         {
            collisionHappened = true;
            break;
         }
      }
   }

   return collisionHappened;
}

//************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Map::Draw()
{
   for (auto iterator = mpMap.begin(); iterator != mpMap.end(); iterator++)
   {
      al_draw_bitmap_region(mpTileSheet,
                            (*iterator)->SpriteSheetCoordinateX * mTileWidth,
                            (*iterator)->SpriteSheetCoordinateY * mTileHeight,
                            mTileWidth,
                            mTileHeight,
                            (*iterator)->TileCoordinateX * mTileWidth,
                            (*iterator)->TileCoordinateY * mTileHeight,
                            0);
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
//
// Method Name: LoadMap
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
void Map::LoadMap(std::string theSpriteSheetFilePath)
{
   std::ifstream mapFile;
	mapFile.open (theSpriteSheetFilePath);
   std::string parsedOutLine = "";
   int lineCount = 0;
   int vectorCount = 0;
   bool SetMap = false;

   while(mapFile.eof() == false)
   {
      getline(mapFile, parsedOutLine);

      // Load the tile sheet information.
      if (lineCount == 0)
      {
         LoadSpriteSheet(parsedOutLine);
      }
      // Load the tile dimensions.
      else if (lineCount == 1)
      {
         SaveTileDimensions(parsedOutLine);
      }
      // Load the tile placements.
      else if (lineCount > 1 && SetMap == false)
      {
         SetMap = SaveTileLocation(parsedOutLine, vectorCount);
         vectorCount++;
      }
      // Load events
      else if (mEventsLoaded == false)
      {
         LoadEvents(parsedOutLine);
      }
      // Load enemies
      else
      {
         LoadEnemies(parsedOutLine);
      }

      lineCount++;
   }

   // Multiply the vector count representing as the number of tiles height-wise by the tile height to get the total height of the map.
   mMapHeight = vectorCount * mTileHeight;

   ConnectTiles();

	mapFile.close();
}

//************************************************************************************************************************************************
//
// Method Name: LoadSpriteSheet
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Map::LoadSpriteSheet(std::string theSpriteSheetFileLocation)
{
   mpTileSheet = al_load_bitmap(theSpriteSheetFileLocation.c_str());
}

//************************************************************************************************************************************************
//
// Method Name: SaveTileDimensions
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Map::SaveTileDimensions(std::string theTileDimensions)
{
   std::string delimiter = ","; // Turn into constant later.
   // the vector of individual words from the text.
   std::vector<int> parsedDimensions;
   // The text for the current line.
   std::string lineText = "";

   // Parse the entire speaker text into separate individual words.
   size_t pos = 0;
   // Find the next word by finding the next instance of the delimiter.
   while ((pos = theTileDimensions.find(delimiter)) != std::string::npos)
   {
      // Add the word to the end of the parsed individual word vector.
      parsedDimensions.push_back(std::stoi(theTileDimensions.substr(0, pos)));
      // Remove the word from the overall text.
      theTileDimensions.erase(0, pos + delimiter.length());
   }
   // Add the last word to the parsed individual word vector.
   parsedDimensions.push_back(std::stoi(theTileDimensions));
   theTileDimensions = "";

   mTileWidth = parsedDimensions[0];
   mTileHeight = parsedDimensions[1];
}

//************************************************************************************************************************************************
//
// Method Name: SaveTileLocation
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
bool Map::SaveTileLocation(std::string theTileLocation, int theVectorRow)
{
   bool finished = false;
   // Reset the width of the map width.
   mMapWidth = 0;

   // Break the parsed line down further to individual tile components.
   std::vector<std::string> parsedTileInformation;
   std::string token = "";
   std::istringstream stringStream(theTileLocation);
   while(std::getline(stringStream, token, ','))
   {
      parsedTileInformation.push_back(token);
      // Increment the map width for each tile in the string.
      mMapWidth++;
   }
   
   // Subtract one for the ending symbol "!"
   mMapWidth--;
   // Multiply the current map width (number of tiles) by the tile width to get the total screen width.
   mMapWidth *= mTileWidth;

   // Break down tile components and save the information to the map vector.
   int count = 0;
   int tileCoordinateX = 0;
   int spriteSheetCoordinateX = 0;
   int spriteSheetCoordinateY = 0;
   bool traversable = false;
   for (auto iterator = parsedTileInformation.begin(); iterator != parsedTileInformation.end(); iterator++)
   {
      std::istringstream ss(*iterator);

      while(std::getline(ss, token, '/'))
      {
         if (token == "!")
         {
            finished = true;
            break;
         }

         if (count == 0)
         {
            spriteSheetCoordinateX = stoi(token);
         }
         else if (count == 1)
         {
            spriteSheetCoordinateY = stoi(token);
         }
         else
         {
            if(token == "T")
            {
               traversable = true;
            }
            else
            {
               traversable = false;
            }
         }
         
         count++;
      }

      if (finished == true)
      {
         break;
      }

      TileInformation* ti = new TileInformation();
      ti->TileWidth = mTileWidth;
      ti->TileHeight = mTileHeight;
      ti->SpriteSheetCoordinateX = spriteSheetCoordinateX;
      ti->SpriteSheetCoordinateY = spriteSheetCoordinateY;
      ti->TileCoordinateX = tileCoordinateX;
      ti->TileCoordinateY = theVectorRow;
      ti->Traversable =   traversable;
      mpMap.push_back(ti);

      tileCoordinateX++;
      count = 0;
   }

   return finished;
}

//************************************************************************************************************************************************
//
// Method Name: ConnectTiles
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
void Map::ConnectTiles()
{
   for (auto currentTile = mpMap.begin(); currentTile != mpMap.end(); currentTile++)
   {
      // Add top neighbor if not first row.
      if ((*currentTile)->TileCoordinateY != 0)
      {
         auto topNeighbor = currentTile;
         for (int count = 0; count < (mMapWidth / mTileWidth); count++)
         {
            topNeighbor--;
         }
         (*currentTile)->pTopNeighbor = *topNeighbor;
      }
      // Add bottom neighbor if not last row.
      if ((*currentTile)->TileCoordinateY != (mMapHeight / mTileHeight) - 1)
      {
         auto bottomNeighbor = currentTile;
         for (int count = 0; count < (mMapWidth / mTileWidth); count++)
         {
            bottomNeighbor++;
         }
         (*currentTile)->pBottomNeighbor = *bottomNeighbor;
      }
      // Add left neighbor if not first column.
      if ((*currentTile)->TileCoordinateX != 0)
      {
         auto leftNeighbor = currentTile;
         leftNeighbor--;
         (*currentTile)->pLeftNeighbor = *leftNeighbor;
      }
      // Add right neighbor if not last column.
      if ((*currentTile)->TileCoordinateX != (mMapWidth / mTileWidth) - 1)
      {
         auto rightNeighbor = currentTile;
         rightNeighbor++;
         (*currentTile)->pRightNeighbor = *rightNeighbor;
      }
   }
}

//************************************************************************************************************************************************
//
// Method Name: LoadEvents
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Map::LoadEvents(std::string theEventInformation)
{
   // Break the parsed line down further to individual event components.
   std::vector<std::string> parsedEventInformation;
   std::string token = "";
   std::istringstream stringStream(theEventInformation);
   while(std::getline(stringStream, token, ','))
   {
      parsedEventInformation.push_back(token);
   }

   if(parsedEventInformation[0] == "CHANGE_MAP")
   {
      mpEventStorage->AddChangeMapEvent(new ChangeMapEvent(std::stoi(parsedEventInformation[1]),
                                                           std::stoi(parsedEventInformation[2]),
                                                           mTileWidth,
                                                           mTileHeight,
                                                           parsedEventInformation[3],
                                                           std::stoi(parsedEventInformation[4]),
                                                           std::stoi(parsedEventInformation[5])));
   }

   if (parsedEventInformation.size() == 7 && parsedEventInformation[6] == "!")
   {
      mEventsLoaded = true;
   }
}

//************************************************************************************************************************************************
//
// Method Name: LoadEnemies
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Map::LoadEnemies(std::string theEnemyInformation)
{
   // Break the parsed line down further to individual enemy components.
   std::vector<std::string> parsedEventInformation;
   std::string token = "";
   std::istringstream stringStream(theEnemyInformation);
   while(std::getline(stringStream, token, ','))
   {
      parsedEventInformation.push_back(token);
   }

   mpEnemyList.push_back(new Enemy(*mpGraphics,
                                   std::stoi(parsedEventInformation[0]),
                                   std::stoi(parsedEventInformation[1])));
}
//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************