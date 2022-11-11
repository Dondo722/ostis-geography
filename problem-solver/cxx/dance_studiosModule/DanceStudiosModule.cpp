/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "DanceStudiosModule.hpp"


#include "agent/SearchDanceStudiosByCityAgent.hpp"
#include "keynodes/DanceStudiosKeynodes.hpp"

using namespace dance_studios;

SC_IMPLEMENT_MODULE(DanceStudiosModule)

sc_result DanceStudiosModule::InitializeImpl()
{
  SC_LOG_INFO("module start");

  if (!DanceStudiosKeynodes::InitGlobal())
    return SC_RESULT_ERROR;


  SC_AGENT_REGISTER(SearchDanceStudiosByCityAgent)

  return SC_RESULT_OK;
}

sc_result DanceStudiosModule::ShutdownImpl()
{

  SC_AGENT_UNREGISTER(SearchDanceStudiosByCityAgent)

  return SC_RESULT_OK;
}
