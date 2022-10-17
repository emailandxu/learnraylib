#include "raylib.h"
#include "drawCube.h"

#ifndef ASSETS_PATH
    #define ASSETS_PATH "D:\\git-repo\\learnraylib\\assets\\"
#endif

constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;


int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "你好世界");
    SetTargetFPS(144);

    Image img = LoadImage(ASSETS_PATH"test.png");
    
    Camera3D camera;
    initCamera(camera);

    
    Model cube = LoadModelFromMesh(GenMeshCube(0.2f, 0.2f, 0.2f));
    
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        BeginDrawing();

        ClearBackground(BLACK);
        BeginMode3D(camera);
    
        drawGridCudes(25, 25, cube);
        
        EndMode3D();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
