#include <fstream>
#include <sstream>
#include <filesystem>
#include <windows.h>

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

void Shader::Initialize(const std::string& vsPath, const std::string& fsPath)
{
	CHECK(!bIsInitialized_);

	uniformLocationCache_ = std::map<std::string, uint32_t>();

	std::string vsSource = ReadShaderFile(vsPath);
	std::string fsSource = ReadShaderFile(fsPath);

	uint32_t vsID = CreateAndCompileShader(EType::Vertex, vsSource);
	ASSERT(vsID != 0, L"failed to create and compile %s", vsPath.c_str());

	uint32_t fsID = CreateAndCompileShader(EType::Fragment, fsSource);
	ASSERT(fsID != 0, L"failed to create and compile %s", fsPath.c_str());

	programID_ = glCreateProgram();
	CHECK(programID_ != 0);

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

void Shader::Initialize(const std::string& vsPath, const std::string& gsPath, const std::string& fsPath)
{
	CHECK(!bIsInitialized_);

	std::string vsSource = ReadShaderFile(vsPath);
	std::string gsSource = ReadShaderFile(gsPath);
	std::string fsSource = ReadShaderFile(fsPath);

	uint32_t vsID = CreateAndCompileShader(EType::Vertex, vsSource);
	ASSERT(vsID != 0, L"failed to create and compile %s", vsPath.c_str());

	uint32_t gsID = CreateAndCompileShader(EType::Geometry, gsSource);
	ASSERT(gsID != 0, L"failed to create and compile %s", gsPath.c_str());

	uint32_t fsID = CreateAndCompileShader(EType::Fragment, fsSource);
	ASSERT(fsID != 0, L"failed to create and compile %s", fsPath.c_str());

	programID_ = glCreateProgram();
	CHECK(programID_ != 0);

	GL_FAILED(glAttachShader(programID_, vsID));
	GL_FAILED(glAttachShader(programID_, gsID));
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
	GL_FAILED(glDeleteShader(gsID));
	GL_FAILED(glDeleteShader(fsID));

	bIsInitialized_ = true;
}

void Shader::Release()
{
	CHECK(bIsInitialized_);

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
	const char* sourcePtr = source.c_str();
	uint32_t shaderID = 0;

	switch (type)
	{
	case EType::Vertex:
		shaderID = glCreateShader(GL_VERTEX_SHADER);
		ASSERT(shaderID != 0, "failed to create vertex shader");
		break;

	case EType::Geometry:
		shaderID = glCreateShader(GL_GEOMETRY_SHADER);
		ASSERT(shaderID != 0, "failed to create geometry shader");
		break;

	case EType::Fragment:
		shaderID = glCreateShader(GL_FRAGMENT_SHADER);
		ASSERT(shaderID != 0, "failed to create fragment shader");
		break;

	default:
		ASSERT(false, "undefined shader type");
		break;
	}
	
	GL_FAILED(glShaderSource(shaderID, 1, &sourcePtr, nullptr));
	GL_FAILED(glCompileShader(shaderID));

	int32_t success;
	GL_FAILED(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success));
	if (!success)
	{
		char buffer[1024];

		glGetShaderInfoLog(shaderID, 1024, nullptr, buffer);
		ASSERT(false, "failed to compile shader\n%s", buffer);
	}

	return shaderID;
}