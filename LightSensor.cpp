#include "LightSensor.hpp"

LightSensor::LightSensor(const QString &filePath, QObject *parent) :
	QObject(parent)
{
	m_file = new QFile(filePath);
}

int LightSensor::getLight()
{
	m_file->open(QIODevice::ReadOnly);
	char data[128];
	m_file->readLine(data, 128);
	QString s(data);
	return s.toInt();
}