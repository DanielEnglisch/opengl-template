#pragma once

#include "GlApp.h"

namespace glu {
	class VertexBuffer {
	private:
		unsigned int m_id;
	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();
		void Bind() const;
		void Unbind() const;
	};

	class IndexBuffer {
	private:
		unsigned int m_id;
		unsigned int m_count;
	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();
		void Bind() const;
		void Unbind() const;
		inline unsigned int getCount() const { return m_count; }
	};




	unsigned int CompileShader(unsigned int type, const std::string & source);
	void setUniform(const unsigned int programId, const std::string & uniformName, const double value);
	void setUniform4f(const unsigned int programId, const std::string & uniformName, const double v1, const double v2, const double v3, const double v4);
	unsigned int CreateProgram(const std::string & vert, const std::string & frag);

}