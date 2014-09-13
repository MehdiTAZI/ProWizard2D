#ifndef _GLPrimerEffects_H
#define _GLPrimerEffects_H
extern bool STATE[10];
namespace ProWiz
{
	namespace GraphicsManager
	{
		enum Qualities
		{
			Normal=GL_DONT_CARE,Fastest=GL_FASTEST,Nicest=GL_NICEST
		};

		namespace Effects
		{

			class Blending:public PW_Singleton<Blending>
			{
			public :
				void Activate(){glEnable(GL_BLEND);}
				void Disactivate(){glDisable(GL_BLEND);}
				void SetBlending(unsigned __int8 Type)
				{
					if(Type== 0)glBlendFunc(GL_SRC_ALPHA,GL_ONE);


					if(Type== 1)glBlendFunc(GL_ONE,GL_ONE);


					if(Type==2)glBlendFunc(GL_DST_ALPHA,GL_SRC_ALPHA);


					if(Type==3 )glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_SRC_COLOR);


					if(Type==4)glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );

				}
				enum Blending_Model
				{
					Normal=0,Black=1,Shadow=2,Type1=3,Type2=4
				};

			};
			
	
			

			///////////////////////////////////////////////////////
			///////////////////////////////////////////////////////
			///////////////////////////////////////////////////////
			template<typename T>
			class Scrolling:public ProWiz::GraphicsManager::Drawing::GeometryObjects::VirualObj
			{
			public :
				T Speed;
				bool XAxes;
				bool YAxes;
				ProWiz::Math::Point2D<T> Position ;
				ProWiz::Math::Dimension2D<T> Dimension;

				Scrolling()
				{
					Set();
				}
				Scrolling(const T &X,const T &Y,const T &Width,const T &Height)
				{
					Set(X,Y,Width,Height);
				}

				Scrolling(T position[2],T dimension[2])
				{
					Set(position,dimension);
				}

				Scrolling(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
				{
					Set(position,dimension);
				}
				virtual ~Scrolling()
				{
					Position.~Point2D();
					Dimension.~Dimension2D();
				}
				void Set()
				{
					Position.Set();
					Dimension.Set();
				}
				void Set(const T &X,const T &Y,const T &Width,const T &Height)
				{
					Position.Set(X,Y);
					Dimension.Set(Width,Height);
				}

				void Set(T position[2],T dimension[2])
				{
					Position.Set(position);
					Dimension.Set(dimension);
				}

				void Set(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
				{
					Position.Set(position);
					Dimension.Set(dimension);
				}
				virtual void Draw()
				{
					Color.SetColor();
					if(Texture==true)
					{
						glBindTexture(GL_TEXTURE_2D, Picture);

						glBegin(GL_QUADS);

						glTexCoord2f(scro*XAxes, scro*YAxes);glVertex2f(Position.X, Position.Y);
						glTexCoord2f((scro)*XAxes+1.0f, scro*YAxes);glVertex2f(Position.X+Dimension.Width,Position.Y);
						glTexCoord2f((scro)*XAxes+1.0f, (scro*YAxes)+1.0f);glVertex2f(Position.X+Dimension.Width,Position.Y+Dimension.Height);
						glTexCoord2f((scro)*XAxes, (scro*YAxes)+1.0f);glVertex2f(Position.X, Position.Y+Dimension.Height);

						glEnd();

					}
					if(Texture==false)
					{
						glBegin(GL_QUADS);

						glVertex2f(Position.X, Position.Y);
						glVertex2f(Position.X+Dimension.Width,Position.Y);
						glVertex2f(Position.X+Dimension.Width,Position.Y+Dimension.Height);
						glVertex2f(Position.X, Position.Y+Dimension.Height);

						glEnd();
					}
				}
				virtual void Draw(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
				{
					Color.SetColor();
					if(Texture==true)
					{
						glBindTexture(GL_TEXTURE_2D, Picture);
						glBegin(GL_QUADS);
						glTexCoord2f(scro*XAxes, scro*YAxes);	glVertex2f(position.X,position.Y);
						glTexCoord2f((scro)*XAxes+Density, scro*YAxes);	glVertex2f(position.X+dimension.Width,position.Y);
						glTexCoord2f((scro)*XAxes+Density, (scro*YAxes)+Density);glVertex2f(position.X+dimension.Width,position.Y+dimension.Height);
						glTexCoord2f((scro)*XAxes, (scro*YAxes)+Density);	glVertex2f(position.X, position.Y+dimension.Height);
						glEnd();
					}
					if(Texture==false)
					{
						glBegin(GL_QUADS);
						glVertex2f(position.X,position.Y);
						glVertex2f(position.X+dimension.Width,position.Y);
						glVertex2f(position.X+dimension.Width,position.Y+dimension.Height);
						glVertex2f(position.X, position.Y+dimension.Height);
						glEnd();
					}
				}
				virtual void Draw(T X,T Y,T Width ,T Height)
				{
					Color.SetColor();
					if(Texture==true)
					{
						glBindTexture(GL_TEXTURE_2D, Picture);
						glBegin(GL_QUADS);
						glTexCoord2f(scro*XAxes, scro*YAxes);	glVertex2f(X,Y);
						glTexCoord2f((scro)*XAxes+Density, scro*YAxes);	glVertex2f(X+Width,Y);
						glTexCoord2f((scro)*XAxes+Density, (scro*YAxes)+Density);g lVertex2f(X+Width,Y+Height);
						glTexCoord2f((scro)*XAxes+Density, (scro*YAxes)+Density);g	glVertex2f(X, Y+Height);
						glEnd();
					}
					if(Texture==false)
					{
						glBegin(GL_QUADS);
						glVertex2f(X,Y);
						glVertex2f(X+Width,Y);
						glVertex2f(X+Width,Y+Height);
						glVertex2f(X, Y+Height);
						glEnd();
					}
				}
			};


		}//////////////////////////////////////////////////////////////////////////
		
	}
}
#endif