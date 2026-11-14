#include "raylib.h"
#include <string.h>
#include <stdio.h>

#define MAX_INPUT_CHARS 32
#define AMOGUS "     #####\n"\
"###        ####\n"\
"#  #             #\n"\
"#  #        ####\n"\
"#  #        #\n"\
"#  #        # when the\n"\
"###        # imposter sus\n"\
"    ######\n"\
"    ###  ##\n"\
"    ###  ##\n"

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

    if (IsKeyPressed(KEY_ENTER)) {
      if (strcmp(input, "amogus") == 0) {
        sprintf(text, "> %s\n%s\n> ", input, AMOGUS);
      } else if (strcmp(input, "exit") == 0) {
        break;
      } else if (input[0] == '\0') {
        strcpy(text, "> ");
      } else {
        sprintf(text, "> %s\num.. idk what does '%s' means bruh.\n> ", input, input);
      }

      while (letterCount > 0) {
        letterCount--;
        input[letterCount] = '\0';
      }
    }

    BeginDrawing();
      ClearBackground(BLACK);
      DrawText(TextFormat("%s%s", text, input), 0, 0, 24, GREEN);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
