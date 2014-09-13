#ifndef VECTOR_H
#define VECTOR_H

	#include"Function.h"		
	
namespace ProWiz
	{
		namespace Math
			{

		//Template 
			template <typename T>
			
				class Vector2D
					{

					public:
					// Variable
					T X, Y;

					//Initialisation des vecteur
					
					Vector2D(){}//Par Defaut
					
					Vector2D(const T &NewX, const T &NewY) 
						{ X=NewX; Y=NewY; }//Variable
					
					//Vector2D( T Array[2]) { X=Array[0]; Y=Array[1]; }//Tableau
					Vector2D(const Vector2D<T>& Vector)	
						{X=Vector.X; Y=Vector.Y; };//Classe

					//Detruire 
					virtual ~Vector2D(){}

					// Partie Operateurs
	
					//L'Inverse du vecteur
					Vector2D<T> operator-() const 
						{ return Vector2D<T>(-X, -Y);   }

					//
					Vector2D<T>& operator=(const Vector2D<T>& Vector)
						{ X = Vector.X; Y = Vector.Y; return *this; }
					Vector2D<T>& operator=(const float& Value)	{ X = Value; Y = Value; return *this; }


					/**/
					Vector2D<T> operator+(const Vector2D<T>& Vector) const 
						{return Vector2D<T>(X + Vector.X, Y + Vector.Y);}
					Vector2D<T>& operator+=(const Vector2D<T>& Vector)	
						{X+=Vector.X; Y+=Vector.Y; return *this; }
		
					Vector2D<T> operator+(const T Value) const 
						{return Vector2D<T>(X + Value, Y + Value);	}
					Vector2D<T>& operator+=(const T Value) 
						{X+=Value; Y+=Value; return *this; }
				
					/**/

					/**/
					Vector2D<T> operator-(const Vector2D<T>& Vector) const 
						{return Vector2D<T>(X - Vector.X, Y - Vector.Y);}
					Vector2D<T>& operator-=(const Vector2D<T>& Vector)	
						{X-=Vector.X; Y-=Vector.Y; return *this; }
				

					Vector2D<T> operator-(const T Value) const 
						{return Vector2D<T>(X - Value, Y - Value);}

					Vector2D<T>& operator-=(const T Value) 
						{X-=Value; Y-=Value; return *this; }
				
					/**/

					/**/
					Vector2D<T> operator*(const Vector2D<T>& Vector) const 
						{return Vector2D<T>(X * Vector.X, Y * Vector.Y);	}
					Vector2D<T>& operator*=(const Vector2D<T>& Vector)	
						{X*=Vector.X; Y*=Vector.Y; return *this; }
				

					Vector2D<T> operator*(const T Value) const 
						{return Vector2D<T>(X * Value, Y * Value);	}
					Vector2D<T>& operator*=(const T Value) 
						{X*=Value; Y*=Value; return *this; }
				
					/**/

					/**/
					Vector2D<T> operator/(const Vector2D<T>& Vector) const 
					{
						T oneOverX = 1 / Vector.X; //evite la division par Zero
						T oneOverY = 1 / Vector.Y; //evite la division par Zero
						return Vector2D<T>(X * oneOverX , Y *oneOverY );	
					}
					Vector2D<T>& operator/=(const Vector2D<T>& Vector)	
					{
						T oneOverX = 1 / Vector.X; //evite la division par Zero
						T oneOverY = 1 / Vector.Y ; //evite la division par Zero

						X*=oneOverX; Y*= oneOverY ; 
						return *this; 
					}
				

					Vector2D<T> operator/(const T Value) const 
					{
						T oneOver = 1 / Value; //evite la division par Zero
						return Vector2D<T>(X * oneOver , Y *oneOver );	
					}
					Vector2D<T>& operator/=(const T Value)
					{
						T oneOver = 1 / Value; //evite la division par Zero
						X*=oneOver; Y*=oneOver; 
						return *this; 
					}
					
					/**/

					//Comparaison

					bool operator==(const Vector2D<T>& Vector) const 
						{return Vector.X==X && Vector.Y==Y; }
					bool operator==(const T Value) const
						{return GetLength() && Value; }
					
					bool operator!=(const Vector2D<T>& Vector) const 
						{return Vector.X!=X || Vector.Y!=Y; }
					bool operator!=(const T Value) const 
						{return GetLength() || Value; }

					bool operator>=(const Vector2D<T>& Vector) const
						{return GetLength() >= Vector.GetLength();	}
					bool operator>=(const T Value) const
						{return GetLength() >= Value;}
					
					bool operator<=(const Vector2D<T>& Vector) const
						{return GetLength() <= Vector.GetLength();	}
					
					bool operator<=(const T Value) const
						{return GetLength() <= Value;	}

					bool operator>(const Vector2D<T>& Vector) const	
						{return GetLength() > Vector.GetLength();	}
					bool operator>(const T Value) const
						{return GetLength() > Value;	}

					bool operator<(const Vector2D<T>& Vector) const
						{return GetLength() < Vector.GetLength();	}
					bool operator<(const T Value) const
						{return GetLength() < Value;	}

					bool operator&=(const Vector2D<T>& Vector) const
						{return GetLength() == Vector.GetLength();}
		
					// Fonctions

					void Set(const T& NewX, const T& NewY) 
						{X=NewX; Y=NewY; }
					
					void Set(const Vector2D<T> &Vector) 
						{X=Vector.X; Y=Vector.Y;}
					
					void Set() 
						{ X=0; Y=0;}

					void Set(T Array[2]) 
						{ X=Array[0]; Y=Array[1];}

					//Retourne le produit scalaire de 2 vecteur
					//Le produit scalaire Il est défini soit par ||a||*||b||*cos (a) soit par x1*x2 + y1*y2
					T DotProduct(const Vector2D<T>& Vector) const
						{return X*Vector.X + Y*Vector.Y;}
					void Zero()
						{Set();}
					//Retourne la longueur du vecteur
					inline T GetLength() const 
						{return T (sqrt(X*X + Y*Y)); }
					//L'inverse du vecteur
					Vector2D<T> Reverse() const
						{ return Vector2D<T> (-X, -Y);  }

					// Distance de ce vecteur par rapport a un autre
					T GetDistance(const Vector2D<T>& Vector) const
						{	T vx = X - Vector.X; T vy = Y - Vector.Y;return T (sqrt(vx*vx + vy*vy));	}

					//On eleve La racine carré
					T GetDistanceSquared(const Vector2D<T>& Vector) const
						{T vx = X - Vector.X; T vy = Y - Vector.Y;	return T((vx*vx + vy*vy));}

					//La Normal du vecteur
					Vector2D<T>& Normalize()
					{
		
						T magSq = X*X + Y*Y ;
						if (magSq > 0) 
						{ 
							
							T oneOverMag = 1 / sqrt(magSq);

							X *= oneOverMag;
							Y *= oneOverMag;
						}
						return *this;
					}

					//Translation du vecteur
						Vector2D<T> Move ( T X_Value, T Y_Value)
						{
						X+=X_Value;Y+=Y_Value;
						return Vector2D<T>(X,Y);
						}
						Vector2D<T> Move ( const Vector2D<T>& Vector)
						{
							X+=Vector.X;Y+=Vector.Y;
							return Vector2D<T>(X,Y);
						}
						Vector2D<T> Move (unsigned __int16 Moving,int Speed)
						{
							if (Moving =ProWiz::Math::Constante::Moving::Down)X=X+Speed;
							if (Moving =ProWiz::Math::Constante::Moving::Up)X=X-Speed;
							if (Moving =ProWiz::Math::Constante::Moving::Left)Y=Y-Speed;
							if (Moving =ProWiz::Math::Constante::Moving::Right)Y=Y+Speed;
						}
					//Rotation du vecteur
	
					Vector2D<T> RotateByDegrees(T Degrees, const Vector2D<T>& Center)
					{
						Degrees *= 	ProWiz::Math::Constante::PI / 180;//Convertir en degré
						T Cos = (T)cos(Degrees);
						T Sin = (T)sin(Degrees);

						X -= Center.X;
						Y -= Center.Y;

						Set(X*Cos - Y*Sin, X*Sin + Y*Cos);

						X += Center.X;
						Y += Center.Y;
						return Vector2D<T> (X,Y);
					}

					Vector2D<T> RotateByDegrees(T Degrees, const T &CenterX=0, const T &CenterY=0)
					{
						Degrees *= 	ProWiz::Math::Constante::PI / 180;//Convertir en degré
						T Cos = (T)cos(Degrees);
						T Sin = (T)sin(Degrees);

						X -= CenterX;
						Y -= CenterY;

						Set(X*Cos - Y*Sin, X*Sin + Y*Cos);

						X += CenterX;
						Y += CenterY;
						return Vector2D<T> (X,Y);
					}
					Vector2D<T> RotateByRadians(T Radians, const Vector2D<T>& Center)
					{
		
						T Cos = (T)cos(Radians);
						T Sin = (T)sin(Radians);

						X -= Center.X;
						Y -= Center.Y;

						Set(X*Cos - Y*Sin, X*Sin + Y*Cos);

						X += Center.X;
						Y += Center.Y;
						return Vector2D<T> (X,Y);
					}
					Vector2D<T> RotateByRadians(T Radians, const T &CenterX=0, const T &CenterY=0)
					{

						T Cos = (T)cos(Radians);
						T Sin = (T)sin(Radians);

						X -= CenterX;
						Y -= CenterY;

						Set(X*Cos - Y*Sin, X*Sin + Y*Cos);

						X += CenterX;
						Y += CenterY;
						return Vector2D<T> (X,Y);
					}
					Vector2D<T> Scale(T Size)
					{
						X *= abs(Size);
						Y *= abs(Size);
						return Vector2D<T> (X,Y);
					}
					Vector2D<T> Scale(Vector2D<T> SVector)
					{
						X *= abs( SVector.X);
						Y *= abs(SVector.Y);
						return Vector2D<T> (X,Y);
					}
					//Calcule l'angle entre 2 vecteur.
								
					inline T GetDegreesAngleWith(const Vector2D<T>& Vector) const
					{
						///degrees
					return T(acos((X*Vector.X + Y*Vector.Y)/(GetLength()* Vector.GetLength()))* (180 / ProWiz::Math::Constante::PI));
					}
					inline T GetRadiansAngleWith(const Vector2D<T>& Vector) const
					{
						///degrees
						return T(acos((X*Vector.X + Y*Vector.Y)/(GetLength()* Vector.GetLength())));
					}
					inline Vector2D<T> UnitVector() const
					{
						T temp =GetLength() ;
					// un Vecteur unitaire est un vecteur qui a la meme direction que
					//ce vecteur mais qui a une taille plus petite
					if (temp==1) return 0;//Deja un vecteur unité
					return Vector2D<T> (X/temp,Y/temp);
					}
					
					bool IsUnitVector()
					{
						if (GetLength()==1) return true;//Deja un vecteur unité
						if (GetLength()!=1) return false;
					}
					
			};
		}//Math

	}//ProWiz

#endif //Vector	