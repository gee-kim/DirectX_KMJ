#include "PreCompile.h"
#include "ContentsConstValue.h"

const float UContentsConstValue::TileSize = 2.0f;
std::shared_ptr<UEngineTexture> UContentsConstValue::MapTex;
float4 UContentsConstValue::MapTexScale;

int UContentsConstValue::Count = 0;
bool UContentsConstValue::IsMagicGlassOn = false;