#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
    public:
        Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
        void setTarget(Character* hero);
        virtual void tick(float deltaTime) override;
        
    private:
        Character* target;
        
};