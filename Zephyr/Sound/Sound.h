#ifndef Sound_H
#define Sound_H

namespace ProWiz
{
	namespace SoundManager
	{
		namespace Constante
			{

				enum SoundFormat
					{
						Media =1,Voice = 2,Sound =3
					};
			}
	
		struct CMusic
		{
			FSOUND_SAMPLE *Voice;
			FMUSIC_MODULE *Media;
			FSOUND_STREAM *Sound;
		};


		class SoundEngine: public PW_Singleton<SoundEngine>
		{
		friend class PW_Singleton <SoundEngine>;
		private :
		CMusic TMusic;
		float Spect;
		float *spec;
		int SpeedPercente;

		public:

	// Initialisation de FMOD


	SoundEngine()
	{
		
		SpeedPercente = 10;
		TMusic.Media=NULL;
		TMusic.Voice=NULL;
		TMusic.Voice =NULL;

	}

	virtual ~SoundEngine()
	{
		SpeedPercente = 10;
		TMusic.Media=NULL;
		TMusic.Voice=NULL;
		TMusic.Voice =NULL;
	}
	
	bool InitEngine(int Freq=44100,int Canaux=32,unsigned int Parametre=0,bool Spectrum=true)// Initialisation de Fmod

	{

		FSOUND_Init(Freq,Canaux,Parametre);//initialise fmod

		FSOUND_DSP_SetActive(FSOUND_DSP_GetFFTUnit(), Spectrum);//Pour avoir les spectrum 

		return true;	

	}

	/*--------------------------------------*/
	/*--------------------------------------*/
	float GetSpectrum( int Start , int End)

	{

		spec=NULL;
		Spect=NULL;

		spec= FSOUND_DSP_GetSpectrum();	

		for( int count = Start;count<=End;count++)
		{

			Spect += spec[count];

		}
		if (End==0 ) End=1;
		return (Spect/End)*4*116;


	}
    
	void  Open(char Chemin[],UINT Format=ProWiz::SoundManager::Constante::Sound)
	{


		if(Format==ProWiz::SoundManager::Constante::Voice)TMusic.Voice = FSOUND_Sample_Load(0, Chemin, FSOUND_LOOP_OFF, 0,0);

		if(Format==ProWiz::SoundManager::Constante::Sound)TMusic.Sound = FSOUND_Stream_Open(Chemin,0,0,0);

		if(Format==ProWiz::SoundManager::Constante::Media)TMusic.Media = FMUSIC_LoadSong (Chemin);

	}


	void Play(int Channel=0,UINT Format=ProWiz::SoundManager::Constante::Sound)
	{

		if(Format==ProWiz::SoundManager::Constante::Voice)FSOUND_PlaySound(Channel,TMusic.Voice);

		if(Format==ProWiz::SoundManager::Constante::Sound)FSOUND_Stream_Play(Channel,TMusic.Sound);

		if(Format==ProWiz::SoundManager::Constante::Media)FMUSIC_PlaySong(TMusic.Media);

	}


	void  Stop(UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0)
	{

		if(Format==ProWiz::SoundManager::Constante::Voice)FSOUND_StopSound (Channel);
		if(Format==ProWiz::SoundManager::Constante::Sound)FSOUND_Stream_Stop(TMusic.Sound);
		if(Format==ProWiz::SoundManager::Constante::Media)FMUSIC_StopSong(TMusic.Media);
	}


	/**/
	//Gestion de frequence et de tampo (rapidité d'excution)
	/**/
	void SetSpeed(int Value,UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0)
	{
		Value=abs(Value);
		if (Value >100)Value = 100;

		//Normal Speed = 21,60864%
		if(Format==ProWiz::SoundManager::Constante::Voice || Format==ProWiz::SoundManager::Constante::Sound)
		{
			Value = ((Value*204085)/100);
			FSOUND_SetFrequency(Channel ,int(Value)) ;
		}
		//Normal Speed = 0%->1%
		if(Format==ProWiz::SoundManager::Constante::Media)
			
		{
			SpeedPercente = Value;
			float Valf=Value ;
			Valf=float((Valf*10)/100);
			FMUSIC_SetMasterSpeed(TMusic.Media ,Valf) ;
		}
	}
	void SetDefautSpeed(UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0)
	{
		if(Format==ProWiz::SoundManager::Constante::Voice || Format==ProWiz::SoundManager::Constante::Sound){FSOUND_SetFrequency (Channel,44100);}
		if(Format==ProWiz::SoundManager::Constante::Media){FMUSIC_SetMasterSpeed (TMusic.Media ,1.0);SpeedPercente=10;}
	}
	int GetSpeed(UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0)
	{
 	
		if(Format==ProWiz::SoundManager::Constante::Voice || Format==ProWiz::SoundManager::Constante::Sound)
			{
				return (FSOUND_GetFrequency(Channel)+1*100)/204085;
			}
	
		if(Format==ProWiz::SoundManager::Constante::Media)
			{
				//MARCHE PAS CORRECTEMENT // RETURN 40 3+1*10
				//return ProWiz::Math::Functions::PerCent<int>(FMUSIC_GetSpeed(TMusic.Media)+1,10);
				return SpeedPercente;
			}

	}
	//Muet
	int Muet(UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0 ) 
	{
		if (GetVolume(Format,Channel)==0)
		{
			SetVolume(100,Format,Channel);return 0;
		}
		if (GetVolume(Format,Channel)==100)
		{
			SetVolume(0,Format,Channel);return 1;
		}
	}
	 
	
	//****//
	//Volume
	//****//
	void SetVolume(int Value=100,UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0 )
	{
		Value=abs(Value);
		Value = ((Value*255)/100);
		if(Format==ProWiz::SoundManager::Constante::Voice || Format==ProWiz::SoundManager::Constante::Sound)FSOUND_SetVolume(Channel , Value);
		if(Format==ProWiz::SoundManager::Constante::Media)FMUSIC_SetMasterVolume(TMusic.Media,Value );
	}
	int GetVolume(UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0 )
	{
		
		if(Format==ProWiz::SoundManager::Constante::Voice || Format==ProWiz::SoundManager::Constante::Sound)return (FSOUND_GetVolume(Channel)+1*100)/255;
		if(Format==ProWiz::SoundManager::Constante::Media)return (FMUSIC_GetMasterVolume(TMusic.Media)+1*100)/255;
		
	}
	

	void SetPosition(int Val,UINT Format=ProWiz::SoundManager::Constante::Sound)
		{

		if(Format==ProWiz::SoundManager::Constante::Sound)FSOUND_Stream_SetTime(TMusic.Sound,Val);

		if(Format==ProWiz::SoundManager::Constante::Media)FMUSIC_SetOrder(TMusic.Media,Val);
		}

	int GetLength(UINT Format=ProWiz::SoundManager::Constante::Sound)
		{
		if(Format==ProWiz::SoundManager::Constante::Voice)FSOUND_Sample_GetLength(TMusic.Voice);

		if(Format==ProWiz::SoundManager::Constante::Sound)return FSOUND_Stream_GetLengthMs(TMusic.Sound);

		if(Format==ProWiz::SoundManager::Constante::Media)FMUSIC_GetNumOrders(TMusic.Media);
		}

	double GetCurrentPosition(UINT Format=ProWiz::SoundManager::Constante::Sound)
		{

		if(Format==ProWiz::SoundManager::Constante::Sound)return FSOUND_Stream_GetTime(TMusic.Sound);

		if(Format==ProWiz::SoundManager::Constante::Media)return FMUSIC_GetOrder(TMusic.Media);
		}
	//****//
	//Les Fonction pour la commande Balance
	//****//
	void SetPanValue(int Channel=0,int Value=128)
	{
		FSOUND_SetPan(Channel,Value);
	}
	
	void SetPanAxis(int Channel=0,int X_Axis=0)
	{
		FSOUND_SetPan(Channel,X_Axis+128);
	}

	int GetPanValue(int Channel=0)
	{
		return FSOUND_GetPan(Channel);
	}
	int GetPanAxis(int Channel=0)
	{
		return ( FSOUND_GetPan(Channel)-128);
	}
	
	//****//
	//Les Fonction pour la commande Paused
	//****//

	void Paused(UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0)
	{
		SetPaused(Format,!GetPaused(Format,Channel),Channel);
	}

	//****//
	//Pour Appliquer
	//****//
	void  SetPaused(bool Mode=false,int Channel=0,UINT Format=ProWiz::SoundManager::Constante::Sound)
	{

		if(Format==ProWiz::SoundManager::Constante::Voice || Format==ProWiz::SoundManager::Constante::Sound)FSOUND_SetPaused (Channel,Mode);
		if(Format==ProWiz::SoundManager::Constante::Media)FMUSIC_SetPaused (TMusic.Media,Mode);
	}

	//****//
	//Pour recevoir
	//****//

	bool GetPaused(UINT Format=ProWiz::SoundManager::Constante::Sound,int Channel=0)
	{

		if(Format==ProWiz::SoundManager::Constante::Voice || Format==ProWiz::SoundManager::Constante::Sound)return FSOUND_GetPaused(Channel);
		if(Format==ProWiz::SoundManager::Constante::Media)return FMUSIC_GetPaused(TMusic.Media);
		return false;
	}

	//****//
	//Les Fonction pour la commande Close
	//****//
	
	void  Close(UINT Format=ProWiz::SoundManager::Constante::Sound)
	{
		if(Format==ProWiz::SoundManager::Constante::Sound)
		{
			FSOUND_Stream_Close(TMusic.Sound)  ;
			TMusic.Sound=NULL;
		}

		if(Format==ProWiz::SoundManager::Constante::Voice)
		{
			FSOUND_Sample_Free(TMusic.Voice)  ;
			TMusic.Voice=NULL;
		}

		if(Format==ProWiz::SoundManager::Constante::Media)
		{
			FMUSIC_FreeSong(TMusic.Media);
			TMusic.Media=NULL;
		}
	}


	//****//
	//Destrucion des resource utiliser par Fmod
	//****//

	void  DestroyEngine()
	{

		FSOUND_Stream_Close(TMusic.Sound);
		FSOUND_Sample_Free (TMusic.Voice);

		FMUSIC_FreeSong(TMusic.Media);

		FSOUND_Close();

		TMusic.Media=NULL;
		TMusic.Voice=NULL;
		TMusic.Sound=NULL;

	}
		};

	}
}

#endif

