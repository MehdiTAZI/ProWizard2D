#ifndef Color4_H
#define Color4_H

namespace ProWiz
	{
	namespace Tools
		{
		class Color{

		public :
			float Red,Green,Blue,Alpha;
			Color& operator=(Color& color)	
				{color.Red=Red; color.Blue=Blue;color.Green=Green;color.Alpha=Alpha; return *this; }
			Color(float red,float green,float blue,float alpha=100)
				{Set(red,green,blue,alpha);}

			Color(const Color &Color)
				{Set(Color);}

			Color()
				{Set();}

			virtual ~Color(){}

		void Set(float red,float green,float blue,float alpha=100)
			{Red=red;Green=green;Blue=blue;Alpha=alpha;}

		void Set(const Color &Color)
			{Red=Color.Red;Green=Color.Green;Blue=Color.Blue;Alpha=Color.Alpha;}				

		void Set()
			{Red=100;Green=100;Blue=100;Alpha=100;}

		void SetColor()
			{glColor4f(Red/100.0f,Green/100.0f,Blue/100.0f,Alpha/100.0f);}
			};
		}
	}
#endif