//***************************************************************************************************************************************************
//
// File Name: DialogBox.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     MM/DD/2018     TODO: Add history update
//
//***************************************************************************************************************************************************

#include "DialogBox.h"

//***************************************************************************************************************************************************
// Start Public Method Definitions
//***************************************************************************************************************************************************

//***************************************************************************************************************************************************
//
// Method Name: DialogBox
//
// Description:
//  Set the parameters of the dialog box with the passed in values. Also sets other text to default values. Determine the number characters and
//  number of lines that will fit in the dialog box.
//
//***************************************************************************************************************************************************
DialogBox::DialogBox(std::string theSpeakerName, std::string theSpeakerText, RectangleObject* pTheDimensions)
{
   mSpeakerName = theSpeakerName;
   mSpeakerText = theSpeakerText;
   mpDimensions = pTheDimensions;
   mCoordianteX = mpDimensions->GetCoordinateX();
   mCoordianteY = mpDimensions->GetCoordinateY();
   mpOverlayImage = nullptr;
   mpCharacterImage = nullptr;
   mpFont = al_load_ttf_font("../Fonts/VT323-Regular.ttf",
                             24,
                             0);
   mFontColor = al_map_rgb(255,
                           255,
                           255);

   DetermineNumberCharactersInLine();
   DetermineNumberLinesToFit();
}

//***************************************************************************************************************************************************
//
// Method Name: AddOverlay
//
// Description:
//  Changes the overlay image pointer.
//
//***************************************************************************************************************************************************
void DialogBox::AddOverlay(DialogImage* pTheOverlayImage)
{
   mpOverlayImage = pTheOverlayImage;
}

//***************************************************************************************************************************************************
//
// Method Name: AddCharacterImage
//
// Description:
//  Changes the character image pointer. Redetermine the number of characters in a line as the text area is now different.
//
//***************************************************************************************************************************************************
void DialogBox::AddCharacterImage(DialogImage* pTheCharacterImage)
{
   mpCharacterImage = pTheCharacterImage;
   DetermineNumberCharactersInLine();
}

//***************************************************************************************************************************************************
//
// Method Name: CameraUpdate
//
// Description:
//  Update the dialog pieces coordinates relative to the camera coordinates.
//
//***************************************************************************************************************************************************
void DialogBox::CameraUpdate(Camera* pTheCamera)
{
   // Update the entire dialog coordinates based on the dialog screen coordinates and camera coordinates.
   mCoordianteX = mpDimensions->GetCoordinateX() + pTheCamera->GetCoordinateX();
   mCoordianteY = mpDimensions->GetCoordinateY() + pTheCamera->GetCoordinateY();
   
   // Update the overlay image coordinates based on the update dialog coordinates.
   if (mpOverlayImage != nullptr)
   {
      mpOverlayImage->SetCoordinateX(mCoordianteX);
      mpOverlayImage->SetCoordinateY(mCoordianteY);
   }

   // Update the character image coordinates based on the updated dialog coordinates.
   if (mpCharacterImage != nullptr)
   {
      mpCharacterImage->SetCoordinateX(mCoordianteX);
      mpCharacterImage->SetCoordinateY(mCoordianteY);
   }
}

//***************************************************************************************************************************************************
//
// Method Name: NextLineSet
//
// Description:
//  Remove the number of lines equal to the number of lines that can visible to the dialog area from the lines vector. If there are no lines then
//  indicate the dialog is complete.
//
//***************************************************************************************************************************************************
bool DialogBox::NextLineSet()
{
   bool dialogComplete = false;

   // Delete the number of text lines for the display box.
   for (int count = 0; count < mNumberOfTextLinesVisible; count++)
   {
      if (mTextLine.begin() != mTextLine.end())
      {
         mTextLine.erase(mTextLine.begin());
      }
   }

   // If there are not more lines of text, then the dialog is complete.
   if (mTextLine.empty() == true)
   {
      dialogComplete = true;
   }

   return dialogComplete;
}

//***************************************************************************************************************************************************
//
// Method Name: Draw
//
// Description:
//  Update the line vector with the text on the first pass. Draw the overlay and character images in order if they exist. Draw the speaker name text.
//  Draw the lines in the line vector equal to the number of lines able to fit in the dialog area within the dialog area.
//
//***************************************************************************************************************************************************
void DialogBox::Draw(Graphics& theGraphics)
{
   // On the first draw of a text parse the entire text into separate lines.
   if (mSpeakerText != "")
   {
      BreakUpTextIntoLines();
   }

   // Draw the Overlay for the dialog box.
   if (mpOverlayImage != nullptr)
   {
      mpOverlayImage->Draw(theGraphics);
   }

   // Draw the character image for the dialog box.
   if (mpCharacterImage != nullptr)
   {
      mpCharacterImage->Draw(theGraphics);
   }

   int padding = 10; // turn into constant later.
   int fontHeight = 24; // turn into constant later.
   int characterImageWidth = 0;
   if (mpCharacterImage != nullptr)
   {
      characterImageWidth = mpCharacterImage->GetImageWidth();
   }

   // Draw the speaker name into the dialog box.
   al_draw_text(mpFont,
                mFontColor,
                mCoordianteX + characterImageWidth + padding,
                mCoordianteY + padding, ALLEGRO_ALIGN_LEFT,
                mSpeakerName.c_str());

   // Draw the speaker text (up to the number of lines that fit) into the dialog.
   int count = 1;
   for (auto iterator = mTextLine.begin();
        iterator != mTextLine.end();
        iterator++)
   {
      // Draw the line text to the next line below.
      al_draw_text(mpFont,
                   mFontColor,
                   mCoordianteX + padding + characterImageWidth,
                   mCoordianteY + padding + (fontHeight * count),
                   ALLEGRO_ALIGN_LEFT,
                   (*iterator).c_str());

      // Check if another line won't fit and break if so.
      count++;
      if (count > mNumberOfTextLinesVisible)
      {
         break;
      }
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
// Method Name: DetermineNumberCharactersinLine
//
// Description:
//  Determine the number of characters that can fit in the line by calculating the width of the dialog area of the box and dividing by the width of a
//  character of the current font.
//
//***************************************************************************************************************************************************
void DialogBox::DetermineNumberCharactersInLine()
{
   // Get the width of a single character.
   int characterWidth = al_get_text_width(mpFont, "B");
   int padding = 10; // Turn to constant later.

   // Get the width of the character image
   int characterImageWidth  = 0;
   if (mpCharacterImage != nullptr)
   {
      characterImageWidth = mpCharacterImage->GetImageWidth();
   }

   // text Area Width is determined by the dialog box width - character image width - padding on the left and right.
   int textAreaWidth = mpDimensions->GetWidth() - characterImageWidth - (padding * 2);

   // Determine number of character to fit int the text area by dividing the text area width by the character width.
   mNumberCharactersInLine = textAreaWidth / characterWidth;
}

//***************************************************************************************************************************************************
//
// Method Name: DetermineNumberLinesToFit
//
// Description:
//  Determine the number of lines that can fit in the dialog area by calculating the height of the dialog area of the box and dividing by the height
//  of a character of the current font.
//
//***************************************************************************************************************************************************
void DialogBox::DetermineNumberLinesToFit()
{
   int fontHeight = 24; // Turn to constant later.
   int padding = 10; // Turn to constant later.

   // Text Area Height is determined by the dialog box height - font height for where the speaker name is placed - padding on top and bottom.
   int textAreaHeight = mpDimensions->GetHeight() - fontHeight - (padding * 2);

   // Determine number of character to fit int the text area by dividing the text area width by the character width.
   mNumberOfTextLinesVisible = textAreaHeight / fontHeight;
}

//***************************************************************************************************************************************************
//
// Method Name: BreakUpTextIntoLines
//
// Description:
//  Reduce the text string into individual lines that will fit within the dialog area by creating lines equal to or less than the width of the dialog
//  area. Store all the lines into a line vector.
//
//***************************************************************************************************************************************************
void DialogBox::BreakUpTextIntoLines()
{
   // Start the number of characters remaining as the maximum characters in a line.
   int theCharactersRemainingForLine = mNumberCharactersInLine;
   std::string delimiter = " "; // Turn into constant later.
   // the vector of individual words from the text.
   std::vector<std::string> parsedTextToSingleWord;
   // The text for the current line.
   std::string lineText = "";

   // Parse the entire speaker text into separate individual words.
   size_t pos = 0;
   // Find the next word by finding the next instance of the delimiter.
   while ((pos = mSpeakerText.find(delimiter)) != std::string::npos)
   {
      // Add the word to the end of the parsed individual word vector.
      parsedTextToSingleWord.push_back(mSpeakerText.substr(0, pos));
      // Remove the word from the overall text.
      mSpeakerText.erase(0, pos + delimiter.length());
   }
   // Add the last word to the parsed individual word vector.
   parsedTextToSingleWord.push_back(mSpeakerText);
   mSpeakerText = "";

   // Create lines to the maximum character length by appending each word that fits in the length to the string.
   for (auto iterator = parsedTextToSingleWord.begin();
        iterator != parsedTextToSingleWord.end();
        iterator++)
   {
      // Check if the next word will be too big for this line.
      if ((theCharactersRemainingForLine - static_cast<int>((*iterator).length())) < 0)
      {
         // Add the line to the vector of lines.
         mTextLine.push_back(lineText);
         // Reset the lineText for the next line.
         lineText = "";
         // Reset the character count for the new line.
         theCharactersRemainingForLine = mNumberCharactersInLine;
      }

      // Decrement the line character count by the number of characters in the word plus one for a space.
      theCharactersRemainingForLine -= (static_cast<int>((*iterator).length()) + 1);
      // Append the word the line text.
      lineText.append((*iterator));
      // Append a space to go between the words.
      lineText.append(" ");
   }

   // Add the final line if there is words in the line text.
   if (lineText != " ")
   {
      mTextLine.push_back(lineText);
   }
}

//***************************************************************************************************************************************************
// End Private Method Definitions
//***************************************************************************************************************************************************