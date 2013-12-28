#include "main.fx"

sampler2D g_samScene =
sampler_state
{
    Texture = <g_MeshTexture>;
    AddressU = Wrap;
    AddressV = Wrap;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};
//-----------------------------------------------------------------------------
float4 PixNoLight( float2 Tex : TEXCOORD0 ) : COLOR
{
  return tex2D( g_samScene, Tex );
}
//--------------------------------------------------------------------------------------------------
technique RenderNoLight
{
    pass p0
    {
        VertexShader = null;
        PixelShader = compile ps_2_0 PixNoLight();
        ZEnable = false;
    }
}
//--------------------------------------------------------------------------------------------------