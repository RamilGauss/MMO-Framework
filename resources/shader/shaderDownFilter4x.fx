#include "main.fx"

//texture g_txSrcColor;

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
float4 DownFilter( in float2 Tex : TEXCOORD0 ) : COLOR0
{
  float4 Color = 0;
  for (int i = 0; i < 16; i++)
  {
    Color += tex2D( g_samSrcColor, Tex + TexelCoordsDownFilter[i].xy );
  }
  return Color / 16;
}
//-----------------------------------------------------------------------------
technique PostProcess
{
    pass p0
    <
        float fScaleX = 0.25f;
        float fScaleY = 0.25f;
    >
    {
        VertexShader = null;
        PixelShader = compile ps_2_0 DownFilter();
        ZEnable = false;
    }
}
