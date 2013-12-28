#ifndef MAIN_SHADER_FX
#define MAIN_SHADER_FX

#ifndef MAX_NUM_LIGHTS
#define MAX_NUM_LIGHTS 4
#endif


float3 g_vMaterialAmbient   : Ambient  = float3( 0.2f, 0.2f, 0.2f );   // Material's ambient color
float3 g_vMaterialDiffuse   : Diffuse  = float3( 0.8f, 0.8f, 0.8f );   // Material's diffuse color
float3 g_vMaterialSpecular  : Specular = float3( 1.0f, 1.0f, 1.0f );  // Material's specular color
float  g_fMaterialAlpha     : Opacity  = 1.0f;
int    g_nMaterialShininess : SpecularPower = 32;
//--------------------------------------------------------------------------------------
// Global variables
//--------------------------------------------------------------------------------------
float3 g_vLightColor     : LightColor    = float3( 1.0f, 0.0f, 0.0f );    // Light color
float3 g_vLightPosition  : LightPosition = float3( 0.0f, 0.0f, 10.0f );   // Light position
//###float3 g_vLightColor[MAX_NUM_LIGHTS]     : LightColor;   // = float3( 1.0f, 0.0f, 0.0f );    // Light color
//###float3 g_vLightPosition[MAX_NUM_LIGHTS]  : LightPosition;// = float3( 0.0f, 0.0f, 10.0f );   // Light position

float3 g_vCameraPosition : CameraPosition;
     
float4x4 g_mProj : Proj;          
float4x4 g_mView : View;         

texture  g_MeshTexture : Texture;   // Color texture for mesh           
//--------------------------------------------------------------------------------------
// Texture samplers
//--------------------------------------------------------------------------------------
sampler MeshTextureSampler = 
sampler_state
{
    Texture = <g_MeshTexture>;    
    MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

float g_BloomScale      : g_BloomScale      = 1.4f;
float g_BloomShiftScale : g_BloomShiftScale = 4;

#endif