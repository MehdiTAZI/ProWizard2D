#ifndef Collision_H
#define Collision_H
namespace ProWiz
{
	namespace Physics
	{
			template<typename T>
			class Collision
			{
			public :
			Collision()
			{

			}
			virtual ~Collision()
			{

			}
			//Sprite And Sprite
			bool IfCollision(ProWiz::GraphicsManager::Drawing::Sprite<T> Sprite_1,ProWiz::GraphicsManager::Drawing::Sprite<T> Sprite_2)
			{
			bool Co,ColX1,ColY1,ColX2,ColY2;
			ColX1 =  Sprite_1.Position.X >= Sprite_2.Position.X &&
				     Sprite_1.Position.X <= Sprite_2.Position.X+ Sprite_2.Dimension.Width ;

			ColY1 =  Sprite_1.Position.Y >= Sprite_2.Position.Y && 
					 Sprite_1.Position.Y <= Sprite_2.Position.Y + Sprite_2.Dimension.Height;
				  

			ColX2 =   Sprite_2.Position.X >= Sprite_1.Position.X &&
					  Sprite_2.Position.X <= Sprite_1.Position.X+ Sprite_1.Dimension.Width;
				  
			ColY2 =	  Sprite_2.Position.Y >= Sprite_1.Position.Y && 
					 Sprite_2.Position.Y <= Sprite_1.Position.Y + Sprite_1.Dimension.Height;
				Co = ColX1 && ColY1 || ColX2 && ColY2 || ColX1 && ColY2 || ColX2 && ColY1 ;

			return (Co);
			}


		};

	}
}


#endif