#ifndef Function_M_H
#define Function_M_H
//Constantes mathematiques

		namespace ProWiz
			{
				namespace Math
				{
									
					namespace Constante
					{
					
						namespace Moving
						{
							enum Moving
							{
								Up =1,Down =0, Left= 3 , Right =4
							};
						}
						const double	PI = 3.1415926535897932384626433832795;
						const double	EPSILON=	0.0000000000001f;
						const double	M = 0.4342944819f;
						const double	e =1.543873444f;
						
					}
					/*Fonctions mathematique*/
					class Operations :public PW_Singleton<Operations>
					{
			public :
			//Convertion
				template <typename T>
				T DegToRad(const T & Degrees){return T( Degrees * ( ProWiz::Math::Constante::PI/ 180));}
				template <typename T>
				T RadToDeg(const T &Radians){return T(Radians * (180 /  ProWiz::Math::Constante::PI));}
					//Fonction Mathematique

					float Sin(const float &Radians){return  sin(Radians); }
					double Sin(const double &Radians){return  sin(Radians); }

					float Cos(const float &Radians){return float( cos(Radians)); }
					double Cos(const double &Radians){return double( cos(Radians)); }

					float Tan(const float &Radians){return float( tan(Radians)); }
					double Tan(const double &Radians){return double( tan(Radians)); }

					float ASin(const float &Radians){return float( asin(Radians)); }
					double ASin(const double &Radians){return double( asin(Radians)); }

                    float ACos(const float &Radians){return float(  acos(Radians)) ;}
					double ACos(const double &Radians){return double(  acos(Radians)) ;}
					
					float ATan(const float &Radians){return float( atan(Radians)); }
					double ATan(const double &Radians){return double( atan(Radians)); }


					float Power(const float &X,const float &Y){return float( pow(X,Y)) ;}
					double Power(const double &X,const double &Y){return double( pow(X,Y)) ;}

					float Exp(const float &X){return float( exp(X)) ;}
					double Exp(const double &X){return double( exp(X)) ;}

					float Exp2(const float &X){return float( exp(0.69314718055994530941723212145818f * X)) ;}
					double Exp2(const double &X){return double( exp(0.69314718055994530941723212145818f * X)) ;}

					float Log(const float &X){return float( log(X)) ;}
					double Log(const double &X){return double( log(X)) ;}

					float Log2(const float &X){return float( log(X)/0.69314718055994530941723212145818f) ;}
					double Log2(const double &X){return double( log(X)/0.69314718055994530941723212145818f) ;}

					float Log10(const float &X){return float(log10(X));}
					double Log10(const double &X){return double(log10(X));}

					float Ln (const float &X){return float( log(X)/ ProWiz::Math::Constante::M) ;}
					double Ln (const double &X){return double( log(X)/ ProWiz::Math::Constante::M) ;}
					
					float Sqrt(const float &X){return float( sqrt(X)) ;}
					double Sqrt(const double &X){return double( sqrt(X)) ;}


					inline float Mod(float X, float Y){return float(X - Y * floor(X / Y));}
					inline double Mod(double X, double Y ){return double(X - Y * floor(X / Y));}


					inline float UpperNbr(const float &X){return float(  ceil(X)) ;}
					inline double UpperNbr(const double &X){return double(  ceil(X)) ;}

					inline float LowerNbr(const float &X){return float(  floor(X)) ;}
					inline double LowerNbr(const double &X){return double(  floor(X)) ;}
						

					template <typename T>
					T Abs(const T &X){return X >= 0 ? X : -X;}

					template <typename T>
						T Sign(const T &X )
					{
						T Result;

						if (X>0)Result=1;
						if (X<0)Result= (-1);
						if (X==0)Result=0;

						return T(Result);
					}

					template <typename T>
					inline T Min(T X, T Y){	return X < Y ? X : Y;}

					template <typename T>
					inline T Max(T X, T Y){	return X > Y ? X : Y;}

					template <typename T>
						inline T Inter(const T &X, T MinVal, T MaxVal)
					{
						if( Min(Max(X, MinVal), MaxVal)==X)return T(1);
						if( Min(Max(X, MinVal), MaxVal)!=X)return T(0);
					}

					template <typename T>
						inline T Distance (T Point1,T Point2){return T(Abs(Point1-Point2));}

					template <typename T>
					inline T PerCent( T Value, const T &MaxValue){return T((Value*100)/MaxValue)  ;}
					
					template <typename T>
					inline T Random (const T &MinValue ,const T &MaxValue ){return T( rand()%((MaxValue)+1-(MinValue))+(MinValue));}

					};
				}
			}
	#endif //Fonction_H