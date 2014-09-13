#ifndef _TIME_H_
#define _TIME_H_
tm* dt;
namespace ProWiz
{
	namespace Tools
	{
		class Time:public PW_Singleton<Time>
		{
		public : 

			int Seconde,Minute,Hour,Day,Month,Year,DayInYear,DayInWeek;
			void UpDate()
			{
				time_t T;
				time(&T);
				dt = localtime(&T);
				Seconde=dt->tm_sec;
				Minute=dt->tm_min;
				Hour=dt->tm_hour;
				Day=dt->tm_mday;
				Month = dt->tm_mon+1;
				Year=dt->tm_year+1900;
				DayInYear = dt->tm_yday;
				DayInWeek=dt->tm_wday;
			}
			char * GetDateTime()
			{
				char msg[50];
				sprintf(msg,"%d/%d/%d - %d:%d:%d",dt->tm_mday,dt->tm_mon+1,dt->tm_year+1900,dt->tm_hour,dt->tm_min,dt->tm_sec);
				return msg;
			}


		};
	}
}



#endif