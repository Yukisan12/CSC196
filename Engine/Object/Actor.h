#pragma once
#include "Math/Transform.h"
#include "Graphics/Shape.h"

namespace nc
{
	class Scene;

	class Actor
	{
	public:
		enum class eType
		{
			PLAYER,
			ENEMY,
			BOSS,
			PLAYER_PROJECTILE,
			ENEMY_PROJECTILE,
			ONEUP,
			SPEEDBOOST,
			LOCATOR
		};

	public:
		Actor() {}
		Actor(const Transform& transform, const Shape& shape) : m_transform{ transform }, m_shape{ shape } {}// make sure to initialize m_transform and m_shape
		~Actor() {}

		virtual void Destroy();

		virtual eType GetType() = 0;

		virtual bool Load(const std::string& filename);

		virtual void Update(float dt);
		void Draw(Core::Graphics& graphics);

		virtual void OnCollision(Actor* actor) {}

		float GetRadius();

		bool IsDestroy() { return m_destroy; }
		void SetScene(Scene* scene) { m_scene = scene; }
		Transform& GetTransform() { return m_transform; } // return the transform
		Shape& GetShape() { return m_shape; } // return the shape

		Actor* GetParent() { return m_parent; }
		void AddChild(Actor* child);

	protected:
		bool m_destroy{ false };
		Scene* m_scene{ nullptr };
		Transform m_transform;
		Shape m_shape;

		Actor* m_parent{ nullptr };
		std::vector<Actor*> m_children;
	};
}
