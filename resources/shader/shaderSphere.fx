#include "main.fx"
//--------------------------------------------------------------------------------------
// Model variables
//--------------------------------------------------------------------------------------

float4x4 g_mWorld : World;          // World matrix

bool bBeginOutputParam: BeginOutputParam = false;
//--------------------------------------------------------------------
bool bEndOutputParam:   EndOutputParam   = false;

//--------------------------------------------------------------------------------------
// Name: Projection
// Type: Vertex Shader Fragment
// Desc: Projection transform
//--------------------------------------------------------------------------------------
void Projection( float4 vPosObject: POSITION,
                 float3 vNormalObject: NORMAL,
                 float2 vTexCoordIn: TEXCOORD0,
                 out float4 vPosProj: POSITION,
                 out float2 vTexCoordOut: TEXCOORD0,
                 out float4 vColorOut: COLOR0)
{
	float4x4 mWorldViewProjection = mul(mul(g_mWorld,g_mView),g_mProj);
	// Transform the position into world space for lighting, and projected space
	// for display
	float4 vPosWorld = mul( vPosObject, g_mWorld );
	vPosProj = mul( vPosObject, mWorldViewProjection );
	
	// Transform the normal into world space for lighting
	float3 vNormalWorld = mul( vNormalObject, (float3x3)g_mWorld );
	
	// Pass the texture coordinate
	vTexCoordOut = vTexCoordIn;
	
	// Compute the light vector
	float3 vLight = normalize( g_vLightPosition - vPosWorld.xyz );
	
	// Compute the ambient and diffuse components of illumination
	vColorOut.rgb = g_vLightColor * g_vMaterialAmbient;
	vColorOut.rgb += g_vLightColor * g_vMaterialDiffuse * saturate( dot( vLight, vNormalWorld ) );
	
	// If enabled, calculate the specular term
	float3 vCamera = normalize(vPosWorld.xyz - g_vCameraPosition);
	float3 vReflection = reflect( vLight, vNormalWorld );
	float  fPhongValue = saturate( dot( vReflection, vCamera ) );

	vColorOut.rgb += g_vMaterialSpecular * pow(fPhongValue, g_nMaterialShininess);
			
	vColorOut.a = 1.0f;
}
//--------------------------------------------------------------------------------------
// Name: Lighting
// Type: Pixel Shader
// Desc: Compute lighting and modulate the texture
//--------------------------------------------------------------------------------------
void Lighting( float2 vTexCoord: TEXCOORD0,
               float4 vColorIn: COLOR0,
               out float4 vColorOut: COLOR0 )
{  
	vColorOut = vColorIn;

	vColorOut   *= tex2D( MeshTextureSampler, vTexCoord );  
	vColorOut.a *= g_fMaterialAlpha;
  
  //###
  //vColorOut = 0;
  //vColorOut.a = 1;
}
//--------------------------------------------------------------------------------------
// Techniques
//--------------------------------------------------------------------------------------
technique TexturedSpecular
{
    pass P0
    {
        VertexShader = compile vs_2_0 Projection();
        PixelShader = compile ps_2_0 Lighting();    
    }
}

