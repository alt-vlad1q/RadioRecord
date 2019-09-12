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
    m_stations.insert(QString("Neurofunk"), QUrl("http://air.radiorecord.ru:805/neurofunk_320"));
    m_stations.insert(QString("Tecktonik"), QUrl("http://air.radiorecord.ru:805/tecktonik_320"));
    m_stations.insert(QString("2-step"), QUrl("http://air.radiorecord.ru:805/2step_320"));
    m_stations.insert(QString("Trance Hits"), QUrl("http://air.radiorecord.ru:805/trancehits_320"));
    m_stations.insert(QString("Rap Hits"), QUrl("http://air.radiorecord.ru:805/rap_320"));
    m_stations.insert(QString("Rap Classics"), QUrl("http://air.radiorecord.ru:805/rapclassics_320"));
    m_stations.insert(QString("Cadillac"), QUrl("http://air.radiorecord.ru:805/cadillac_320"));
    m_stations.insert(QString("1980-е"), QUrl("http://air.radiorecord.ru:805/1980_320"));
    m_stations.insert(QString("Chill House"), QUrl("http://air.radiorecord.ru:805/chillhouse_320"));
    m_stations.insert(QString("1970-е"), QUrl("http://air.radiorecord.ru:805/1970_320"));
    m_stations.insert(QString("Complextro"), QUrl("http://air.radiorecord.ru:805/complextro_320"));
    m_stations.insert(QString("Groove Tribal"), QUrl("http://air.radiorecord.ru:805/groovetribal_320"));
    m_stations.insert(QString("Russian Hits"), QUrl("http://air.radiorecord.ru:805/russianhits_320"));
    m_stations.insert(QString("Megamix"), QUrl("http://air.radiorecord.ru:805/mix_320"));
    m_stations.insert(QString("Jungle"), QUrl("http://air.radiorecord.ru:805/jungle_320"));
    m_stations.insert(QString("Liquid Funk"), QUrl("http://air.radiorecord.ru:805/liquidfunk_320"));
    m_stations.insert(QString("Drum'n'Bass Hits"), QUrl("http://air.radiorecord.ru:805/drumhits_320"));
    m_stations.insert(QString("Russian Gold"), QUrl("http://air.radiorecord.ru:805/russiangold_320"));
    m_stations.insert(QString("Eurodance"), QUrl("http://air.radiorecord.ru:805/eurodance_320"));
    m_stations.insert(QString("Technopop"), QUrl("http://air.radiorecord.ru:805/technopop_320"));
    m_stations.insert(QString("Disco Func"), QUrl("http://air.radiorecord.ru:805/discofunk_320"));
    m_stations.insert(QString("EDM"), QUrl("http://air.radiorecord.ru:805/club_320"));
    m_stations.insert(QString("Tropical"), QUrl("http://air.radiorecord.ru:805/trop_320"));
    m_stations.insert(QString("GOA PSY"), QUrl("http://air.radiorecord.ru:805/goa_320"));
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

void StationChooser::stop()
{
    m_player->stop();
}
