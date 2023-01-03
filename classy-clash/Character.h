#include "raylib.h"

class Character
{
public:
    Character(
        int winWidth, 
        int winHeight
    );
    Vector2 getWorldPos() { return worldPos; }
    void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{}; 
    // 1 : facing right, -1 : facing left
    float rightLeft{1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float width{};
    float height{};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float scale{4.0f};
    Vector2 characterOrigin{};
};