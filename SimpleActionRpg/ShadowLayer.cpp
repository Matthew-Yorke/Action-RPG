//***************************************************************************************************************************************************
//
// File Name: ShadowLayer.cpp
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
#include "ShadowLayer.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: ShadowLayer
//
// Description:
//  Load the shadow bitmap with the passed in argument and set member variables to their default values.
//
//***************************************************************************************************************************************************
ShadowLayer::ShadowLayer(std::string theFileLocation)
{
   mpShadowBitmap = al_load_bitmap(theFileLocation.c_str());
   mOpacity = 0;
   mpDimensions = new RectangleObject(0,
                                      0,
                                      al_get_bitmap_width(mpShadowBitmap),
                                      al_get_bitmap_height(mpShadowBitmap));
   mCoordinateX = 0;
   mCoordinateY = 0;
}

//***************************************************************************************************************************************************
//
// Method Name: ~ShadowLayer
//
// Description:
//  Frees any allocated memory managed by this class.
//
//***************************************************************************************************************************************************
ShadowLayer::~ShadowLayer()
{
   al_destroy_bitmap(mpShadowBitmap);
   delete mpDimensions;
}

//***************************************************************************************************************************************************
//
// Method Name: GetOpacity
//
// Description:
//  Returns the current opacity of the shadow layer.
//
//***************************************************************************************************************************************************
int ShadowLayer::GetOpacity()
{
   return mOpacity;
}

//***************************************************************************************************************************************************
//
// Method Name: SetOpacity
//
// Description:
//  Updates the opacity with the passed in argument.
//
//***************************************************************************************************************************************************
void ShadowLayer::SetOpacity(int theOpactiy)
{
   mOpacity = theOpactiy;
}

//***************************************************************************************************************************************************
//
// Method Name: SetIntensity
//
// Description:
//  Add a light to the vector of lights to blended over the shadow map upon a draw.
//
//***************************************************************************************************************************************************
void ShadowLayer::AddLight(Light* pTheLight)
{
   mLightList.push_back(pTheLight);
}

//***************************************************************************************************************************************************
//
// Method Name: RemoveLight
//
// Description:
//  TODO: Add description.
//
//***************************************************************************************************************************************************
inline void ShadowLayer::RemoveLight()
{
   // TODO: Remove specific light?
   // Note: Is this needed?
}

//***************************************************************************************************************************************************
//
// Method Name: CameraUpdate
//
// Description:
//  Update the X-Coordinate and Y-Coordinate relative to the camera coordinates. Also update the lights so they do not move along with the shadow
//  layer.
//
//***************************************************************************************************************************************************
void ShadowLayer::CameraUpdate(Camera* pTheCamera)
{
   // Update the entire dialog coordinates based on the dialog screen coordinates and camera coordinates.
   mCoordinateX = mpDimensions->GetCoordinateX() + pTheCamera->GetCoordinateX();
   mCoordinateY = mpDimensions->GetCoordinateY() + pTheCamera->GetCoordinateY();

   // Update the light locations as the camera moves.
   for (auto currentLight = mLightList.begin();
        currentLight != mLightList.end();
        currentLight++)
   {
      (*currentLight)->CameraUpdate(pTheCamera);
   }
}

//***************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  Draw the blended lights onto the shadow layer bitmap. Then draw the tinted shadow layer onto the screen.
//
//***************************************************************************************************************************************************
void ShadowLayer::Draw(Graphics& theGraphics)
{
   // Set the target to draw on as the shadow layer bitmap.
   al_set_target_bitmap(mpShadowBitmap);
   
   // Clear the bitmap to black.
   al_clear_to_color(al_map_rgb(0,
                                0,
                                0));

   // Set the blender to additive of the source alpha and inverse destination alpha.
   al_set_blender(ALLEGRO_ADD,
                  ALLEGRO_ALPHA,
                  ALLEGRO_INVERSE_ALPHA);

   // Add lights by blending them to shadow bitmap.
   for (auto currentLight = mLightList.begin();
        currentLight != mLightList.end();
        currentLight++)
   {
      (*currentLight)->Draw(theGraphics);
   }

    // Switch target back to the display and draw the tinted shadow bitmap
   al_set_target_bitmap(al_get_backbuffer(theGraphics.GetDisplay()));
   al_draw_tinted_bitmap(mpShadowBitmap,
                         al_map_rgba(255,
                                     255,
                                     255,
                                     mOpacity),
                         mCoordinateX,
                         mCoordinateY,
                         0);

   // Set blender back to the default.
   al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE,
                  ALLEGRO_INVERSE_ALPHA);
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