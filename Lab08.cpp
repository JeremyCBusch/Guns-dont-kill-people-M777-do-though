/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include <list>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "howitzer.h"
#include "projectile.h"
#include "simulator.h"

using namespace std;

const int SCREEN_HEIGHT = 800;
const int SCREEN_WIDTH = 1000;
const float FPS = 1.0 / 1.0;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      time(0.0),
      angle(0.0),
      input(new UserInput()),
      howitzer(input, &projectiles, Position(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0, false)),
      ground(ptUpperRight)
   {
      ground.reset(howitzer.getPosition());
   }
   ~Demo()
   {
      delete input;
   }

   Ground ground;                 // the ground
   UserInput * input;
   Position  ptUpperRight;        // size of the screen
   Howitzer howitzer;
   list<Projectile> projectiles;
   double angle;                  // angle of the howitzer 
   double time;                   // amount of time since the last firing
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   //Demo* pDemo = (Demo*)p;
   Simulator* sim = (Simulator*)p;

   //
   // accept input
   //

   pDemo->input->set(pUI);

   pDemo->time += 0.5;

   pDemo->howitzer.update();

   list<list<Projectile>::iterator> finished;
   // move the projectile across the screen
   for (list<Projectile>::iterator proj = pDemo->projectiles.begin(); proj != pDemo->projectiles.end(); ++proj)
   {
      (*proj).update();
      if (pDemo->ground.getElevationMeters((*proj).getPosition()) >= (*proj).getPosition().getMetersY())
      {
         finished.push_back(proj);
      }
   }
   for (auto & curr : finished)
   {
      pDemo->projectiles.erase(curr);
   }

   //
   // draw everything
   //
   sim->update();
   sim->draw();

   // draw the ground first
   pDemo->ground.draw(gout);

   // draw the howitzer
   pDemo->howitzer.draw(gout, pDemo->time);

   // draw the projectile

   for (Projectile& proj : pDemo->projectiles)
   {
      proj.draw(gout);
   }

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pDemo->time << "s\n";
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(SCREEN_WIDTH);
   ptUpperRight.setPixelsY(SCREEN_HEIGHT);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "M777 Howitzer Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator sim(ptUpperRight, FPS);

   // set everything into action
   ui.run(callBack, &sim);


   return 0;
}
