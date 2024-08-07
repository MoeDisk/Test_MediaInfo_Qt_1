#ifndef MEDIAINFOHELPER_H
#define MEDIAINFOHELPER_H

#define _UNICODE

#include "MediaInfoDLL_Win.h"

#ifdef MEDIAINFO_LIBRARY
#include "MediaInfo/MediaInfo.h" //Staticly-loaded library (.lib or .a or .so)
#define MediaInfoNameSpace MediaInfoLib;
#else //MEDIAINFO_LIBRARY
//#include "MediaInfoDemo.h" //Dynamicly-loaded library (.dll or .so)
#define MediaInfoNameSpace MediaInfoDLL;
#endif //MEDIAINFO_LIBRARY
#include <iostream>
#include <iomanip>
using namespace MediaInfoNameSpace


#ifdef __MINGW32__
#ifdef _UNICODE
#define _itot _itow
#else //_UNICODE
#define _itot itoa
#endif //_UNICODE
#endif //__MINGW32

#include <QString>
class HMediaInfoHelper
{
    struct HMediaInfo
    {
      int width;   //宽
      int height;  //高
      int duration; //时长
      double frameRate;  //帧率
      double bitRate;   //比特率
      QString completeInfo; //常规信息
      HMediaInfo(){
          width = 0;
          height = 0;
          duration = 0;
          frameRate = 0.0;
          bitRate = 0.0;
      }
    };
public:
    HMediaInfoHelper();

    /**
    * @brief 获取媒体信息
    * @param mediaFile 媒体文件名
    * @param mediaType 媒体类型  -1general  0图片 1视频 2音频
    * @return
    */
    HMediaInfo GetMediaInfo(QString mediaFile,int mediaType = -1);
};

#endif // MEDIAINFOHELPER_H
