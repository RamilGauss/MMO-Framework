#include "main.fx"

float4x4 g_mWorld : World;        
float4x4 g_mWorldView;
texture  g_txCubeMap : TextureCubeMap;
float    g_fReflectivity = 0.09f; // доля отражаемого
//-----------------------------------------------------------------------------
samplerCUBE g_samCubeMap = 
sampler_state
{
    Texture = <g_txCubeMap>;
    MinFilter = Linear;
    MagFilter = Linear;
    MipFilter = Linear;
};
//-----------------------------------------------------------------------------
void mainVS( float4 Pos : POSITION,
             float3 Normal : NORMAL,
             float2 vTexCoordIn: TEXCOORD0,
             out float4 oPos : POSITION,
             out float2 vTexCoordOut: TEXCOORD0,
             out float3 EnvTex : TEXCOORD1,
             out float4 vColorOut: COLOR0)
{
	float4x4 mWorldView = mul(g_mWorld,g_mView);
  oPos = mul( Pos, mWorldView);//g_mWorldView );

  // Compute normal in camera space
  float3 vN = mul( Normal, mWorldView);//g_mWorldView );
  vN = normalize( vN );
  // Obtain the reverse eye vector
  float3 vEyeR = -normalize( oPos );
  // Compute the reflection vector
  float3 vRef = 2 * dot( vEyeR, vN ) * vN - vEyeR;
  // Store the reflection vector in texcoord0
  EnvTex = vRef;
  // Apply the projection
  oPos = mul( oPos, g_mProj );
	//-----------------------------------------------------------------
	
	float4x4 mWorldViewProjection = mul(mul(g_mWorld,g_mView),g_mProj);
	// Transform the position into world space for lighting, and projected space
	// for display
	float4 vPosWorld = mul( Pos, g_mWorld );
	//vPosProj = mul( Pos, mWorldViewProjection );
	
	// Transform the normal into world space for lighting
	float3 vNormalWorld = mul( Normal, (float3x3)g_mWorld );
	
  
  vColorOut = float4(0,0,0,1);
  for(int i = 0 ; i < MAX_NUM_LIGHTS ; i++)
  {
    if(g_vLightColor[i].r>0.0f)
    if(g_vLightColor[i].g>0.0f)
    if(g_vLightColor[i].b>0.0f)
    {
      // Compute the light vector
      float3 vLight = normalize( g_vLightPosition[i] - vPosWorld.xyz );
      
      // Compute the ambient and diffuse components of illumination
      vColorOut.rgb += g_vLightColor[i] * g_vMaterialAmbient;
      vColorOut.rgb += g_vLightColor[i] * g_vMaterialDiffuse * saturate( dot( vLight, vNormalWorld ) );
      
      // If enabled, calculate the specular term
      float3 vCamera = normalize(vPosWorld.xyz - g_vCameraPosition);
      float3 vReflection = reflect( vLight, vNormalWorld );
      float  fPhongValue = saturate( dot( vReflection, vCamera ) );

      vColorOut.rgb += g_vMaterialSpecular * pow(fPhongValue, g_nMaterialShininess);
    }
	}
  
	vColorOut.a = 1.0f;
	//------------------------------------------------------------------------------
	vTexCoordOut = vTexCoordIn;
}
//-----------------------------------------------------------------------------
#define LIMIT_COLOR_FOR_REFLECT 0.85f
#define COEF_COLOR_FOR_REFLECT  2.50f
float4 mainPS( float2 vTexCoord: TEXCOORD0,
               float4 vColorIn : COLOR0,
				       float3 Tex      : TEXCOORD1 ): COLOR	 
{
#if 1
	// выделить источник освещения
  float4 colorMirror = texCUBE( g_samCubeMap, Tex );
  if((colorMirror.r>LIMIT_COLOR_FOR_REFLECT)&&
     (colorMirror.g>LIMIT_COLOR_FOR_REFLECT)&&
	   (colorMirror.b>LIMIT_COLOR_FOR_REFLECT))
  {
    colorMirror = COEF_COLOR_FOR_REFLECT * g_fReflectivity * texCUBE( g_samCubeMap, Tex );	
		colorMirror.rgb = saturate(colorMirror.rgb);
  }
  else
    colorMirror = g_fReflectivity * texCUBE( g_samCubeMap, Tex );
#else
  float4 colorMirror = g_fReflectivity * texCUBE( g_samCubeMap, Tex );
#endif  
  
	float4 vColorOut = vColorIn;

	vColorOut   *= tex2D( MeshTextureSampler, vTexCoord );  
	vColorOut.a  = 1.0f;  
	vColorOut.a *= g_fMaterialAlpha;
	
	vColorOut += colorMirror;
	return vColorOut;
}
//-----------------------------------------------------------------------------
technique Render
{
    pass p0
    {
        VertexShader = compile vs_2_0 mainVS();
        PixelShader = compile ps_2_0  mainPS();
    }
}
//-----------------------------------------------------------------------------