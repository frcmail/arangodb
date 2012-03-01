////////////////////////////////////////////////////////////////////////////////
/// @brief tasks used to handle asynchronous events
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2012 triagens GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Achim Brandt
/// @author Copyright 2008-2012, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_SCHEDULER_ASYNC_TASK_H
#define TRIAGENS_SCHEDULER_ASYNC_TASK_H 1

#include "Scheduler/Task.h"

namespace triagens {
  namespace rest {

////////////////////////////////////////////////////////////////////////////////
/// @brief task used to handle asyncs
////////////////////////////////////////////////////////////////////////////////

    class  AsyncTask : virtual public Task {
      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief constructs a new task
////////////////////////////////////////////////////////////////////////////////

        AsyncTask ();

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief signals the task
///
/// Note that this method can only be called after the task has been registered.
////////////////////////////////////////////////////////////////////////////////

        void signal ();

      protected:

////////////////////////////////////////////////////////////////////////////////
/// @brief destructor
////////////////////////////////////////////////////////////////////////////////

        ~AsyncTask ();

      protected:

////////////////////////////////////////////////////////////////////////////////
/// @brief handles the signal
////////////////////////////////////////////////////////////////////////////////

        virtual bool handleAsync () = 0;

      protected:

////////////////////////////////////////////////////////////////////////////////
/// {@inheritDoc}
////////////////////////////////////////////////////////////////////////////////

        void setup (Scheduler*, EventLoop);

////////////////////////////////////////////////////////////////////////////////
/// {@inheritDoc}
////////////////////////////////////////////////////////////////////////////////

        void cleanup ();

////////////////////////////////////////////////////////////////////////////////
/// {@inheritDoc}
////////////////////////////////////////////////////////////////////////////////

        bool handleEvent (EventToken, EventType);

      protected:

////////////////////////////////////////////////////////////////////////////////
/// @brief event for async signals
////////////////////////////////////////////////////////////////////////////////

        EventToken watcher;
    };
  }
}

#endif
