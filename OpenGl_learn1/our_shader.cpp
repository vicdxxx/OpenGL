//#include<our_shader.h>
//#include<string>
//#include<fstream>
//#include<sstream>
//#include<iostream>
//
//#include<GL\glew.h>
//Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
//{
//	std::string vertexCode;
//	std::string fragmentCode;
//	try {
//		std::ifstream vShaderFile(vertexPath);
//		std::ifstream fShaderFile(fragmentPath);
//
//		std::stringstream vShaderStream, fShaderStream;
//		vShaderStream << vShaderFile.rdbuf();
//		fShaderStream << fShaderFile.rdbuf();
//
//		vShaderFile.close();
//		fShaderFile.close();
//
//		vertexCode = vShaderStream.str();
//		fragmentCode = fShaderStream.str();
//
//	}
//	catch (std::exception e)
//	{
//		std::cout << "ERROR::SHADER::FILE_NOT_SUCCEDFULLY_READ" << std::endl;
//	}
//
//	GLuint vertex, fragment;
//	GLint success;
//	GLchar infoLog[512];
//	vertex = glCreateShader(GL_VERTEX_SHADER);
//	const char* vShader = vertexCode.c_str();;
//	glShaderSource(vertex, 1, (const GLchar**)&vShader, NULL);
//	glCompileShader(vertex);
//	// ´òÓ¡±àÒëÊ±´íÎó
//	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	};
//
//	fragment = glCreateShader(GL_FRAGMENT_SHADER);
//	const char* fShader = fragmentCode.c_str();
//	glShaderSource(fragment, 1, (const GLchar**)&fShader, NULL);
//	glCompileShader(fragment);
//	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::CONPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	this->Program = glCreateProgram();
//	glAttachShader(this->Program, vertex);
//	glAttachShader(this->Program, fragment);
//	glLinkProgram(this->Program);
//	glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(Program, 512, NULL, infoLog);
//		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertex);
//	glDeleteShader(fragment);
//
//}
//void Shader::Use()
//{
//	glUseProgram(this->Program);
//}