#include "main.fx"

float4x4 texTrans : WorldProjection;
// pSize is the pixel size of the texture,
// equivalent to the inverse of the texture width.
float pSize = 1.0f;

struct GLOW_INPUT
{
	float4 pos : POSITION;         
	float2 texCoord : TEXCOORD;
};
//VS output / PS input:
struct GLOW_OUTPUT
{
    float4 pos : POSITION;		   
    float2 texCoord0 : TEXCOORD0;
    float2 texCoord1 : TEXCOORD1;
    float2 texCoord2 : TEXCOORD2;
    float2 texCoord3 : TEXCOORD3;
};
struct TEXTURE_OUTPUT
{
    float4 pos : POSITION;       
    float2 texCoord0 : TEXCOORD0;
};
//PS output:
struct pixel
{
	float4 color : COLOR;
};
//////////////////////////
//  Vertex Shaders:
//////////////////////////
GLOW_OUTPUT glowVSHorizontal1(GLOW_INPUT IN)
{
	GLOW_OUTPUT OUT;
	
	OUT.pos =  IN.pos;//###mul(IN.pos, texTrans);
	OUT.texCoord0 = IN.texCoord + float2(-pSize*3, 0); 
	OUT.texCoord1 = IN.texCoord + float2(-pSize*2, 0); 
	OUT.texCoord2 = IN.texCoord + float2(-pSize*1, 0); 
	OUT.texCoord3 = IN.texCoord + float2(0, 0 ); 
	
	return OUT;
}
GLOW_OUTPUT glowVSHorizontal2(GLOW_INPUT IN)
{
	GLOW_OUTPUT OUT;
	
	OUT.pos =  IN.pos;//###mul(IN.pos, texTrans);
	OUT.texCoord0 = IN.texCoord + float2(pSize*3,0); 
	OUT.texCoord1 = IN.texCoord + float2(pSize*2, 0); 
	OUT.texCoord2 = IN.texCoord + float2(pSize*1, 0); 
	OUT.texCoord3 = IN.texCoord + float2(0, 0 ); 
	
	return OUT;
}
GLOW_OUTPUT glowVSVertical1(GLOW_INPUT IN)
{
	GLOW_OUTPUT OUT;
	
	OUT.pos =  IN.pos;//###mul(IN.pos, texTrans);
	OUT.texCoord0 = IN.texCoord + float2(0,-pSize*3); 
	OUT.texCoord1 = IN.texCoord + float2(0,-pSize*2); 
	OUT.texCoord2 = IN.texCoord + float2(0,-pSize*1); 
	OUT.texCoord3 = IN.texCoord + float2(0,0); 
	
	return OUT;
}
GLOW_OUTPUT glowVSVertical2(GLOW_INPUT IN)
{
	GLOW_OUTPUT OUT;
	
	OUT.pos =  IN.pos;//###mul(IN.pos, texTrans);
	OUT.texCoord0 = IN.texCoord + float2(0,pSize*3); 
	OUT.texCoord1 = IN.texCoord + float2(0,pSize*2);  
	OUT.texCoord2 = IN.texCoord + float2(0,pSize*1); 
	OUT.texCoord3 = IN.texCoord + float2(0,0);  
	
	return OUT;
}
TEXTURE_OUTPUT outputGlowVS(GLOW_INPUT IN)
{
	TEXTURE_OUTPUT OUT;
	OUT.pos =  IN.pos;//###mul(IN.pos, texTrans);	
	OUT.texCoord0 = IN.texCoord;
	
	return OUT;
}
//////////////////////////
//  Pixel Shaders:
//////////////////////////
pixel glowPS(GLOW_OUTPUT IN)
{
	pixel OUT;
	float4 color = tex2D( MeshTextureSampler, IN.texCoord0 ) * 0.1;
	color += tex2D( MeshTextureSampler, IN.texCoord1 ) * 0.3;
	color += tex2D( MeshTextureSampler, IN.texCoord2 ) * 0.4;
	color += tex2D( MeshTextureSampler, IN.texCoord3 ) * 0.25;
	
	OUT.color = color;
	OUT.color.a = 1.0f;
	
	return OUT;
}
pixel outputGlowPS(TEXTURE_OUTPUT IN)
{
	pixel OUT;
	OUT.color =  float4(1,0,0,1);//tex2D( MeshTextureSampler, IN.texCoord0 );	
	OUT.color *= sqrt(IN.texCoord0.x*IN.texCoord0.y);
	OUT.color.a = 1;
	//OUT.color =  tex2D( MeshTextureSampler, IN.texCoord0 );		
	return OUT;
}
//////////////////////////
//  Techniques:
//////////////////////////
technique T0
{
#if 1
	pass P0 <string renderStage="texture";>
	{
		//Sampler[0] = (MeshTextureSampler);
		vertexshader = compile vs_2_0 glowVSHorizontal1();
		pixelshader  = compile ps_2_0 glowPS();
		//fvf = XYZ | Tex1;
	}
	pass P1 <string renderStage="texture";>
	{
		//Sampler[0] = (MeshTextureSampler);
		vertexshader = compile vs_2_0 glowVSVertical1();
		pixelshader  = compile ps_2_0 glowPS();
		//fvf = XYZ | Tex1;
	}
	pass P2 <string renderStage="texture";>
	{
		//Sampler[0] = (MeshTextureSampler);
		vertexshader = compile vs_2_0 glowVSHorizontal2();
		pixelshader  = compile ps_2_0 glowPS();
		//fvf = XYZ | Tex1;
	}
	pass P3 <string renderStage="texture";>
	{
		//Sampler[0] = (MeshTextureSampler);
		vertexshader = compile vs_2_0 glowVSVertical2();
		pixelshader  = compile ps_2_0 glowPS();
		//fvf = XYZ | Tex1;
	}
	pass P4 <string renderStage="post";>
	{
		//Sampler[0] = (MeshTextureSampler);
		vertexshader = compile vs_2_0 outputGlowVS();
		pixelshader  = compile ps_2_0 outputGlowPS();
		/*fvf = XYZ | Tex1;
		
		AlphaBlendEnable = true;
		BlendOp = Min;
		SrcBlend = One;
		DestBlend = One;*/
	}	
#else
	pass P0
	{
		vertexshader = compile vs_2_0 outputGlowVS();
		pixelshader  = compile ps_2_0 outputGlowPS();
	}
#endif
}

