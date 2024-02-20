#include <glad/glad.h>

#include "Assertion.h"
#include "FrameBuffer.h"

FrameBuffer::~FrameBuffer()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void FrameBuffer::Initialize(int32_t bufferWidth, int32_t bufferHeight, bool bIsEnableHDR)
{
	CHECK(!bIsInitialized_);
	CHECK((bufferWidth >= 0 && bufferHeight >= 0));

	bIsEnableHDR_ = bIsEnableHDR;

	GL_FAILED(glGenFramebuffers(1, &framebufferID_));
	GL_FAILED(glBindFramebuffer(GL_FRAMEBUFFER, framebufferID_));

	GL_FAILED(glGenTextures(1, &colorBufferID_));
	GL_FAILED(glBindTexture(GL_TEXTURE_2D, colorBufferID_));
	GL_FAILED(glTexImage2D(GL_TEXTURE_2D, 0, bIsEnableHDR_ ? GL_RGBA32F : GL_RGBA, bufferWidth, bufferHeight, 0, GL_RGBA, bIsEnableHDR_ ? GL_FLOAT : GL_UNSIGNED_BYTE, nullptr));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GL_FAILED(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GL_FAILED(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorBufferID_, 0));

	GL_FAILED(glGenRenderbuffers(1, &depthStencilBufferID_));
	GL_FAILED(glBindRenderbuffer(GL_RENDERBUFFER, depthStencilBufferID_));
	GL_FAILED(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, bufferWidth, bufferHeight));
	GL_FAILED(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthStencilBufferID_));

	GLenum state = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	CHECK(state == GL_FRAMEBUFFER_COMPLETE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	bIsInitialized_ = true;
}

void FrameBuffer::Release()
{
	CHECK(bIsInitialized_);

	GL_FAILED(glDeleteRenderbuffers(1, &depthStencilBufferID_));
	GL_FAILED(glDeleteTextures(1, &colorBufferID_));
	GL_FAILED(glDeleteFramebuffers(1, &framebufferID_));

	bIsInitialized_ = false;
}

void FrameBuffer::Clear(float red, float green, float blue, float alpha, float depth, uint8_t stencil)
{
	if (!bIsBind_)
	{
		Bind();
	}

	glClearColor(red, green, blue, alpha);
	glClearDepth(depth);
	glClearStencil(stencil);
	GL_FAILED(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
}

void FrameBuffer::Bind()
{
	if (!bIsBind_)
	{
		bIsBind_ = true;
		GL_FAILED(glBindFramebuffer(GL_FRAMEBUFFER, framebufferID_));
	}
}

void FrameBuffer::Unbind()
{
	if (bIsBind_)
	{
		bIsBind_ = false;
		GL_FAILED(glBindFramebuffer(GL_FRAMEBUFFER, 0));
	}
}

void FrameBuffer::Active(uint32_t unit)
{
	GL_FAILED(glActiveTexture(GL_TEXTURE0 + unit));
	GL_FAILED(glBindTexture(GL_TEXTURE_2D, colorBufferID_));
}