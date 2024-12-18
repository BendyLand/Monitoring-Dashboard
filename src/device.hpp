#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "utils.hpp"

enum class Metric
{
    STORAGE, 
    CPU,
    MEMORY,
    NETWORK,
};

struct Metrics
{
    double storage = 0;
    double cpu     = 0;
    double memory  = 0;
    double network = 0;
};

class Device
{
public:
    Device& operator=(const Device& other) noexcept 
    {
        if (this == &other) return *this; // handle self-assignment
        _name = other._name;
        _id = other._id;
        _metrics = other._metrics;
        return *this;
    }
    Device& operator=(Device&& other) noexcept 
    {
        if (this == &other) return *this; 
        _name = std::move(other._name);
        _id = other._id;
        _metrics = std::move(other._metrics);
        // Reset the moved-from object id
        other._id = 0;
        return *this;
    }

    // Methods
    std::string getName() const;
    uint64_t getId() const;
    Metrics getMetrics() const;
    void setMetrics(double storage, double cpu, double memory, double network);
    void updateMetric(const Metric& field, double value);
    void resetMetrics();
    void setName(const std::string& name);

    // Constructors
    explicit Device() : _name("Unnamed Device"), _id(genRandomNum()) {}
    explicit Device(const std::string& name) :
        _name(name), _metrics{}, _id(genRandomNum())
    {}
    explicit Device(const std::string& name, const Metrics& metrics) :
        _name(name), _metrics(metrics), _id(genRandomNum())
    {}
    // Copy/Move Constructors and Destructor
    Device(const Device& other) noexcept = default;
    Device(Device&& other) noexcept = default;
    ~Device() = default;
private:
    std::string _name;
    uint64_t _id;
    Metrics _metrics;
};

inline std::ostream& operator<<(std::ostream& os, const Metrics& metrics)
{
    os << "Storage: " << metrics.storage << "\n";
    os << "CPU: " << metrics.cpu << "\n";
    os << "Memory: " << metrics.memory << "\n";
    os << "Network: " << metrics.network << "\n";
    return os;
}

class DeviceManager
{
public:
    // Methods
    void addDevice(const Device& device);
    void addDevices(const std::vector<Device>& devices);
    void removeDevice(uint64_t id);
    void printConnectedDevices();
    const std::vector<std::unique_ptr<Device>>& getConnectedDevices();
    // Constructors
    DeviceManager() = default;
    // Copy/Move Constructors and Destructor
    DeviceManager(const DeviceManager& other) noexcept = default;
    DeviceManager(DeviceManager&& other) noexcept = default;
    ~DeviceManager() = default;
private:
    // Fields
    std::vector<std::unique_ptr<Device>> _connectedDevices;
};
