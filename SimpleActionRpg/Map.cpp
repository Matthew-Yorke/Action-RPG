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
Map::Map(std::string theSpriteSheetFilePath)
{
   mpTileSheet = nullptr;
   mTileWidth = 0;
   mTileHeight = 0;
   mMapWidth = 0;
   mMapHeight = 0;

   LoadMap(theSpriteSheetFilePath);
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
// Method Name: ChangeMapEventCollision
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
bool Map::ChangeMapEventCollision(Rectangle* theObject, Map*& theChangedMap, int& thePlayerCoordinateX, int& thePlayerCoordinateY)
{
   bool changeMap = false;

   for (auto currentChangeMapEvent = mpChangeMapEventList.begin();
        currentChangeMapEvent != mpChangeMapEventList.end();
        currentChangeMapEvent++)
   {
      if (theObject->GetCoordinateX() < ((*currentChangeMapEvent)->GetArea()->GetCoordinateX() + (*currentChangeMapEvent)->GetArea()->GetWidth()) &&
          (theObject->GetCoordinateX() + theObject->GetWidth()) > (*currentChangeMapEvent)->GetArea()->GetCoordinateX() &&
          theObject->GetCoordinateY() < ((*currentChangeMapEvent)->GetArea()->GetCoordinateY() + (*currentChangeMapEvent)->GetArea()->GetHeight()) &&
          (theObject->GetCoordinateY() + theObject->GetHeight()) > (*currentChangeMapEvent)->GetArea()->GetCoordinateY())
      {
         theChangedMap = (*currentChangeMapEvent)->Execute();
         thePlayerCoordinateX = (*currentChangeMapEvent)->GetPlayerCoordinateX();
         thePlayerCoordinateY = (*currentChangeMapEvent)->GetPlayerCoordinateY();
         changeMap = true;
         
         break;
      }
   }

   return changeMap;
};

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
   for (auto iterator = mMap.begin(); iterator != mMap.end(); iterator++)
   {
      al_draw_bitmap_region(mpTileSheet,
                            (*iterator).SpriteSheetCoordinateX * mTileWidth,
                            (*iterator).SpriteSheetCoordinateY * mTileHeight,
                            mTileWidth,
                            mTileHeight,
                            (*iterator).TileCoordinateX * mTileWidth,
                            (*iterator).TileCoordinateY * mTileHeight,
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
      if (lineCount == 1)
      {
         SaveTileDimensions(parsedOutLine);
      }

      // Load the tile placements.
      if (lineCount > 1 && SetMap == false)
      {
         SetMap = SaveTileLocation(parsedOutLine, vectorCount);
         vectorCount++;
      }

      // Load events
      if (lineCount > 1 && SetMap == true)
      {
         LoadEvents(parsedOutLine);
      }

      lineCount++;
   }

   // Multiply the vector count representing as the number of tiles height-wise by the tile height to get the total height of the map.
   mMapHeight = vectorCount * mTileHeight;

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
   
   // Multiply the current map width (number of tiles) by the tile width to get the total screen width.
   mMapWidth *= mTileWidth;

   // Break down tile components and save the information to the map vector.
   int count = 0;
   int tileCoordinateX = 0;
   int spriteSheetCoordinateX = 0;
   int spriteSheetCoordinateY = 0;
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
         else
         {
            spriteSheetCoordinateY = stoi(token);
         }
         
         count++;
      }

      if (finished == true)
      {
         break;
      }

      TileInformation ti;
      ti.SpriteSheetCoordinateX = spriteSheetCoordinateX;
      ti.SpriteSheetCoordinateY = spriteSheetCoordinateY;
      ti.TileCoordinateX = tileCoordinateX;
      ti.TileCoordinateY = theVectorRow;
      mMap.push_back(ti);

      tileCoordinateX++;
      count = 0;
   }

   return finished;
}

//************************************************************************************************************************************************
//
// Method Name: LoadEvents
//
// Description:
//  TODO: Add description.
//
// Arguments:
//  theEventInformation - TODO: Add description.
//
// Return:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void Map::LoadEvents(std::string theEventInformation)
{
   // Break the parsed line down further to individual tile components.
   std::vector<std::string> parsedEventInformation;
   std::string token = "";
   std::istringstream stringStream(theEventInformation);
   while(std::getline(stringStream, token, ','))
   {
      parsedEventInformation.push_back(token);
   }

   if(parsedEventInformation[0] == "CHANGE_MAP")
   {
      mpChangeMapEventList.push_back(new ChangeMapEvent(std::stoi(parsedEventInformation[1]),
                                                        std::stoi(parsedEventInformation[2]),
                                                        mTileWidth,
                                                        mTileHeight,
                                                        parsedEventInformation[3],
                                                        std::stoi(parsedEventInformation[4]),
                                                        std::stoi(parsedEventInformation[5])));
   }
}

//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************