#include "main.fx"

texture g_txSceneColor;

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
sampler2D g_samSceneColor = sampler_state
{
    Texture = <g_txSceneColor>;
    AddressU = Clamp;
    AddressV = Clamp;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};

float2 PixelCoordsDownFilter[16] =
{
    { 1.5,  -1.5 },
    { 1.5,  -0.5 },
    { 1.5,   0.5 },
    { 1.5,   1.5 },

    { 0.5,  -1.5 },
    { 0.5,  -0.5 },
    { 0.5,   0.5 },
    { 0.5,   1.5 },

    {-0.5,  -1.5 },
    {-0.5,  -0.5 },
    {-0.5,   0.5 },
    {-0.5,   1.5 },

    {-1.5,  -1.5 },
    {-1.5,  -0.5 },
    {-1.5,   0.5 },
    {-1.5,   1.5 },
};

float2 TexelCoordsDownFilter[16]
<
    string ConvertPixelsToTexels = "PixelCoordsDownFilter";
>;
//-----------------------------------------------------------------------------
float4 Combine( float2 Tex : TEXCOORD0,
                float2 Tex2 : TEXCOORD1 ) : COLOR0
{
    float3 ColorOrig = tex2D( g_samSceneColor, Tex2 );

    ColorOrig += tex2D( g_samSrcColor, Tex );

    return float4( ColorOrig, 1.0f );
}
//-----------------------------------------------------------------------------
technique PostProcess
{
    pass p0
    <
        float fScaleX = 4.0f;
        float fScaleY = 4.0f;
    >
    {
        VertexShader = null;
        PixelShader = compile ps_2_0 Combine();
        ZEnable = false;
    }
}
