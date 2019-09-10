#include "stationchooser.h"

#include <QDir>
#include <QUrl>
#include <QDebug>

StationChooser::StationChooser(QObject *parent) : QObject(parent), m_player(new QMediaPlayer())
{
    m_stations.insert(QString("Radio Record"), QUrl("http://air.radiorecord.ru:805/rr_320"));
    m_stations.insert(QString("Deep"), QUrl("http://air.radiorecord.ru:805/deep_320"));
    m_stations.insert(QString("Веснушка FM"), QUrl("http://air.radiorecord.ru:805/deti_320"));
    m_stations.insert(QString("Gold"), QUrl("http://air.radiorecord.ru:805/gold_320"));
    m_stations.insert(QString("Innocence"), QUrl("http://air.radiorecord.ru:805/ibiza_320"));
    m_stations.insert(QString("Маятник Фуко"), QUrl("http://air.radiorecord.ru:805/mf_320"));
    m_stations.insert(QString("Electro"), QUrl("http://air.radiorecord.ru:805/elect_320"));
    m_stations.insert(QString("Midtempo"), QUrl("http://air.radiorecord.ru:805/mt_320"));
    m_stations.insert(QString("Bass House"), QUrl("http://air.radiorecord.ru:805/jackin_320"));
    m_stations.insert(QString("Progressive"), QUrl("http://air.radiorecord.ru:805/progr_320"));
    m_stations.insert(QString("Synthwave"), QUrl("http://air.radiorecord.ru:805/synth_320"));
    m_stations.insert(QString("House Hits"), QUrl("http://air.radiorecord.ru:805/househits_320"));
    m_stations.insert(QString("Big Hits"), QUrl("http://air.radiorecord.ru:805/bighits_320"));
    m_stations.insert(QString("Dream Dance"), QUrl("http://air.radiorecord.ru:805/dream_320"));
    m_stations.insert(QString("Darkside"), QUrl("http://air.radiorecord.ru:805/darkside_320"));
    m_stations.insert(QString("Uplifting"), QUrl("http://air.radiorecord.ru:805/uplift_320"));
    m_stations.insert(QString("House Classics"), QUrl("http://air.radiorecord.ru:805/houseclss_320"));
    m_stations.insert(QString("EDM Hits"), QUrl("http://air.radiorecord.ru:805/edmhits_320"));


    m_stations.insert(QString("Russian Hits"), QUrl("http://air.radiorecord.ru:805/russianhits_320"));

}

StationChooser::~StationChooser()
{

}

void StationChooser::setStation(QString name)
{
    if(!m_stations.contains(name)) {
        qWarning() << "Station not added";
        return;
    }
    m_player->setMedia(m_stations.value(name));
    m_player->play();
}
