#include "stationchooser.h"

#include <QDir>
#include <QUrl>
#include <QDebug>

StationChooser::StationChooser(QObject *parent) : QObject(parent), m_player(new QMediaPlayer())
{
    m_stations.insert(QString("Radio Record"), QUrl("http://air.radiorecord.ru:805/rr_320?rand=29928349"));
    m_stations.insert(QString("Deep"), QUrl("http://air.radiorecord.ru:805/deep_320"));
    m_stations.insert(QString("Веснушка FM"), QUrl("http://air.radiorecord.ru:805/deti_320"));
    m_stations.insert(QString("Gold"), QUrl("http://air.radiorecord.ru:805/gold_320"));
    m_stations.insert(QString("Innocence"), QUrl("http://air.radiorecord.ru:805/ibiza_320"));
    m_stations.insert(QString("Маятник Фуко"), QUrl("http://air.radiorecord.ru:805/mf_320"));
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
