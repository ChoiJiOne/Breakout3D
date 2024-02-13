#include <fstream>
#include <sstream>
#include <filesystem>

#include <glad/glad.h>

#include "Assertion.h"
#include "Shader.h"

Shader::~Shader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Shader::Load(const std::string& vsPath, const std::string& fsPath)
{
	ASSERT(!bIsInitialized_, "alreay load shader file");

	uniformLocationCache_ = std::map<std::string, uint32_t>();

	std::string vsSource = ReadShaderFile(vsPath);
	std::string fsSource = ReadShaderFile(fsPath);

	uint32_t vsID = CreateAndCompileShader(EType::Vertex, vsSource);
	ASSERT(vsID != 0, L"failed to create and compile %s", vsPath.c_str());

	uint32_t fsID = CreateAndCompileShader(EType::Fragment, fsSource);
	ASSERT(fsID != 0, L"failed to create and compile %s", fsPath.c_str());

	programID_ = glCreateProgram();
	GL_ASSERT(programID_ != 0, "failed to create shader program");

	GL_FAILED(glAttachShader(programID_, vsID));
	GL_FAILED(glAttachShader(programID_, fsID));
	GL_FAILED(glLinkProgram(programID_));

	int32_t success;
	GL_FAILED(glGetProgramiv(programID_, GL_LINK_STATUS, &success));
	if (!success)
	{
		char buffer[1024];

		glGetProgramInfoLog(programID_, 1024, nullptr, buffer);
		ASSERT(false, "failed to link shader program\n%s", buffer);
	}

	GL_FAILED(glDeleteShader(vsID));
	GL_FAILED(glDeleteShader(fsID));

	bIsInitialized_ = true;
}

void Shader::Load(const std::string& vsPath, const std::string& gsPath, const std::string& fsPath)
{
	ASSERT(!bIsInitialized_, "alreay load shader file");

	std::string vsSource = ReadShaderFile(vsPath);
	std::string gsSource = ReadShaderFile(gsPath);
	std::string fsSource = ReadShaderFile(fsPath);

	uint32_t vsID = CreateAndCompileShader(EType::Vertex, vsSource);
	ASSERT(vsID != 0, L"failed to create and compile %s...", vsPath.c_str());

	uint32_t gsID = CreateAndCompileShader(EType::Geometry, gsSource);
	ASSERT(gsID != 0, L"failed to create and compile %s...", gsPath.c_str());

	uint32_t fsID = CreateAndCompileShader(EType::Fragment, fsSource);
	ASSERT(fsID != 0, L"failed to create and compile %s...", fsPath.c_str());

	programID_ = glCreateProgram();
	ASSERT(programID_ != 0, "failed to create shader program...");

	GL_ASSERT(glAttachShader(programID_, vsID), "failed to attach vertex shader in shader program...");
	GL_ASSERT(glAttachShader(programID_, gsID), "failed to attach geometry shader in shader program...");
	GL_ASSERT(glAttachShader(programID_, fsID), "failed to attach fragment shader in shader program...");
	GL_ASSERT(glLinkProgram(programID_), "failed to link shader program...");

	int32_t success;
	GL_ASSERT(glGetProgramiv(programID_, GL_LINK_STATUS, &success), "failed to get program link info...");
	if (!success)
	{
		char buffer[1024];

		glGetProgramInfoLog(programID_, 1024, nullptr, buffer);
		ASSERT(false, "failed to link shader program\n%s", buffer);
	}

	GL_ASSERT(glDeleteShader(vsID), "invalid delete %d shader...", vsID);
	GL_ASSERT(glDeleteShader(gsID), "invalid delete %d shader...", gsID);
	GL_ASSERT(glDeleteShader(fsID), "invalid delete %d shader...", fsID);
	
	bIsInitialized_ = true;
}

void Shader::Release()
{
	ASSERT(bIsInitialized_, "not initialized before or has already been released");

	if (programID_)
	{
		GL_FAILED(glDeleteProgram(programID_));
	}

	bIsInitialized_ = false;
}

void Shader::Bind()
{
	GL_FAILED(glUseProgram(programID_));
}

void Shader::Unbind()
{
	GL_FAILED(glUseProgram(0));
}

int32_t Shader::GetUniformLocation(const std::string& name)
{
	return glGetUniformLocation(programID_, name.c_str());
}

std::string Shader::ReadShaderFile(const std::string& path)
{
	ASSERT(std::filesystem::exists(std::filesystem::path(path)), "invalid %s shader file", path.c_str());

	std::ifstream fileStream(path);
	ASSERT(fileStream.is_open(), "failed to open %s", path.c_str());

	std::stringstream fileStringStream;
	fileStringStream << fileStream.rdbuf();

	fileStream.close();

	return fileStringStream.str();
}

uint32_t Shader::CreateAndCompileShader(const EType& type, const std::string& source)
{
	uint32_t shaderType = 0;
	switch (type)
	{
	case EType::Vertex:
		shaderType = GL_VERTEX_SHADER;
		break;

	case EType::Geometry:
		shaderType = GL_GEOMETRY_SHADER;
		break;

	case EType::Fragment:
		shaderType = GL_FRAGMENT_SHADER;
		break;

	default:
		ASSERT(false, "undefined shader type...");
		break;
	}

	const char* sourcePtr = source.c_str();
	uint32_t shaderID = glCreateShader(shaderType);
	ASSERT(shaderID != 0, "failed to create %s shader", type == EType::Vertex ? "Vertex" : "Fragment");

	GL_ASSERT(glShaderSource(shaderID, 1, &sourcePtr, nullptr), "failed to set source code in shader...");
	GL_ASSERT(glCompileShader(shaderID), "failed to compile %s shader...", type == EType::Vertex ? "Vertex" : "Fragment");

	int32_t success;
	GL_ASSERT(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success), "failed to get shader compile status...");
	if (!success)
	{
		char buffer[1024];

		glGetShaderInfoLog(shaderID, 1024, nullptr, buffer);
		ASSERT(false, "failed to compile shader\n%s", buffer);
	}

	return shaderID;
}