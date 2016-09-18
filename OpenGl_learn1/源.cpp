//
//
//
//#include <GL\glew.h>
//#include <GLFW\glfw3.h>
//
//#include<iostream>
//
//#include<string>
//#include<fstream>
//#include<sstream>
//
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//
//}
//int main0()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//	//glfwDefaultWindowHints();
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LM", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//	if (window==NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glewExperimental = GL_TRUE;
//	if (glewInit()!=GLEW_OK)
//	{
//		std::cout << "Failed to create GLEW" << std::endl;
//		return -1;
//	}
//
//	GLfloat vertices0[] = {
//		// 第一个三角形
//		0.5f, 0.5f, 0.0f,   // 右上角
//		0.5f, -0.5f, 0.0f,  // 右下角
//		-0.5f, 0.5f, 0.0f,  // 左上角
//
//		// 第二个三角形
//		
//	};
//	GLfloat vertices1[] = {
//
//		0.4f, -0.5f, 0.0f,  // 右下角
//		-0.5f, -0.5f, 0.0f, // 左下角
//		-0.6f, 0.5f, 0.0f   // 左上角
//						
//	};
//	GLfloat vertices2[] = {
//
//		0.5f, 0.5f, 0.0f, 1.0f,0.0f,0.0f,  // 右上角
//		0.5f, -0.5f, 0.0f,  0.0f,1.0f,0.0f,// 右下角
//		-0.5f, -0.5f, 0.0f, 0.0f,0.0f,1.0f// 左下角
//		-0.5f, 0.5f, 0.0f, 0.5f,0.4f,0.3f,  // 左上角
//		-0.7f,0.8f,0.0f, 0.5f,0.7f,0.2f,
//		-0.9f,0.6f,0.0f, 0.3f,0.2f,0.8f
//	};
//	GLfloat vertices3[] = {
//
//		0.5f, 0.5f, 0.0f,   // 右上角
//		0.5f, -0.5f, 0.0f,  // 右下角
//		-0.5f, -0.5f, 0.0f, // 左下角
//		-0.5f, 0.5f, 0.0f,   // 左上角
//		-0.7f,0.8f,0.0f,
//		-0.9f,0.6f,0.0f
//	};
//	GLuint indices2[] = { // 起始于0!
//
//		3,4,5 // 第一个三角形
//		  // 第二个三角形
//	};
//	GLuint indices3[] = {
//		0,2,3
//	};
//
//
//	//glViewport(0, 0, 800, 600);
//	glfwSetKeyCallback(window, key_callback);
//
//
//	std::ifstream f;
//	std::string Path = "F:\\C++\\OpenGl_learn1\\OpenGl_learn1\\VertexShader1.glsl";
//	f.open(Path.c_str(),std::ios::in| std::ios::binary);
//	if (!f.is_open())
//	{
//		throw std::runtime_error(std::string("Failed to open file: ")+Path);
//	}
//	std::stringstream buffer;
//	buffer << f.rdbuf();
//	std::string vertex_shader = buffer.str();
//	const char* vs_code = vertex_shader.c_str();
//	GLuint vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, (const GLchar**)&vs_code, NULL);
//	glCompileShader(vertexShader);
//
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	GLuint fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	std::string fragment_shader_path = "F:\\C++\\OpenGl_learn1\\OpenGl_learn1\\FragmentShader1.glsl";
//	std::ifstream file;
//	file.open(fragment_shader_path,std::ios::in | std::ios::binary);
//	if (!file.is_open())
//	{
//		std::runtime_error(std::string("Failed to open file: ")+fragment_shader_path);
//	}
//	std::stringstream tempbuff;
//	tempbuff << file.rdbuf();
//	std::string fragment_shader = tempbuff.str();
//	const char* fs_code = fragment_shader.c_str();
//	file.close();
//	tempbuff.str("");
//
//	glShaderSource(fragmentShader, 1, (const GLchar**)&fs_code, NULL);
//	glCompileShader(fragmentShader);
//
//	GLint fsuccess;
//	GLchar infoLogf[512];
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fsuccess);
//	if (!fsuccess)
//	{
//		glGetShaderInfoLog(fragmentShader,512,NULL,infoLogf);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLogf << std::endl;
//	}
//
//	GLuint fragmentShader2;
//	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//    fragment_shader_path = "F:\\C++\\OpenGl_learn1\\OpenGl_learn1\\FragmentShader.glsl";
//	file;
//	file.open(fragment_shader_path, std::ios::in | std::ios::binary);
//	if (!file.is_open())
//	{
//		std::runtime_error(std::string("Failed to open file: ") + fragment_shader_path);
//	}
//
//	tempbuff << file.rdbuf();
//	 fragment_shader = tempbuff.str();
//	fs_code = fragment_shader.c_str();
//	glShaderSource(fragmentShader2, 1, (const GLchar**)&fs_code, NULL);
//	glCompileShader(fragmentShader2);
//
//	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &fsuccess);
//	if (!fsuccess)
//	{
//		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLogf);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLogf << std::endl;
//	}
//
//
//	GLuint shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram,vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	GLint psuccess;
//	glGetProgramiv(shaderProgram,GL_LINK_STATUS, &psuccess);
//	if (!psuccess)
//	{
//		glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
//		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLogf << std::endl;
//	}
//
//	GLuint shaderProgram2;
//	shaderProgram2 = glCreateProgram();
//	glAttachShader(shaderProgram2, vertexShader);
//	glAttachShader(shaderProgram2, fragmentShader2);
//	glLinkProgram(shaderProgram2);
//	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &psuccess);
//	if (!psuccess)
//	{
//		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
//		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLogf << std::endl;
//	}
//
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	
//
//
//	GLuint VBO;
//	glGenBuffers(1, &VBO);
//
//	GLuint VAO;
//	glGenVertexArrays(1, &VAO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (const GLvoid*)0);
//	GLint attrib = glGetAttribLocation(shaderProgram,"position");
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//	GLuint VAO2;
//	glGenVertexArrays(1, &VAO2);
//	GLuint VBO2;
//	glGenBuffers(1, &VBO2);
//	GLuint EB2;
//	glGenBuffers(1, &EB2);
//	glBindVertexArray(VAO2);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EB2);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	GLint xx;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &xx);
//	std::cout << xx << std::endl;
//	//glPolygonMode(GL_FRONT, GL_FILL);
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//
//	while (!glfwWindowShouldClose(window)) 
//	{
//		glfwPollEvents();
//
//		glClearColor(0.3f,0.4f,0.1f,1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		GLfloat timeValue = glfwGetTime();
//		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//	/*	GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");*/
//		
//		glUseProgram(shaderProgram);
//		
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//	
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//
//		glUseProgram(0);
//		glUseProgram(shaderProgram2);
//		glBindVertexArray(VAO2);
//		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT,0);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//
//
//
//		glUseProgram(0);
//		
//		glfwSwapBuffers(window);
//	}
//	glfwTerminate();
//	return 0;
//}
//
//
//
