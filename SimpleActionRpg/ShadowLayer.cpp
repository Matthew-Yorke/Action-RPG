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
   
   // Set the blender to additive of the source alpha and inverse destination alpha.
   al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

   // Add lights to the shadow bitmap.
   for (auto currentLight = mLightList.begin(); currentLight != mLightList.end(); currentLight++)
   {
      currentLight->Draw(theGraphics);
   }

    // Switch target back to the display and draw the tinted shadow bitmap
   al_set_target_bitmap(al_get_backbuffer(theGraphics.GetDisplay()));
   al_draw_tinted_bitmap(mBitmap, al_map_rgba(255, 255, 255, mIntensity), 0, 0, 0);

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