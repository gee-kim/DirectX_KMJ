#pragma once

class UContentsConstValue
{
public : 
	static const float TileSize;
	static std::shared_ptr<UEngineTexture> MapTex;
	static float4 MapTexScale;

	static int MonsterCount;
	static int BulletCount;

	static bool IsAttackEnd;
	static bool IsSoundOn;
	
	static bool IsOpeningOff;
	static bool IsMagicGlassOn;
	static bool IsSignOn;
};

