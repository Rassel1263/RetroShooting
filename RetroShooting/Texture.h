#pragma once
class Texture 
{
public:
	LPDIRECT3DTEXTURE9 src;
	D3DXIMAGE_INFO info;
};

class TextureManager : public Singleton<TextureManager>
{
private:
	std::map<std::wstring, Texture*> texMap;

public:
	~TextureManager();
	const Texture* GetTexture(std::wstring filePath);
};

