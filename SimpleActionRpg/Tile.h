#ifndef Tile_h
#define Tile_h

struct TileInformation
{
   int SpriteSheetCoordinateX = 0;
   int SpriteSheetCoordinateY = 0;
   int TileCoordinateX = 0;
   int TileCoordinateY = 0;
   float GlobalGoal = INFINITY;
   float LocalGoal = INFINITY;
   bool Visited = false;
   bool Traversable = false;
   TileInformation* pParent = nullptr;
   TileInformation* pTopNeighbor = nullptr;
   TileInformation* pBottomNeighbor = nullptr;
   TileInformation* pLeftNeighbor = nullptr;
   TileInformation* pRightNeighbor = nullptr;
};

#endif