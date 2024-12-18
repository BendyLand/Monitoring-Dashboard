#pragma once

#include <iostream>
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
