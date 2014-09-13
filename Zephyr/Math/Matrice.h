#ifndef Matrice_H
#define Matrice_H

namespace ProWiz
{
	namespace Math
	{
		template <typename T>
		
			class Matrice3x3
				{
				
				public :
					T M[3][3];

					//Initialisation
					virtual ~Matrice3x3(){}
					Matrice3x3()
						{SetIdentity();}
					Matrice3x3(const T &Value)
						{Set(Value);}
					Matrice3x3(const Matrice3x3<T> &Matrix)	{Set(Matrix);}
					Matrice3x3(T Array[3][3]){Set(Array);}
					Matrice3x3(const T &M11,const T &M12,const T &M13,const T &M21,const T &M22,const T &M23,const T &M31,const T &M32,const T &M33)
						{Set(M11,M12,M13,M21,M22,M23,M31,M32,M33);}
					Matrice3x3(const ProWiz::Math::Vector2D<T> &Axis_X ,const ProWiz::Math::Vector2D<T> &Axis_Y)
						{Set(Axis_X,Axis_Y);}

					//Operator


					// Operateur () et []
					T & operator()(unsigned __int16 Row, unsigned __int16 Col) 
						{return M[Col,Row]; }

					const T& operator()(unsigned __int16 Row, unsigned __int16 Col) const 
						{return M[Col, Row]; }

					// Operateur =

					Matrice3x3<T>& operator=(const Matrice3x3<T> &Matrix)
					{
						M[0,0] = Matrix.M[0,0];M[0,1] = Matrix.M[0,1];M[0,2] = Matrix.M[0,2];
						M[1,0] = Matrix.M[1,0];M[1,1] = Matrix.M[1,1];M[1,2] = Matrix.M[1,2];
						M[2,0] = Matrix.M[2,0];M[2,1] = Matrix.M[2,1];M[2,2] = Matrix.M[2,2];
						return *this;
					}
			
					//Comparaison
					bool operator==(const Matrice3x3<T> &Matrix)
						{
							for (unsigned __int16 i = 0; i < 3; ++i)
								for (unsigned __int16 j = 0; j < 3; ++j)
							{if (M[i,j] != Matrix.M[i,j])return false;}
							return true;
						}
					//retourne l'oposé de ==
					bool operator!=(const Matrice3x3<T> &Matrix)
						{return !(*this ==Matrix);}
			
					//ADDITION ,Multiplication ...........Incrementation/Decrementation 		
					Matrice3x3<T> operator+(const Matrice3x3<T> & Matrix)const
						{return Addition(Matrix);}
					Matrice3x3<T>& operator+=(const Matrice3x3<T> & Matrix)
						{*this = (*this) + Matrix; return (*this);}
				
					Matrice3x3<T> operator-(const Matrice3x3<T> & Matrix) const
						{return Negate(Matrix);}
					Matrice3x3<T> &operator-=(const Matrice3x3<T> & Matrix) 
						{*this = (*this) -Matrix; return (*this);}

					Matrice3x3<T> operator * ( const Matrice3x3<T>& Matrix) const
						{ return Multiply(Matrix); }
					Matrice3x3<T> operator * ( const T& Value ) const 
						{ return Multiply( Value ); }
					Matrice3x3<T>& operator *= ( const Matrice3x3<T>& Matrix)
						{ *this = (*this) * Matrix; return (*this); }
					Matrice3x3<T>& operator *= ( const T& Value ) 
						{ *this = (*this) *  Value; return (*this); }

					friend	ProWiz::Math::Vector2D<T> operator * (const Matrice3x3<T>& Matrix , const ProWiz::Math::Vector2D<T> & Vect)
						{
							return ProWiz::Math::Vector2D<T>(Matrix.M[0,0]* Vect.X + Matrix.M[1,0]*Vect.Y,
															 Matrix.M[0,1]* Vect.X+ Matrix.M[1,1]*Vect.Y)
												+ ProWiz::Math::Vector2D<T>(Matrix.M[1,2], Matrix.M[2,0]); 
						}

					//Set Appliquer les valeur

					void Set(){SetIdentity();}
					void Set(const T &Value)
						{
							for(int i =0;i<3;i++)
								for(int j =0;j<3;j++)
									M[i,j]=Value;
						}
					void Set(const T &M11,const T &M12,const T &M13,const T &M21,const T &M22,const T &M23,const T &M31,const T &M32,const T &M33)
						{
							M[0,0] = M11;M[0,1] = M12;M[0,2] = M13;
							M[1,0] = M21;M[1,1] = M22;M[1,2] = M23;
							M[2,0] = M31;M[2,1] =M32;M[2,2] = M33;
						}
						
					void Set(const ProWiz::Math::Vector2D<T> &Axis_X ,const ProWiz::Math::Vector2D<T> &Axis_Y)
						{
							M[0,0]=Axis_X.X; M[0,1]=Axis_Y.X; M[0,2]=0;
							M[1,0]=Axis_X.Y;M[1,1]=Axis_Y.Y;M[1,2]=0;
							M[2,0]=0;M[2,1]=0;M[2,2]=0;
						}

					void Set(const Matrice3x3<T> &Matrix)
						{
							M[0,0] = Matrix.M[0,0];M[0,1] = Matrix.M[0,1];M[0,2] = Matrix.M[0,2];
							M[1,0] = Matrix.M[1,0];M[1,1] = Matrix.M[1,1];M[1,2] = Matrix.M[1,2];
							M[2,0] = Matrix.M[2,0];M[2,1] = Matrix.M[2,1];M[2,2] = Matrix.M[2,2];
						}

					void Set(T Array[3][3])
					{
						M[0,0]=Array[0,0][0,0];M[0,1]=Array[0,1][0,0];M[0,2]=Array[0,2][0,0];
						M[1,0]=Array[0,0][0,1];M[1,1]=Array[0,1][0,1];M[1,2]=Array[0,2][0,1];
						M[2,0]=Array[0,0][0,2];M[2,1]=Array[0,1][0,2];M[2,2]=Array[0,2][0,2];
					}

						//Get
					ProWiz::Math::Vector2D<T> GetAxis_X()
						{return ProWiz::Math::Vector2D<T>(M[0,0],M[1,0]);}
					
					ProWiz::Math::Vector2D<T> GetAxis_Y()
						{return ProWiz::Math::Vector2D<T>(M[0,1],M[1,1]);}

					bool IsIdentity()
						{if(M[0,0] ==1 && M[1,1] ==1 && M[2,2] == 1)return true;	return false;}
					
// FONCTIONS 
					//Avoir la transposé de la matrice en cours
					Matrice3x3<T> GetTransposed()
						{
							Matrice3x3<T> mat;
							for (unsigned __int16 r=0; r<3; ++r)
								for (unsigned __int16 c=0; c<3; ++c)
									mat(r,c) = (*this)(c,r);
								return mat;
						}
						// Transformer la matrice courante a ca transposé 
					void SetTransposed()
						{(*this)=GetTransposed();}

					void SetIdentity()
						{
							M[0,0] = 1;M[0,1] = 0;M[0,2] = 0;
							M[1,0] = 0;M[1,1] = 1;M[1,2] = 0;
							M[2,0] = 0;M[2,1] = 0;M[2,2] = 1;
						}
					void SetDiagonal(const T &Value)
						{
							M[0,0] = Value;M[0,1] = 0;M[0,2] = 0;
							M[1,0] = 0;M[1,1] = Value;M[1,2] = 0;
							M[2,0] = 0;M[2,1] = 0;M[2,2] = Value;
						}
					void SetAxis(const ProWiz::Math::Vector2D<T> &Axis_X ,const ProWiz::Math::Vector2D<T> &Axis_Y)
						{
							M[0,0]=Axis_X.X; M[0,1]=Axis_Y.X; M[0,2]=0;
							M[1,0]=Axis_X.Y;M[1,1]=Axis_Y.Y;M[1,2]=0;
							M[2,0]=0;M[2,1]=0;M[2,2]=0;
						}

						//Algo Pris d'un livre de math :)
					Matrice3x3<T>  Addition(const Matrice3x3<T> & Matrix)const
						{ 
							return Matrice3x3<T>(this->M[0,0]+Matrix.M[0,0],this->M[0,1]+Matrix.M[0,1],this->M[0,2]+Matrix.M[0,2],this->M[1,0]+Matrix.M[1,0],this->M[1,1]+Matrix.M[1,1],this->M[1,2]+Matrix.M[1,2],this->M[2,0]+Matrix.M[2,0],this->M[2,1]+Matrix.M[2,1],this->M[2,2]+Matrix.M[2,2]);
						}
					Matrice3x3<T>  Negate(const Matrice3x3<T>& Matrix )const
						{
							return Matrice3x3<T>(this->M[0,0]-Matrix.M[0,0],this->M[0,1]-Matrix.M[0,1],this->M[0,2]-Matrix.M[0,2],this->M[1,0]-Matrix.M[1,0],this->M[1,1]-Matrix.M[1,1],this->M[1,2]-Matrix.M[1,2],this->M[2,0]-Matrix.M[2,0],this->M[2,1]-Matrix.M[2,1],this->M[2,2]-Matrix.M[2,2]);
						}
					Matrice3x3<T>& Scaling( const ProWiz::Math::Vector2D<T> &Axis)
						{M[0,0]*=Axis.X;M[1,1]*=Axis.Y;return (*this);}
   					Matrice3x3<T>& Scaling( const T& VAL_X,const T& VAL_Y)
						{M[0,0]*=VAL_X;M[1,1]*=VAL_Y;return (*this);}
				 
					Matrice3x3<T>& Scaling(const T& Value)
						{M[0,0]*=Value;M[1,1]*=Value;return (*this);}
			
					Matrice3x3<T>& Reflect(const T& ValX,const T& ValY)
						{
							M[0,0]= 1-(2* pow(ValX,2));
							M[1,1]=1-(2*pow(ValY,2));
			
							M[0,1]= -2*ValX*ValY;
							M[1,0]=-2*ValX*ValY;
							return (*this);
						}

					Matrice3x3<T>& Reflect(const ProWiz::Math::Vector2D<T> &Axis)
						{
							M[0,0]= (1-(2*Axis.X^2));
							M[1,1]=(1-(2*Axis.Y^2));

							M[0,1]= (-2*Axis.X*Axis.Y);
							M[1,0]=(-2*Axis.X*Axis.Y);
							return (*this);
						}

					Matrice3x3<T>& Shearing(const ProWiz::Math::Vector2D<T> &Val)
						{M[0,1]= Val.Y;M[1,0]=Val.X;return (*this);}
					Matrice3x3<T>& Shearing(const T& ValX,const T& ValY)
						{M[0,1]= ValY;M[1,0]=ValX;	return (*this);}
					Matrice3x3<T>& Multiply( const T& Value )
						{
							for (int i=0;i<3;i++)
								for (int j=0;j<3;j++)
							       M[i,j] *=Value
							return (*this);
						}

					Matrice3x3<T>& Multiply( const T& VAL_X,const T& VAL_Y )
						{

							M[0,0]*=VAL_X; M[0,1]*=VAL_X; M[0,2]=VAL_X;
							M[1,0]*=VAL_Y ;M[1,1]*=VAL_Y ;M[1,2]=VAL_Y;
							M[2,0]=1;M[2,1]=1;M[2,2]=1;
							return (*this);
						}

					Matrice3x3<T>& Multiply( const ProWiz::Math::Vector2D<T> &Axis)
						{
							M[0,0]*=Axis.X; M[0,1]*=Axis.X; M[0,2]=1;
							M[1,0]*=Axis.Y;M[1,1]*=Axis.Y;M[1,2]=1;
							M[2,0]=1;M[2,1]=1;M[2,2]=1;
							return (*this);
						}
	
					Matrice3x3<T> Multiply( const Matrice3x3<T>& Matrix ) const
						{

						 Matrice3x3<T> newM;
						 for (int i = 1;i<4;i++)
							 for(int j = 1 ; i<4;i++)
								 for (int k = 1;k<4 ;k++)
									 newM[i,j]=newM[i,j]+M[i,k]*Matrix[k,j];

						return newM;
					}
					void Zero()	{Set();}

					Matrice3x3<T> SetTranslation( const ProWiz::Math::Vector2D<T>& P )
						{return SetTranslation( P.X, P.Y );}
				 
					Matrice3x3<T> SetTranslation( const T& X, const T& Y )
						{
							Matrice3x3<T> newM;
							newM.SetIdentity();
							newM.M[2,0] = X;
							newM.M[2,1] = Y;
							return newM;
						}
					 
					Matrice3x3<T>& SetTranslate( const ProWiz::Math::Vector2D<T>& P )
						{return SetTranslate( P.X, P.Y );}
						 
					Matrice3x3<T>& SetTranslate( const T& X, const T& Y )
						{M[2,0] += X;M[2,1] += Y;return (*this);}
			
					inline ProWiz::Math::Vector2D<T>& GetTranslation() const
						{return ProWiz::Math::Vector2D<T>(M[2,0], M[2,1]);}
				
					Matrice3x3<T> SetRotationRadians( const T& Radians )
						{
							T Sin, Cos;
							Sin =  sin(Radians);
							Cos =  cos(Radians);
																	
							return Matrice3x3<T> (Cos, Sin, 0.0,
												  -Sin, Cos, 0.0,
												  0.0, 0.0, 1.0 );
		
							}

					Matrice3x3<T> SetRotationDegrees( const T& Degrees )
						{
							T Sin, Cos;
							Sin =  sin(ProWiz::Math::Functions::DegToRad<T>(Degrees));
						Cos =  cos(ProWiz::Math::Functions::DegToRad<T>(Degrees));

						return Matrice3x3<T>( Cos, Sin, 0.0,
											-Sin, Cos, 0.0,
											0.0, 0.0, 1.0 );

						}			
					double GetRotationDegrees()
					{
						return (( acos(M[0,0])*(3.1415926535897932384626433832795/ 180)));
					}
					Matrice3x3<T>& SetRotateDegrees( const T& Degrees )
					{
						return (*this) *= SetRotationRadians(( Degrees * ( 3.1415926535897932384626433832795/ 180)));
					}
					Matrice3x3<T>& SetRotateRadians( const T& Radians )
					{
						return (*this) *= SetRotationRadians(Radians);
					}
					inline void SetRotateVector( ProWiz::Math::Vector2D<T>& Vector ) const
						{
							ProWiz::Math::Vector2D<T> tmp = Vector;
							Vector.X = tmp.X*M[0,0] + tmp.Y*M[1,0];
							Vector.Y = tmp.X*M[0,1] + tmp.Y*M[1,1];
						}

					inline void	SetTransformVector(ProWiz::Math::Vector2D<T>& Vector) const
						{
							f32 vector[0,2];

							vector[0,0] = Vector.X*M[0,0] + Vector.Y*M[1,0] + M[2,0];
							vector[0,1] = Vector.X*M[0,1] + Vector.Y*M[1,1] + M[2,1];

							Vector.X = vector[0,0];
							Vector.Y = vector[0,1];
						}

				inline void SetTransformVector( const ProWiz::Math::Vector2D<T>& In, ProWiz::Math::Vector2D<T>& Out) const
					{
						Out.X = In.X*M[0,0] + In.Y*M[1,0]+ M[2,0];
						Out.Y = In.X*M[0,1] + In.Y*M[1,1]+ M[2,1];
					}
					
				inline void SetTranslateVector( ProWiz::Math::Vector2D<T>& Vector ) const
					{
						Vector.X =+M[2,0];
						Vector.Y =+M[2,1];
					}

				T Determinant()
					{
						return (  (M[0,0]*(M[1,1]*M[2,2]) -(M[2,1]*M[1,2]))- (M[0,1]*(M[1,2]*M[2,0]) -(M[1,0]*M[2,2])) +   (M[0,2]*(M[1,0]*M[2,1]) -(M[2,0]*M[1,1]))     );
					}
			};
	}//Math

}//ProWiz*/
#endif