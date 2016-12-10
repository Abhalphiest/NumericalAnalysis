#version 330 core
out vec4 color;

uniform sampler2D Texture;

in vec2 UV;
in vec3 Normal;
in vec3 light_vector;

void main()
{    
	vec3 normal1         = normalize(Normal);
	vec3 light_vector1   = normalize(light_vector);

	vec4 c = texture(Texture, UV);
	
	vec4 ambient_color  = vec4(0.6, 0.65, 0.75, 1.0);
	vec4 diffuse_color  = vec4(0.7, 0.75, 0.95, 1.0);

	float ambient_contribution  = 0.50;
	float diffuse_contribution  = 1.70;

	float d = dot(normal1, light_vector1);
	bool facing = d > 0.0;

	color = 
		    ambient_color  * ambient_contribution  * c +
		    diffuse_color  * diffuse_contribution  * c * max(d, 0);


	color.a = 1.0;
}