//#define GLEW_STATIC
//#include<GL/glew.h>
//#include<GLFW\glfw3.h>
//
//#include<iostream>
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//int main1()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	GLFWwindow* window = glfwCreateWindow(800,600,"LM",nullptr,nullptr);
//	glfwMakeContextCurrent(window);
//	if (window==NULL)
//	{
//		std::cout << "Failed to create glfw window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glewExperimental = GL_TRUE;
//	if (glewInit()!=GLEW_OK)
//	{
//		std::cout << "Failed to create glew" << std::endl;
//		return -1;
//	}
//	glViewport(0,0,800, 600);
//
//	glfwSetKeyCallback(window, key_callback);
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glfwSwapBuffers(window);
//	}
//	glfwTerminate();
//	return 0;
//}