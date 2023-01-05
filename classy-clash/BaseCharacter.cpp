#include "BaseCharacter.h"

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

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle {
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale,
    };
}