void main(float4 position : POSITION,
					float2 uv		    : TEXCOORD0,
					float3 normal   : NORMAL,
					  
					out float4 oPosition : POSITION,
					out float2 oUv	     : TEXCOORD0,
					
					uniform float4x4 worldViewProj, 
					uniform float3   g_Normal)
{
	oPosition = mul(worldViewProj, position);
	oUv = uv;
	g_Normal = normal;
}


/*
varying vec3 n;
varying vec3 v;
varying vec2 texcoord;

void main(void)
{
	v = vec3(gl_ModelViewMatrix * gl_Vertex);
	n = normalize(gl_NormalMatrix * gl_Normal);
	gl_Position = ftransform();
	texcoord = gl_MultiTexCoord0.xy;		
}
*/