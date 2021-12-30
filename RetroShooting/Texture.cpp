#include "DXUT.h"
#include "Texture.h"

TextureManager::~TextureManager()
{
    for (auto tex : texMap)
    {
        tex.second->src->Release();
        delete tex.second;
    }
}

const Texture* TextureManager::GetTexture(std::wstring filePath)
{
    auto tf = texMap.find(filePath);

    if (tf != texMap.end())
        return tf->second;

    Texture* pTex = new Texture();

    if (FAILED(D3DXCreateTextureFromFileExW(DXUTGetD3D9Device(),
        filePath.c_str(),
        D3DX_DEFAULT_NONPOW2,
        D3DX_DEFAULT_NONPOW2,
        0,
        0,
        D3DFMT_A8R8G8B8,
        D3DPOOL_MANAGED,
        D3DX_DEFAULT,
        D3DX_DEFAULT,
        0,
        &pTex->info,
        0,
        &pTex->src)))
    {
        delete pTex;
        return nullptr;
    }

    return texMap.insert(std::make_pair(filePath, pTex)).first->second;
}
