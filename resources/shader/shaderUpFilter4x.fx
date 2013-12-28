#include "main.fx"

sampler2D g_samSrcColor =
sampler_state
{
    Texture = <g_MeshTexture>;
    AddressU = Clamp;
    AddressV = Clamp;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};
//-----------------------------------------------------------------------------
float4 UpFilterPS( float2 Tex : TEXCOORD0 ) : COLOR0
{
    return tex2D( g_samSrcColor, Tex );
}
technique PostProcess
{
    pass p0
    <
        float fScaleX = 4.0f;
        float fScaleY = 4.0f;
    >
    {
        VertexShader = null;
        PixelShader = compile ps_2_0 UpFilterPS();
        ZEnable = false;
    }
}
