/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef StatisticValueH
#define StatisticValueH

#include <math.h>
             
//---------------------------------------------------------------------------
// Классы предназначены TStatXXX для расчета статистических параметров
// (мат. ожидания, дисперсии, СКО) не непрерывном потоке данных.
// Для защиты от переполнения аккумуляторов введен режим расчета статистики по 
// заданному кол-ву последних значений. Данная реализация классов, 
// с целью экономии памяти, допускает погрешность в расчетах.
// Отличия от математически точных значений крайне незначительны и не имеют 
// практического значения.
//---------------------------------------------------------------------------
inline double calcSKO( int sum, int sum2, int count )
{
  // У Никонова:
  // disp = ( mSum2 - 2*(mSum/mCount)*mSum + ((mSum*mSum)/mCount) ) / mCount )
  // Упрощаем:
  double disp = ( sum2 - sum*sum/(double)count ) / count;
  //if(disp<0) disp = 0;//-disp;//???

  return sqrt( disp );
}
//---------------------------------------------------------------------------
inline double calcSKO( unsigned __int64 sum, unsigned __int64 sum2, int count )
{
  // У Никонова:
  // disp = ( mSum2 - 2*(mSum/mCount)*mSum + ((mSum*mSum)/mCount) ) / mCount )
  // Упрощаем:
  double disp = ( sum2 - sum*sum/(double)count ) / count;
  //if(disp<0) disp = 0;//-disp;//???

  return sqrt( disp );
}
//---------------------------------------------------------------------------
inline double calcSKO( double sum, double sum2, int count )
{
  // У Никонова:
  // disp = ( mSum2 - 2*(mSum/mCount)*mSum + ((mSum*mSum)/mCount) ) / mCount )
  // Упрощаем:
  double disp = ( sum2 - sum*sum/(double)count ) / count;

  return sqrt( disp );
}
//---------------------------------------------------------------------------
// Макрос удобной детализации шаблона 
#define TStatType_char    TStatValueT<char,   float, unsigned char>
#define TStatType_short   TStatValueT<short,  float, unsigned char>
#define TStatType_int     TStatValueT<int,    double,unsigned char>
#define TStatType_double  TStatValueT<double, double,unsigned char>

//---------------------------------------------------------------------------
// Расчет статистических параметров для линейного набора значений
// TValue, TAverage, TCount - типы данных для хранения соответствующих величин
template <typename TValue, typename TAverage, typename TCount>
class TStatValueT
{
protected:  
  TAverage mAverage;  // среднее значение (мат. ожидание)
  mutable float mSKO; // среднеквадратичное отклонение (СКО)

  TCount  mMaxCount;  // кол-во последних значений по которым ведется накопления статистики
  TCount  mCount;     // кол-во элементов накопления статистики
  double  mSum;       // Сумма значений
  double  mSum2;      // Сумма квадратов значений

public:  

  TStatValueT( TCount maxCount )
  {
    mMaxCount = maxCount;
    reset();
  }

  // значение не задано
  bool empty() const
  {
    return mCount == 0;
  }

  // установить начальное значение
  void reset()
  {
    mSKO = 0;
    mCount = 0;
    mSum = mSum2 = 0;
    mAverage = 0;
  }
  
  // установить начальное значение
  void reset( TValue value )
  {
    mCount = 1;
    mSum = value;
    mSum2 = value*value;

    mAverage = (TAverage)value;
    mSKO = 0;
  }

  // добавить в набор очередной замер
  void add( TValue value )
  {
    mSum += value;
    mSum2 += value*value;
    mCount++;
    mAverage = (TAverage)( mSum / mCount );
    
    if( mCount >= mMaxCount )
    {
      mSum  -= mAverage;
      mSum2 -= mSum2/mCount;
      mCount--;
    }
    mSKO = 0;
  }


  TAverage summa() const
  {
    return TAverage(mSum);
  }
  // среднее арифметическое значение (мат. ожидание)
  TAverage aver() const
  {
    return mAverage;
  }

  // среднеквадратичное отклонение (СКО)
  float getSKO() const
  {
    if( (int)mSKO == 0 && mCount )
      mSKO = (float)calcSKO( mSum, mSum2, mCount );
    return mSKO;
  }

  //bool save( TIOStream& od ) const 
  //{
  //  return 
  //    od.put( mCount) &&
  //    od.put( mSum  ) &&
  //    od.put( mSum2 );
  //}

  //bool load( TIOStream& od )
  //{
  //  if( od.get( mCount) &&
  //      od.get( mSum  ) &&
  //      od.get( mSum2 ) )
  //  {
  //    mAverage = mCount ? mSum/mCount : 0;
  //    mSKO = 0;
  //    return true;
  //  }
  //  return false;
  //}

	// кол-во элементов накопления статистики
	TCount GetCount()	    { return mCount; }

	// мах кол-во элементов накопления статистики
	TCount GetMaxCount()	{ return mMaxCount; }
	
	void SetMaxCount( TCount cnt )
	{
		mMaxCount = cnt;
		if( mCount >= mMaxCount )
		{
			int delta = mCount - mMaxCount + 1;
			mSum -= mAverage*delta;
			mSum2 -= (mSum2/mCount)*delta;
		}
	}
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Расчет статистических параметров для циклического набора значений (например - углы)
// Схема области значений по четвертям: 
//  4 | 1
//  -----
//  3 | 2
// Обеспечивается корректная совместная обработка значений из 4 и 1 четвертей.

// Макрос удобной детализации шаблона 
#define TStatCyclicType_char(maxValue)    TStatCyclicValueT<char,   float,  guchar, maxValue>
#define TStatCyclicType_short(maxValue)   TStatCyclicValueT<short,  float,  guchar, maxValue>
#define TStatCyclicType_int(maxValue)     TStatCyclicValueT<int,    double, guchar, maxValue>
#define TStatCyclicType_double(maxValue)  TStatCyclicValueT<double, double, guchar, maxValue>

// TValue, TAverage, TCount - типы данных для хранения соответствующих величин
template <typename TValue, typename TAverage, typename TCount, int maxValue >
class TStatCyclicValueT
{
protected:  
  char      mHasHiValue;// наличие в потоке значений из 4 четверти
  TAverage  mAverage;   // среднее значение (мат. ожидание)
  mutable float mSKO; // среднеквадратичное отклонение (СКО)

  TCount  mMaxCount;  // кол-во последних значений по которым ведется накопления статистики
  TCount  mCount;     // кол-во элементов накопления статистики
  double  mSum;       // Сумма значений
  double  mSum2;      // Сумма квадратов значений

public:  

  TStatCyclicValueT( TCount maxCount )
  {
    reset();
    mMaxCount = maxCount;
  }

  // значение не задано
  bool empty() const
  {
    return mCount == 0;
  }

  // сброс в начальное состояние
  void reset()
  {
    mHasHiValue = false;
    mSKO = 0;
    mCount = 0;
    mSum = mSum2 = 0;
    mAverage = 0;
  }

  // установить начальное значение
  void reset( TValue value )
  {
    mHasHiValue = ( value > maxValue*3/4 ) ? true  : false;

    mCount = 1;
    mSum = value;
    mSum2 = value*value;

    mAverage = (TAverage)value;
    mSKO = 0;
  }

  // добавить в набор очередной замер
  void add( TValue value )
  {
    // коррекция значения для ухода из зоны "заворота" значений
    if( mCount == 0 )
    {
      if( value > maxValue*3/4 )
        mHasHiValue = true;
    }
    else 
    {
      if( mHasHiValue ) 
      {
        if( value < maxValue/4 )
          value = maxValue + value;
      }
      else
      {
        if( value > maxValue*3/4 )
        {
          mHasHiValue = true;
          if( mAverage < maxValue/4 )
          {
            // переводим все предыдущие значения из 1 четверти в 5:
            mAverage += maxValue;
            getSKO();
            // обратный расчет значений аккумуляторов по известному СКО
            // 1)  disp = sko*sko;
            // 2)  disp = ( sum2 - sum*sum/(double)count ) / count;
            //     sum2 = disp * count + sum*sum/(double)count;
            //               
            mSum  = mAverage * mCount;
            mSum2 = mSKO*mSKO*mCount + mSum*mSum/mCount;
          }
        }
      }
    }
    mSum  += value;
    mSum2 += value*value;
    mCount++;
    mAverage = (TAverage)( mSum / mCount );

    if( mCount >= mMaxCount )
    {
      mSum -= mAverage;
      mSum2 -= mSum2/mCount;
      mCount = mMaxCount - 1;
    }
    mSKO = 0;
  }

  // среднее арифметическое значение (мат. ожидание)
  TAverage aver() const
  {
    return mAverage >= maxValue ? mAverage - maxValue : mAverage;
  }

  // среднеквадратичное отклонение (СКО)
  float getSKO() const
  {
    if( mSKO == 0 && mCount)
      mSKO = (float)calcSKO( mSum, mSum2, mCount );
    return mSKO;
  }

  //bool save( TIOStream& od ) const 
  //{
  //  return 
  //    od.put( *(signed char*)&mHasHiValue) &&
  //    od.put( mCount) &&
  //    od.put( mSum  ) &&
  //    od.put( mSum2 );
  //}

  //bool load( TIOStream& od )
  //{
  //  if( od.get( *(signed char*)&mHasHiValue ) &&
  //      od.get( mCount) &&
  //      od.get( mSum  ) &&
  //      od.get( mSum2 ) )
  //  {
  //    mSKO = 0;
  //    mAverage = (TAverage)(mCount ? mSum/mCount : 0);
  //    return true;
  //  }
  //  return false;
  //}

  // кол-во элементов накопления статистики
  TCount GetCount()	{ return mCount; }

  // мах кол-во элементов накопления статистики
  TCount GetMaxCount()	{ return mMaxCount; }

  void SetMaxCount(TCount cnt)
  {
    mMaxCount = cnt;
    if( mCount >= mMaxCount )
    {
      int delta = mCount - mMaxCount + 1;
      mSum -= mAverage*delta;
      mSum2 -= (mSum2/mCount)*delta;
    }
  }
};
//---------------------------------------------------------------------------
// Расчет статистических параметров для линейного набора значений относительно опорного значения
// TValue, TAverage, TSKO, TCount - типы данных для хранения соответствующих величин
template <typename TValue, typename TCount>
class TAbsStatValueT
{
protected:  
  TValue  mAbsValue;  // опорное значение
  mutable float mSKO; // среднеквадратичное отклонение (СКО)

  TCount  mMaxCount;// кол-во последних значений по которым ведется накопления статистики
  TCount  mCount;   // кол-во элементов накопления статистики
  double  mSum2;    // Сумма квадратов значений

public:  

  TAbsStatValueT( TCount maxCount, TValue absValue )
  {
    mSKO = 0;
    mCount = 0;
    mMaxCount = maxCount;
    mSum2 = 0;
    mAbsValue = absValue;
  }

  // значение не задано
  bool empty() const
  {
    return mCount == 0;
  }

  // установить начальное значение
  void reset( TValue value )
  {
    mCount = 1;
    mSum2 = ( value - mAbsValue ) * ( value - mAbsValue );  
    mSKO = 0;
  }

  // добавить в набор очередной замер
  void add( TValue value )
  {
    mSum2 += ( value - mAbsValue ) * ( value - mAbsValue );  

    if( ++mCount >= mMaxCount )
    {
      mSum2 -= mSum2/mCount;
      mCount = mMaxCount - 1;
    }
    mSKO = 0;
  }

  float getSKO()
  {
    if( mSKO == 0 && mCount )
    {
      double disp = mSum2 / mCount;
      mSKO = (float)sqrt( disp );
    }
    return mSKO;
  }

  // кол-во элементов накопления статистики
  TCount GetCount()	    { return mCount; }

  // мах кол-во элементов накопления статистики
  TCount GetMaxCount()	{ return mMaxCount; }

  void SetMaxCount(TCount cnt)
  {
    mMaxCount = cnt;
    if( mCount >= mMaxCount )
    {
      int delta = mCount - mMaxCount + 1;
      mSum2 -= (mSum2/mCount)*delta;
    }
  }
};
//---------------------------------------------------------------------------

#endif
