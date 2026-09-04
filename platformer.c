//date 4 september 2026
//by human23


#include <stdio.h>
#include <math.h>
#include "raylib.h"

float beanPY = 0;
float beanPX = 0;

float velocityY = 0;
float velocityX = 0;
float gravity = 0;
float jump = 0;
float left = 0;
float right = 0;
float acceleration = 0.9;

int main()
{
    InitWindow(800, 450, "yes");
    {
        while (!WindowShouldClose())
        {   
            
            //velocity loop
            velocityY = velocityY + gravity + jump;
            velocityX = acceleration * velocityX + left + right;

            // position is dependent on the speed its falling at
            beanPY = beanPY + velocityY;
            beanPX = beanPX + velocityX;
            
            // LEFT AND RIGHT
            if (IsKeyDown(KEY_A))
            {
                    left = -1;
            }
            else{left=0;}

            if (IsKeyDown(KEY_D))
            {
                    right = 1;
            }
            else{right=0;}



            // IF TOuchING GROUND
            if (beanPY > GetScreenHeight() -100)
            {
                gravity = 0; 
                velocityY = 0;
                
                // JUMPInG WHEn TOUCHING GROUND
                if (IsKeyPressed(KEY_W))
                {
                    jump = -15;
                }

                //GET OUT OF THe groUND
                beanPY -= 0.01;
            }
            else 
            { //we are not toucing the ground pleaase keep moving
                gravity = 0.8;
                jump = 0;
            }

            
            SetTargetFPS(60); 
            BeginDrawing();   
                ClearBackground(RAYWHITE);
                DrawRectangle(beanPX, beanPY, 100, 100, RED); 
                DrawText("Flappy beans", 160, 200, 20, LIGHTGRAY);
            EndDrawing();
        }
    }
 
}
