//***************************************************************************************************************************************************
//
// File Name: Light.cpp
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
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
ShadowLayer::ShadowLayer(std::string theFileLocation)
{
   mBitmap = al_load_bitmap(theFileLocation.c_str());
   mIntensity = 0;
   mpDimensions = new Rectangle(0,
                                0,
                                al_get_bitmap_width(mBitmap),
                                al_get_bitmap_height(mBitmap));
   mCoordinateX = 0;
   mCoordinateY = 0;
}

//***************************************************************************************************************************************************
//
// Method Name: ~ShadowLayer
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
ShadowLayer::~ShadowLayer()
{
   al_destroy_bitmap(mBitmap);
}

//************************************************************************************************************************************************
//
// Method Name: GetIntenstiry
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
int ShadowLayer::GetIntenstiry()
{
   return mIntensity;
}

//************************************************************************************************************************************************
//
// Method Name: SetIntensity
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void ShadowLayer::SetIntensity(int theIntensity)
{
   mIntensity = theIntensity;
}

//************************************************************************************************************************************************
//
// Method Name: SetIntensity
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
void ShadowLayer::AddLight(Light* theLight)
{
   mLightList.push_back(theLight);
}

//************************************************************************************************************************************************
//
// Method Name: RemoveLight
//
// Description:
//  TODO: Add description.
//
//************************************************************************************************************************************************
inline void ShadowLayer::RemoveLight()
{
   // TODO: Remove specific light
}

//*********************************************************************************************************************************************
//
// Method Name: CameraUpdate
//
// Description:
//  Update the dialog pieces coordinates relative to the camera coordinates.
//
//*********************************************************************************************************************************************
void ShadowLayer::CameraUpdate(Camera* theCamera)
{
   // Update the entire dialog coordinates based on the dialog screen coordinates and camera coordinates.
   mCoordinateX = mpDimensions->GetCoordinateX() + theCamera->GetCoordinateX();
   mCoordinateY = mpDimensions->GetCoordinateY() + theCamera->GetCoordinateY();

   // Update the light locations as the camera moves.
   for (auto currentLight = mLightList.begin(); currentLight != mLightList.end(); currentLight++)
   {
      (*currentLight)->CameraUpdate(theCamera);
   }
}

//***************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
void ShadowLayer::Draw(Graphics& theGraphics)
{
   al_set_target_bitmap(mBitmap);
   
   al_clear_to_color(al_map_rgb(0,0,0));

   // Set the blender to additive of the source alpha and inverse destination alpha.
   al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

   // Add lights to the shadow bitmap.
   for (auto currentLight = mLightList.begin(); currentLight != mLightList.end(); currentLight++)
   {
      (*currentLight)->Draw(theGraphics);
   }

    // Switch target back to the display and draw the tinted shadow bitmap
   al_set_target_bitmap(al_get_backbuffer(theGraphics.GetDisplay()));
   al_draw_tinted_bitmap(mBitmap, al_map_rgba(255, 255, 255, mIntensity), mCoordinateX, mCoordinateY, 0);

   // Set blender back to the default.
   al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
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