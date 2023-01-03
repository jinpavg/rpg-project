#include "Character.h"
#include "raymath.h"
#include "stdio.h"

Character::Character(int winWidth, int winHeight)
{
    width = texture.width/maxFrames;
    height = texture.height;
    screenPos = {
        static_cast<float>(winWidth) / 2.0f - (scale * (0.5f * width)),
        static_cast<float>(winHeight) / 2.0f - (scale * (0.5f * height))};
}

void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0f;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0f;
    if (Vector2Length(direction) != 0.0f)
    {
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    // update animation frame

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    Rectangle source{
        frame * width,
        0.0f,
        rightLeft * width,
        height};

    Rectangle dest{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale};

    DrawTexturePro(texture, source, dest, characterOrigin, 0.0f, WHITE);
}

void Character::undoMovement()
{
    //printf("hi");
    worldPos = worldPosLastFrame;
}

Rectangle Character::getCollisionRec()
{
    return Rectangle {
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale,
    };
}