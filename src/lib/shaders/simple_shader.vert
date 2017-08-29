#version 330

uniform mat4 modelViewProj;
in vec3 position;
in vec3 col;
out vec3 frag_color;

void main() {
    gl_Position = modelViewProj * vec4(position, 1.0);
    frag_color = col;
}
