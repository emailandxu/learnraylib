#include "raylib.h"
#include "raymath.h"

void initCamera(Camera3D& camera){
    camera.position = { 10.f, 3.f, 10.f }; // position
    camera.target = { 0.0f, 0.5f, 0.0f }; // target
    camera.up = { 0.0f, 1.0f, 0.0f }; // up vector
    camera.fovy = 60.0f; // fovy
    camera.type = CAMERA_PERSPECTIVE; // type
}


void drawGridCudes(int row, int column, Model& cube){

    static float cube_rx = 0.;
    static float cube_ry = 0.;

    const float cube_rstep = 0.02f;
    
    cube.transform = MatrixRotateXYZ({
            cube_rx,
            cube_ry += cube_rstep,
            0.
        });

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            DrawModelWires(cube, { i * 0.5f, 6.f - 0.1f *(i + j), j * 0.5f }, 1., RED);
        }
    }
}
