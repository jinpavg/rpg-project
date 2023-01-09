#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    
    // update animation frame

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    if (Vector2Length(velocity) != 0.0f)
    {
        // set worldPos = worldPos + velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    Rectangle source{
        frame * width,
        0.0f,
        rightLeft * width,
        height};

    Rectangle dest{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale};
    
    

    DrawTexturePro(texture, source, dest, characterOrigin, 0.0f, WHITE);
}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle {
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale,
    };
}