
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"
#include <cmath>

#include "main.h"

class entity
{
public:
	Vector2 position;
	Vector2 direction;
	Vector2 velocity;
	float angleRad;
	
	int id;
	int size;

	void init(float posX, float posY, int id_, int size_ = 10, float angle = 0)
	{
		position.x = posX;
		position.y = posY;

		angleRad = angle;
		direction.x = std::cos(angle);
		direction.y = std::sin(angle);
		id = id_;
		size = size_;

		velocity.x = 0;
		velocity.y = 0;
	}

	void updatePosition()
	{
		position.x += velocity.x;
		position.y += velocity.y;
	}
	
	void setVelocity(const Vector2& velocity_vector)
	{
		velocity = velocity_vector;
	}
	void setVelocity( float x, float y )
	{
		velocity.x = x;
		velocity.y = y;
	}

	void accelerate( const Vector2& velocity_vector )
	{
		velocity.x += velocity_vector.x;
		velocity.y += velocity_vector.y;
	}
	void accelerate( float x, float y )
	{
		velocity.x += x;
		velocity.y += y;
	}

	void accelerateDirection(float acceleration )
	{
		velocity.x += direction.x * acceleration;
		velocity.y += direction.y * acceleration;

	}

	void pointToMouse()
	{
		direction = Vector2Normalize(Vector2Subtract(mousePos, position));
		angleRad = std::atan2(direction.y, direction.x);
	}
	
	void pointToTarget( const Vector2& target )
	{
		direction = Vector2Normalize(Vector2Subtract(target, position));
	}
	void pointToTarget(float x, float y)
	{
		Vector2 temp{ x,y };
		direction = Vector2Normalize(Vector2Subtract(temp, position));
	}

	void setDirection(float angleRad)
	{
		direction.x = std::cos(angleRad);
		direction.y = std::sin(angleRad);
	}

};

class bullet
{
public:



	entity positional;
};

namespace mainGlobals
{
	static int ids{ 0 };
	int playermode{ 0 };

}

using namespace mainGlobals;

int getNewId()
{
	int temp = ids;
	ids += 1;
	return temp;
}


void drawPointer( const entity entity )
{
	DrawCircle ( entity.position.x + entity.direction.x * 20, entity.position.y + entity.direction.y * 20, 5, DARKGRAY );
}


void playerInput( entity& player, float speed )
{
	if (IsKeyDown(KEY_A)) {
		
		if (playermode == 0)
		{
			player.accelerate(-(dt * speed), 0);
		}
		else { player.velocity.x = -(dt * speed); }
	}
	else if (IsKeyDown(KEY_D))
	{
		if (playermode == 0)
		{
			player.accelerate(dt * speed, 0);
		}
		else { player.velocity.x = dt * speed; }
	}

	if (IsKeyDown(KEY_W)) 
	{ 
		if (playermode == 0)
		{
			player.accelerate(0, -(dt * speed));
		}
		else { player.velocity.y = -(dt * speed); }
	}
	else if (IsKeyDown(KEY_S))
	{
		if (playermode == 0)
		{
			player.accelerate(0, (dt * speed));
		}
		else { player.velocity.y = dt * speed; }
	}
}

void shoot(const entity& player)
{
	if 
}


int main()
{
	InitWindow(screenWidth, screenHeight, "PROGRAM");
	SetTargetFPS(120);

	Vector2 deltaCircle = { 0, (float)screenHeight / 3.0f };
	Vector2 frameCircle = { 0, (float)screenHeight * (2.0f / 3.0f) };

	entity player1{ }; player1.init(screenWidth/2, screenHeight/2, getNewId(), 15, 0);

	entity bullets[32] {};

	const float speed = 50.0f;
	const float circleRadius = 12.0f;
	
	while (!WindowShouldClose()) // detects ESC.
	{
		dt = GetFrameTime();
		mousePos = GetMousePosition();

		/// logic part
		
		if (deltaCircle.x > screenWidth + 15) deltaCircle.x = 0;
		if (frameCircle.x > screenWidth + 15) frameCircle.x = 0;

		deltaCircle.x += dt * speed;
		frameCircle.x += 0.1f * speed;

		playerInput( player1 , 10.0f );
		player1.pointToMouse();
		player1.updatePosition();
		
		if (player1.position.x > screenWidth + 10) { player1.position.x = 0; }
		else if (player1.position.x < 0 ) { player1.position.x = screenWidth + 10; }

		if (player1.position.y > screenHeight + 10) { player1.position.y = 0; }
		else if (player1.position.y < 0) { player1.position.y = screenHeight - 10; }


		/// Render part
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if ( Vector2Distance( mousePos, player1.position ) < player1.size + 5 )
		{
			DrawText("you", player1.position.x - 14, player1.position.y - 44, 18, BLACK);
		}

		//player
		DrawCircleV(player1.position, player1.size, BLACK);
		drawPointer( player1 );


		//circles
		DrawCircleV(deltaCircle, circleRadius, RED);
		DrawCircleV(frameCircle, circleRadius, BLUE);

		// virtual buttons


		EndDrawing();
	}

	CloseWindow();
	return 0;
}