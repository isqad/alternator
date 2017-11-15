#include <map>
#include "sphinxudf.h"
#include "alternate.h"

extern "C" {

int alternate_ver()
{
    return SPH_UDF_VERSION;
}

int alternate_init(SPH_UDF_INIT * init, SPH_UDF_ARGS * args, char * error_flag)
{
    // init map
    // attribute => counter
    std::map<int,int> attrsCounter;

    init->func_data = &attrsCounter;

    return 0;
}

void alternate_deinit(SPH_UDF_INIT * init)
{
    // clear our map
    std::map<int,int>* pMap = (std::map<int,int>*)init->func_data;

    (*pMap).clear();
}

sphinx_int64_t alternate(SPH_UDF_INIT * init, SPH_UDF_ARGS * args, char * error_flag)
{
    int res = *(int*)args->arg_values[0];
    std::map<int,int>* pMap = (std::map<int,int>*)init->func_data;

    int curVal = (*pMap)[res];

    if (curVal)
    {
      (*pMap)[res] = curVal + 1;
    }
    else
    {
      (*pMap)[res] = 1;
    }

    return (*pMap)[res];
}

}
