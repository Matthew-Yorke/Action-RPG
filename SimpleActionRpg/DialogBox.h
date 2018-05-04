//***************************************************************************************************************************************************
//
// File Name: DialogBox.h
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/YYYY     TODO: Add Description.
//
//***************************************************************************************************************************************************

#ifndef DialogBox_H
#define DialogBox_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include "Sprite.h"
#include "DialogImage.h"
#include "RectangleObject.h"
#include "Camera.h"

class DialogBox
{
   //************************************************************************************************************************************************
   // Start Method Declarations
   //************************************************************************************************************************************************

   public:

      //*********************************************************************************************************************************************
      //
      // Method Name: DialogBox
      //
      // Description:
      //  Constructor that creates the dialog box based on passed in parameters. Also sets other member variables to default values.
      //
      // Arguments:
      //  theSpeakerName - The string describing who is speaking in the dialog box.
      //  theSpeakerText - The string of the entire dialog the speaker speaks in the dialog box.
      //  theDimensions - The dimensions of the dialog box including the X-Coordinates, Y-Coordinates, width and height.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      DialogBox(std::string theSpeakerName, std::string theSpeakerText, RectangleObject* theDimensions);

      //*********************************************************************************************************************************************
      //
      // Method Name: AddOverlay
      //
      // Description:
      //  Changes the overlay image pointer.
      //
      // Arguments:
      //  theOverlayImage - Pointer to the dialog image for the overlay including the image and dimensions.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void AddOverlay(DialogImage* theOverlayImage);

      //*********************************************************************************************************************************************
      //
      // Method Name: AddCharacterImage
      //
      // Description:
      //  Changes the character image pointer.
      //
      // Arguments:
      //  theCharacterImage - Pointer to the dialog image for the overlay including the image and dimensions.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void AddCharacterImage(DialogImage* theCharacterImage);

      //*********************************************************************************************************************************************
      //
      // Method Name: CameraUpdate
      //
      // Description:
      //  Update the message box screen location based upon the camera location.
      //
      // Arguments:
      //  theCamera - Pointer to the camera object used to update the X and Y coordinates relative to the camera.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void CameraUpdate(Camera* theCamera);

      //*********************************************************************************************************************************************
      //
      // Method Name: NextLineSet
      //
      // Description:
      //  Remove the number of lines that are currently to be displayed so the next set of lines can be displayed on a draw.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  Return if dialog is to be still displayed (true) or not (false).
      //
      //*********************************************************************************************************************************************
      bool NextLineSet();

      //*********************************************************************************************************************************************
      //
      // Method Name: Draw
      //
      // Description:
      //  Draw the dialog box including the overlay, character image, and dialog text.
      //
      // Arguments:
      //  theGraphics - Reference to the graphics object for drawing to the screen.
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void Draw(Graphics& theGraphics);

   protected:

   // There are currently no protected methods for this class.

   private:

      //*********************************************************************************************************************************************
      //
      // Method Name: DetermineNumberCharactersInLine
      //
      // Description:
      //  Determines how many characters can fit in a line within the dialog area of the dialog box.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void DetermineNumberCharactersInLine();

      //*********************************************************************************************************************************************
      //
      // Method Name: DetermineNumberLinesToFit
      //
      // Description:
      //  Determines how many lines that can fit in the dialog area of the dialog box.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void DetermineNumberLinesToFit();

      //*********************************************************************************************************************************************
      //
      // Method Name: BreakUpTextIntoLines
      //
      // Description:
      //  Reduces the entire dialog text into individual lines that will fit within the dialog area of the box.
      //
      // Arguments:
      //  N/A
      //
      // Return:
      //  N/A
      //
      //*********************************************************************************************************************************************
      void BreakUpTextIntoLines();

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

      // The string indicating who the speak is of the dialog.
      std::string mSpeakerName;

      // The string of all the text the speaker is saying.
      std::string mSpeakerText;

      // The dimensions of the dialog box. The X and Y Coordinates are where on the visible screen to start the dialog box.
      RectangleObject* mpDimensions;

      // The X-Coordinate to display the dialog box relative to the camera position.
      int mCoordianteX;

      // The Y-Coordinate to display the dialog box relative to the camera position.
      int mCoordianteY;

      // The overlay to be used for the dialog box.
      DialogImage* mpOverlayImage;

      // The dialog image for the character portrait.
      DialogImage* mpCharacterImage;

      // The font (including type and size) used for the dialog text.
      ALLEGRO_FONT* mpFont;

      // The color of the font to be displayed.
      ALLEGRO_COLOR mFontColor;

      // Determines how many lines of text can be visible in the text box at a time.
      int mNumberOfTextLinesVisible;

      // Determines how many characters can fit in a line of text for the dialog box.
      int mNumberCharactersInLine;

      // Vector holding each line of text to be displayed in the text box.
      std::vector<std::string> mTextLine;

   //************************************************************************************************************************************************
   // End Member Variable Declarations
   //************************************************************************************************************************************************
};

#endif