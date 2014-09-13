#ifndef Sprites_H
#define Sprites_H
namespace ProWiz
	{
	namespace GraphicsManager
		{
		namespace Drawing
			{
			template<typename T>
		class Sprite
			{
			public:

				ProWiz::Math::Point2D<T> Position;
				ProWiz::Math::Dimension2D<T> Dimension;
				ProWiz::Tools::Color Color;

				GLuint Picture;
				bool Visible;
				Sprite()
					{
					Set();
					Nbr_Animation = Nbr_Frame = 4;
					Delay = 250;	// millisecondes
					curr_delay = curr_anim = curr_frame = 0;
					Animated = true;
					Visible=true;
					}
				Sprite(const T &X,const T &Y,const T &Width,const T &Height)
					{
					Set(X,Y,Width,Height);
					Nbr_Animation = Nbr_Frame = 4;
					Delay = 250;	// millisecondes
					curr_delay = curr_anim = curr_frame = 0;
					Animated = true;
					 Visible=true
					}

				Sprite(T position[2],T dimension[2])
					{
					Set(position,dimension);
					Nbr_Animation = Nbr_Frame = 4;
					Delay = 250;	// millisecondes
					curr_delay = curr_anim = curr_frame = 0;
					Animated = true;
					 Visible=true
					}

				Sprite(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
					{
					Set(position,dimension);
					Nbr_Animation = Nbr_Frame = 4;
					Delay = 250;	// millisecondes
					curr_delay = curr_anim = curr_frame = 0;
					Animated = true;
					 Visible=true;
					}
				virtual ~Sprite()
					{
					Position.~Point2D();
					Dimension.~Dimension2D();
					Color.~Color();
					}
				void Set()
					{Position.Set();Dimension.Set();}
				void Set(const T &X1,const T &Y1,const T &Width,const T &Height)
					{Position.Set(X1,Y1);Dimension.Set(Width,Height);}
				void SetPicture(int Pic)
					{
					Picture = Pic;
					}
				void Set(T position[2],T dimension[2])
					{Position.Set(position);Dimension.Set(dimension);}

				void Set(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
					{Position.Set(position);Dimension.Set(dimension);}

				void Init(unsigned int _Nbr_Animation, unsigned int _Nbr_Frames, unsigned int _Delay)
					{
					Nbr_Animation	= _Nbr_Animation;
					Nbr_Frame = _Nbr_Frames;
					Delay = _Delay;
					}
				unsigned int GetAnimation()
					{return curr_anim;}

				void SetAnimation (unsigned int _Animation)	
					{curr_anim	= _Animation;}

				void Animate (bool _Animate)
					{Animated = _Animate;}

				void SetFrame (unsigned int _Frame)
					{curr_frame= _Frame;}

				unsigned int GetFrame ()	
					{return	curr_frame;}

				void  Update (T Time)
					{	
					if (Animated == false)
						return;

					curr_delay += Time;//Incremente le temp
					if (curr_delay > Delay)
						{
						curr_delay = curr_delay % Delay;
						curr_frame ++;
						if (curr_frame >= Nbr_Frame)
							{
							curr_frame = 0;
							curr_anim++;
							if(curr_anim>=Nbr_Animation)curr_anim=0;
							}
							
						}
					}

				void Draw()
					{
					ProWiz::Math::Vector2D<T> over (Dimension.Width / (Nbr_Frame*Dimension.Width),Dimension.Height / (Nbr_Animation*Dimension.Height));
	
					if ( Visible ==false)return;
					Color.SetColor();

					glBindTexture(GL_TEXTURE_2D,Picture);
					
				
					glBegin(GL_QUADS);

					glTexCoord2f(curr_frame*over.X, curr_anim*over.Y);glVertex2i(Position.X, Position.Y);
					glTexCoord2f(curr_frame*over.X+over.X, curr_anim*over.Y);glVertex2i(Position.X+Dimension.Width, Position.Y);
					glTexCoord2f(curr_frame*over.X+over.X, curr_anim*over.Y+over.Y);glVertex2i(Position.X+Dimension.Width, Position.Y+Dimension.Height);
					glTexCoord2f(curr_frame*over.X,curr_anim*over.Y+over.Y);glVertex2i(Position.X, Position.Y+Dimension.Height);

					glEnd();
					}
				void Draw(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
					{
					ProWiz::Math::Vector2D<T> over (Dimension.Width / Nbr_Frame/Dimension.Width,Dimension.Height / Nbr_Animation/Dimension.Height);
					if ( Visible ==false)return;
					Color.SetColor();

					glBindTexture(GL_TEXTURE_2D,Picture);
					glBegin(GL_QUADS);

					glTexCoord2f(curr_frame*over.X, curr_anim*over.Y);glVertex2i(position.X, position.Y);
					glTexCoord2f(curr_frame*over.X+over.X, curr_anim*over.Y);glVertex2i(position.X+dimension.Width, position.Y);
					glTexCoord2f(curr_frame*over.X+over.X, curr_anim*over.Y+over.Y);glVertex2i(position.X+dimension.Width, position.Y+dimension.Height);
					glTexCoord2f(curr_frame*over.X,curr_anim*over.Y+over.Y);glVertex2i(position.X, position.Y+dimension.Height);

					glEnd();
					}
				void Draw(T X,T Y,T Width ,T Height)
					{
					ProWiz::Math::Vector2D<T> over (Dimension.Width / Nbr_Frame/Dimension.Width,Dimension.Height / Nbr_Animation/Dimension.Height);
					if ( Visible ==false)return;
					Color.SetColor();

					glBindTexture(GL_TEXTURE_2D,Picture);
					glBegin(GL_QUADS);

					glTexCoord2f(curr_frame*over.X, curr_anim*over.Y);glVertex2i(X,Y);
					glTexCoord2f(curr_frame*over.X+over.X, curr_anim*over.Y);glVertex2i(X+Width,Y);
					glTexCoord2f(curr_frame*over.X+over.X, curr_anim*over.Y+over.Y);glVertex2i(X+Width,Y+Height);
					glTexCoord2f(curr_frame*over.X,curr_anim*over.Y+over.Y);glVertex2i(X,Y+Height);

					glEnd();
					}

				bool Animated;
				unsigned int Nbr_Animation,Nbr_Frame,Delay;

			private:

				int curr_delay,curr_anim, curr_frame;// variable pour gerer l'animmation

			};
			}
		}
	}
#endif