#include "device.hpp"

using std::cout; using std::endl; using std::string;

void DeviceManager::printConnectedDevices()
{
    for (const auto& d : this->_connectedDevices) {
        cout << "Name: " << d->getName() << endl;
        cout << "Id: " << d->getId() << endl;
        cout << "Metrics:\n" << d->getMetrics() << endl;
    }
}

void DeviceManager::addDevices(const std::vector<Device>& devices)
{
    for (const Device& d : devices) {
        this->_connectedDevices.emplace_back(std::make_unique<Device>(d));
    }
}

void DeviceManager::addDevice(const Device& device)
{
    std::unique_ptr<Device> temp = std::make_unique<Device>(device);
    this->_connectedDevices.emplace_back(std::move(temp));
}

void DeviceManager::removeDevice(uint64_t id)
{
    this->_connectedDevices.erase(
        std::remove_if(
            this->_connectedDevices.begin(),
            this->_connectedDevices.end(),
            [id](auto& item) { return item->getId() == id; }
        ),
        this->_connectedDevices.end()
    );
}

const std::vector<std::unique_ptr<Device>>& DeviceManager::getConnectedDevices()
{
    return this->_connectedDevices;
}

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
