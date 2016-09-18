//#define GLEW_STATIC
//#include <GL\glew.h>
//#include<GLFW\glfw3.h>
//
//#include<iostream>
//#include<string>
//#include<sstream>
//#include<fstream>
//
//#include"our_shader.h"
//void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, GL_TRUE);
//
//	}
//}
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
//	GLFWwindow* window = glfwCreateWindow(1200, 700, "LM", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//	if (window==NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwSetKeyCallback(window, key_callback2);
//
//	glewExperimental = GL_TRUE;
//	if (glewInit()!=GLEW_OK)
//	{
//		std::cout << "FAiled to create GLEW" << std::endl;
//		return -1;
//	}
//
//	Shader ourShader("F:\\C++\\OpenGl_learn1\\OpenGl_learn1\\VertexShader1.glsl", "F:\\C++\\OpenGl_learn1\\OpenGl_learn1\\FragmentShader1.glsl");
//	//std::string shader_path = "F:\\C++\\OpenGl_learn1\\OpenGl_learn1\\VertexShader1.glsl";
//	//std::ifstream shader_file;
//	//shader_file.open(shader_path, std::ios::in | std::ios::binary);
//	//if (!shader_file.is_open())
//	//{
//	//	throw std::runtime_error( std::string("Failed to open shader file: ")+shader_path );
//	//}
//	//std::stringstream tempbuf;
//	//tempbuf << shader_file.rdbuf();
//	//std::string shader = tempbuf.str();
//	//tempbuf.str("");
//	//shader_file.close();
//	//GLuint VertexShader;
//	//VertexShader = glCreateShader(GL_VERTEX_SHADER);
//	//const char* vShader;
//	//vShader = shader.c_str();
//	//glShaderSource(VertexShader, 1, (const GLchar**)&vShader, NULL);
//	//glCompileShader(VertexShader);
//	//GLint success;
//	//glGetShaderiv(VertexShader,GL_COMPILE_STATUS,&success);
//	//GLchar infoLog[512];
//	//if (!success)
//	//{
//	//	glGetShaderInfoLog(VertexShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//	//shader_path = "F:\\C++\\OpenGl_learn1\\OpenGl_learn1\\FragmentShader1.glsl";
//	//shader_file.open(shader_path, std::ios::in | std::ios::binary);
//	//if (!shader_file.is_open())
//	//{
//	//	throw std::runtime_error(std::string("Failed to open shader file: ") + shader_path);
//	//}
//	//tempbuf << shader_file.rdbuf();
//	//shader = tempbuf.str();
//	//tempbuf.clear();
//	//shader_file.close();
//	//GLuint FragmentShader;
//	//FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	//const char* fShader = shader.c_str();
//	//glShaderSource(FragmentShader, 1, (const GLchar**)&fShader, NULL);
//	//glCompileShader(FragmentShader);
//	//glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &success);
//	//if (!success)
//	//{
//	//	glGetShaderInfoLog(FragmentShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::FRAGMENT::CONPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//	//GLuint Program;
//	//Program = glCreateProgram();
//	//glAttachShader(Program, VertexShader);
//	//glAttachShader(Program, FragmentShader);
//	//glLinkProgram(Program);
//	//glGetProgramiv(Program, GL_LINK_STATUS,&success);
//	//if (!success)
//	//{
//	//	glGetProgramInfoLog(Program, 512, NULL, infoLog);
//	//	std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
//	//}
//	//glDeleteShader(VertexShader);
//	//glDeleteShader(FragmentShader);
//	GLfloat vertices[] = {
//		-0.7f, -0.7f, 1.0f,
//		0.7f, -0.7f, 0.0f,
//		0.0f, 0.7f, 0.0f
//	};
//	GLuint VBO;
//	glGenBuffers(1, &VBO);
//	GLuint VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER,VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(1);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		GLint	uniformloction;
//		uniformloction = glGetUniformLocation(ourShader.Program,"ourColor_u");
//		GLint	uniformloction1;
//		uniformloction1 = glGetUniformLocation(ourShader.Program, "translate");
//
//		glUseProgram(ourShader.Program);
//		glUniform4f(uniformloction, 0.5f, 0.3f, 0.6f, 1.0f);
//		glUniform4f(uniformloction1, 1.0f, 0.0f, 0.0f, 0.0f);
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//		glUseProgram(0);
//		glfwSwapBuffers(window);
//	}
//	return 0;
//}
