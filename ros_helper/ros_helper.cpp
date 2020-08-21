#include "ros_helper.hpp"
#include <functional>

#pragma push_macro("signals")
#undef signals
#include "SignalDefines.hpp"
#pragma pop_macro("signals")

RosHelper::RosHelper(int argc, char *argv[], const std::string &node_name) : QObject(nullptr), mWorkThread(nullptr), mIsWorking(false), mEnableCtl(false)
  , mRealSpeed(0.0)
  , mSetSpeed(0.0)
  , mRealThro(0.0)
  , mSetThro(0.0)
  , mSlope(0.0)
{
    if (argc)
    {
        // mValTable.reserve(FILTER_SIZE);
        if (!mWorkThread)
        {
            mWorkThread = new std::thread([this, argc, argv, node_name] {
                int c = argc;
                ros::init(c, argv, node_name);
                ros::NodeHandle _n;
                ros::Subscriber chassisSub = _n.subscribe<nox_msgs::SignalArray>("/chassis_states", 10, std::bind(&RosHelper::chassisInfo, this, std::placeholders::_1));
                ros::Subscriber drivingCmdSub = _n.subscribe<nox_msgs::SignalArray>("/chassis_signals", 10, std::bind(&RosHelper::drivingCmdInfo, this, std::placeholders::_1));

                ros::Subscriber chassisParamSub = _n.subscribe<std_msgs::Float32MultiArray>("/chassis_params", 10, std::bind(&RosHelper::chassisParams, this, std::placeholders::_1));

                ros::Publisher ctlPub = _n.advertise<nox_msgs::SignalArray>("/chassis_signals", 10);

                mIsWorking = true;
                ros::Rate loop(50);

                while (mIsWorking)
                {
                    // defines::Panel panel;
                    // panel.

                    ros::spinOnce();
                    loop.sleep();
                }
                std::cout << "ROS HELPER EXIT! BYE!" << std::endl;
            });
        }
    }
}

RosHelper::~RosHelper()
{
    mIsWorking = false;
    if (mWorkThread)
    {
        mWorkThread->join();
        delete mWorkThread;
        mWorkThread = nullptr;
    }
}

double RosHelper::averageFilter(double val)
{
    static double sum = 0;
    mValTable.push_back(val);
    if (mValTable.size() > FILTER_SIZE)
    {
        sum -= mValTable.front();
        mValTable.pop_front();
    }
    else
    {
        return val;
    }

    sum += val;

    return sum / (double)FILTER_SIZE;
}

double RosHelper::complementaryFilter(double val)
{
    static double last_val = val;
    const double m = 0.01;
    double res = val * m + (last_val * (1.0 - m));
    last_val = res;
    return res;
}

void RosHelper::chassisInfo(const nox_msgs::SignalArrayConstPtr &msg)
{
    static int cnt = 0;
    defines::Panel panel;
    panel.FromMsgs(*msg);
    mRealSpeed = panel.Speed.Get();
    mRealThro = panel.Throttle.Get();
    mRealBrake = panel.Brake.Get();
    mEngineSpeed = panel.EngineSpeed.Get();

}
void RosHelper::drivingCmdInfo(const nox_msgs::SignalArrayConstPtr &msg)
{
    static int cnt = 0;
    defines::Panel panel;
    panel.FromMsgs(*msg);
    mSetSpeed = panel.Speed.Get();


}

void RosHelper::chassisParams(const std_msgs::Float32MultiArrayConstPtr &msg)
{
    mSetThro = msg->data.at(0);
    mSlope = msg->data.at(1);
}
