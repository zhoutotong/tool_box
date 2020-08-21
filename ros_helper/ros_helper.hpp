#pragma once

#include <ros/ros.h>
#include <thread>
#include <QObject>
#include <std_msgs/Float32MultiArray.h>
#include "nox_msgs/Chassis.h"
#include "nox_msgs/DrivingCommand.h"
#include "nox_msgs/Vehicle.h"

#include <deque>

#pragma push_macro("signals")
#undef signals
#include "SignalDefines.hpp"
#pragma pop_macro("signals")

class RosHelper : public QObject
{
    Q_OBJECT
public:
    RosHelper(const RosHelper &) = delete;
    RosHelper & operator =(const RosHelper &) = delete;
    ~RosHelper();
    static RosHelper &getInstance(int argc = 0, char *argv[] = nullptr, std::string node_name = "")
    {
        static RosHelper instance(argc, argv, node_name);
        return instance;
    }

private:
    RosHelper(int argc, char *argv[], const std::string &node_name);

    std::thread *mWorkThread;
    bool mIsWorking;
    double mRealSpeed;
    double mSetSpeed;
    double mRealThro;
    double mSetThro;
    double mRealBrake;
    double mSlope;
    double mEngineSpeed;

    bool mEnableCtl;

    void chassisInfo(const nox_msgs::SignalArrayConstPtr &msg);
    void drivingCmdInfo(const nox_msgs::SignalArrayConstPtr &msg);
    void chassisParams(const std_msgs::Float32MultiArrayConstPtr &msg);

    enum DataDefines {
        FILTER_SIZE = 256,
    };
    std::deque<double> mValTable;
    double averageFilter(double val);
    double complementaryFilter(double val);

public:
    inline double getRealSpeed() const { return mRealSpeed; }
    inline double getSetSpeed() const { return mSetSpeed; }
    inline double getRealThro() const { return mRealThro; }
    inline double getSetThro() const { return mSetThro; }
    inline double getBrake() const { return mRealBrake; }
    inline double getSlope() const { return mSlope; }
    inline double getEngineSpeed() const { return mEngineSpeed; }

    // inline void setThro(double thro) { mSetThro = thro; }
};