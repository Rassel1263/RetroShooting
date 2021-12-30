#include "DXUT.h"
#include "Sprite.h"

Sprite::~Sprite()
{
    if (drawRect)
        SAFE_DELETE(drawRect);
}

void Sprite::LoadAll(std::wstring filePath)
{
    textures.clear();

    if (std::filesystem::is_directory(filePath))
    {
        for (auto file : std::filesystem::recursive_directory_iterator(filePath))
        {
            if (auto texture = TextureManager::GetInstance().GetTexture(file.path()))
                textures.push_back(texture);
        }
    }
    else
    {
        if (auto texture = TextureManager::GetInstance().GetTexture(filePath))
            textures.push_back(texture);
    }

    szScene = textures.size();
}

void Sprite::Update(float deltaTime)
{
    if (!bAnimation)
        return;

    aniTime += deltaTime;

    if (aniTime >= aniMaxTime)
    {
        aniTime = 0.0f;

        if (scene < szScene - 1)
            scene++;
        else if (aniLoop)
            scene = 0;
        else
            bAnimation = false;
    }
}

void Sprite::Render(const SpriteRI& ri)
{
    D3DXVECTOR2 centerPos = D3DXVECTOR2(GetNowScene()->info.Width * ri.center.x, GetNowScene()->info.Height * ri.center.y);
    D3DXMatrixTransformation2D(&matrix, &centerPos, 0.0f, &ri.scale, &centerPos, -D3DXToRadian(ri.rotate), &(ri.pos - centerPos));

    Game::GetInstance().pSprite->SetTransform((isCamera) ? &(matrix * Game::GetInstance().matWorld) : &matrix);
    Game::GetInstance().pSprite->Draw(GetNowScene()->src, drawRect, NULL, NULL, color);
}

void Sprite::Reset()
{
    scene = 0;
    aniTime = 0.0f;
    bAnimation = true;
}

const Texture* Sprite::GetNowScene()
{
    return textures[scene];
}
