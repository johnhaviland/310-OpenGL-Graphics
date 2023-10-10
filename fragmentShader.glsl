uniform sampler2D texture;
uniform float opacity;

void main() {
    vec4 texColor = texture2D(texture, gl_TexCoord[0].st);
    gl_FragColor = mix(gl_Color, texColor, opacity); // Preserve original color
}
