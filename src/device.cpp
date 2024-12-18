#include "device.hpp"

using std::cout; using std::endl; using std::string;

void Device::resetMetrics()
{
    this->_metrics.storage = 0;
    this->_metrics.cpu = 0;
    this->_metrics.memory = 0;
    this->_metrics.network = 0;
}

void Device::updateMetric(const Metric& field, double value)
{
    switch (field) {
    case Metric::STORAGE:
        this->_metrics.storage = value;
        break;
    case Metric::CPU:
        this->_metrics.cpu = value;
        break;
    case Metric::MEMORY:
        this->_metrics.memory = value;
        break;
    case Metric::NETWORK:
        this->_metrics.network = value;
        break;
    }
}

Metrics Device::getMetrics() const
{
    return this->_metrics;
}

string Device::getName() const
{
    return this->_name;
}

uint64_t Device::getId() const
{
    return this->_id;
}

void Device::setMetrics(double storage, double cpu, double memory, double network)
{
    this->_metrics.storage = storage;
    this->_metrics.cpu = cpu;
    this->_metrics.memory = memory;
    this->_metrics.network = network;
}

void Device::setName(const string& name)
{
    this->_name = name;
}
