
#ifndef Primer_Objs_H
#define Primer_Objs_H


namespace ProWiz
{
	namespace GraphicsManager
	{
		namespace Drawing
		{
		namespace GeometryObjects
			{
		
				//Classe Obj --==Class Mere==--
				
				class VirualObj
				{

					public :
						VirualObj()
						{

						}
						virtual ~VirualObj()
						{

						}
					ProWiz::Tools::Color Color;
					bool Textured;
					unsigned __int16 Picture;
					virtual void Draw()=0; 
				};

				//Classe Point ,Line , Cercle .... --==Class Fille==--
				
				

				//Classe Rectangle
				
				template<typename T>
				class Rectangle:public VirualObj
				{
				public :

					ProWiz::Math::Point2D<T> Position ;
					ProWiz::Math::Dimension2D<T> Dimension;

					Rectangle()
						{Set();	}
					Rectangle(const T &X,const T &Y,const T &Width,const T &Height)
						{Set(X,Y,Width,Height);}

					Rectangle(T position[2],T dimension[2])
						{Set(position,dimension);}

					Rectangle(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
						{Set(position,dimension);}
					virtual ~Rectangle()
						{Position.~Point2D();Dimension.~Dimension2D();}
					void Set()
						{Position.Set();Dimension.Set();}
					void Set(const T &X,const T &Y,const T &Width,const T &Height)
						{Position.Set(X,Y);	Dimension.Set(Width,Height);}

					void Set(T position[2],T dimension[2])
						{Position.Set(position);Dimension.Set(dimension);}

					void Set(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
						{Position.Set(position);Dimension.Set(dimension);}

					virtual void Draw()
					{
						Color.SetColor();
						if(Textured==true)
						{
						glBindTexture(GL_TEXTURE_2D, Picture);
						
						glBegin(GL_QUADS);
						
						glTexCoord2f(0, 0);	glVertex2f(Position.X, Position.Y);
						glTexCoord2f(1, 0);	glVertex2f(Position.X+Dimension.Width,Position.Y);
						glTexCoord2f(1, 1);	glVertex2f(Position.X+Dimension.Width,Position.Y+Dimension.Height);
						glTexCoord2f(0, 1);	glVertex2f(Position.X, Position.Y+Dimension.Height);
						
						glEnd();
						}
						if(Textured==false)
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
						if(Textured==true)
						{
						glBindTexture(GL_TEXTURE_2D, Picture);
						glBegin(GL_QUADS);
						glTexCoord2f(0, 0);	glVertex2f(position.X,position.Y);
						glTexCoord2f(1, 0);	glVertex2f(position.X+dimension.Width,position.Y);
						glTexCoord2f(1, 1);	glVertex2f(position.X+dimension.Width,position.Y+dimension.Height);
						glTexCoord2f(0, 1);	glVertex2f(position.X, position.Y+dimension.Height);
						glEnd();
						}
						if(Textured==false)
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
						if(Textured==true)
						{
						glBindTexture(GL_TEXTURE_2D, Picture);
						glBegin(GL_QUADS);
						glTexCoord2f(0, 0);	glVertex2f(X,Y);
						glTexCoord2f(1,0);	glVertex2f(X+Width,Y);
						glTexCoord2f(1, 1);	glVertex2f(X+Width,Y+Height);
						glTexCoord2f(0, 1);	glVertex2f(X, Y+Height);
						glEnd();
						}
						if(Textured==false)
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

				template<typename T>
			class Scroller:public VirualObj
				{
				private :
					ProWiz::Math::Point2D<T> scro;
				public :

					ProWiz::Math::Point2D<T> Position ;
					ProWiz::Math::Dimension2D<T> Dimension;
					ProWiz::Math::Vector2D<T> scrolling;
					Scroller()
						{Set();	}
					Scroller(const T &X,const T &Y,const T &Width,const T &Height)
						{Set(X,Y,Width,Height);}

					Scroller(T position[2],T dimension[2])
						{Set(position,dimension);}

					Scroller(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
						{Set(position,dimension);}
					virtual ~Scroller()
						{Position.~Point2D();Dimension.~Dimension2D();scro.~Point2D();}
					void Set()
						{Position.Set();Dimension.Set();}
					void Set(const T &X,const T &Y,const T &Width,const T &Height)
						{Position.Set(X,Y);	Dimension.Set(Width,Height);}

					void Set(T position[2],T dimension[2])
						{Position.Set(position);Dimension.Set(dimension);}

					void Set(ProWiz::Math::Point2D<T> position,ProWiz::Math::Dimension2D<T> dimension)
						{Position.Set(position);Dimension.Set(dimension);}

					virtual void Draw()
						{
						Color.SetColor();
						if(Textured==true)
							{
							glBindTexture(GL_TEXTURE_2D, Picture);
							scro +=scrolling;
							glBegin(GL_QUADS);
		
							glTexCoord2f(-scro.X, -scro.Y);	glVertex2f(Position.X, Position.Y);
							glTexCoord2f(1-scro.X, -scro.Y);	glVertex2f(Position.X+Dimension.Width,Position.Y);
							glTexCoord2f(1-scro.X, 1-scro.Y);	glVertex2f(Position.X+Dimension.Width,Position.Y+Dimension.Height);
							glTexCoord2f(-scro.X, 1-scro.Y);	glVertex2f(Position.X, Position.Y+Dimension.Height);

							glEnd();
							}
						if(Textured==false)
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
						if(Textured==true)
							{
							glBindTexture(GL_TEXTURE_2D, Picture);
							scro +=scrolling;
							glBegin(GL_QUADS);
							glTexCoord2f(-scro.X, -scro.Y);	glVertex2f(position.X,position.Y);
							glTexCoord2f(1-scro.X, -scro.Y);	glVertex2f(position.X+dimension.Width,position.Y);
							glTexCoord2f(1-scro.X, 1-scro.Y);	glVertex2f(position.X+dimension.Width,position.Y+dimension.Height);
							glTexCoord2f(-scro.X, 1-scro.Y);	glVertex2f(position.X, position.Y+dimension.Height);
							glEnd();
							}
						if(Textured==false)
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
						if(Textured==true)
							{
							glBindTexture(GL_TEXTURE_2D, Picture);
							scro +=scrolling;
							glBegin(GL_QUADS);
							glTexCoord2f(-scro.X, -scro.Y);	glVertex2f(X,Y);
							glTexCoord2f(1-scro.X,-scro.Y);	glVertex2f(X+Width,Y);
							glTexCoord2f(1-scro.X, 1-scro.Y);	glVertex2f(X+Width,Y+Height);
							glTexCoord2f(-scro.X, 1-scro.Y);	glVertex2f(X, Y+Height);
							glEnd();
							}
						if(Textured==false)
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

			
				template<typename T>
				class Drawer
				{

				public:
					Drawer(){}
					virtual ~Drawer(){}
					void DrawObj(VirualObj* C_OBJ)
						{C_OBJ->Draw();}

				}; 
			
			}
		}
	}

}


#endif