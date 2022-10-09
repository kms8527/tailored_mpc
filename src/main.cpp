#include <ros/ros.h>
#include "mpc.hh"
#include "structures/params.hh"


void dynamicCallback(tailored_mpc::dynamicConfig &config, uint32_t level, MPC* mpc){

    ROS_WARN("MPC: Setting new dynamic parameters..");
	mpc->reconfigure(config);

}

int main(int argc, char **argv) {

    // Init Node:
    ros::init(argc, argv, "tailored_mpc");

    // Handle Connections:
    ros::NodeHandle nh;

    // Params object
    Params params = Params(nh);

    // Optimizer object
    shared_ptr<casadi::Function> solverPtr;
    if(!params.FORCES){
        Optimizer opt(params);
        solverPtr = opt.generate_solver();
    }
    // MPC object
    MPC mpc(params);
    mpc.ipopt.solver_ptr = solverPtr;

    // Publishers & Subscribers
    ros::Subscriber subState = nh.subscribe(params.mpc.topics.state, 1, &MPC::stateCallback, &mpc);
    ros::Subscriber subPlanner = nh.subscribe(params.mpc.topics.planner, 1, &MPC::plannerCallback, &mpc);
    ros::Publisher pubCommands = nh.advertise<as_msgs::CarCommands>(params.mpc.topics.commands, 1);

    // Dynamic reconfigure
	dynamic_reconfigure::Server<tailored_mpc::dynamicConfig> server;
	dynamic_reconfigure::Server<tailored_mpc::dynamicConfig>::CallbackType f;
   
	f = boost::bind(&dynamicCallback, _1, _2, &mpc);
	server.setCallback(f);

    // ros::Rate r(int(1/mpc.T));
    ROS_INFO_STREAM("MPC: publish frequency: " << mpc.Hz << "Hz");
    ros::Rate r(mpc.Hz);
    while(ros::ok()){

        // mpc.solve();

        as_msgs::CarCommands msg = as_msgs::CarCommands();
        mpc.msgCommands(&msg);
        // pubCommands.publish(msg);

        ros::spinOnce();
        r.sleep();
    }

    return 0;
}