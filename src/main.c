#include "raylib.h"

int main(void) {
  InitWindow(1280, 640, "hacking terminal for a totally serious hackers");
  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawText("Welcome to hacking terminal for a totally serious hackers!", 1280/2 - TextMeasure("Welcome to hacking terminal for a totally serious hackers!", 16)/2, 640/2 - 8, 16, GREEN);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
