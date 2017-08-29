#version 330

in vec3 frag_color;
uniform float intensity;
out vec4 color;

void main() {
    //color = vec4(vec3(intensity), 1.0);
    color = vec4(frag_color, 1.0);
}
