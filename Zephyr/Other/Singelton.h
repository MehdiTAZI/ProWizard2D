#ifndef _SINGLETON_H_
#define _SINGLETON_H_

// ==============================================
// CSingleton - singleton.
// ==============================================

template <typename T> class PW_Singleton
{
protected:
	// constructeur/destructeur
	PW_Singleton( void ) { }
	~PW_Singleton( void ) { }


public:
	// fonctions publiques
	static T *GetInstance( void )
	{
		if( m_Singleton == 0 )
			m_Singleton = new T;

		return ((T *)m_Singleton);
	}

	static void Kill( void )
	{
		if( m_Singleton != 0 )
		{
			delete m_Singleton;
			m_Singleton = 0;
		}
	}


protected:
	// variables membres privées
	static T	*m_Singleton;

};


template <typename T> T *PW_Singleton<T>::m_Singleton = 0;

/*Exemple d'utilisation 
CTextureManager *pTexMgr;
pTexMgr = CTextureManager::GetInstance();
CTextureManager::Kill();

*/
#endif	// __SINGLETON_H