
#ifndef POINT_H
#define POINT_H

	namespace ProWiz
	{
		namespace Math
		{
			template<typename T>

				class Point2D
					{
				public :
					T X,Y;

					//Initialisation
					Point2D(){}
					Point2D(const T &NewX,const T&NewY)
						{X=NewX; Y=NewY ;}
					
					Point2D(T array[2])
						{Set(array);}

					Point2D(const Point2D<T>& point)
						{Set(point);}

					Point2D(const ProWiz::Math::Vector2D<T>& Vector)
						{Set(Vector);}

					//Deconstructeur
					virtual ~Point2D(){}
					
					Point2D<T>& operator = (const Point2D<T>& Point)
						{X=Point.X;Y=Point.Y;return *this;}

					Point2D<T>& operator = (const ProWiz::Math::Vector2D<T>& Vector)
						{X=Vector.X;Y=Vector.Y;return *this;}

					Point2D<T>& operator=(const float& Value)
						{X = Value; Y = Value; return *this; }
					
					/*friend ProWiz::Math::Vector2D<T>& operator = (const Point2D<T>& Point)
						{X=Point.X;Y=Point.Y;return *this;}*/
	

					//L'Inverse du vecteur
					Point2D<T> operator-() const
						{return Point2D<T>(-X, -Y);}
					
					/**/
					Point2D<T> operator+(const Point2D<T>& Point) const 
						{return Point2D<T>(X + Point.X, Y + Point.Y);}
					
					Point2D<T>& operator+=(const Point2D<T>& Point)	
						{X+=Point.X; Y+=Point.Y; return *this; }
				
					
					Point2D<T> operator+(const ProWiz::Math::Vector2D<T>& Vector) const 
						{return Point2D<T>(X + Vector.X, Y + Vector.Y);	}
					
					Point2D<T>& operator+=(const ProWiz::Math::Vector2D<T>& Vector)	
						{ X+=Vector.X; Y+=Vector.Y; return *this; }
					
					Point2D<T> operator+(const T Value) const 
						{ return Point2D<T>(X + Value, Y + Value);	}
					
					Point2D<T>& operator+=(const T Value) 
						{ X+=Value; Y+=Value; return *this; }

					/**/

					/**/
					Point2D<T> operator-(const Point2D<T>& Point) const 
						{ return Point2D<T>(X - Point.X, Y - Point.Y);	}
					
					Point2D<T>& operator-=(const Point2D<T>& Point)	
						{ X-=Point.X; Y-=Point.Y; return *this; }
										
					Point2D<T> operator-(const ProWiz::Math::Vector2D<T>& Vector) const 
						{ return Point2D<T>(X- Vector.X, Y -Vector.Y);	}
					
					Point2D<T>& operator-=(const ProWiz::Math::Vector2D<T>& Vector)	
						{ X-=Vector.X; Y-=Vector.Y; return *this; }


					Point2D<T> operator-(const T Value) const 
						{ return Point2D<T>(X - Value, Y - Value);}
					Point2D<T>& operator-=(const T Value)
						{ X-=Value; Y-=Value; return *this; }

					/**/

					/**/
					Point2D<T> operator*(const Point2D<T>& Point) const 
						{ return Point2D<T>(X * Point.X, Y * Point.Y);	}
					
					Point2D<T>& operator*=(const Point2D<T>& Point)	
						{ X*=Point.X; Y*=Point.Y; return *this; }

					Point2D<T> operator*(const ProWiz::Math::Vector2D<T>& Vector) const 
						{ return Point2D<T>(X *Vector.X, Y *Vector.Y);	}
					
					Point2D<T>& operator*=(const ProWiz::Math::Vector2D<T>& Vector)	
						{ X*=Vector.X; Y*=Vector.Y; return *this; }

					Point2D<T> operator*(const T Value) const 
						{ return Point2D<T>(X * Value, Y * Value);	}
					
					Point2D<T>& operator*=(const T Value) 
						{ X*=Value; Y*=Value; return *this; }

					/**/

					/**/
					Point2D<T> operator/(const Point2D<T>& Point) const 
					{
						T oneOverX = 1 / Point.X; //evite la division par Zero
						T oneOverY = 1 / Point.Y; //evite la division par Zero
						return Point2D<T>(X * oneOverX , Y *oneOverY );	
					}
					Point2D<T>& operator/=(const Point2D<T>& Point)	
					{
						T oneOverX = 1 / Point.X; //evite la division par Zero
						T oneOverY = 1 /  Point.Y ; //evite la division par Zero

						X*=oneOverX; Y*= oneOverY ; 
						return *this; 
					}

					Point2D<T> operator/(const ProWiz::Math::Vector2D<T>& Vector) const 
					{
						T oneOverX = 1 / Vector.X; //evite la division par Zero
						T oneOverY = 1 / Vector.Y; //evite la division par Zero
						return Point2D<T>(X * oneOverX , Y *oneOverY );	
					}
					Point2D<T>& operator/=(const ProWiz::Math::Vector2D<T>& Vector)	
					{
						T oneOverX = 1 / Vector.X; //evite la division par Zero
						T oneOverY = 1 /  Vector.Y ; //evite la division par Zero

						X*=oneOverX; Y*= oneOverY ; 
						return *this; 
					}


					Point2D<T> operator/(const T Value) const 
					{
						T oneOverX = 1 / Value; //evite la division par Zero
						return Point2D<T>(X * Value , Y *Value );	
					}
					Point2D<T>& operator/=(const T Value)
					{
						T oneOverX = 1 / Value; //evite la division par Zero

						X*=Value; Y*=Value; 
						return *this; 
					}

					/**/

					//Comparaison

					bool operator==(const Point2D<T>& Point) const 
						{return Point.X==X && Point.Y==Y; }

					bool operator!=(const Point2D<T>& Point) const 
						{return Point.X!=X || Point.Y!=Y; }


					void Set(const T& NewX, const T& NewY) 
						{X=NewX; Y=NewY; }
					void Set(const Point2D<T> &Point) 
						{ X=Point.X; Y=Point.Y;}
					void Set(const ProWiz::Math::Vector2D<T> &Vector) 
						{ X=Vector.X; Y=Vector.Y;}
					void Set() 
						{ X=0; Y=0;}
					void Set(T Array[2]) 
						{ X=Array[0]; Y=Array[1];}
					
					
					Point2D<T> Reverse() const
						{ return Point2D<T> (-X, -Y);  }

					// Distance de ce vecteur par rapport a un autre
					T GetDistance(const Point2D<T>& Point) const
						{T vx = X - Point.X; T vy = Y - Point.Y;return T (sqrt(vx*vx + vy*vy));}

					//On eleve La racine carré
					T GetDistanceSquared(const Point2D<T>& Point) const
						{T vx = X - Point.X; T vy = Y - Point.Y;	return T((vx*vx + vy*vy));}
			
					//Translation du vecteur
					Point2D<T> Move ( T X_Value, T Y_Value)
					{
						X+=X_Value;Y+=Y_Value;
						return Point2D<T>(X,Y);
					}
					Point2D<T> Move ( const Point2D<T>& Point)
					{
						X+=Point.X;Y+=Point.Y;
						return Point2D<T>(X,Y);
					}
					Point2D<T> Move (UINT Moving,int Speed)
					{
						if (Moving =ProWiz::Math::Constante::Moving::Down)X=X+Speed;
						if (Moving =ProWiz::Math::Constante::Moving::Up)X=X-Speed;
						if (Moving =ProWiz::Math::Constante::Moving::Left)Y=Y-Speed;
						if (Moving =ProWiz::Math::Constante::Moving::Right)Y=Y+Speed;
					}


				};

		}

	}

#endif

