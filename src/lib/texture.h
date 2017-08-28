#include "commons.h"



class GLTexture {

  public:

    using handleType = std::unique_ptr<uint8_t[], void(*)(void*)>;

    GLTexture();

    GLTexture(const std::string& textureName);

    GLTexture(const std::string& textureName, GLint textureId);

    GLTexture(const GLTexture& other) = delete;;

    GLTexture(GLTexture&& other) noexcept;

    GLTexture& operator=(const GLTexture& other) = delete;;

    GLTexture& operator=(GLTexture&& other) noexcept;

    ~GLTexture();

    GLuint texture() const ;

    const std::string& textureName() const ;

    handleType load(const std::string& fileName);

  private:
    std::string mTextureName;
    GLuint mTextureId;

};
