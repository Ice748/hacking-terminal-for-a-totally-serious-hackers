#include "raylib.h"

#define MAX_INPUT_CHARS 20

int main(void) {
  char text[1024] = "Welcome to a hacking terminal for a totally serious hackers!\nA 100% serious hacking tool for elite cyber-criminals.\n\n> ";
  char input[MAX_INPUT_CHARS + 1] = "\0";
  int letterCount = 0;

  InitWindow(1280, 640, "hacking terminal for a totally serious hackers");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
            input[letterCount] = (char)key;
            input[letterCount + 1] = '\0';
            letterCount++;
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        letterCount--;
        if (letterCount < 0) letterCount = 0;
        input[letterCount] = '\0';
    }

    BeginDrawing();
      ClearBackground(BLACK);
      DrawText(TextFormat("%s%s", text, input), 0, 0, 16, GREEN);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
