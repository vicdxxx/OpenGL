#pragma once

#include<vector>

#include<GL/glew.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVITY = 0.25f;
const GLfloat ZOOM = 45.0f;

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	GLfloat Yaw;
	GLfloat Pitch;

	GLfloat MovementSpeed;
	GLfloat MouseSensitivity;
	GLfloat Zoom;


	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH) :Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
	{
		this->Position = position;
		this->WorldUp = up;
		this->Yaw = yaw;
		this->Pitch = pitch;
		this->updateCameraVectors();
	}
	Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw = YAW, GLfloat pitch = PITCH) :Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
	{
		this->Position = glm::vec3(posX, posY, posZ);
		this->WorldUp = glm::vec3(upX, upY, upZ);
		this->Yaw = yaw;
		this->Pitch = pitch;
		this->updateCameraVectors();
	}
	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(this->Position, this->Position + this->Front, this->Up);
	}
	void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
	{
		GLfloat velocity = this->MovementSpeed*deltaTime;
		if (direction == FORWARD)
		{
			this->Position += this->Front*velocity;
		}
		if (direction == BACKWARD)
		{
			this->Position -= this->Front*velocity;
		}
		if (direction == LEFT)
		{
			this->Position -= this->Right*velocity;
		}
		if (direction == RIGHT)
		{
			this->Position += this->Right*velocity;
		}
		if (direction == UP)
		{
			this->Position += this->Up*velocity;
		}
		if (direction == DOWN)
		{
			this->Position -= this->Up*velocity;
		}
	}
	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= this->MouseSensitivity;
		yoffset *= this->MouseSensitivity;

		this->Yaw += xoffset;
		this->Pitch += yoffset;

		if (constrainPitch)
		{
			if (this->Pitch > 89.0f)
			{
				this->Pitch = 89.0f;
			}
			if (this->Pitch < -89.0f)
			{
				this->Pitch = -89.0f;
			}
			this->updateCameraVectors();
		}
	}
	void ProcessMouseScroll(GLfloat yoffset) {
		if (this->Zoom >= 1.0f &&this->Zoom <= 45.0f)
		{
			this->Zoom -= yoffset;
		}
		if (this->Zoom <= 1.0f)
		{
			this->Zoom = 1.0f;
		}
		if (this->Zoom >= 45.0f)
		{
			this->Zoom = 45.0f;
		}
	}
	static glm::mat4 lookAt(glm::vec3 Pos, glm::vec3 Target, glm::vec3 worldUp)
	{
		glm::mat4 x;
		glm::vec3 Direction = glm::normalize(Pos - Target);
		glm::vec3 Right = glm::normalize(glm::cross(glm::normalize(worldUp), Direction));
		glm::vec3 Up = glm::normalize(glm::cross(Direction, Right));
		x = glm::mat4(Right.x, Up.x, Direction.x, 0,
			Right.y, Up.y, Direction.y, 0,
			Right.z, Up.z, Direction.z, 0,
			0, 0, 0, 1
		)*glm::mat4(1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			-Pos.x, -Pos.y, -Pos.z, 1
		);
		return x;
	}
private:
	void updateCameraVectors()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(this->Pitch))*cos(glm::radians(this->Yaw));
		front.y = sin(glm::radians(this->Pitch));
		front.z = cos(glm::radians(this->Pitch))*sin(glm::radians(this->Yaw));
		this->Front = glm::normalize(front);
		this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));
		this->Up = glm::normalize(glm::cross(this->Right, this->Front));
	}

};

