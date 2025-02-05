#ifndef LOGGER_H__
#define LOGGER_H__
#include <iostream>
#include <vector>
#include <queue>

#include "Job.h"

#include "TaggedData.h"
#include "DelayedData.h"


/** This file is engine code of CPSim-Re engine
 * @file Logger.h
 * @class Logger
 * @author Seonghyeon Park
 * @date 2020-04-30
 * @brief Codes for Engine-Logger 
*/
struct logDump{
    long long timeStamp;
    int jobID;
    std::string evType;
    bool operator<(const logDump& rhs) const{
        return timeStamp > rhs.timeStamp;
    }
};

class logComp{
public:
    int operator() (const logDump& l1, const logDump& l2)
    {
        return l1.timeStamp > l2.timeStamp;
    }
};

class Logger{
private:
    std::vector<std::shared_ptr<Job>> m_execution_order_buffer;
    std::vector<double> m_current_time_buffer;
    
public:
    /**
     * Constructors and Destructors
     */
    
    Logger();
    ~Logger();

    // Final Project 2 case 1
    void _2019_18675_task_read_write_logger(std::string, std::string);
    std::string _2019_18675_log_prepare_Tagged_Data(std::shared_ptr<TaggedData>);
    std::string _2019_18675_log_prepare_Delayed_Data(std::shared_ptr<DelayedData>);
    std::string _2019_18675_log_prepare_byte_hex(int);
    //Final Project 2 case 2
    void _2019_18675_real_cyber_event_logger(long long, int, std::string, bool);
    std::priority_queue<logDump, std::vector<logDump>, logComp> prQ;
    /**
     * Getter & Setter
     */

    std::vector<std::shared_ptr<Job>> get_execution_order_buffer();
    void set_execution_order_buffer(std::vector<std::shared_ptr<Job>>);
    void add_current_simulated_job(std::shared_ptr<Job>);
    void start_logging();
    void log_task_vector_status(std::vector<std::shared_ptr<Task>>&);
    void log_job_vector_of_each_ECU_status(std::vector<std::vector<std::vector<std::shared_ptr<Job>>>>&);
    void log_job_vector_of_simulator_status(std::vector<std::shared_ptr<Job>>&);
    void log_which_job_was_deadline_miss(std::shared_ptr<Job>);
    void print_job_execution_on_ECU(std::vector<std::shared_ptr<Job>>, std::vector<std::shared_ptr<Job>>, int);
    void print_job_execution_schedule();
    void print_offline_guider_status();
    void set_schedule_log_info(std::vector<std::shared_ptr<Task>>&);
};

#endif