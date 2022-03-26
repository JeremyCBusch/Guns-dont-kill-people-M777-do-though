#include "userInput.h"

UserInput::UserInput(bool left, bool right, bool up, bool down, bool space) :
   left(left), right(right), up(up), down(down), space(space) {}

void UserInput::set(const Interface* pUI)
{
   this->prevLeft = left;
   this->prevRight = right;
   this->prevUp = up;
   this->prevDown = down;
   this->prevSpace = space;

   this->left = pUI->isLeft();
   this->right = pUI->isRight();
   this->up = pUI->isUp();
   this->down = pUI->isDown();
   this->space = pUI->isSpace();
}

bool UserInput::isLeft()
{
   return left;
}

bool UserInput::isRight()
{
   return right;
}

bool UserInput::isUp()
{
   return up;
}

bool UserInput::isDown()
{
   return down;
}

bool UserInput::isSpace()
{
   return space;
}

bool UserInput::isSpacePressed()
{
   return !prevSpace && space;
}