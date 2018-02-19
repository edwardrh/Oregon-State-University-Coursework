#version 330 compatibility

uniform float	uTime;		// "Time", from Animate( )
in vec2  	vST;		// texture coords
float		uS0, uSize, uT0, uKa;
vec3		myColor, ambient;

void
main( )
{
	myColor = vec3( 1., 1., 0.3 );

	uS0 = .5;
	uT0 = 1.3;
	uSize = 0.4;
	uKa = 1.75;

	/*if( uS0-uSize/2. <= vST.s && vST.s <= uS0+uSize/2. && 
		uT0-uSize/2. <= vST.t && vST.t <= uT0+uSize/2. )
	{
		myColor = vec3( 0., 1., 1. );
	}*/

	if( uS0-uSize <= vST.s && uT0-uSize <= vST.t )
	{
		myColor = vec3( 0., 1., 1. );
	}

	ambient = uKa * myColor;

	gl_FragColor = vec4( myColor,  1. );
}
