//
// Created by Mohamad Harits Nur Fauzan on 14/07/23.
//

#ifndef ANIMATIONPROGRAMMING_SHADER_H
#define ANIMATIONPROGRAMMING_SHADER_H

#include <map>
#include <string>

class Shader {
private:
    unsigned int mHandle;

    std::map<std::string, unsigned int> mAttributes; // maps attribute name with its handle
    std::map<std::string, unsigned int> mUniforms; // maps uniform name with its handle

private:
    std::string ReadFile(const std::string& path);
    unsigned int CompileVertexShader(const std::string& vertex);
    unsigned int CompileFragmentShader(const std::string& fragment);
    bool LinkShaders(unsigned int vertex, unsigned int fragment);

    void PopulateAttributes();
    void PopulateUniforms();

private:
    Shader(const Shader&);
    Shader& operator=(const Shader&);

public:
    Shader();
    Shader(const std::string& vertex, const std::string& fragment);
    ~Shader();

    void Load(const std::string& vertex, const std::string& fragment);

    void Bind();
    void UnBind();

    unsigned int GetAttribute(const std::string& name);
    unsigned int GetUniform(const std::string& name);
    unsigned int GetHandle();
};


#endif //ANIMATIONPROGRAMMING_SHADER_H
