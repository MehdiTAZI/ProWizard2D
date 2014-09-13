#ifndef Dimension_H
#define Dimension_H
namespace ProWiz
{
	namespace Math
	{
		template<typename T>

			class Dimension2D

			{
			public :
				T Width,Height;

				//Initialisation
				Dimension2D(){}
				Dimension2D(const T &NewWidth,const T&NewHeight)
					{Width=NewWidth; Height=NewHeight ;}

				Dimension2D(T Array[2])
					{Width=Array[0]; Height=Array[1] ;}

				Dimension2D(const Dimension2D<T>& Dimension)
					{Width=Dimension.Width;Height=Dimension.Height;}

				//Deconstructeur
				virtual ~Dimension2D(){}//Ne pas mettre une valeur Numerique pour eviter les bug pour template

				Dimension2D<T>& operator = (const Dimension2D<T>& Dimension)
					{Width=Dimension.Width;Height=Dimension.Height;return *this;}

				Dimension2D<T>& operator=(const float& Value)
					{ Width = Value;Height = Value; return *this; }

				//L'Inverse du vecteur
				Dimension2D<T> operator-() const
					{return Dimension2D<T>(-Width, -Height);}

				/**/
				Dimension2D<T> operator+(const Dimension2D<T>& Dimension) const 
					{return Dimension2D<T>(Width + Dimension.Width, Height + Dimension.Height);}

				Dimension2D<T>& operator+=(const Dimension2D<T>& Dimension)	
					{ Width+=Dimension.Width; Height+=Dimension.Height; return *this; }

				Dimension2D<T> operator+(const T Value) const 
					{return Dimension2D<T>(Width + Value, Height + Value);}

				Dimension2D<T>& operator+=(const T Value)
					{Width+=Value; Height+=Value; return *this }

				/**/

				/**/
				Dimension2D<T> operator-(const Dimension2D<T>& Dimension) const
					{return Dimension2D<T>(Width - Dimension.Width, Height - Dimension.Height);	}

				Dimension2D<T>& operator-=(const Dimension2D<T>& Dimension)
					{Width-=Dimension.Width; Height-=Dimension.Height; return *this; }

				Dimension2D<T> operator-(const T Value) const 
					{return Dimension2D<T>(Width- Value, Height - Value);	}

				Dimension2D<T>& operator-=(const T Value) 
					{Width-=Value; Height-=Value; return *this; }

				/**/

				/**/
				Dimension2D<T> operator*(const Dimension2D<T>& Dimension) const 
					{return Dimension2D<T>(Width * Dimension.Width, Height * Dimension.Height);	}

				Dimension2D<T>& operator*=(const Dimension2D<T>& Dimension)	
					{Width*=Dimension.Width; Height*=Dimension.Height; return *this; }

				Dimension2D<T> operator*(const T Value) const 
					{return Dimension2D<T>(Width * Value, Height * Value);	}

				Dimension2D<T>& operator*=(const T Value)
					{Width*=Value; Height*=Value; return *this;}

				/**/

				/**/
				Dimension2D<T> operator/(const Dimension2D<T>& Dimension) const 
				{
					T oneOverWidth = 1 / Dimension.Width; //evite la division par Zero
					T oneOverHeight = 1 / Dimension.Height; //evite la division par Zero
					return Dimension2D<T>(Width * oneOverWidth , Height *oneOverHeight );	
				}
				Dimension2D<T>& operator/=(const Dimension2D<T>& Dimension)	
				{
					T oneOverWidth = 1 / Dimension.Width; //evite la division par Zero
					T oneOverHeight  = 1 /  oneOverHeight  ; //evite la division par Zero

					Width*=oneOverWidth; Height*= oneOverHeight  ; 
					return *this; 
				}


				Dimension2D<T> operator/(const T Value) const 
				{
					T oneOver = 1 / Value; //evite la division par Zero
					return Dimension2D<T>(Width * oneOver , Height  *oneOver );	
				}
				Dimension2D<T>& operator/=(const T Value)
				{
					T oneOver = 1 / Value; //evite la division par Zero

					Width*=oneOver ; Height*=oneOver ; 
					return *this; 
				}

				/**/

				//Comparaison

				bool operator==(const Dimension2D<T>& Dimension) const 
					{return Dimension.Width==Width && Dimension.Height==Height; }

				bool operator!=(const Dimension2D<T>& Dimension) const 
					{return Dimension.Width!=Width || Dimension.Height!=Height; }


				void Set(const T& NewWidth, const T& NewHeight) 
					{Width=NewWidth; Height=NewHeight; }

				void Set(const Dimension2D<T> &Dimension) 
					{Width=Dimension.Width; Height=Dimension.Height;}

				void Set() 
					{Width=0; Height=0;}
				void Set(T Array[2]) 
					{Width=Array[0]; Height=Array[1];}

				Dimension2D<T> Reverse() const 
					{return Dimension2D<T> (-Width, -Height);  }


			};
	}

}

#endif

