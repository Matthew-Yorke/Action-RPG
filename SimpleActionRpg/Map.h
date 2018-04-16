//***************************************************************************************************************************************************
//
// File Name: Map.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef Map_H
#define Map_H

#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include <vector>

class Map
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //************************************************************************************************************************************************
      //
      // Method Name: Map
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theMapFileLocation - The file location of the map information.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      Map(std::string theMapFileLocation);

      //************************************************************************************************************************************************
      //
      // Method Name: ~Map
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
      ~Map();

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
      void Draw();

   protected:

   // There are currently no protected methods for this class.

   private:

      //************************************************************************************************************************************************
      //
      // Method Name: LoadMap
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theMapFileLocation - The file location of the map information.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void LoadMap(std::string theMapFileLocation);

      //************************************************************************************************************************************************
      //
      // Method Name: LoadSpriteSheet
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theSpriteSheetFileLocation - The file location of the sprite sheet.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void LoadSpriteSheet(std::string theSpriteSheetFileLocation);

      //************************************************************************************************************************************************
      //
      // Method Name: SaveTileDimensions
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theTileDimensions - The string containing the width and height of a tile.
      //
      // Return:
      //  N/A
      //
      //************************************************************************************************************************************************
      void SaveTileDimensions(std::string theTileDimensions);

      //************************************************************************************************************************************************
      //
      // Method Name: SaveTileLocation
      //
      // Description:
      //  TODO: Add description.
      //
      // Arguments:
      //  theTileLocation - TODO: Add description.
      //  theVectorRow = TODO: Add description.
      //
      // Return:
      //  TODO: Add description.
      //
      //************************************************************************************************************************************************
      bool SaveTileLocation(std::string theTileLocation, int theVectorRow);

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

      // The sprite sheet tiles are draw from.
      ALLEGRO_BITMAP* mpTileSheet;

      // The number of tiles for the width of the map.
      int mTileWidth;

      // The number of tiles for the height of the map.
      int mTileHeight;

      struct TileInformation
      {
         int SpriteSheetCoordinateX;
         int SpriteSheetCoordinateY;
         int TileCoordinateX;
         int TileCoordinateY;
      };

      std::vector<TileInformation> mMap;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif