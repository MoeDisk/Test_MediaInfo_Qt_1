#include "MediaInfoHelper.h"

HMediaInfoHelper::HMediaInfoHelper()
{

}

HMediaInfoHelper::HMediaInfo HMediaInfoHelper::GetMediaInfo(QString mediaFile, int mediaType)
{
    //参数0-图片，1-视频，2-音频，3-通用
    HMediaInfo res;
    MediaInfo MI;
    auto temp = mediaFile.toStdWString();
    auto desFile = temp.c_str();
    MI.Open(desFile);
    MI.Option(__T("Complete"), __T("1"));
    stream_t streamType = Stream_General;
    if (mediaType == 0) {
        streamType = Stream_Image;
    } else if (mediaType == 1) {
        streamType = Stream_Video;
    }else if(mediaType == 2){
        streamType = Stream_Audio;
    } else {
        streamType = Stream_General;
    }
    auto comp = QString::fromStdWString((std::basic_string<wchar_t>)MI.Inform());
    auto wid = QString::fromStdWString((std::basic_string<wchar_t>)MI.Get(streamType, 0, __T("Width"))).toInt();
    auto hei = QString::fromStdWString((std::basic_string<wchar_t>)MI.Get(streamType, 0, __T("Height"))).toInt();
    auto dur = QString::fromStdWString((std::basic_string<wchar_t>)MI.Get(streamType, 0, __T("Duration"))).toInt();
    auto frameRate = QString::fromStdWString((std::basic_string<wchar_t>)MI.Get(streamType, 0, __T("FrameRate"))).toDouble();
    auto bitRate = QString::fromStdWString((std::basic_string<wchar_t>)MI.Get(streamType, 0, __T("BitRate"))).toDouble();
    MI.Close();

    res.completeInfo = comp;
    res.width = wid;
    res.height = hei;
    res.duration = dur;
    res.frameRate = frameRate;
    res.bitRate = bitRate;
    return res;
}
