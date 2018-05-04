#ifndef Tile_h
#define Tile_h

struct TileInformation
{
   int SpriteSheetCoordinateX;
   int SpriteSheetCoordinateY;
   int TileCoordinateX;
   int TileCoordinateY;
   bool Traversable;
   TileInformation* pTopNeighbor = nullptr;
   TileInformation* pBottomNeighbor = nullptr;
   TileInformation* pLeftNeighbor = nullptr;
   TileInformation* pRightNeighbor = nullptr;
};

#endif