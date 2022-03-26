#pragma once

#include "uiInteract.h" // for INTERFACE

class UserInput
{
public:
   UserInput(bool left = false, bool right = false, bool up = false, bool down = false, bool space = false);
   UserInput(const Interface* pUI);
   void set(bool left = false, bool right = false, bool up = false, bool down = false, bool space = false);
   void set(const Interface* pUI);
   bool isLeft();
   bool isRight();
   bool isUp();
   bool isDown();
   bool isSpace();

   bool isLeftPressed();
   bool isRightPressed();
   bool isUpPressed();
   bool isDownPressed();
   bool isSpacePressed();
#ifndef DEBUG
private:
#endif

   bool left;
   bool right;
   bool up;
   bool down;
   bool space;

   bool prevLeft;
   bool prevRight;
   bool prevUp;
   bool prevDown;
   bool prevSpace;
};
