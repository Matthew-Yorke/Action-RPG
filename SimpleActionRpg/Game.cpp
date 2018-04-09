//***************************************************************************************************************************************************
//
// File Name: Game.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "stdio.h"
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Game.h"
#include "Graphics.h"
#include "PlayerCharacter.h" // TODO: Remove
#include "Light.h" // TODO: Remove
#include "ShadowLayer.h" // TODO: Remove

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: Game
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
Game::Game()
{
   // Initialize member variables.
   mpDisplay = nullptr;
   mpTimer = nullptr;
   mpEventQueue = nullptr;
   mIsGameDone = false;
}

//***************************************************************************************************************************************************
//
// Method Name: Initialize
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
bool Game::Initialize()
{
   // Initialize allegro and catch if a failure occurs.
   if (!al_init())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: al_init",
                                 "Failed to initialize allegro!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      return false;
   }

   // Initialize the allegro image add-on and catch if a failure occurs.
   if (!al_init_image_addon())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: al_init_image_addon",
                                 "Failed to initialize al_init_image_addon!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      return false;
   }

   // Initialize the allegro primitives add-on and catch if a failure occurs.
   if (!al_init_primitives_addon())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: al_init_primitives_addon",
                                 "Failed to initialize al_init_primitives_addon!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      return false;
   }

   // Initialize the allegro display and catch if a failure occurs.
   mpDisplay = al_create_display(mScreenWidth, mScreenHeight);
   if (!mpDisplay)
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: display",
                                 "Failed to initialize display!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      return false;
   }

   // Initialize the allegro audio and catch if a failure occurs.
   if (!al_install_audio())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: audio",
                                 "Failed to initialize the audio add-on!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(mpDisplay);
      return false;
   }

   // Initialize the allegro acodec and catch if a failure occurs.
   if (!al_init_acodec_addon())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: acodec",
                                 "Failed to initialize the acodec add-on!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(mpDisplay);
      return false;
   }

   // Reserve samples for the allegro audio mixer and catch if a failure occurs.
   if (!al_reserve_samples(5))
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: reserve samples",
                                 "Failed to reserve samples!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(mpDisplay);
      return false;
   }

   // Install the keyboard for allegro and catch if a failure occurs.
   if (!al_install_keyboard())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: install keyboard",
                                 "Failed to install the keyboard component!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(mpDisplay);
      return false;
   }

   //Install the font add-on for allegro
   al_init_font_addon();
   // Install the keyboard for allegro and catch if a failure occurs.
   if (!al_init_font_addon())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: initialize font add-on",
                                 "Failed to initialize the font add-on!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(mpDisplay);
      return false;
   }

   //Install the ttf(True Type Font) for allegro
   al_init_ttf_addon();
   // Install the keyboard for allegro and catch if a failure occurs.
   if (!al_init_ttf_addon())
   {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: initialize ttf add-on",
                                 "Failed to initialize the ttf add-on!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(mpDisplay);
      return false;
   }

   // Setup the event_queue and catch if a failure occurs.
   mpEventQueue = al_create_event_queue();
   if (!mpEventQueue) {
      al_show_native_message_box(mpDisplay,
                                 "Error",
                                 "Error: al_create_event_queue",
                                 "Failed to initialize al_create_event_queue!",
                                 NULL,
                                 ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(mpDisplay);
      al_destroy_timer(mpTimer);
      return false;
   }

   // Set FPS to 60.
   mpTimer = al_create_timer(1.0 / 60.0);

   // Register types of events the event_queue will handle.
   al_register_event_source(mpEventQueue, al_get_display_event_source(mpDisplay));
   al_register_event_source(mpEventQueue, al_get_keyboard_event_source());
   al_register_event_source(mpEventQueue, al_get_timer_event_source(mpTimer));

   // Start the timer event.
   al_start_timer(mpTimer);

   // No failures occurred during initialization.
   return true;
}

//***************************************************************************************************************************************************
//
// Method Name: GameLoop
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
void Game::GameLoop()
{
   // Tracks what the next event will be from the event queue.
   ALLEGRO_EVENT nextEvent;

   // Set up the graphics used in this game.
   Graphics graphics(mpDisplay);

   // TODO: Remove: Test Code - Start
   PlayerCharacter* pTestCharacter = new PlayerCharacter(graphics);
   PlayerCharacter* pTestCharacter2 = new PlayerCharacter(graphics);
   int count = 0;
   int time = 0;
   bool increase = true;
   // TODO: Remove: Test Code - End

   bool redraw = false;
   float lastUpdateTime = static_cast<float>(al_current_time());

   // Continuously loop until the game is exited.
   while (mIsGameDone == false)
   {
      //Obtain event actions before updating
      do
      {
         // Wait an obtain the next event in the event queue.
         al_wait_for_event(mpEventQueue, &nextEvent);

         // The event was the user clicking the exit button on the display.
         if (nextEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
         {
            // Indicate the game is being exited.
            mIsGameDone = true;
         }
         // The event was the user pressing a key down.
         else if (nextEvent.type == ALLEGRO_EVENT_KEY_DOWN)
         {
            pTestCharacter->KeyDown(nextEvent);
         }
         // The event was the user releasing a downed key.
         else if (nextEvent.type == ALLEGRO_EVENT_KEY_UP)
         {
            pTestCharacter->KeyUp(nextEvent);
         }
         // The event was a timer event.
         else if (nextEvent.type == ALLEGRO_EVENT_TIMER)
         {
            // The timer event was from the FPS timer.
            // Note: This will occur ever 1/60th a second.
            if (nextEvent.timer.source == mpTimer)
            {
               const float currentTime = static_cast<float>(al_current_time());

               // Call to update - Start
               pTestCharacter->Update(currentTime - lastUpdateTime);
               // Call to update - End

               lastUpdateTime = currentTime;
               redraw = true;
            }
         }
      } while (!al_is_event_queue_empty(mpEventQueue));

      // Redraw 
      if (redraw == true)
      {
         redraw = false;

         // Call to draw - Start
         ALLEGRO_BITMAP* grassTile = al_load_bitmap("../Images/TestGrassTile.png"); // Temporary background.
         al_draw_bitmap(grassTile, 0, 0, 0); // Temporary background.
         al_draw_bitmap(grassTile, 100, 0, 0); // Temporary background.
         al_draw_bitmap(grassTile, 0, 99, 0); // Temporary background.
         al_draw_bitmap(grassTile, 100, 99, 0); // Temporary background.
         pTestCharacter->Draw(graphics);

         // Lighting Test - Start
         ShadowLayer* shadowLayer = new ShadowLayer("../Images/ShadowLayer.png"); 
         Light* testLight = new Light(50, 50, 100, al_map_rgb(255, 255, 255), 5);
         Light* testLight2 = new Light(150, 150, 100, al_map_rgb(255, 0, 0), 3);
         shadowLayer->AddLight(*testLight);
         shadowLayer->AddLight(*testLight2);

         if (increase)
         {
            time++;
            if (time == 5) {
               count++;
               time = 0;
            }

            if (count == 240)
               increase = false;
         }
         else
         {
            time++;
            if (time == 5) {
               count--;
               time = 0;
            }

            if (count == 0)
               increase = true;
         }

         shadowLayer->SetIntensity(count);
         shadowLayer->Draw(graphics);

         delete shadowLayer;
         delete testLight;
         delete testLight2;
         al_destroy_bitmap(grassTile);
         // Lighting Test - End
         // Call to draw - End

         // Flip the two screens (drawing unseen screen with the display screen) and clear the new drawing screen.
         al_flip_display();
         al_clear_to_color(al_map_rgb(0,
                                      0,
                                      0));
      }
   }
}

//***************************************************************************************************************************************************
//
// Method Name: Terminate
//
// Description:
//  TODO: Add method description.
//
//***************************************************************************************************************************************************
void Game::Terminate()
{
   al_destroy_display(mpDisplay);
   al_destroy_timer(mpTimer);
   al_destroy_event_queue(mpEventQueue);
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