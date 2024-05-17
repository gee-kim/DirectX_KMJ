#include "PreCompile.h"
#include "ContentsConstValue.h"

const float UContentsConstValue::TileSize = 2.0f;
std::shared_ptr<UEngineTexture> UContentsConstValue::MapTex;
float4 UContentsConstValue::MapTexScale;

int UContentsConstValue::MonsterCount = 0;
int UContentsConstValue::BulletCount = 0;

bool UContentsConstValue::IsAttackEnd = false;
bool UContentsConstValue::IsSoundOn = false;

bool UContentsConstValue::IsOpeningOff = false;

bool UContentsConstValue::IsMagicGlassOn = false;

bool UContentsConstValue::IsSignOn = false;