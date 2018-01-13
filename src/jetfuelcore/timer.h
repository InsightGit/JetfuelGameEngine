/*
* Jetfuel Game Engine- A SDL-based 2D game-engine
* Copyright (C) 2017 InfernoStudios
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef JETFUELCORE_TIMER_H_
#define JETFUELCORE_TIMER_H_
#include <cstdio>
#include <ctime>

namespace jetfuel {
    namespace core {
        class Timer {
        public:
            /// \brief Default constructor
            ///
            /// Initializes a timer with a duration that will
            /// be set later.
            Timer(){}

            /// \brief Constructs a timer with a duration and
            /// optionally starts that timer.
            ///
            /// Constructs a timer with a duration that
            /// can be changed later before/after it is in use
            /// and optionally starts the timer if
            /// starttimer is set to true.
            ///
            /// \param double duration
            /// \param bool starttimer
            Timer(double duration, bool starttimer = false){
                m_duration = duration;
                if(starttimer){
                    Start();
                }
            }

            /// \brief Sets the duration of the timer if it
            /// is not in use.
            ///
            /// Sets the duration of the timer if it is not in use.
            /// If it is in use, the function will not
            /// set the duration and return a boolean of false.
            /// Otherwise, this function will set the duration of and
            /// return a boolean of true.
            ///
            /// \param double duration
            bool Set_duration(double duration) {
                if(!m_inuse){
                    m_duration = duration;
                    return true;
                }

                return false;
            }

            /// \brief Starts the timer if it is not already in use
            /// or has no duration set.
            ///
            /// Starts the timer and marks the timer as in use
            /// if it not already in use or it has no duration set.
            /// If it is in use or has no duration, then it will not
            /// start the timer and will return a boolean of false.
            ///
            /// Otherwise, it will start the timer, returning a
            /// boolean of true.
            bool Start() {
                if(m_duration==NULL || m_inuse){
                    return false;
                }

                m_startperiod = std::clock();
                m_inuse = true;
                return true;
            }


            /// \brief Checks if the timer has finished.
            ///
            /// Checks if the timer has finished.
            /// If the timer has finished, the function
            /// will mark the timer as no longer in use to be reused.
            /// This function will return a boolean
            /// of true if the timer was in use and has finished,
            /// and a boolean of false otherwise.
            bool Has_timer_finished() {
                // Check if in use (started).
                if(m_inuse){
                    // Check that the delta between now and
                    // startperiod equals the duration.
                    if((std::clock() - m_startperiod) /
                        (double) CLOCKS_PER_SEC == m_duration){
                        m_inuse = false;
                        m_finished = true;
                        return true;
                    }
                }
                return false;
            }

            /// \brief Checks if the timer has been started.
            ///
            /// Checks if the timer has been started.
            /// This function will return a boolean of true if the
            /// timer has been started (NOT FINISHED) and false otherwise.
            bool Has_timer_been_started(){
                if(!m_finished){
                    return m_inuse;
                }
                return true;
            }
        private:
            ///////////////////
            /// Member data ///
            ///////////////////

            std::clock_t m_startperiod; ///< Start period for when the timer started.
            bool m_inuse = false; ///< Boolean for when the timer is in use.
            bool m_finished = false; ///< Boolean for when the timer has finished.
            double m_duration; ///< Duration of the timer.
        };


        /// jetfuel::core::Timer
        ///
        /// jetfuel::core::Timer is a simple timer for use while
        /// delaying an in-game action.
        ///
        /// Code Example:
        ///     jetfuel::core::Timer timer(5.05);
        ///     timer.Start();
        ///     if(timer.Has_timer_finished()){
        ///         std::cout << "Timer with 5.05 seconds has finished!"
        ///         << std::endl;
        ///     }

    } /* namespace core */
} /* namespace jetfuel */

#endif /* JETFUELCORE_TIMER_H_ */
