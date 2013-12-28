#include "main.fx"

texture g_Texture0  : g_Texture0;
bool use0 : use0 = false;
texture g_Texture1  : g_Texture1;
bool use1 : use1 = false;
texture g_Texture2  : g_Texture2;
bool use2 : use2 = false;
texture g_Texture3  : g_Texture3;
bool use3 : use3 = false;
texture g_Texture4  : g_Texture4;
bool use4 : use4 = false;


sampler2D g_sam0 =
sampler_state
{
    Texture = <g_Texture0>;
    AddressU = Wrap;
    AddressV = Wrap;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};
sampler2D g_sam1 =
sampler_state
{
    Texture = <g_Texture1>;
    AddressU = Wrap;
    AddressV = Wrap;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};
sampler2D g_sam2 =
sampler_state
{
    Texture = <g_Texture2>;
    AddressU = Wrap;
    AddressV = Wrap;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};
sampler2D g_sam3 =
sampler_state
{
    Texture = <g_Texture3>;
    AddressU = Wrap;
    AddressV = Wrap;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};
sampler2D g_sam4 =
sampler_state
{
    Texture = <g_Texture4>;
    AddressU = Wrap;
    AddressV = Wrap;
    MinFilter = Point;
    MagFilter = Linear;
    MipFilter = Linear;
};
//-----------------------------------------------------------------------------
float4 Blend( float2 Tex : TEXCOORD0 ) : COLOR
{
	float4 color0 = float4(0,0,0,0);
  float4 color1 = float4(0,0,0,0);
	float4 color2 = float4(0,0,0,0);
	float4 color3 = float4(0,0,0,0);
	float4 color4 = float4(0,0,0,0);	
	if(use0)
		color0 = tex2D( g_sam0, Tex );
	if(use1)
		color1 = tex2D( g_sam1, Tex );
	if(use2)
		color2 = tex2D( g_sam2, Tex );
	if(use3)
		color3 = tex2D( g_sam3, Tex );
	if(use4)
		color4 = tex2D( g_sam4, Tex );

	return color0+color1+color2+color3+color4;
}
//--------------------------------------------------------------------------------------------------
technique PostEffect
{
	pass p0
	{
		VertexShader = null;
		PixelShader = compile ps_2_0 Blend();
		ZEnable = false;
	}
}
//--------------------------------------------------------------------------------------------------
