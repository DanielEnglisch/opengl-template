#include "GlUtils.h"

glu::VertexBuffer::VertexBuffer(const void * data, unsigned int size)
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

glu::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_id);
}

void glu::VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void glu::VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


glu::IndexBuffer::IndexBuffer(const unsigned int * data, unsigned int count)
	:m_count{count}
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

glu::IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_id);

}

void glu::IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);

}

void glu::IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}



	unsigned int glu::CompileShader(unsigned int type, const std::string& source) {
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		/* Error checking */
		int res;
		glGetShaderiv(id, GL_COMPILE_STATUS, &res);
		if (res == GL_FALSE) {
			int len;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
			char* message = (char*)alloca(len * sizeof(char));
			glGetShaderInfoLog(id, len, &len, message);
			std::cout << "Error compiling " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: " << message << std::endl;
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	void glu::setUniform(const unsigned int programId, const std::string& uniformName, const double value) {
		unsigned int loc = glGetUniformLocation(programId, uniformName.c_str());
		glUniform1d(loc, value);
	}

	void glu::setUniform4f(const unsigned int programId, const std::string & uniformName, const double v1, const double v2, const double v3, const double v4) {
		unsigned int loc = glGetUniformLocation(programId, uniformName.c_str());
		glUniform4d(loc, v1,v2,v3,v4);
	}

	unsigned int glu::CreateProgram(const std::string & vert, const std::string & frag){
		unsigned int programId = glCreateProgram();
		unsigned int vShader = CompileShader(GL_VERTEX_SHADER, vert);
		unsigned int fShader = CompileShader(GL_FRAGMENT_SHADER, frag);
		glAttachShader(programId, vShader);
		glAttachShader(programId, fShader);
		glLinkProgram(programId);
		glValidateProgram(programId);
		glDetachShader(programId, vShader);
		glDetachShader(programId, fShader);

		return programId;
	}


